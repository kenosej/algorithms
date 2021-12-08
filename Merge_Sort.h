#pragma once

#include "SortBase.h"

template <typename T>
class MergeSort : public SortBase<T>
{
	void merge(const int& left, const int& mid, const int& right)
	{
		const int subArr1Size = mid - left + 1;
		const int subArr2Size = right - mid;

		T* subArr1 = new T[subArr1Size];
		T* subArr2 = new T[subArr2Size];

		for (int i = 0; i < subArr1Size; i++)
			subArr1[i] = this->_arr[left + i];

		for (int i = 0; i < subArr2Size; i++)
			subArr2[i] = this->_arr[mid + 1 + i];

		int indexSubArr1 = 0;
		int indexSubArr2 = 0;
		int mergeArrIndex = left;

		while (indexSubArr1 < subArr1Size && indexSubArr2 < subArr2Size)
			if (subArr1[indexSubArr1] < subArr2[indexSubArr2])
				this->_arr[mergeArrIndex++] = subArr1[indexSubArr1++];
			else
				this->_arr[mergeArrIndex++] = subArr2[indexSubArr2++];

		while (indexSubArr1 < subArr1Size)
			this->_arr[mergeArrIndex++] = subArr1[indexSubArr1++];

		while (indexSubArr2 < subArr2Size)
			this->_arr[mergeArrIndex++] = subArr2[indexSubArr2++];

		delete[] subArr1; delete[] subArr2;
	}
	void mergeSort(const int& left, const int& right)
	{
		if (left >= right) return;

		const int mid = left + (right - left) / 2;

		mergeSort(left, mid);
		mergeSort(mid + 1, right);

		merge(left, mid, right);
	}
public:
	MergeSort() : SortBase<T>(returnNameOfSort()) {}
	const char* returnNameOfSort() const
	{
		return "Merge sort";
	}
	void sort()
	{
		this->startTrackingTime();
		mergeSort(0, this->_length - 1);
		this->stopAndPrintTrackingTime();
	}
};
