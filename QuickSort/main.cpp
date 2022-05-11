#include <string>
#include <vector>
#include <iostream>
using namespace std;
//퀵 정렬 알고리즘
/* 
 장점:
	속도가 빠르가
	@ 시간복잡도가 O( n*log(n) )
	메모리 공간이 적다
	@ O( log(n) ) 만큼의 메모리 공간 필요
 단점
	정렬된 배열에 대해서는 수행시간이 더 많이 걸린다.
	최악의 경우 n**2 n의 제곱의 시간이 걸린다.
*/
template <typename T>
class CQuickSort
{
public:
	// begin은 0, end는 SortArray의 size - 1을 넣기 (또는 정렬하고 싶은 구간 넣기)
	static void QuickSortFunction(vector<T>& SortArray, int begin, int end)
	{
		int pivot;
		if (begin < end)
		{
			pivot = Partition(SortArray, begin, end);//pivot위치로 분할 위치 결정
			QuickSortFunction(SortArray, begin, pivot - 1);//왼쪽 partition에 대한 정렬
			QuickSortFunction(SortArray, pivot + 1, end);//오른쪽 partition에 대한 정렬
		}
	}
private:
	static int Partition(vector<T>& SortArray, int begin, int end)
	{
		int pivot, left, right;
		T key;
		left = begin;
		right = end;
		pivot = (int)((begin + end) / 2.0);	//배열의 중앙의 위치의 값을 pivot으로 설정
		while (left < right)
		{
			while ((SortArray[left] < SortArray[pivot]) && (left < right)) { left++; }		// left는 오른쪽 이동 >>
			while ((SortArray[right] >= SortArray[pivot]) && (left < right)) { right--; }	// right는 왼쪽 이동 <<
			if (left < right) // left와 right 원소를 자리 교체, left와 right가 교차하지 않음
			{
				key = SortArray[left];
				SortArray[left] = SortArray[right];
				SortArray[right] = key;
				if (left == pivot)// left가 pivot인 경우 변경된 위치를 저장한다.
				{
					pivot = right;
				}
			}
		}
		//만약 left와 right가 같은 경우, right원소와 pivot 위치 교환
		key = SortArray[pivot];
		SortArray[pivot] = SortArray[right];
		SortArray[right] = key;
		// 정렬되어 확정된 피봇의 위치 반환
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