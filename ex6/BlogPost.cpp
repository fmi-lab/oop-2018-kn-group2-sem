#include <iostream>
#include "Tag.cpp"
#include "BlogPostSummary.cpp"

class BlogPost {
public:
	BlogPost(int id = 0, 
		const char * title = "", 
		const char * content = "", 
		const char * image = "",
		const Tag * tags = nullptr,
		int tagsCount = 0) {

		this->id = id;
		doCopy(this->title, title);
		doCopy(this->content, content);
		doCopy(this->image, image);
		doCopy(tags, tagsCount);
	}

	~BlogPost() {
		doDelete();
	}

	BlogPost(const BlogPost& other) {
		doCopy(other);
	}

	BlogPost& operator=(const BlogPost& other) {
		if (this != &other) {
			doDelete();
			doCopy(other);
		}
		return *this;
	}

	BlogPostSummary getSummary() {
		return new BlogPostSummary(id, title);
	}

	int getId() const {
		return id;
	}

	void setId(int id) {
		this->id = id;
	}

	const char * getTitle() const {
		return title;
	}

	void setTitle(const char * title) {
		delete this->title;
		doCopy(this->title, title);
	}


	const char * getContent() const {
		return content;
	}

	void setContent(const char * content) {
		delete this->content;
		doCopy(this->content, content);
	}

	const char * getImage() const {
		return image;
	}

	void setImage(const char * image) {
		delete this->image;
		doCopy(this->image, image);
 	}

 	bool containsTag(Tag tag) {
 		for (int i = 0; i < tagsCount; i++) {
 			if (tags[i] == tag) {
 				return true;
 			}
 		}
 		return false;
 	}

 	void addTag(Tag tag) {
 		if (containsTag(tag)) {
 			return;
 		}
 		Tag * newTags = new Tag[tagsCount + 1];
 		for (int i = 0; i < tagsCount; i++) {
 			newTags[i] = tags[i];
 		}
 		newTags[tagsCount] = tag;
 		delete[] tags;
 		tags = newTags;
 		tagsCount++;
 	}

private:
	void doCopy(char* &to, const char * from) {
		to = new char[strlen(from) + 1];
		strcpy(to, from);
	}
	void doCopy(const Tag * tags, int tagsCount) {
		this->tags = new Tag[tagsCount];
		this->tagsCount = tagsCount;
		for (int i = 0; i < tagsCount; i++) {
			this->tags[i] = tags[i];
		}		
	}

	void doCopy(const BlogPost& other) {
		this->id = other.id;
		doCopy(this->title, other.title);
		doCopy(this->content, other.content);
		doCopy(this->image, other.image);
		doCopy(other.tags, other.tagsCount);		
	}

	void doDelete() {
		delete[] title;
		delete[] content;
		delete[] image;
		delete[] tags;
	}

private:
	int id;
	char * title;
	char * content;
	char * image;
	Tag * tags;
	int tagsCount;
};