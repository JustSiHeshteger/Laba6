#include "SelectionSort.h"
#include "Timer.h"

SelectionSort::SelectionSort(std::vector<int>& arr) {
	this->resetCountCompare();
	this->resetCountSwap();
	this->arr = arr;
}

void SelectionSort::sortByIncrease() {
	size_t arrSize = this->arr.size();

	if (arrSize == 0) {
		return;
	}

	Timer t;

	for (size_t i = 0; i < arrSize - 1; i++) {
		size_t minIndex = i;

		for (size_t j = i + 1; j < arrSize; j++) {
			if (this->arr[j] < this->arr[minIndex]) {
				minIndex = j;
			}

			this->countCompare++;
		}

		if (i != minIndex) {
			this->swapElements(i, minIndex);
		}
	}

	this->duration += t.getDuration();
}

void SelectionSort::sortByDecrease() {
	size_t arrSize = this->arr.size();

	if (arrSize == 0) {
		return;
	}

	Timer t;

	for (size_t i = 0; i < arrSize - 1; i++) {
		size_t maxIndex = i;

		for (size_t j = i + 1; j < arrSize; j++) {
			if (this->arr[j] > this->arr[maxIndex]) {
				maxIndex = j;
			}

			this->countCompare++;
		}

		if (i != maxIndex) {
			this->swapElements(i, maxIndex);
		}
	}

	this->duration += t.getDuration();
}

std::string SelectionSort::getSortType() {
	return "Selection sort:";
}