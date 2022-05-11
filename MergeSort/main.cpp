#include <string>
#include <vector>
#include <iostream>
using namespace std;

template <typename T>
class CMergeSort // 2-way ���� ����
{
public:
	static void MergeSortFunction(vector<T>& SortArray)
	{
		/*
		reserve( size )  => array�� capacity���� size ������ ũ�� ���� X,
		������ ������ ����� ��� iterator�� ���Ұ� invalidate

		resize( rsize , value ) => array�� ������ ����(size)�� rsize ������ ũ�� ������ ������ ���δ�,
		�����ڷ� size�� rsize ���� �ø���.
		value�� ���� ���� ��� �ش簪���� �ʱ�ȭ
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
			MergeSort(CompleteSortArray, SortArray, begin, middle);	// �պκп� ���� ����
			MergeSort(CompleteSortArray, SortArray, middle + 1, end);	// �޺κп� ���� ���� 
			Merge(CompleteSortArray, SortArray, begin, middle, end);	// �κ����տ� ���Ͽ� ���� �� ����
		}
	}
	static void Merge(vector<T>& CompleteSortArray, vector<T>& SortArray, int begin, int middle, int end)
	{
		int i = begin;		// ù ��° �κ������� ���� ��ġ
		int j = middle + 1;	// �� ��° �κ������� ���� ��ġ
		int k = begin;		// �迭 CompleteSortArray�� ���� ����

		while (i <= middle && j <= end)//����
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
		if (i > middle)	//�� ��° �κ����տ� ���� �ִ� ���Ҹ� ���� ������ CompleteSortArray�� ����
		{
			for (int t = j; t <= end; t++, k++)
			{
				CompleteSortArray[k] = SortArray[t];
			}
		}
		else			//ù ��° �κ����տ� ���� �ִ� ���Ҹ� ���� ������ CompleteSortArray�� ����
		{
			for (int t = i; t <= middle; t++, k++)
			{
				CompleteSortArray[k] = SortArray[t];
			}
		}
		for (int t = begin; t <= end; t++)// �ϰ�����
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