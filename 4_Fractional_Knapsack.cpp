#include <iostream>
#include <vector>
#include<iomanip>
using namespace std;
int find_max( vector<int> weights, vector<int> values){
	double max = 0.000;
	int len = weights.size();
	int m = 0;
	for (int i = 0; i < len; i++){
		if (max < values[i] / weights[i]){
			max = values[i] / weights[i];
			m = i;
		}
	}

	return m;
	
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
	double value = 0.000;
	while (capacity > 0.000){

		int len = weights.size();
		double max = 0.000;
		int m = 0;
		for (int i = 0; i < len; i++){
			if (max < values[i]*1.0 / weights[i]*1.0){
				max = values[i]*1.0 / weights[i]*1.0;
				m = i;
			}
		}

		if (capacity<=weights[m]){
			value += (values[m]*1.0 / weights[m]*1.0)*capacity;
			capacity -= capacity;
		}
		else if(capacity>weights[m]&&weights.size()>1) {
			capacity -= weights[m];
			value += values[m];
		
		}
		else if (capacity>weights[m] && weights.size()<=1){
			return values[m];
		}
		weights.erase(weights.begin() + m);
		values.erase(values.begin() + m);
	}
	return value;
}

int main() {
	int n;
	int capacity;
	std::cin >> n >> capacity;
	vector<int> values(n);
	vector<int> weights(n);
	for (int i = 0; i < n; i++) {
		std::cin >> values[i] >> weights[i];
	}

	double optimal_value = get_optimal_value(capacity, weights, values);

	std::cout.precision(4);
	std::cout <<fixed<< optimal_value << std::endl;
	return 0;
}
