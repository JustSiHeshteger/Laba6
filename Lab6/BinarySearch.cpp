#include "BinarySearch.h"

BinarySearch::BinarySearch(std::vector<int>& arr) {
	this->setArray(arr);
}

void BinarySearch::findByElement(int element) {
	this->result.clear();
	Timer t;
	
	findElement(element, 0);

	this->duration = t.getDuration();
}

void BinarySearch::findBySequence(std::vector<int>& sequence) {
	this->result.clear();
	Timer t;

	for (int i = 0; i < sequence.size(); i++) {
		findElement(sequence[i], i);
	}

	this->duration = t.getDuration();
}

void BinarySearch::findElement(int element, int key) {
	int left = 0;
	int right = this->arr.size() - 1;

	int middle;

	while (left <= right) {
		middle = (left + right) / 2;

		if (this->arr[middle] == element) {
			Data data;
			data.key = key;
			data.position = middle;
			data.element = arr[middle];
			this->result.push_back(data);
			break;
		}

		if (this->arr[middle] < element) {
			left = middle + 1;
		}
		else {
			right = middle - 1;
		}
	}
}

std::string BinarySearch::getSearchType() {
	return "Binary Search";
}