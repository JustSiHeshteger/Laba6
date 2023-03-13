#pragma once
#include "AbstractSearch.h"

class SequentialSearch : public AbstractSearch
{
public:
	SequentialSearch(std::vector<int>& arr);

	void findByElement(int) override;
	void findBySequence(std::vector<int>&) override;
	std::string getSearchType() override;
};

