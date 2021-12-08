#pragma once

#include <exception>
#include "Test_Algorithms.h"

template <typename T>
class AlgoTestDriver
{
	SortBase<T>* _sb;
	T* _data; // not responsible for deleting data
	int _length;
	const char* _crt;

	void printLengthOfDataSet() const
	{
		cout << "Length of the data set:\t\t" << _length << " (";

		if (_length > 0)
		{
			const int totalBytes = sizeof(_data[0]) * _length;
			if (totalBytes > 1000 && totalBytes < 1000000) cout << totalBytes / 1000 << "kB";
			if (totalBytes > 999999) cout << totalBytes / 1000000 << "MB";
		}
		cout << ")\n";
	}

	void printFirst5Elements() const
	{
		cout << "First 5 elements of data set:\t";
		for (int i = 0; i < 5 && i < _length; i++)
		{
			cout << _data[i];
			if (i + 1 < 5) cout << ", ";
		}
		cout << '\n';
	}
	void printLast5Elements() const
	{
		cout << "Last 5 elements of data set:\t";
		for (int i = _length - 5; i < _length && i > -1; i++)
		{
			cout << _data[i];
			if (i < _length - 1) cout << ", ";
		}
		cout << '\n';
	}
public:
	AlgoTestDriver() : 
		_sb{ nullptr },
		_data{ nullptr },
		_length{ 0 },
		_crt{ "------------------------------------------------------------------\n" } // could be done better
	{}
	~AlgoTestDriver() { delete _sb; }

	AlgoTestDriver* algorithm(SortBase<T>* sb)
	{
		bool wasAlreadySet = false;
		if (_sb) wasAlreadySet = true;
		
		delete _sb;
		_sb = sb;

		if (wasAlreadySet) cout << _crt;

		return this;
	}

	AlgoTestDriver* onData(T* t, const int& length)
	{
		_data = t;
		_length = length;
		return this;
	}

	AlgoTestDriver* sort(const bool& printUnsortedData = false, const bool& printSortedData = false)
	{
		try {
			_sb->init(_length, _length, _data);
			if (printUnsortedData) _sb->print();
			_sb->sort();
			if (printSortedData) _sb->print();
		}
		catch (exception& e) {
			cout << '\n' << _crt;
			cout << e.what() << '\n';
			cout << _crt << '\n';
		}
		return this;
	}

	AlgoTestDriver* printMeta(const bool& printLength = true, const bool& printFirst5 = true, const bool& printLast5 = true)
	{
		if (printLength) printLengthOfDataSet();
		if (printFirst5) printFirst5Elements();
		if (printLast5) printLast5Elements();
		return this;
	}

	void newLine()
	{
		cout << '\n';
	}
};
