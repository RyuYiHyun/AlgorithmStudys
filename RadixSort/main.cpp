#include <string>
#include <vector>
#include <iostream>
using namespace std;

template<class Type>
class Queue
{
private:
	struct QueueNode
	{
		Type data;
		QueueNode* link;
	};
public:
	Queue()
	{
		front = nullptr;
		rear = nullptr;
	}
	bool isEmpty()// 공백 검사
	{
		if (front == nullptr)
		{ return true; }// 큐가 비어있습니다.
		else
		{ return false; }// 큐에 원소가 남아 있습니다.
	}
	void push(Type item)
	{
		QueueNode* newNode = new QueueNode();
		newNode->data = item;
		newNode->link = nullptr;
		if (isEmpty())// 공백인지
		{
			front = newNode;
			rear = newNode;
		}
		else// 공백이 없으면 뒤에 추가
		{
			rear->link = newNode;
			rear = newNode;
		}
	}
	void push_back(Type item)
	{
		QueueNode* newNode = new QueueNode();
		newNode->data = item;
		newNode->link = nullptr;
		if (isEmpty())// 공백인지
		{
			front = newNode;
			rear = newNode;
		}
		else// 공백이 없으면 뒤에 추가
		{
			rear->link = newNode;
			rear = newNode;
		}
	}

	Type pop()
	{
		QueueNode* popNode = front;
		Type item;
		try
		{
			if (isEmpty())
			{
				throw 0;
			}
			item = popNode->data;
			front = front->link;
			if (front == nullptr)
			{
				rear = nullptr;
			}
			free(popNode);
			return item;
		}
		catch(int code)
		{
			cout << "빈 큐에서 pop을 했습니다.";
			system("pause");
			exit(1);
		}
	}
	Type peek()
	{
		Type item;
		try
		{
			if (isEmpty())
			{
				throw 0;
			}
			item = front->data;
			return item;
		}
		catch (int code)
		{
			cout << "빈 큐에서 peek를 했습니다.";
			system("pause");
			exit(1);
		}
	}
	void clear()
	{
		while (!isEmpty())
		{
			pop();
		}
	}

	void ShowQueue()
	{
		QueueNode* key = front;
		cout << "Queue [ ";
		while (key != nullptr)
		{
			cout.width(4);
			cout << key->data;
			key = key->link;
		}
		cout.width(4);
		cout << " ]";
	}
private:
	QueueNode* front;
	QueueNode* rear;
};

class CRadixSort // 기수정렬
{
public:
	// 원소들의 진법 RADIX
	// 원소들 중에 DIGIT 자리수
	static void RadixSortFunction(vector<int>& SortArray, int arraySize,int DIGIT)
	{
		const int RADIX = 10;
		int factor = 1;
		Queue<int>* Bucket[RADIX];// 10진수는 0 ~ 9 값을 넣기 위함
		for (int i = 0; i < RADIX; i++)
		{
			Bucket[i] = new Queue<int>();
		}
		for (int digit = 0; digit < DIGIT; digit++)
		{
			for (int i = 0; i < arraySize; i++)//원소들의 자리수의 값에 해당하는 Bucket에 넣는다.
			{
				Bucket[(SortArray[i] / factor) % RADIX]->push(SortArray[i]);
			}
			int arrayIndex = 0;
			for (int i = 0; i < RADIX; i++)// 자리 값에 해당하는 Bucket에서 값을 다시 넣는다.
			{
				while (!Bucket[i]->isEmpty())
				{
					SortArray[arrayIndex] = Bucket[i]->pop();
					arrayIndex++;
				}
			}
			factor = factor * RADIX; // 자리수 증가
		}
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
	CRadixSort::RadixSortFunction(sortarray, sortarray.size(), 2);
	vector<int>::iterator iter;
	for (iter = sortarray.begin(); iter != sortarray.end(); iter++)
	{
		cout << (*iter) << endl;
	}
	return 0;
}