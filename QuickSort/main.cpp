#include <string>
#include <vector>
#include <iostream>
using namespace std;
//�� ���� �˰���
/* 
 ����:
	�ӵ��� ������
	@ �ð����⵵�� O( n*log(n) )
	�޸� ������ ����
	@ O( log(n) ) ��ŭ�� �޸� ���� �ʿ�
 ����
	���ĵ� �迭�� ���ؼ��� ����ð��� �� ���� �ɸ���.
	�־��� ��� n**2 n�� ������ �ð��� �ɸ���.
*/
template <typename T>
class CQuickSort
{
public:
	// begin�� 0, end�� SortArray�� size - 1�� �ֱ� (�Ǵ� �����ϰ� ���� ���� �ֱ�)
	static void QuickSortFunction(vector<T>& SortArray, int begin, int end)
	{
		int pivot;
		if (begin < end)
		{
			pivot = Partition(SortArray, begin, end);//pivot��ġ�� ���� ��ġ ����
			QuickSortFunction(SortArray, begin, pivot - 1);//���� partition�� ���� ����
			QuickSortFunction(SortArray, pivot + 1, end);//������ partition�� ���� ����
		}
	}
private:
	static int Partition(vector<T>& SortArray, int begin, int end)
	{
		int pivot, left, right;
		T key;
		left = begin;
		right = end;
		pivot = (int)((begin + end) / 2.0);	//�迭�� �߾��� ��ġ�� ���� pivot���� ����
		while (left < right)
		{
			while ((SortArray[left] < SortArray[pivot]) && (left < right)) { left++; }		// left�� ������ �̵� >>
			while ((SortArray[right] >= SortArray[pivot]) && (left < right)) { right--; }	// right�� ���� �̵� <<
			if (left < right) // left�� right ���Ҹ� �ڸ� ��ü, left�� right�� �������� ����
			{
				key = SortArray[left];
				SortArray[left] = SortArray[right];
				SortArray[right] = key;
				if (left == pivot)// left�� pivot�� ��� ����� ��ġ�� �����Ѵ�.
				{
					pivot = right;
				}
			}
		}
		//���� left�� right�� ���� ���, right���ҿ� pivot ��ġ ��ȯ
		key = SortArray[pivot];
		SortArray[pivot] = SortArray[right];
		SortArray[right] = key;
		// ���ĵǾ� Ȯ���� �Ǻ��� ��ġ ��ȯ
		return right;
	}
};

int main()
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

	CQuickSort<int>::QuickSortFunction(sortarray, 0, sortarray.size() - 1);

	vector<int>::iterator iter;
	for (iter = sortarray.begin(); iter != sortarray.end(); iter++)
	{
		cout << (*iter) << endl;
	}
	system("Pause");
	return 0;
}