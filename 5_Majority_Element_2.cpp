#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using std::vector;

int count(vector<int>&a, int left, int right, int val){
	int count = 0;
	for (int i = left; i <= right; i++){
		if (val == a[i]){
			count++;
		}
	}
	return count;
}
int get_majority_element(vector<int> &a, int left, int right) {
	if (left > right) {
		cout << ">" << -1 << endl;
		return -1;
	};
	if (left == right) {
		cout << "=" << a[left] << endl;
		return a[left];
	};
	int mid = left + (right - left) / 2;

	int left_majority = get_majority_element(a, left, mid);
	int right_majority = get_majority_element(a, mid + 1, right);


	if (left_majority == -1 && right_majority != -1){
		int n = count(a, left, right, right_majority);
		if (n> a.size() / 2){
			return right_majority;
		}
		else{
			return -1;
		}
	}
	else if (left_majority != -1 && right_majority == -1){
		int n = count(a, left, right, left_majority);
		if (n > a.size() / 2){
			return left_majority;
		}
		else {
			return -1;
		}
	}
	else if (left_majority != -1 && right_majority != -1){
		int l = count(a, left, right, left_majority);
		int r = count(a, left, right, right_majority);
		if (l > (right - left + 1) / 2){
			return left_majority;
		}
		else if (r > (right - left + 1) / 2){
			return right_majority;
		}
		else {
			return -1;
		}
	}


	return -1;
}

int main() {
	int n;
	std::cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < a.size(); ++i) {
		std::cin >> a[i];
	}

	std::cout << (get_majority_element(a, 0, a.size() - 1) != -1) << '\n';
}
