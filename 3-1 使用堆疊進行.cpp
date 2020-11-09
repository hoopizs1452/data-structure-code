#include <iostream>
using namespace std;
class Stack{
private:
    int top;
    int capacity;
    int *array;
    void DoubleCapacity();
public:
    Stack():top(-1),capacity(1){
        array = new int[capacity];
    }
    void Push(int x);
    void Pop();
    void PrintStack();
};
void Stack::DoubleCapacity(){

    capacity *= 2;
    int *newStack = new int[capacity]; 

    for (int i = 0 ; i < capacity/2; i++) {
        newStack[i] = array[i];
    }

    delete [] array;
    array = newStack;
}
void Stack::Push(int x){

    if (top == capacity - 1) {
        DoubleCapacity();
    }
    array[++top] = x;
}

void Stack::Pop(){

    if (top == -1) {
        std::cout << "Stack is empty.\n";
        return;
    }
    top--;
}
void Stack::PrintStack()
{
    if (top == -1) {
        std::cout << "Stack is empty.\n";
    }
    else
    {
        for (int i = top;i>=0;i--)
        {
            std::cout <<array[i]<<" ";
        }
    }
}
int main(int argc, char *argv[])
{
    Stack stack;
    int times, input;
    cin >> times;
    for(int i = 0; i < times; i++) {
        cin >> input;
        stack.Push(input);
    }
    cin >> times;
    for(int i = 0; i < times; i++) {
        stack.Pop();
    }
    stack.PrintStack();
}
