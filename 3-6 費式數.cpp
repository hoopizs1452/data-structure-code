#include <iostream>
using namespace std;

int fact(int n)
{
	if(n==0)
		return 0;
	else if(n==1)
		return 1;
	else
		return fact(n-1)+fact(n-2);
} 

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	cout << fact(n) << endl;
	
}
