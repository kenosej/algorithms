#pragma once

#include <thread>
#include "SortBase.h"

template <typename T>
class SelectionSort : public SortBase<T>
{
public:
	SelectionSort() : SortBase<T>(returnNameOfSort()) {}
	const char* returnNameOfSort() const
	{
		return "Selection sort";
	}
	void sort()
	{
		this->startTrackingTime();
		for (int i = 0; i < this->_length; i++)
		{
			int smallestElIndex = i;

			for (int j = i + 1; j < this->_length; j++)
				if (this->_arr[smallestElIndex] > this->_arr[j])
					smallestElIndex = j;

			swap(this->_arr[i], this->_arr[smallestElIndex]);
		}
		this->stopAndPrintTrackingTime();
	}
	void visualSort()
	{
		for (int i = 0; i < this->_length; i++)
		{
			int smallestElIndex = i;

			for (int j = i + 1; j < this->_length; j++)
			{
				cout << "Sorted till " << i << endl;

				if (this->_arr[smallestElIndex] > this->_arr[j])
					smallestElIndex = j;

				cout << "Next smallest element " << this->_arr[smallestElIndex] << endl;
				this->helpPrint();
				this_thread::sleep_for(chrono::milliseconds(1200));
				system("cls");
			}

			swap(this->_arr[i], this->_arr[smallestElIndex]);
		}
	}
};
