#include <iostream>
using namespace std;

class Queue
{
	public:
		int arr[10];
		int rear,front;
		Queue();
		void Enqueue(int x);
		void Dequeue();
		void PrintQueue();
};

Queue::Queue()
{
	arr[10] = {0};
	rear = -1;
	front = -1;
}

void Queue::Enqueue(int x)
{
	rear += 1;
	arr[rear] = x;
}

void Queue::Dequeue()
{
	front += 1;
}

void Queue::PrintQueue()
{
	for(int i=front+1; i<=rear; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main(int argc, char *argv[])
{
    Queue queue;
    int times, input;
    cin >> times;
    for(int i = 0; i < times; i++) {
        cin >> input;
        queue.Enqueue(input);
    }
    cin >> times;
    for(int i = 0; i < times; i++) {
        queue.Dequeue();
    }
    queue.PrintQueue();
}
