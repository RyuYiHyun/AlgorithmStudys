#include <string>
#include <vector>
#include <iostream>
using namespace std;

template <typename T>
class CShellSort // �� ����
{
public:
	static void ShellSortFunction(vector<T>& SortArray, int arraySize)
	{
		int interval = arraySize / 2;
		while (interval >= 1)// ������ 1���� ������ ����
		{
			for (int i = 0; i < interval; i++)
			{
				IntervalSort(SortArray, i, arraySize - 1, interval);
			}
			interval = interval / 2;
		}
	}
private:
	static void IntervalSort(vector<T>& SortArray, int begin, int end, int interval)// ���� �������� �κ��������� �������� ����
	{
		int i, j;
		int key;
		// �������ɿ��� i�� 0�� ������ 1����, ���⼭�� begin�� ������ begin + interval ���� ����
		for (i = begin + interval; i <= end; i = i + interval)
		{
			key = SortArray[i];
			for (j = i - interval; j >= begin && SortArray[j] > key; j = j - interval)
			{
				SortArray[j + interval] = SortArray[j];
			}
			SortArray[j + interval] = key;
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
	CShellSort<int>::ShellSortFunction(sortarray, sortarray.size());
	vector<int>::iterator iter;
	for (iter = sortarray.begin(); iter != sortarray.end(); iter++)
	{
		cout << (*iter) << endl;
	}
	return 0;
}