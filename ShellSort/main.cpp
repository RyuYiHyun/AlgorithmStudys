#include <string>
#include <vector>
#include <iostream>
using namespace std;

template <typename T>
class CShellSort // 셀 정렬
{
public:
	static void ShellSortFunction(vector<T>& SortArray, int arraySize)
	{
		int interval = arraySize / 2;
		while (interval >= 1)// 간격이 1까지 까지만 수행
		{
			for (int i = 0; i < interval; i++)
			{
				IntervalSort(SortArray, i, arraySize - 1, interval);
			}
			interval = interval / 2;
		}
	}
private:
	static void IntervalSort(vector<T>& SortArray, int begin, int end, int interval)// 일정 간격으로 부분집합으로 삽입정렬 수행
	{
		int i, j;
		int key;
		// 삽입정령에서 i는 0의 다음인 1부터, 여기서는 begin의 다음인 begin + interval 부터 시작
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