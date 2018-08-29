#include <iostream>

using namespace std;

long nthFibonacci(int n){
	if(n <= 1)
		return n;

	int prev = 0, curr = 1;
	int now;

	for(int i = 2; i <= n; ++i){
		now = prev + curr;
		prev = curr;
		curr = now;
	}

	return now;
}

int main(){
	int n = 3;
	cout << nthFibonacci(n) << endl;
}