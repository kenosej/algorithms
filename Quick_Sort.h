#pragma once

#include "SortBase.h"

template <typename T>
class QuickSort : public SortBase<T> // with the pivot at the 1st element; algorithms with the different pivot starting points could be added
{
	int quickSort(const int start, const int finish)
	{
		int pivot = start;
		int i = start + 1;
		int j = finish;
		bool iFound = false;
		bool jFound = false;

		while (i <= j)
		{
			if (!iFound && this->_arr[i] > this->_arr[pivot])
				iFound = true;
			else if (!iFound)
				i++;

			if (!jFound && this->_arr[j] < this->_arr[pivot])
				jFound = true;
			else if (!jFound)
				j--;

			if (iFound && jFound)
			{
				swap(this->_arr[i++], this->_arr[j--]);
				iFound = false;
				jFound = false;
			}
		}

		swap(this->_arr[pivot], this->_arr[j]);
		return j;
	}
	void partitionForQuick(const int& start, const int& end)
	{
		if (start >= end) return;

		int sortedIndex = quickSort(start, end);

		partitionForQuick(start, sortedIndex - 1);
		partitionForQuick(sortedIndex + 1, end);
	}
public:
	QuickSort() : SortBase<T>(returnNameOfSort()) {}
	const char* returnNameOfSort() const
	{
		return "Quick sort";
	}
	void sort()
	{
		this->startTrackingTime();
		partitionForQuick(0, this->_length - 1);
		this->stopAndPrintTrackingTime();
	}
};
