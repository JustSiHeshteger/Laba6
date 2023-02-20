#include "InsertionSort.h"
#include "Timer.h"

InsertionSort::InsertionSort(std::vector<int>& arr) {
	this->resetCountCompare();
	this->resetCountSwap();
	this->arr = arr;
}

void InsertionSort::sortByIncrease() {
	size_t arrSize = this->arr.size();

	Timer t;

	for (size_t i = 1; i < arrSize; i++) { 
		size_t k = i;

		while (k > 0) {
			if (this->arr[k] < this->arr[k - 1]) {
				this->swapElements(k, k - 1);
			}

			k--;
			this->countCompare++;
		}
	}

	this->duration += t.getDuration();
}

void InsertionSort::sortByDecrease() {
	size_t arrSize = this->arr.size();

	Timer t;

	for (size_t i = 1; i < arrSize; i++) { 
		size_t k = i;

		while (k > 0) {
			if (this->arr[k] > this->arr[k - 1]) {
				this->swapElements(k, k - 1);
			}

			k--;
			this->countCompare++;
		}
	}

	this->duration += t.getDuration();
}

std::string InsertionSort::getSortType() {
	return "Insertion sort:";
}