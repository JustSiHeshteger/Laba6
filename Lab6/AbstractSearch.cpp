#include "AbstractSearch.h"

void AbstractSearch::setArray(std::vector<int>& arr) {
	this->arr = std::vector<int>(arr);
}

std::vector<int> AbstractSearch::getArray() {
	return this->arr;
}

void AbstractSearch::clearResult() {
	this->result.clear();
}

std::vector<Data> AbstractSearch::getResult() {
	return this->result;
}

float AbstractSearch::getDuration() {
	return this->duration;
}