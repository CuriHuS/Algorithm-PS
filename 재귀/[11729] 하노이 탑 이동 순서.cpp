#include <iostream>
#include <cmath>
using namespace std;

void move(int N, int start, int end) {
	cout << start << " " << end << "\n;  # endl 대신 개행문자 사용으로 시간 단축
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
	ios::sync_with_stdio(false); #중요: cout 시의 출력 시간을 대폭 감소 이거 없으면 시간 초과
		int N;
	cin >> N;
	cout << static_cast<long long>(pow(2, N)) - 1 << endl;
	hanoi(N, 1, 3, 2);

}
