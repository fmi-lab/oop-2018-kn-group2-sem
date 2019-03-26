#include <iostream>
#include "BlogPost.cpp"

class Blog {
public:
	Blog() {
		blogPostsCount = 0;
		blogPost = new BlogPost[0];
	}

	~Blog() {
		doDelete();
	}

	Blog(const Blog& other) {
		doCopy(other);
	}

	Blog& operator=(const Blog& other) {
		if (this != &other) {
			doDelete();
			doCopy(other);
		}
		return *this;
	}

	BlogPostSummary* findAllBlogPosts(int & n) {
		posts = new BlogPostSummary[blogPostsCount];
		n = blogPostsCount;
		for (int i = 0; i < blogPostsCount; i++) {
			posts[i] = blogPosts[i].getSummary();
		}
		return posts;
	}

	BlogPost getBlogPostBy(int id) {

	}

	BlogPostSummary* findBlogPostsBy(const char * tag, int & n) {

	}

	void create(BlogPost blogPost) {

	}

private:
	void doCopy(const BlogPost * blogPosts, int blogPostsCount) {
	}

	void doCopy(const Blog& other) {
		doCopy(other.blogPosts, other.blogPostsCount);
	}

	void doDelete() {
		delete[] blogPosts;
	}

private:
	BlogPost * blogPosts;
	int blogPostsCount;
};
