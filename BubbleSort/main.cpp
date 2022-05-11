#include <string>
#include <vector>
#include <iostream>
using namespace std;

template <typename T>
class CBubbleSort // 버블 정렬
{
public:
	static void BubbleSortFunction(vector<T>& SortArray, int arraySize)
	{
		T key;
		for (int i = arraySize - 1; i > 0; i--)
		{
			for (int j = 0; j < i; j++)
			{
				if (SortArray[j] > SortArray[j + 1])
				{
					key = SortArray[j];
					SortArray[j] = SortArray[j + 1];
					SortArray[j + 1] = key;
				}
			}
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
	CBubbleSort<int>::BubbleSortFunction(sortarray, sortarray.size());
	vector<int>::iterator iter;
	for (iter = sortarray.begin(); iter != sortarray.end(); iter++)
	{
		cout << (*iter) << endl;
	}
	return 0;
}