#pragma once

#include <thread>
#include "SortBase.h"

template <typename T>
class InsertionSort : public SortBase<T>
{
public:
	InsertionSort() : SortBase<T>(returnNameOfSort()) {}
	const char* returnNameOfSort() const
	{
		return "Insertion sort";
	}
	void sort()
	{
		this->startTrackingTime();
		for (int i = 1; i < this->_length; i++)
			for (int j = i; j > 0; j--)
				if (this->_arr[j - 1] > this->_arr[j]) swap(this->_arr[j - 1], this->_arr[j]);
				else break;
		this->stopAndPrintTrackingTime();
	}
	void visualSort()
	{
		for (int i = 1; i < this->_length; i++)
		{
			T watchElement = this->_arr[i];
			for (int j = i; j > 0; j--)
			{
				cout << "Sorted until index " << i << endl;
				cout << "Watch for element " << watchElement << endl;
				if (this->_arr[j - 1] > this->_arr[j])
				{
					this->helpPrint();
					swap(this->_arr[j - 1], this->_arr[j]);
					this_thread::sleep_for(chrono::milliseconds(2200));
					system("cls");
				}
				else
				{
					this->helpPrint();
					this_thread::sleep_for(chrono::milliseconds(2200));
					system("cls");
					break;
				}
			}
		}
	}
	void informativeSort()
	{
		for (int i = 1; i < this->_length; i++)
		{
			cout << "Sorted till index " << i << "\n\n";
			this->helpPrint();
			for (int j = i; j > 0; j--)
			{
				cout << "Comparing this->_arr[" << j - 1 << "] and this->_arr[" << j << "]\n";
				if (this->_arr[j - 1] > this->_arr[j])
				{
					cout << "\tSwapping this->_arr[" << j - 1 << "] and this->_arr[" << j << "]\n";
					cout << "\t\tcuz " << this->_arr[j - 1] << " > " << this->_arr[j] << endl;
					swap(this->_arr[j - 1], this->_arr[j]);
				}
				else
				{
					cout << "\tNo swapping cuz " << this->_arr[j - 1] << " isnt > " << this->_arr[j] << endl;
					break;
				}
			}
			cout << endl;
		}
	}
};
