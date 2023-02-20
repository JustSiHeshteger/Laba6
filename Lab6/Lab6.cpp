#include <iostream>
#include <thread>
#include <iomanip>
#include <windows.h>

#include "BubbleSort.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "ShellSort.h"
#include "QuickSort.h"
#include "Validator.h"
#include "Matrix.h"

HANDLE hStdout;
CONSOLE_SCREEN_BUFFER_INFO start_attribute;

int getNumber(std::string message)
{
    std::string number = "";

    do
    {
        std::cout << message;
        std::cin >> number;
    } while (!Validator::isIntegerNumber(number, "Введенное значение не является целым числом."));

    int num = std::stoi(number);
    return num;
}

void printMatrix(Matrix matrix) {
    std::vector<std::vector<int>> m = matrix.getMatrix();

    for (int i = 0; i < matrix.getM(); i++) {
        for (int j = 0; j < matrix.getN(); j++) {
            if (i == j)
                SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE);
            else if (i < j)
                SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN);
            else if (i > j)
                SetConsoleTextAttribute(hStdout, FOREGROUND_RED);

            std::cout << std::setw(7) << m[i][j];
        }

        std::cout << std::endl;
    }

    SetConsoleTextAttribute(hStdout, start_attribute.wAttributes);
    std::cout << std::endl;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hStdout, &start_attribute);

    int M, N;
    do {
        M = getNumber("Введите количество строк матрицы N (ЦЕЛОЕ, ПОЛОЖИТЕЛЬНОЕ, более 0): ");
    } while (!Validator::checkNumber(M));

    do {
        N = getNumber("Введите количество столбцов матрицы M (ЦЕЛОЕ, ПОЛОЖИТЕЛЬНОЕ, более 0): ");
    } while (!Validator::checkNumber(N));

    Matrix matrix(M, N);
    std::cout << "Неотсортированная матрица: " << std::endl;
    //printMatrix(matrix);

    std::vector<int> arrDiagonal = matrix.getMainDiagonal();
    std::vector<int> arrUp = matrix.getUpDiagonal();
    std::vector<int> arrDown = matrix.getDownDiagonal();

    std::vector<std::unique_ptr<AbstractSort>> sorts;
    sorts.push_back(std::make_unique<BubbleSort>(arrDiagonal));
    sorts.push_back(std::make_unique<InsertionSort>(arrDiagonal));
    sorts.push_back(std::make_unique<SelectionSort>(arrDiagonal));
    sorts.push_back(std::make_unique<ShellSort>(arrDiagonal));
    sorts.push_back(std::make_unique<QuickSort>(arrDiagonal));

    for (auto&& sort : sorts) {
        std::cout << sort->getSortType() << std::endl;
        sort->sortByIncrease();
        matrix.setMainDiagonal(sort->getArray());

        sort->setArray(arrUp);
        sort->sortByDecrease();
        matrix.setUpDiagonal(sort->getArray());

        sort->setArray(arrDown);
        sort->sortByIncrease();
        matrix.setDownDiagonal(sort->getArray());

        //printMatrix(matrix);
    }

    std::cout << "|----Sort type----|-Count compare-|-Count swap-|--Duration--|" << std::endl;
    for (auto&& sort : sorts) {
        std::cout << "|-----------------|---------------|------------|------------|" << std::endl;
        std::cout << "|" << std::setw(17) << sort->getSortType() << "|";
        std::cout << std::setw(15) << sort->getCountCompare() << "|";
        std::cout << std::setw(12) << sort->getCountSwap() << "|";
        std::cout << std::setw(12) << std::fixed << sort->getDuration() << "|";
        std::cout << std::endl;
    }
    std::cout << "|-----------------|---------------|------------|------------|" << std::endl;

    system("pause");
}