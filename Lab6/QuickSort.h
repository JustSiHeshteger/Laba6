#pragma once
#include "AbstractSort.h"

class QuickSort : public AbstractSort
{
private:
	void sort(int start, int end, short type);
	int getPivot(int start, int left, short type);
	
public:
	QuickSort(std::vector<int>& arr);

	void sortByIncrease() override;
	void sortByDecrease() override;
	std::string getSortType() override;
};

