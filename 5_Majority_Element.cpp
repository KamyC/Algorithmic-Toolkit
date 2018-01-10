#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
	if (left == right) return -1;
	if (left + 1 == right) return a[left];
	int comp = a.size() / 2; 
	sort(a.begin(), a.end());
	int count = 0;
	int maj = 0;
	for (int i = 0; i < right; i++){
		if (count == 0){
			maj = a[i];
		}
		if (a[i] == maj){
			count++;
		}
		else{
			count--;
		}
	}
	//cout <<"maj:"<< maj << endl;
	count = 0; 
	for (int i = 0; i < right; i++){
		if (a[i] == maj){
			count++;
		}
	}
	if (count > comp){
		return 1;
	}
	return 0;
}

int main() {
	int n;
	std::cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < a.size(); ++i) {
		std::cin >> a[i];
	}
	
	std::cout << (get_majority_element(a, 0, a.size()-1)!=-1) << '\n';
}
