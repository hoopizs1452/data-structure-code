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
	Plot();
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

void BinTree::Plot() 
{
	Inorder(root);
	cout << endl;
	Preorder(root);
	cout << endl;
	Postorder(root);
	cout << endl;
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
