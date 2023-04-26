#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
  
	vector<vector<int>> paper(100,vector<int>(100, 0));
	
  int x, y;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		for (int y1=y; y1 < y+10; y1++) {
			for (int x1=x ; x1 < x+10; x1++) {
				if (paper[y1][x1] == 0) paper[y1][x1] = 1;
			}
		}
	}
	int count = 0;
	for (auto data : paper) {
		for (auto data_x : data) {
			if (data_x == 1) count++;
		}
	}
	cout << count;
}
