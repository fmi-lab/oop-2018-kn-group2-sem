class Tag {
public:
	Tag() {
		doCopy(this->name, "");
	}

	Tag(const char * name) {
		doCopy(this->name, name);
	}

	~Tag() {
		doDelete();
	}

	Tag(const Tag& other) {
		doCopy(other);
	}

	Tag& operator=(const Tag& other) {
		if (this != &other) {
			doDelete();
			doCopy(other);
		}
		return *this;
	}

	bool operator==(const Tag& other) {
		return strcmp(this->name, other.name) == 0;
	}

	const char * getName() const {
		return name;
	}

	void setName(const char * name) {
		delete this->name;
		doCopy(this->name, name);
	}
private:
	void doCopy(char* &to, const char * from) {
		to = new char[strlen(from) + 1];
		// strcpy_s(to, strlen(from) + 1, from); // VS
		strcpy(to, from); // warning: unsafe copy
	}

	void doCopy(const Tag& other) {
		doCopy(this->name, other.name);
	}

	void doDelete() {
		delete[] name;
	}

private:
	char * name;
};