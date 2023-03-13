#pragma once
#include "AbstractSearch.h"

class BinarySearch : public AbstractSearch
{
private:
	void findElement(int, int);

public:
	BinarySearch(std::vector<int>& arr);

	void findByElement(int) override;
	void findBySequence(std::vector<int>&) override;
	std::string getSearchType() override;
};

