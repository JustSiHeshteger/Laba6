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
#include "SequentialSearch.h"
#include "BinarySearch.h"

HANDLE hStdout;
CONSOLE_SCREEN_BUFFER_INFO start_attribute;

int getNumber(std::string);
void printMatrix(Matrix, std::vector<int>);

int main()
{
    setlocale(LC_ALL, "Rus");
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hStdout, &start_attribute);

    int M, N, action;
    do {
        M = getNumber("Введите количество строк матрицы N (ЦЕЛОЕ, ПОЛОЖИТЕЛЬНОЕ, более 0): ");
    } while (!Validator::checkNumber(M));

    do {
        N = getNumber("Введите количество столбцов матрицы M (ЦЕЛОЕ, ПОЛОЖИТЕЛЬНОЕ, более 0): ");
    } while (!Validator::checkNumber(N));

    do {
        action = getNumber("Выберите действие:\n1. Поиск одного элемента\n2. Поиск последовательности элементов\n");
    } while (!Validator::checkNumber(action, 1, 2));

    std::vector<int> elements;
    Matrix matrix(M, N);
    std::cout << "Начальная матрица: " << std::endl;
    printMatrix(matrix, elements);

    std::vector<int> unsort = matrix.getAllElements();

    BubbleSort bSort(unsort);
    bSort.sortByIncrease();
    std::vector<int> sort = bSort.getArray();

    std::vector<std::unique_ptr<AbstractSearch>> search;
    search.push_back(std::make_unique<SequentialSearch>(unsort));
    search.push_back(std::make_unique<BinarySearch>(sort));
    std::vector<int> sequence;

    switch (action)
    {
    case 1:
        int n;
        do {
            n = getNumber("Введите элемент, который хотите найти: ");
        } while (!Validator::checkNumber(n, -1000000, 1000000));

        for (auto&& s : search) {
            std::vector<Data> data;
            s->findByElement(n);
            data = s->getResult();
            
            for (int i = 0; i < data.size(); i++) {
                std::cout << "Элемент " << data[i].element << " найден с помощью " << s->getSearchType() << "." << std::endl;
            }
            std::cout << "Время: " << std::fixed << s->getDuration() << std::endl << std::endl;

            if (s->getSearchType() == "Sequential Search") {
                for (int i = 0; i < data.size(); i++) {
                    elements.push_back(data[i].element);
                }
            }
        }
        break;

    case 2:
        int count;
        do {
            count = getNumber("Введите количество элементов в последовательности: ");
        } while (!Validator::checkNumber(count, -1000000, 1000000));

        for (int i = 0; i < count; i++) {
            int element;
            do {
                element = getNumber("Введите элемент, который хотите найти: ");
            } while (!Validator::checkNumber(element, -1000000, 1000000));

            sequence.push_back(element);
        }

        for (auto&& s : search) {
            std::vector<Data> data;
            s->findBySequence(sequence);
            data = s->getResult();

            for (int i = 0; i < data.size(); i++) {
                std::cout << "Элемент " << data[i].element << " найден с помощью " << s->getSearchType() << "." << std::endl;
            }
            std::cout << "Время: " << std::fixed << s->getDuration() << std::endl << std::endl;

            if (s->getSearchType() == "Sequential Search") {
                for (int i = 0; i < data.size(); i++) {
                    elements.push_back(data[i].element);
                }
            }
        }
        break;

    default:
        break;
    }

    printMatrix(matrix, elements);

    system("pause");
}

int getNumber(std::string message)
{
    std::string number = "";

    do
    {
        std::cout << message;
        std::cin >> number;
    } while (!Validator::isIntegerNumber(number, "Введенное значение не является допустимым числом."));

    int num = std::stoi(number);
    return num;
}

template <typename T>
void remove(std::vector<T>& v, size_t index) {
    v.erase(v.begin() + index);
}

void printMatrix(Matrix matrix, std::vector<int> elements) {
    std::vector<std::vector<int>> m = matrix.getMatrix();

    for (int i = 0; i < matrix.getM(); i++) {
        for (int j = 0; j < matrix.getN(); j++) {
            for (int k = 0; k < elements.size(); k++) {
                if (m[i][j] == elements[k]) {
                    remove(elements, k);
                    SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN);
                }
            }

            std::cout << std::setw(7) << m[i][j];
            SetConsoleTextAttribute(hStdout, start_attribute.wAttributes);
        }
        std::cout << std::endl;
    }

    SetConsoleTextAttribute(hStdout, start_attribute.wAttributes);
    std::cout << std::endl;
}