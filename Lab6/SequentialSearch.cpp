#include "SequentialSearch.h"

SequentialSearch::SequentialSearch(std::vector<int>& arr) {
	this->setArray(arr);
}

void SequentialSearch::findByElement(int element) {
	this->clearResult();
	Timer t;

	for (int i = 0; i < this->arr.size(); i++) {
		if (element == this->arr[i]) {
			Data data;
			data.key = 0;
			data.position = i + 1;
			data.element = arr[i];
			this->result.push_back(data);
			break;
		}
	}

	this->duration = t.getDuration();
}

void SequentialSearch::findBySequence(std::vector<int>& sequence) {
	this->clearResult();
	Timer t;

	int key = 0;
	for (int i = 0; i < sequence.size(); i++) {
		for (int j = 0; j < this->arr.size(); j++) {
			if (sequence[i] == this->arr[j]) {
				Data data;
				data.key = key;
				data.position = j + 1;
				data.element = arr[j];
				this->result.push_back(data);
				key++;
				break;
			}
		}
	}

	this->duration = t.getDuration();
}

std::string SequentialSearch::getSearchType() {
	return "Sequential Search";
}