#pragma once
#include "FileRepository.h"

class HTMLRepository : public FileRepository{
protected:
	void repoWriteFile() override;
	void repoReadFile() override {}
public:
	std::string site;
	HTMLRepository(const std::string& source) : FileRepository{ source } {}
	void display() override;
};