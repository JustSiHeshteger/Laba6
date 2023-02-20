#pragma once
#include "AbstractSort.h"

class SelectionSort : public AbstractSort
{
public:
	SelectionSort(std::vector<int>& arr);

	void sortByIncrease() override;
	void sortByDecrease() override;
	std::string getSortType() override;
};

