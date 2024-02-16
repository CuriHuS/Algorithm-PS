#include <iostream>

using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	int** graph = new int* [N+1];
	for (int i = 0; i <= N; i++) graph[i] = new int[N+1];
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			graph[i][j] = 0;
		}
	}
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> graph[i][j];
			graph[i][j] += graph[i][j - 1];
			graph[i][j] += graph[i - 1][j];
			graph[i][j] -= graph[i - 1][j - 1];
		}
	}

	int x1, y1, x2, y2, sum = 0;

	for (int t = 0; t < M; t++) {
		cin >> x1 >> y1 >> x2 >> y2;
		sum = graph[x2][y2] - graph[x2][y1 - 1] - graph[x1 - 1][y2] + graph[x1 - 1][y1 - 1];
		cout << sum << "\n";
	}
}
