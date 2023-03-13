#pragma once
#include <vector>
#include "Data.cpp"
#include "Timer.h"
#include <string>

class AbstractSearch
{
protected:
	float duration;
	std::vector<int> arr;
	std::vector<Data> result;

	void clearResult();

public:
	virtual void findByElement(int) = 0;
	virtual void findBySequence(std::vector<int>&) = 0;
	virtual std::string getSearchType() = 0;

	void setArray(std::vector<int>& arr);
	std::vector<int> getArray();
	std::vector<Data> getResult();

	float getDuration();
};

