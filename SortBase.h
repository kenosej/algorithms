#pragma once

#include <chrono>
#include <iostream>
#include <exception>
// possibly needed <string> and <utility> (<utility> for swap()) 

using namespace std;

template <
	class result_t = chrono::milliseconds,
	class clock_t = chrono::steady_clock,
	class duration_t = chrono::milliseconds
>
auto since(chrono::time_point<clock_t, duration_t> const& start)
{
	return chrono::duration_cast<result_t>(clock_t::now() - start);
}

template <typename T>
class SortBase // developed on int; possible narrowing conversions/errors if using other types - testing needed
{
	const char* _algoName;
	bool _negativesAreAllowed;
	long long _totalSortRunningTimeInMs;
	chrono::steady_clock::time_point _start;

	void stopTrackingTime()
	{
		_totalSortRunningTimeInMs = since(_start).count();
	}
	void printTrackingTime() const
	{
		cout << _algoName << " :: Elapsed = " << _totalSortRunningTimeInMs << "ms" << endl;
	}
protected:
	T* _arr;
	int _size, _length;

	void helpPrint() const
	{
		for (int i = 0; i < _length; i++)
			cout << i << '\t';
		cout << '\n';
		for (int i = 0; i < _length; i++)
			cout << _arr[i] << '\t';
		cout << '\n';
	}
	void checkForNegatives() const
	{
		for (int i = 0; i < this->_length; i++)
			if (this->_arr[i] < 0)
				throw exception((string(_algoName) + " cannot contain negative values.").c_str());
		// TODO: info about data set
		// string lib only used in above case; probably better without it
	}
public:
	SortBase(const char* algoName, const bool& negativesAreAllowed = true) :
		_algoName{ algoName },
		_negativesAreAllowed{ negativesAreAllowed },
		_arr{ nullptr }, _size{ 0 }, _length{ 0 },
		_totalSortRunningTimeInMs{ -1 } 
	{}
	virtual ~SortBase()
	{
		delete[] _arr; _arr = nullptr;
	}
	virtual const char* returnNameOfSort() const = 0;
	virtual void sort() = 0;
	virtual void visualSort() const {} // can be implemented by derived algorithms for showing step-by-step process
	virtual void informativeSort() const {} // can be implemented by derived algorithms for showing step-by-step process
	// easier approach for visualSort() and informativeSort() in testing algorithms should be added
	void print() const
	{
		for (int i = 0; i < _length; i++)
			cout << "_arr[" << i << "] - " << _arr[i] << endl;
	}
	void init(int size, int length, T arr[])
	{
		delete[] _arr;
		_size = size;
		_length = length;
		_arr = new T[_size];

		for (int i = 0; i < _length; i++) _arr[i] = arr[i];
		if (!_negativesAreAllowed) checkForNegatives();
	}
	void startTrackingTime()
	{
		_start = chrono::steady_clock::now();
	}
	void stopAndPrintTrackingTime()
	{
		stopTrackingTime();
		printTrackingTime();
	}
	long long getTotalSortRunningTimeInMs() const
	{
		return _totalSortRunningTimeInMs; // tracking time calls done in every derived sort() | myb better solution would be placing some type of hooks
	}
};
