#include "Matrix.h"

Matrix::Matrix(int m, int n) {
	this->M = m;
	this->N = n;
    srand(time(0));
    this->fillMatrix(10000);
}

void Matrix::fillMatrix(int randomNum) {
    for (int i = 0; i < this->M; i++) {
        std::vector<int> buf;
        for (int j = 0; j < this->N; j++) {
            int num = rand() % randomNum;
            buf.push_back(num);
        }

        matrix.push_back(buf);
    }
}

std::vector<std::vector<int>> Matrix::getMatrix() {
    return this->matrix;
}

int Matrix::getM() {
    return this->M;
}

int Matrix::getN() {
    return this->N;
}

std::vector<int> Matrix::getMainDiagonal() {
    std::vector<int> arr;

    for (int i = 0; i < this->M; i++) {
        for (int j = 0; j < this->N; j++) {
            if (i == j) {
                arr.push_back(matrix[i][j]);
            }
        }
    }

    return arr;
}

void Matrix::setMainDiagonal(std::vector<int> arr) {
    int pointer = 0;

    for (int i = 0; i < this->M; i++) {
        for (int j = 0; j < this->N; j++) {
            if (i == j) {
                matrix[i][j] = arr[pointer];
                pointer++;
            }
        }
    }
}

std::vector<int> Matrix::getUpDiagonal() {
    std::vector<int> arr;

    for (int i = 0; i < this->M; i++) {
        for (int j = 0; j < this->N; j++) {
            if (i < j) {
                arr.push_back(matrix[i][j]);
            }
        }
    }

    return arr;
}

void Matrix::setUpDiagonal(std::vector<int> arr) {
    int pointer = 0;

    for (int i = 0; i < this->M; i++) {
        for (int j = this->N - 1; j >= 0; j--) {
            if (i < j) {
                matrix[i][j] = arr[pointer];
                pointer++;
            }
        }
    }
}

std::vector<int> Matrix::getDownDiagonal() {
    std::vector<int> arr;

    for (int i = 0; i < this->M; i++) {
        for (int j = 0; j < this->N; j++) {
            if (i > j) {
                arr.push_back(matrix[i][j]);
            }
        }
    }

    return arr;
}

void Matrix::setDownDiagonal(std::vector<int> arr) {
    int pointer = 0;

    for (int i = this->M - 1; i > 0; i--) {
        for (int j = 0; j < this->N; j++) {
            if (i > j) {
                matrix[i][j] = arr[pointer];
                pointer++;
            }
        }
    }
}