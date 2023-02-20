#pragma once
#include "AbstractSort.h"

class ShellSort : public AbstractSort
{
public:
	ShellSort(std::vector<int>& arr);

	void sortByIncrease() override;
	void sortByDecrease() override;
	std::string getSortType() override;
};

