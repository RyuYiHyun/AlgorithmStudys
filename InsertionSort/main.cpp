#include <string>
#include <vector>
#include <iostream>
using namespace std;

template <typename T>
class CInsertionSort // ��������
{
public:
	static void InsertionSortFunction(vector<T>& SortArray, int arraySize)
	{
		int i;// i�� 1���� ���� ����, �ݺ���
		int j;// j�� i�� ���� �κ� Ž�� ��
		int key;// ���� �Ϸ��� ��

		///* for�� 2���� �̿��� ���
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
		/* for�� 1���� while�� �̿��� ���
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