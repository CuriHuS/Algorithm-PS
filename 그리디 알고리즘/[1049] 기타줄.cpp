#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<int>pack;
	vector<int>unit;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		pack.push_back(a);
		unit.push_back(b);
	}
	sort(pack.begin(), pack.end());
	sort(unit.begin(), unit.end());
  // 어차피 min값만 쓰는거라 sort 안 쓰고 for문으로 최솟값만 찾아도 상관 없을 듯

	int money = 0;
	while (N > 0) {
		if (unit[0] * 6 < pack[0]) { // 패키지보다 낱개로 사는게 더 싸면 낱개로만 사
			money += unit[0] * N;
			break;
		}
		else {
			if (N / 6 >= 1) { //일단 무조건 패키지를 사는게 이득인 상황
				money += pack[0] * (N / 6);
				N %= 6;
			} 
			else { // 살 수량이 6개보다 적어서 패키지를 살지 낱개를 살지 고민
				if (N * unit[0] < pack[0]) { // 낱개가 더 이득인 상황
					money += unit[0] * N;
					break;
				}
				else { // 패키지로 사는게 더 이득인 상황
					money += pack[0];
					break;
				}
			}
		}
	}
	cout << money;
}
