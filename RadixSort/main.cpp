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
	bool isEmpty()// ���� �˻�
	{
		if (front == nullptr)
		{ return true; }// ť�� ����ֽ��ϴ�.
		else
		{ return false; }// ť�� ���Ұ� ���� �ֽ��ϴ�.
	}
	void push(Type item)
	{
		QueueNode* newNode = new QueueNode();
		newNode->data = item;
		newNode->link = nullptr;
		if (isEmpty())// ��������
		{
			front = newNode;
			rear = newNode;
		}
		else// ������ ������ �ڿ� �߰�
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
		if (isEmpty())// ��������
		{
			front = newNode;
			rear = newNode;
		}
		else// ������ ������ �ڿ� �߰�
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
			cout << "�� ť���� pop�� �߽��ϴ�.";
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
			cout << "�� ť���� peek�� �߽��ϴ�.";
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

class CRadixSort // �������
{
public:
	// ���ҵ��� ���� RADIX
	// ���ҵ� �߿� DIGIT �ڸ���
	static void RadixSortFunction(vector<int>& SortArray, int arraySize,int DIGIT)
	{
		const int RADIX = 10;
		int factor = 1;
		Queue<int>* Bucket[RADIX];// 10������ 0 ~ 9 ���� �ֱ� ����
		for (int i = 0; i < RADIX; i++)
		{
			Bucket[i] = new Queue<int>();
		}
		for (int digit = 0; digit < DIGIT; digit++)
		{
			for (int i = 0; i < arraySize; i++)//���ҵ��� �ڸ����� ���� �ش��ϴ� Bucket�� �ִ´�.
			{
				Bucket[(SortArray[i] / factor) % RADIX]->push(SortArray[i]);
			}
			int arrayIndex = 0;
			for (int i = 0; i < RADIX; i++)// �ڸ� ���� �ش��ϴ� Bucket���� ���� �ٽ� �ִ´�.
			{
				while (!Bucket[i]->isEmpty())
				{
					SortArray[arrayIndex] = Bucket[i]->pop();
					arrayIndex++;
				}
			}
			factor = factor * RADIX; // �ڸ��� ����
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