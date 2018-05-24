#pragma once
#include "FileRepository.h"

class CSVRepository : public FileRepository {
protected:
	void repoReadFile() override;
	void repoWriteFile() override;
public:
	CSVRepository(const std::string& source);
	~CSVRepository();
	void display() override;
};