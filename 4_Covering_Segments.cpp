#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>


using namespace std;
struct Segment {
	int start, end;
};

vector<int> optimal_points(vector<Segment> &segments) {
	vector<int> points;
	/*for (size_t i = 0; i < segments.size(); ++i) {
		points.push_back(segments[i].start);
		points.push_back(segments[i].end);
	}*/
	while (segments.size() > 0){
		int min_end = segments[0].end;
		for (int i = 0; i < segments.size(); i++){
			if (min_end>segments[i].end){
				min_end = segments[i].end;
			}
		}
		points.push_back(min_end);
		//cout << "point_size: " << points.size() << endl;
		for (int i = 0; i < points.size(); i++){
		/*	cout << "----" << points[i] << endl;*/
		}
		int i = segments.size(); 
		while (i-- > 0){
			if (min_end <= segments[i].end&&min_end >= segments[i].start){
				segments.erase(segments.begin() + i);
			}
		}
			
		
	}
	
	return points;
}

int main() {
	int n;
	std::cin >> n;
	vector<Segment> segments(n);
	for (size_t i = 0; i < segments.size(); ++i) {
		std::cin >> segments[i].start >> segments[i].end;
	}
	vector<int> points = optimal_points(segments);
	std::cout << points.size() << "\n";
	for (size_t i = 0; i < points.size(); ++i) {
		std::cout << points[i] << " ";
	}
}
