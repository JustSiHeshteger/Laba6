#include "BubbleSort.h"
#include "Timer.h"

BubbleSort::BubbleSort(std::vector<int>& arr) {
	this->resetCountCompare();
	this->resetCountSwap();
	this->arr = arr;
}

void BubbleSort::sortByIncrease() {
	size_t arrSize = this->arr.size();

	Timer t;

	for (size_t i = arrSize; i != 1; i--) {
		int currentSwap = 0;
		for (size_t j = 1; j < i; j++) {
			if (arr[j - 1] > arr[j]) {
				this->swapElements(j, j - 1);
				currentSwap++;
			}

			this->countCompare++;
		}

		if (currentSwap == 0) {
			break;
		}
	}

	this->duration += t.getDuration();
}

void BubbleSort::sortByDecrease() {
	size_t arrSize = this->arr.size();

	Timer t;

	for (size_t i = arrSize; i != 1; i--) {
		int currentSwap = 0;

		for (size_t j = 1; j < i; j++) {
			if (arr[j - 1] < arr[j]) {
				this->swapElements(j, j - 1);
				currentSwap++;
			}

			this->countCompare++;
		}

		if (currentSwap == 0) {
			break;
		}
	}

	this->duration += t.getDuration();
}

std::string BubbleSort::getSortType() {
	return "Bubble sort:";
}