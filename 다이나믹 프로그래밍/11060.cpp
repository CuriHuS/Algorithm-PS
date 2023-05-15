#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int* map = new int[N];
	int* dp = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> map[i];
		dp[i] = 1001; // 어떠한 N이 주어져도 N보다 큰 값으로 초기화
	}
	dp[0] = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= map[i]; j++) { // j는 i지점에서 최대 점프 횟수까지 모든 경우의 수를 검색하기 위한 수
			if (i + j < N && dp[i + j]>dp[i] + 1) dp[i + j] = dp[i] + 1;
			// i+j = 점프 횟수 , dp[i+j]: 도착지점에 기록된 최소 점프 수, i에서 i+j로 점프뛰었을 때 횟수가 더 적으면 i+j 위치에 i+1
		}
	}
	if (dp[N - 1] > N) cout << -1;
	else cout << dp[N - 1];
	delete[] map;
	delete[] dp;
}
