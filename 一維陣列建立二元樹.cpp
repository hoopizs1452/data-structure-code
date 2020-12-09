#include <iostream>
using namespace std;

class BinTree
{
private:
	int arr[100];
	int tail, t;
public:
	BinTree():tail(0){};
	void BuildTree(int[], int);
	void Print();
};

void BinTree::BuildTree(int data[], int n)
{
	int temp;
	for(int i=0; i<100; i++)
		arr[i] = 0;
	arr[1] = data[0];
	temp = n;
	for(int i=1; i<n; i++)
	{
		tail = 1;
		while(arr[tail]!=0)
		{
			if(data[i] > arr[tail])
				tail = 2*tail+1;
			else
				tail *= 2;
			if(temp < tail)
			{
				temp = tail;
				t = temp;
			}
		}
		arr[tail] = data[i];
	}
}

void BinTree::Print()
{
	for(int i=1; i<=t; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main(int argc, char *argv[])
{   
    BinTree tree1;
    int n;
    cin >> n;
    int data[n];
    for (int i = 0; i < n; i++) cin >> data[i];
    tree1.BuildTree(data, n);
    tree1.Print();
}
