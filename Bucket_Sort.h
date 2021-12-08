#pragma once

#include "Node.h"
#include "SortBase.h"

template <typename T>
class BucketSort : public SortBase<T>
{
protected:
	Node2w<T>** _workingArr; // using doubly linked list
	unsigned int _numOfBuckets;

	virtual void bucketUp() = 0;
	virtual void bucketDown() = 0;
	void pushInBucket(Node2w<T>*& bucketHead, const T& t)
	{
		if (!bucketHead)
		{
			Node2w<T>* node = new Node2w<T>(t);
			bucketHead = node;
			return;
		}

		Node2w<T>* iForLinkedList = bucketHead;

		while (iForLinkedList->_next)
			iForLinkedList = iForLinkedList->_next;

		Node2w<T>* node = new Node2w<T>(t, iForLinkedList);
		iForLinkedList->_next = node;
	}
	void insertionSortOnLinkedList(Node2w<T>* bucketHead)
	{
		if (!bucketHead || !bucketHead->_next) return;

		Node2w<T>* sorted = bucketHead;
		Node2w<T>* unsorted;

		while (sorted)
		{
			unsorted = sorted->_next;

			while (unsorted)
			{
				if (unsorted->_prev && unsorted->_prev->_info > unsorted->_info)
				{
					// could change pointers only, but in demonstration isn't worth time
					swap(unsorted->_info, unsorted->_prev->_info);
					unsorted = unsorted->_prev;
				}
				else break;
			}

			sorted = sorted->_next;
		}
	}
	void extractFromListsToArr(int& sortedArrIndex, Node2w<T>*& bucketHead)
	{
		if (!bucketHead) return;

		Node2w<T>* iForList = bucketHead;

		while (iForList)
		{
			SortBase<T>::_arr[sortedArrIndex++] = iForList->_info;

			Node2w<T>* temp = iForList->_next;

			if (temp) temp->_prev = nullptr;

			delete iForList;
			iForList = temp;
		}

		bucketHead = nullptr;
	}
public:
	BucketSort(const char* nameOfSort) : SortBase<T>(nameOfSort), _numOfBuckets{ 0 } {}
};

template <typename T>
class BucketByLeadingDigit : public BucketSort<T>
{
	int mapNegativesForLeadingDigits(const int& x) const
	{
		if (x > -1) return x;

		return x * -1 + 9;
	}
	int extractLeadingDigit(int x)
	{
		int digit = 0;

		while (x)
		{
			digit = x % 10;
			x /= 10;
		}

		return digit;
	}
protected:
	void bucketUp()
	{
		this->_numOfBuckets = 19;

		this->_workingArr = new Node2w<T>*[this->_numOfBuckets] { nullptr };

		for (int i = 0; i < this->_length; i++)
			this->pushInBucket(this->_workingArr[mapNegativesForLeadingDigits(this->extractLeadingDigit(this->_arr[i]))], this->_arr[i]);
	}
	void bucketDown()
	{
		int sortedArrIndex = 0;

		for (int i = -9; i < 10; i++)
			this->extractFromListsToArr(sortedArrIndex, this->_workingArr[mapNegativesForLeadingDigits(i)]);
	}
public:
	BucketByLeadingDigit() : BucketSort<T>(returnNameOfSort()) {}
	const char* returnNameOfSort() const
	{
		return "Bucket sort by leading digit";
	}
	void sort()
	{
		this->startTrackingTime();

		bucketUp();

		for (int i = 0; i < this->_numOfBuckets; i++)
			this->insertionSortOnLinkedList(this->_workingArr[i]);

		bucketDown();

		this->stopAndPrintTrackingTime();
	}
};

template <typename T>
class BucketByNumOfDigits : public BucketSort<T>
{
	int greatestDigitCount() const
	{
		int max = -1;

		for (int i = 0; i < SortBase<T>::_length; i++)
		{
			const int digitCountOfEl = digitCount(SortBase<T>::_arr[i]);

			if (max < digitCountOfEl) max = digitCountOfEl;
		}

		return max;
	}
	int digitCount(int x) const
	{
		int digitCount = !x ? 1 : 0;

		while (x)
		{
			++digitCount;
			x /= 10;
		}

		return digitCount;
	}
	// { 8, 88, 888, -8, -88, -888 }
	int mapNegativesForNumOfDigits(const T& t, const int& biggestDigit) const
	{
		if (t > -1) return digitCount(t);
		return digitCount(t) + biggestDigit;
	}
protected:
	void bucketUp()
	{
		const int biggestDigitCount = greatestDigitCount();
		this->_numOfBuckets = biggestDigitCount * 2 + 1;

		this->_workingArr = new Node2w<T>*[this->_numOfBuckets] { nullptr };

		for (int i = 0; i < this->_length; i++)
			this->pushInBucket(this->_workingArr[mapNegativesForNumOfDigits(this->_arr[i], biggestDigitCount)], this->_arr[i]);
	}
	void bucketDown()
	{
		int sortedArrIndex = 0;

		for (int i = this->_numOfBuckets - 1; i > this->_numOfBuckets / 2; i--)
			this->extractFromListsToArr(sortedArrIndex, this->_workingArr[i]);

		for (int i = 1; i <= this->_numOfBuckets / 2; i++)
			this->extractFromListsToArr(sortedArrIndex, this->_workingArr[i]);
	}
public:
	BucketByNumOfDigits() : BucketSort<T>(returnNameOfSort()) {}
	const char* returnNameOfSort() const
	{
		return "Bucket sort by num of digits";
	}
	void sort()
	{
		this->startTrackingTime();

		bucketUp();

		for (int i = 0; i < this->_numOfBuckets; i++)
			this->insertionSortOnLinkedList(this->_workingArr[i]);

		bucketDown();

		this->stopAndPrintTrackingTime();
	}
};
