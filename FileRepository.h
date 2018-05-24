#pragma once
#include "Repository.h"

class FileRepository : public Repository {
protected:
	std::string source;
	
public:
	FileRepository(const std::string& source) : Repository(), source(source) {}
	FileRepository(const FileRepository& f): Repository(f), source(f.source) {}
	virtual ~FileRepository() = default;
	virtual void display() = 0;
	virtual void repoReadFile() = 0;
	virtual void repoWriteFile() = 0;
};
