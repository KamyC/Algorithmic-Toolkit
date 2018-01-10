#include <iostream>
using namespace std;
int get_change(int m) {
	int a = 1;
	int b = 5;
	int c = 10;
	int min = 0;
	while (m >= 10){
		min++;
		m = m - c;
	}
	while (m >= 5 && m < 10){
		min++;
		m = m - b;
	}
	while (m>0){
		min++;
		m = m - a;
	}
	
	return min;
}

int main() {
	int m;
	std::cin >> m;
	std::cout << get_change(m) << '\n';
}
