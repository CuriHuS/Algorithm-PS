#include <iostream>
#include <queue>
#define MAX 1000001
using namespace std;

bool visit[MAX] = {}; // 방문했던 곳인지
int dp[MAX] = {}; // 몇 번째 움직임인지
int from[MAX] = {}; // 이전 숫자 추적

int main() { // dp로 사용했는데 bfs알고리즘과 더 유사함
  // 1부터 시작해서 역으로 N까지 찾아가는 알고리즘
	int N;
	cin >> N;
	dp[1] = 1;
	visit[1] = 1;
	queue<int>v;
	v.push(1);
	int i;
	while (true) {
		i = v.front();
		v.pop();
		if (i*3 < MAX && visit[i * 3] == 0) { // i의 범위를 설정해주지 않으면 Out of bounds 에러
			visit[i * 3] = 1;
			dp[i * 3] = dp[i] + 1;
			from[i * 3] = i;
			v.push(i * 3);
		}
		if (i*2 < MAX && visit[i * 2] == 0) {
			visit[i * 2] = 1;
			dp[i * 2] = dp[i] + 1;
			from[i * 2] = i;
			v.push(i * 2);
		}
		if (i+1 < MAX && visit[i + 1] == 0) {
			visit[i + 1] = 1;
			dp[i + 1] = dp[i] + 1;
			from[i + 1] = i;
			v.push(i + 1);
		}
		if (visit[N] == 1) break;
	}
	int a = N;
	cout << dp[N]-1 << endl;
	cout << N << " ";
	for (int i = 1; i< dp[N]; i++) {
		cout << from[a] << " ";
		a = from[a];
	}
	
}
