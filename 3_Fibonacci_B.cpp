#include<iostream>
#include<stdlib.h>
using namespace std;
__int64 fib(int n){
	__int64 f = 1;
	__int64 g = 0;
	while (0<=n--){	
		g = g + f;
		f = g - f;
	}
	return f;
}
int main(){
	__int64 n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		printf("fib(%2d) = %22I64d\n", i, fib(i));
	}
	return 0;
}