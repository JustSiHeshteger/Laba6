#include "QuickSort.h"
#include "Timer.h"

QuickSort::QuickSort(std::vector<int>& arr) {
	this->resetCountCompare();
    this->resetCountSwap();
	this->arr = arr;
}

void QuickSort::sort(int start, int end, short type) {
    if (start >= end) {
        return;
    }

    int pivot = getPivot(start, end, type);
    sort(start, pivot - 1, type);
    sort(pivot + 1, end, type);
}

int QuickSort::getPivot(int start, int end, short type) {
    int pivot = this->arr[end];
    int pIndex = start;

    for (int i = start; i < end; i++)
    {
        if (type == 0) {
            if (this->arr[i] < pivot)
            {
                swapElements(i, pIndex);
                pIndex++;
            }
        }
        else if (type == 1) {
            if (this->arr[i] > pivot)
            {
                swapElements(i, pIndex);
                pIndex++;
            }
        }

        this->countCompare++;
    }

    if (this->arr[pIndex] != this->arr[end]) {
        swapElements(pIndex, end);
    }

    return pIndex;
}

void QuickSort::sortByIncrease() {
    Timer t;

	this->sort(0, this->arr.size() - 1, 0);

    this->duration += t.getDuration();
}

void QuickSort::sortByDecrease() {
    Timer t;

    this->sort(0, this->arr.size() - 1, 1);

    this->duration += t.getDuration();
}

std::string QuickSort::getSortType() {
	return "Quick sort:";
}