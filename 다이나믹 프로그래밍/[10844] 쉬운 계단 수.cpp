#include <iostream>

using namespace std;
int main() {
	long long const mod = 1000000000; // 중간 중간 10^9로 나눠줄 수
	long long dp[101][10]={0}, N; // int 값의 범위보다 더 크게 나오므로 long long으로 배열 선언
	cin >> N; 

	for (int i = 1; i < 10; i++) { // N=1일 때는 모두 1이므로 초기값을 설정해줌
		dp[1][i] = 1;
	}

	for (int i = 2; i < N+1; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) { // 해당 자리의 수가 0일 때는 1의 값만 가져올 수 있으므로 이전 시행의 1의 횟수 가져옴
				dp[i][j] = dp[i - 1][1]%mod; // N의 값이 커지면 중간에 long long 범위를 넘어서 계산 마다 mod로 나눠줌
			}
			else if (j == 9) { // 해당 자리의 수가 9일 때는 8의 값만 가져올 수 있으므로 이전 시행의 8의 횟수만 가져온다
				dp[i][j] = dp[i - 1][8]%mod;
			}
			else { // 2~8은 자신보다 크거나 작은 수를 둘 다 가져올 수 있다.
				dp[i][j] = dp[i - 1][j - 1]%mod + dp[i - 1][j + 1]%mod;
			}
		}
	}
	long long result = 0;
	for (int i = 0; i < 10; i++) {
		result += dp[N][i];
		result %= mod;
	}

	cout << result % mod;
}
