#pragma once

#include "SortBase.h"

template <typename T>
class BubbleSort : public SortBase<T>
{
public:
	BubbleSort() : SortBase<T>(returnNameOfSort()) {}
	const char* returnNameOfSort() const
	{
		return "Bubble sort";
	}
	void sort() // optimized version of the bubble sort; there's room for implementing "raw" bubble sort
	{
		this->startTrackingTime();
		for (int i = 0; i < this->_length; i++)
		{
			bool sorted = true;

			for (int j = 0; j < this->_length - i - 1; j++)
				if (this->_arr[j] > this->_arr[j + 1])
				{
					swap(this->_arr[j], this->_arr[j + 1]);
					sorted = false;
				}

			if (sorted) break;
		}
		this->stopAndPrintTrackingTime();
	}
	void informativeSort()
	{
		for (int i = 0; i < this->_length; i++)
		{
			bool sorted = true;

			cout << "Going from " << i << " for " << this->_length - i - 1 << " times. " << i + 1 << ". loop: \n";
			for (int j = 0; j < this->_length - i - 1; j++)
			{
				cout << "Comparing " << this->_arr[j] << " and " << this->_arr[j + 1] << ".";
				if (this->_arr[j] > this->_arr[j + 1])
				{
					cout << " Switched.";
					swap(this->_arr[j], this->_arr[j + 1]);
					sorted = false;
				}
				cout << "\n";
			}
			cout << "Finished " << i + 1 << ". loop.\n\n";

			if (sorted)
			{
				cout << "Already sorted.";
				return;
			}
		}
	}
};
