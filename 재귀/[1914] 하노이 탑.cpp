#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void move(int N, int start, int end) {
	cout << start << " " << end << "\n";
}

void hanoi(int N, int start, int end, int sub) {
	if (N == 1) {
		move(1, start, end);
		return;
	}
	else {
		hanoi(N - 1, start, sub, end);
		move(N, start, end);
		hanoi(N - 1, sub, end, start);
	}
}

int main() {
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	if (N <= 20){
		cout << static_cast<long long>(pow(2, N)) - 1 << endl;
		hanoi(N, 1, 3, 2);
	}
	else { // 11729 하노이 탑과 다른 점이다. 최대 2^100까지 계산하므로 long long의 범위를 넘는다. 그래서 N>20이상인 수부터는 배열로 자리수를 각각 계산해준다.
		vector<int>count(1,1); 
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < count.size(); j++) {
				count[j] *= 2;
			}
			for (int j = 0; j < count.size(); j++) {
				if (count[j] >= 10) {  // 각 자리의 수가 10이 넘어가면 다음 자리수를 1 올려준다.
					if (j == count.size() - 1) { // 만약 벡터의 인덱스가 마지막이라면 다음 인덱스가 없으니 push_back을 해준다.
						count[j] -= 10;
						count.push_back(1);
					}
					else {  // 마지막 인덱스가 아니라면 다음 인덱스의 값을 1 올려준다.
						count[j + 1]++;
						count[j] -= 10;
					}
				}
			}
		}
		count[0]--;
		for (int i = count.size() - 1; i >= 0; i--) cout << count[i];
	}
}
