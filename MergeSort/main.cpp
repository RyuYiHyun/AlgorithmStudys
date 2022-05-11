#include <string>
#include <vector>
#include <iostream>
using namespace std;

template <typename T>
class CMergeSort // 2-way 병합 정렬
{
public:
	static void MergeSortFunction(vector<T>& SortArray)
	{
		/*
		reserve( size )  => array의 capacity값이 size 값보다 크면 동작 X,
		작으면 공간을 만들고 모든 iterator와 원소가 invalidate

		resize( rsize , value ) => array의 원소의 개수(size)가 rsize 값보다 크면 원소의 개수를 줄인다,
		생성자로 size가 rsize 까지 늘린다.
		value가 값이 있을 경우 해당값으로 초기화
		*/
		int arraySize = SortArray.size();
		vector<T> CompleteSortArray;
		CompleteSortArray.resize(arraySize);
		MergeSort(CompleteSortArray, SortArray, 0, arraySize - 1);
	}
private:
	static void MergeSort(vector<T>& CompleteSortArray, vector<T>& SortArray, int begin, int end)
	{
		int middle;
		if (begin < end)
		{
			middle = (begin + end) / 2;
			MergeSort(CompleteSortArray, SortArray, begin, middle);	// 앞부분에 대한 분할
			MergeSort(CompleteSortArray, SortArray, middle + 1, end);	// 뒷부분에 대한 분할 
			Merge(CompleteSortArray, SortArray, begin, middle, end);	// 부분집합에 대하여 정렬 및 병합
		}
	}
	static void Merge(vector<T>& CompleteSortArray, vector<T>& SortArray, int begin, int middle, int end)
	{
		int i = begin;		// 첫 번째 부분집합의 시작 위치
		int j = middle + 1;	// 두 번째 부분집합의 시작 위치
		int k = begin;		// 배열 CompleteSortArray에 원소 저장

		while (i <= middle && j <= end)//정렬
		{
			if (SortArray[i] <= SortArray[j])
			{
				CompleteSortArray[k] = SortArray[i];
				i++;
			}
			else
			{
				CompleteSortArray[k] = SortArray[j];
				j++;
			}
			k++;
		}
		if (i > middle)	//두 번째 부분집합에 남아 있는 원소를 병합 집합을 CompleteSortArray에 복사
		{
			for (int t = j; t <= end; t++, k++)
			{
				CompleteSortArray[k] = SortArray[t];
			}
		}
		else			//첫 번째 부분집합에 남아 있는 원소를 병합 집합을 CompleteSortArray에 복사
		{
			for (int t = i; t <= middle; t++, k++)
			{
				CompleteSortArray[k] = SortArray[t];
			}
		}
		for (int t = begin; t <= end; t++)// 일괄복사
		{
			SortArray[t] = CompleteSortArray[t];
		}
	}
};

int main(void)
{
	vector<int> sortarray;
	sortarray.push_back(69);
	sortarray.push_back(10);
	sortarray.push_back(30);
	sortarray.push_back(2);
	sortarray.push_back(16);
	sortarray.push_back(8);
	sortarray.push_back(31);
	sortarray.push_back(22);
	CMergeSort<int>::MergeSortFunction(sortarray);
	vector<int>::iterator iter;
	for (iter = sortarray.begin(); iter != sortarray.end(); iter++)
	{
		cout << (*iter) << endl;
	}
	return 0;
}