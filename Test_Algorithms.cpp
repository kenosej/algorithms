#include "Test_Data.h"
#include "AlgoTestDriver.h"
#include "Test_Algorithms.h"

void startAlgoTesting()
{
	TestData<int> td;
	AlgoTestDriver<int> atd;
	
	atd.algorithm(new BubbleSort<int>)->onData(td.getData(TestData<int>::SORTED), td.getLength(TestData<int>::SORTED))->printMeta()->sort()->newLine();
	atd.onData(td.getData(TestData<int>::REVERSED), td.getLength(TestData<int>::REVERSED))->printMeta()->sort()->newLine();
	atd.onData(td.getData(TestData<int>::NEG_AND_POS), td.getLength(TestData<int>::NEG_AND_POS))->printMeta()->sort()->newLine();
	atd.onData(td.getData(TestData<int>::BIG_NUMS_POS_AND_NEG), td.getLength(TestData<int>::BIG_NUMS_POS_AND_NEG))->printMeta()->sort();
	
	atd.algorithm(new InsertionSort<int>)->onData(td.getData(TestData<int>::SORTED), td.getLength(TestData<int>::SORTED))->printMeta()->sort()->newLine();
	atd.onData(td.getData(TestData<int>::REVERSED), td.getLength(TestData<int>::REVERSED))->printMeta()->sort()->newLine();
	atd.onData(td.getData(TestData<int>::NEG_AND_POS), td.getLength(TestData<int>::NEG_AND_POS))->printMeta()->sort()->newLine();
	atd.onData(td.getData(TestData<int>::BIG_NUMS_POS_AND_NEG), td.getLength(TestData<int>::BIG_NUMS_POS_AND_NEG))->printMeta()->sort();
	
	atd.algorithm(new SelectionSort<int>)->onData(td.getData(TestData<int>::SORTED), td.getLength(TestData<int>::SORTED))->printMeta()->sort()->newLine();
	atd.onData(td.getData(TestData<int>::REVERSED), td.getLength(TestData<int>::REVERSED))->printMeta()->sort()->newLine();
	atd.onData(td.getData(TestData<int>::NEG_AND_POS), td.getLength(TestData<int>::NEG_AND_POS))->printMeta()->sort()->newLine();
	atd.onData(td.getData(TestData<int>::BIG_NUMS_POS_AND_NEG), td.getLength(TestData<int>::BIG_NUMS_POS_AND_NEG))->printMeta()->sort();
	
	atd.algorithm(new MergeSort<int>)->onData(td.getData(TestData<int>::SORTED), td.getLength(TestData<int>::SORTED))->printMeta()->sort()->newLine();
	atd.onData(td.getData(TestData<int>::REVERSED), td.getLength(TestData<int>::REVERSED))->printMeta()->sort()->newLine();
	atd.onData(td.getData(TestData<int>::NEG_AND_POS), td.getLength(TestData<int>::NEG_AND_POS))->printMeta()->sort()->newLine();
	atd.onData(td.getData(TestData<int>::BIG_NUMS_POS_AND_NEG), td.getLength(TestData<int>::BIG_NUMS_POS_AND_NEG))->printMeta()->sort();

	atd.algorithm(new QuickSort<int>)->onData(td.getData(TestData<int>::SORTED), td.getLength(TestData<int>::SORTED))->printMeta()->sort()->newLine();
	atd.onData(td.getData(TestData<int>::REVERSED), td.getLength(TestData<int>::REVERSED))->printMeta()->sort()->newLine();
	atd.onData(td.getData(TestData<int>::NEG_AND_POS), td.getLength(TestData<int>::NEG_AND_POS))->printMeta()->sort()->newLine();
	atd.onData(td.getData(TestData<int>::BIG_NUMS_POS_AND_NEG), td.getLength(TestData<int>::BIG_NUMS_POS_AND_NEG))->printMeta()->sort();

	atd.algorithm(new BucketByLeadingDigit<int>)->onData(td.getData(TestData<int>::POS_AND_NEG_3_DIGIT_NUMS), td.getLength(TestData<int>::POS_AND_NEG_3_DIGIT_NUMS))->printMeta()->sort();
	atd.algorithm(new BucketByNumOfDigits<int>)->onData(td.getData(TestData<int>::BIG_NUMS_POS_AND_NEG), td.getLength(TestData<int>::BIG_NUMS_POS_AND_NEG))->printMeta()->sort()->newLine();
	atd.onData(td.getData(TestData<int>::SORTED), td.getLength(TestData<int>::SORTED))->printMeta()->sort()->newLine();
	atd.onData(td.getData(TestData<int>::REVERSED), td.getLength(TestData<int>::REVERSED))->printMeta()->sort()->newLine();
	atd.onData(td.getData(TestData<int>::NEG_AND_POS), td.getLength(TestData<int>::NEG_AND_POS))->printMeta()->sort();
	
	atd.algorithm(new CountSort<int>)->onData(td.getData(TestData<int>::SORTED), td.getLength(TestData<int>::SORTED))->printMeta()->sort()->newLine();
	atd.onData(td.getData(TestData<int>::REVERSED), td.getLength(TestData<int>::REVERSED))->printMeta()->sort()->newLine();
	atd.onData(td.getData(TestData<int>::NON_RECURSIVE), td.getLength(TestData<int>::NON_RECURSIVE))->printMeta()->sort();
	
	atd.algorithm(new RadixSort<int>)->onData(td.getData(TestData<int>::SORTED), td.getLength(TestData<int>::SORTED))->printMeta()->sort()->newLine();
	atd.onData(td.getData(TestData<int>::REVERSED), td.getLength(TestData<int>::REVERSED))->printMeta()->sort()->newLine();
	atd.onData(td.getData(TestData<int>::NON_RECURSIVE), td.getLength(TestData<int>::NON_RECURSIVE))->printMeta()->sort();

	// to add a new algorithm:
	//   - make New_Sort.h
	//   - algorithm should #include "SortBase.h" and inherit from SortBase
	//		- in SortBase you'll find fields for the algorithm, e.g. data, data length...
	//   - include it in Test_Algorithms.h
	//   - test new algorithm here (uncomment line below and change it to the new class)
	
	// atd.algorithm(new NewSort<int>)->onData(td.getData(TestData<int>::SORTED), td.getLength(TestData<int>::SORTED))->printMeta()->sort();
}
