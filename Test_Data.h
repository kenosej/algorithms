#pragma once

// To add a new data on which algorithms are about to be tested, follow the 5-step process
// process described in TestData<T> below
// CAUTION: preserve order

template <typename T>
class TestData
{
	const int _length;
	T** _data;
	int* _dataLengths;

	void setSorted(T* data, const int& length)
	{
		for (int i = 0; i < length; i++)
			data[i] = i;
	}

	void setReversed(T* data, const int& length)
	{
		for (int i = 0; i < length; i++)
			data[i] = length - i;
	}

	void setNegAndPos(T* data, const int& length)
	{
		for (int i = 0; i < length; i++)
			data[i] = i % 2 == 0 ? i * -1 : i;
	}

	void setBigNumsPosAndNeg(T* data, const int& length)
	{
		for (int i = 0; i < length; i++)
			data[i] = i % 7 == 0 ? (i % 3 ? i * i * i : i * i * i * -1) : (i % 5 ? i * i * -1 : i * i);
	}

	void setNonRecursive(T* data, const int& length)
	{
		for (int i = 0; i < length; i++)
			data[i] = i % 7 == 0 ? (i % 3 == 0 ? i / 4 * 3 : i) : (i % 2 == 0 ? length - i : i / 7 * 6);
	}

	void setPosAndNeg3DigitNums(T* data, const int& length)
	{
		for (int i = 0, j = 0; i < length; i += 2, j++)
		{
			data[i] = j + 100;
			data[i + 1] = j * -1 - 100;
		}
	}

	void setCustom(T* data, const int& length)
	{
		int customVals[] = { -34, 26, -122, 341, 5212, -111, -43, 89 }; // fills up only up to length parameter

		for (int i = 0; i < length; i++) data[i] = customVals[i];
	}

	void createDataSlots()
	{
		for (int i = 0; i < _length; i++) _data[i] = new T[_dataLengths[i]];
	}
public:
	TestData() :
		_length{ 7 }, // Step 1: increase _length
		_data{ new T*[_length] },
		_dataLengths{ new int[_length] }
	{
		setLenghts();
		createDataSlots();
		setData();
	}
	~TestData()
	{
		delete[] _dataLengths;
		
		for (int i = 0; i < _length; i++) delete[] _data[i];

		delete[] _data;
	}

	enum DataSets : int {
		SORTED,
		REVERSED,
		NEG_AND_POS,
		BIG_NUMS_POS_AND_NEG,
		NON_RECURSIVE, // named like this cuz if used in recursive algorithms stack overflow happens
		POS_AND_NEG_3_DIGIT_NUMS,
		CUSTOM // Step 2: add DataSet name
	};

	void setLenghts(
		const int& length1 = 3000, // if stack overflow occurs, decrease length1, length2, length3 and length4
		const int& length2 = 3000,
		const int& length3 = 3000,
		const int& length4 = 3000,
		const int& length5 = 250000,
		const int& length6 = 1800,
		const int& length7 = 8 // Step 3: set DataSet default length
	)
	{	// caution of order is cuz of this function
		_dataLengths[SORTED] = length1;
		_dataLengths[REVERSED] = length2;
		_dataLengths[NEG_AND_POS] = length3;
		_dataLengths[BIG_NUMS_POS_AND_NEG] = length4;
		_dataLengths[NON_RECURSIVE] = length5;
		_dataLengths[POS_AND_NEG_3_DIGIT_NUMS] = length6;
		_dataLengths[CUSTOM] = length7; // Step 4: bind DataSet length to class internals
	}

	void setData()
	{
		setSorted(_data[SORTED], _dataLengths[SORTED]);
		setReversed(_data[REVERSED], _dataLengths[REVERSED]);
		setNegAndPos(_data[NEG_AND_POS], _dataLengths[NEG_AND_POS]);
		setBigNumsPosAndNeg(_data[BIG_NUMS_POS_AND_NEG], _dataLengths[BIG_NUMS_POS_AND_NEG]);
		setNonRecursive(_data[NON_RECURSIVE], _dataLengths[NON_RECURSIVE]);
		setPosAndNeg3DigitNums(_data[POS_AND_NEG_3_DIGIT_NUMS], _dataLengths[POS_AND_NEG_3_DIGIT_NUMS]);
		setCustom(_data[CUSTOM], _dataLengths[CUSTOM]); // Step 5: make custom private function that will fill your data set; void function(T*, const int&)
	}

	T* getData(DataSets dataSet) const
	{
		return _data[dataSet];
	}

	int getLength(DataSets dataSet) const
	{
		return _dataLengths[dataSet];
	}

	// TODO: simpler addition of custom test data sets
	// current challenge: template and linking errors on attempt of simplifying
};
