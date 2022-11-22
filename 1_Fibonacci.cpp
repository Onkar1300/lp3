// Fibonacci Series using Recursion
#include <bits/stdc++.h>
using namespace std;

int fib(int n)
{
	if (n <= 1)
		return n;
	return fib(n - 1) + fib(n - 2);
}

int main()
{
	int n = 9;
	cout << fib(n);
	return 0;
}

//Space Complexity O(1)
//Time Complexity O(2^N)



// Fibonacci Series using Iteration
#include <bits/stdc++.h>
using namespace std;

int fib(int n){
    int a = 0;
    int b = 1;
    if(n==1){
        return a;
    }
    if(n==2){
        return b;
    }
    for(int i=0;i<n-2;i++){
        int c=a+b;
        a=b;
        b=c;
    }
    return b;
}

int main(){
    int n=9;
    cout<< fib(n);
    return 0;
}

//Space Complexity O(1)
//Time Complexity O(N)