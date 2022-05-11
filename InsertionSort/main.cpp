#include <string>
#include <vector>
#include <iostream>
using namespace std;

template <typename T>
class CInsertionSort // 삽입정렬
{
public:
	static void InsertionSortFunction(vector<T>& SortArray, int arraySize)
	{
		int i;// i는 1에서 부터 시작, 반복값
		int j;// j는 i의 왼쪽 부분 탐색 값
		int key;// 정렬 하려는 값

		///* for문 2개를 이용한 방법
		for (i = 1; i < arraySize; i++)
		{
			key = SortArray[i];
			for (j = i - 1; j >= 0 && SortArray[j] > key; j = j - 1)
			{
				SortArray[j + 1] = SortArray[j];
			}
			SortArray[j + 1] = key;
		}
		//*/
		/* for문 1개와 while을 이용한 방법
		for (i = 1; i < arraySize; i++)
		{
			key = SortArray[i];
			j = i;
			while ((j > 0) && (SortArray[j - 1] > key))
			{
				SortArray[j] = SortArray[j - 1];
				j = j - 1;
			}
			SortArray[j] = key;
		}
		//*/
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
	CInsertionSort<int>::InsertionSortFunction(sortarray, sortarray.size());
	vector<int>::iterator iter;
	for (iter = sortarray.begin(); iter != sortarray.end(); iter++)
	{
		cout << (*iter) << endl;
	}
	return 0;
}