#pragma once
#include "AbstractSort.h"

class InsertionSort : public AbstractSort
{
public:
	InsertionSort(std::vector<int>& arr);

	void sortByIncrease() override;
	void sortByDecrease() override;
	std::string getSortType() override;
};

