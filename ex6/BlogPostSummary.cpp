#include <cstring>

class BlogPostSummary {
public:
	BlogPostSummary(int id = 0, const char * title = "") {
		this->id = id;
		doCopy(this->title, title);
	}

	~BlogPostSummary() {
		doDelete();
	}

	BlogPostSummary(const BlogPostSummary& other) {
		doCopy(other);
	}

	BlogPostSummary& operator=(const BlogPostSummary& other) {
		if (this != &other) {
			doDelete();
			doCopy(other);
		}
		return *this;
	}

	const char * getTitle() const {
		return title;
	}

	void setTitle(const char * title) {
		delete this->title;
		doCopy(this->title, title);
	}

	int getId() const {
		return id;
	}

	void setId(int id) {
		this->id = id;
	}

private:
	void doCopy(char* &to, const char * from) {
		to = new char[strlen(from) + 1];
		strcpy(to, from);
	}

	void doCopy(const BlogPostSummary& other) {
		this->id = other.id;
		doCopy(this->title, other.title);
	}

	void doDelete() {
		delete[] title;
	}

private:
	int id;
	char * title;
};
