#include "Validator.h"

bool Validator::isIntegerNumber(std::string str, std::string message)
{
	int length = str.length(), index = 0;
	bool isNegative = false, dot = false;

	if (!isdigit(str[0]))
	{
		if (str[0] == '-')
		{
			isNegative = true;
			index++;
		}
	}

	while (index != length)
	{
		if (str[index] == '-')
		{
			if (isNegative)
			{
				std::cout << message << std::endl;
				return false;
			}
			else
			{
				isNegative = true;
			}
		}
		else if (str[index] == '.' || str[index] == ',')
		{
			if (!dot)
			{
				dot = true;
			}
			else
			{
				std::cout << message << std::endl;
				return false;
			}

			if (index == length - 1)
			{
				std::cout << message << std::endl;
				return false;
			}
		}
		else if (!isdigit(str[index]))
		{
			std::cout << message << std::endl;
			return false;
		}
		else if (dot)
		{
			if (str[index] != '0')
			{
				std::cout << message << std::endl;
				return false;
			}
		}

		index++;
	}

	return true;
}

bool Validator::checkNumber(int n)
{
	if (n < 1)
	{
		std::cout << "������� ������������ ��������." << std::endl;
		return false;
	}

	return true;
}