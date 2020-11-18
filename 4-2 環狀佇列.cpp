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
	rear = 0;
	front = 0;
}

void Queue::Enqueue(int x)
{
	rear = (rear+1)%10;
	arr[rear] = x;
}

void Queue::Dequeue()
{
	front = (front+1)%10;
}

void Queue::PrintQueue()
{
	int i=front+1;
	while(i!=rear+1)
	{
		cout << arr[i] << " ";
		i=(i+1)%10;
	}
	cout << " rear:" << rear << " front:" << front << endl;
}

int main(int argc, char *argv[])
{
    Queue queue;
    int times, input;
    for(int i = 0; i < 2; i++) {
    	cin >> times;
	    for(int j = 0; j < times; j++) {
	        cin >> input;
	        queue.Enqueue(input);
	    }
	    cin >> times;
	    for(int j = 0; j < times; j++) {
	        queue.Dequeue();
	    }
	}
    queue.PrintQueue();
}
