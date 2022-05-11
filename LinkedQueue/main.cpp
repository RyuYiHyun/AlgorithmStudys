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