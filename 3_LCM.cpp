#include <iostream>
using namespace std;

long long gcd_fast(long a, long b) {
		if (b == 0){
			return a;
		}
		else {
			long long _a = a%b;
			return gcd_fast(b, _a);
		}
	}

int main() {
	long long a, b;
	cin >> a >> b;
	long long r = gcd_fast(a, b);
	long long lcm = (a*b)/r;
	cout << lcm << endl;
	return 0;
}
