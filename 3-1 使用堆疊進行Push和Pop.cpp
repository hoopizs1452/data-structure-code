#include <iostream>
using namespace std;
class Stack{
private:
    int top;
    int capacity;
    int *array;
public:
    Stack():top(-1),capacity(1){
        array = new int[capacity];
    }
    void Push(int x);
    void Pop();
    void PrintStack();
};
void Stack::Push(int x){
    array[++top] = x;
}

void Stack::Pop(){
    top--;
}
void Stack::PrintStack()
{
    for (int i = top;i>=0;i--)
        {
            std::cout <<array[i]<<" ";
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
