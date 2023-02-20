#pragma once
#include <vector>
#include <iostream>
#include <windows.h>

class Matrix
{
private:
	std::vector<std::vector<int>> matrix;
	int N;
	int M;

public:
	Matrix(int, int);

	void fillMatrix(int);
	std::vector<std::vector<int>> getMatrix();

	int getM();
	int getN();

	std::vector<int> getMainDiagonal();
	void setMainDiagonal(std::vector<int>);

	std::vector<int> getUpDiagonal();
	void setUpDiagonal(std::vector<int>);

	std::vector<int> getDownDiagonal();
	void setDownDiagonal(std::vector<int>);
};

