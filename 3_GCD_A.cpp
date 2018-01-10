#include<iostream>
#include<stdlib.h>
using namespace std;

int GCD_Naive(int a, int b){
	int n = a;
	int max_gcd = 0;
	for (int i =1; i <= n; i++){
		if (a%i == 0 && b%i == 0){
			max_gcd = i;
		}
	}
	return max_gcd;
}

int main(){
	int a, b;
	cin >> a >> b;
	cout << GCD_Naive(a, b) << endl;

	return 0;
}