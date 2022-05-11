#include <string>
#include <vector>
#include <iostream>
using namespace std;

template <typename T>
class CSelectionSort // 선택 정렬
{
public:
	static void SelectionSortFunction(vector<T>& SortArray, int arraysize)
	{
		int min;
		T key;
		for (int i = 0; i < arraysize - 1; i++)
		{
			min = i;
			for (int j = i + 1; j < arraysize; j++)
			{
				if (SortArray[j] < SortArray[min])
				{
					min = j;// i 기준에서 오른쪽으로 제일 작은 값을 찾기
				}
			}
			key = SortArray[i];
			SortArray[i] = SortArray[min];
			SortArray[min] = key;
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
	CSelectionSort<int>::SelectionSortFunction(sortarray, sortarray.size());
	vector<int>::iterator iter;
	for (iter = sortarray.begin(); iter != sortarray.end(); iter++)
	{
		cout << (*iter) << endl;
	}
	return 0;
}