#pragma once

#include <exception>
#include "SortBase.h"

template <typename T>
class RadixSort : public SortBase<T>
{
	int maxNumOfDigits;

	int calcNumOfDigits(int x) const
	{
		int numOfDigits = 0;

		while (x)
		{
			numOfDigits++;
			x /= 10;
		}

		return numOfDigits;
	}

	void findMaxNumOfDigits()
	{
		for (int i = 0; i < this->_length; i++)
		{
			int numOfDigitsOfi = calcNumOfDigits(this->_arr[i]);

			if (maxNumOfDigits < numOfDigitsOfi) maxNumOfDigits = numOfDigitsOfi;
		}
	}

	int findDigitOnPosition(const int position, int num) const
	{
		int digit;

		for (int i = 0; i <= position; i++)
		{
			digit = num % 10;
			num /= 10;
		}

		return digit;
	}
	int findMaximumDigitOnDecPosition(const int decPosition) const
	{
		int max = -1;

		for (int i = 0; i < this->_length; i++)
		{
			const int theDigit = findDigitOnPosition(decPosition, this->_arr[i]);

			if (max < theDigit) max = theDigit;
		}

		return max;
	}
	void countSort(const int decPosition)
	{
		const int length = findMaximumDigitOnDecPosition(decPosition) + 1;
		T* workingArr = new T[length]{};

		for (int i = 0; i < this->_length; i++)
			workingArr[findDigitOnPosition(decPosition, this->_arr[i])]++;

		for (int i = 1; i < length; i++)
			workingArr[i] = workingArr[i] + workingArr[i - 1];

		T* arr = new T[this->_length];

		for (int i = this->_length - 1; i >= 0; i--)
			arr[--workingArr[findDigitOnPosition(decPosition, this->_arr[i])]] = this->_arr[i];

		delete[] this->_arr;
		this->_arr = arr;
	}
public:
	RadixSort() : SortBase<T>(returnNameOfSort(), false), maxNumOfDigits{ -1 } {}
	const char* returnNameOfSort() const
	{
		return "Radix sort";
	}
	void sort()
	{
		this->startTrackingTime();

		findMaxNumOfDigits();

		for (int i = 0; i < maxNumOfDigits; i++) countSort(i);

		this->stopAndPrintTrackingTime();
	}
};
