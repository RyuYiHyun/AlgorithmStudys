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

int main()
{
	Queue<int>* qu = new Queue<int>();
	qu->push(1);
	qu->push(3);
	qu->push(4);
	qu->push(5);
	qu->ShowQueue();
	qu->clear();
	qu->ShowQueue();
	qu->push(8);
	qu->pop();
	qu->ShowQueue();
	qu->pop();
	qu->peek();
	return 0;
}