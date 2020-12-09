#include <iostream>
#include <iomanip>
#include <queue>
#include <math.h>
using namespace std;

class TreeNode
{
public:
	friend class BinTree;
	TreeNode(int a) {data = a; leftChild = rightChild = 0;};
private:
	int data;
	TreeNode *leftChild;
	TreeNode *rightChild;
};

class BinTree
{
private:
	TreeNode *root;
public:
	BinTree():root(0){};
	void BuildTree(int[], int);
	void Inorder(TreeNode*);
	void Preorder(TreeNode*);
	void Postorder(TreeNode*);
	void Plot();
};

void BinTree::BuildTree(int data[], int n)
{
	TreeNode* current;
	TreeNode* parent;
	for(int i=0; i<n; i++)
	{
		TreeNode* newNode = new TreeNode(data[i]);
		if(root==NULL)
			root = newNode;
		else
		{
			current = root;
			while(current!=0)
			{
				parent = current;
				if(current->data > data[i])
					current = current->leftChild;
				else
					current = current->rightChild;
			}
			if(parent->data > data[i])
				parent->leftChild = newNode;
			else
				parent->rightChild = newNode;
		}
	} 
}

void BinTree::Plot() {
	int MAX_HEIGHT = 7, CHAR_SPACE = 2;
	int capacity = pow(2, MAX_HEIGHT);
	int arr[capacity] = {0};
	queue<TreeNode*> q;
	queue<int> index_q;
	q.push(root);
	index_q.push(1);
	TreeNode *currentNode;
	int currentIndex, tail = 0;
	while(!q.empty()) {
		currentNode = q.front(); q.pop();
		currentIndex = index_q.front(); index_q.pop();
		arr[currentIndex] = currentNode->data;
		if (tail < currentIndex) tail = currentIndex;
		if (currentNode->leftChild) {
			q.push(currentNode->leftChild);
			index_q.push(currentIndex * 2);}
		if (currentNode->rightChild) {
			q.push(currentNode->rightChild);
			index_q.push(currentIndex * 2 + 1);}
	}
	int i, sps;
	int max_level = tail == 1 ? 1 : sqrt(tail) + 1;
	for (int lv = 1; lv <= max_level; lv++) {
		sps = pow(2, max_level - lv) * CHAR_SPACE;
		i = pow(2, lv - 1);
		cout << setw(sps);
		if (arr[i]) cout << arr[i]; else cout << " ";
		sps *= 2;
		for (i++; i <= pow(2, lv) - 1; i++) {
			cout << setw(sps);
			if (arr[i]) cout << arr[i]; else cout << " ";
		}
		cout << endl;
	}
}

void BinTree::Inorder(TreeNode* n)
{
	if(n != NULL)
	{
		Inorder(n->leftChild);
		cout << n->data << " ";
		Inorder(n->rightChild);
	}
}

void BinTree::Preorder(TreeNode* n)
{
	if(n != NULL)
	{
		cout << n->data << " ";
		Preorder(n->leftChild);
		Preorder(n->rightChild);
	}
}

void BinTree::Postorder(TreeNode* n)
{
	if(n != NULL)
	{
		Postorder(n->leftChild);
		Postorder(n->rightChild);
		cout << n->data << " ";
	}
}


int main(int argc, char *argv[])
{   
    BinTree tree1;
    int n;
    cin >> n;
    int *data = new int[n];
    for (int i = 0; i < n; i++) cin >> data[i];
    tree1.BuildTree(data, n);
}
