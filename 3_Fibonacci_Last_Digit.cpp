#include <iostream>
using namespace std;
int get_fibonacci_last_digit_fast(int n) {
	if (n <= 1){
		return n;
	}
	int f = 1;
	int g = 0;
		while (0<=n--){	
			g = (g + f);
			f = (g - f)%10;
		}
		return f;
}

int main() {
	int n;
	cin >> n;
	cout << get_fibonacci_last_digit_fast(n) << endl;
	return 0;
}
