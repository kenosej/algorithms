#pragma once

#include <exception>
#include "SortBase.h"

template <typename T>
class CountSort : public SortBase<T>
{
public:
	CountSort() : SortBase<T>(returnNameOfSort(), false) {}
	const char* returnNameOfSort() const
	{
		return "Count sort";
	}
	void sort()
	{
		this->startTrackingTime();

		int max = this->_arr[0];

		for (int i = 0; i < this->_length; i++)
			if (max < this->_arr[i]) max = this->_arr[i];

		++max;

		T* workingArr = new T[max]{};

		for (int i = 0; i < this->_length; i++)
			workingArr[this->_arr[i]]++;

		for (int i = 1; i < max; i++)
			workingArr[i] = workingArr[i] + workingArr[i - 1];

		T* sortedArr = new T[this->_length];

		for (int i = this->_length - 1; i >= 0; i--)
			sortedArr[--workingArr[this->_arr[i]]] = this->_arr[i];

		delete[] workingArr; delete[] this->_arr;
		this->_arr = sortedArr;

		this->stopAndPrintTrackingTime();
	}
};
