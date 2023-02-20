#pragma once
#include "AbstractSort.h"
#include "Timer.h"

class BubbleSort : public AbstractSort
{
public: 
	BubbleSort(std::vector<int>& arr);

	void sortByIncrease() override;
	void sortByDecrease() override;
	std::string getSortType() override;
};