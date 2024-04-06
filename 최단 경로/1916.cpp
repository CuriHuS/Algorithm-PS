#include <iostream>
#include <algorithm>
#include <queue>

#define endl "\n"
#define MAX 20001
#define INF 100000000
using namespace std;

int N, M, Start, End;
long long int Dist[MAX];
bool Visited[MAX];
vector<pair<int, int>> Vertex[MAX];

void Input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c; cin >> a >> b >> c;
		Vertex[a].push_back(make_pair(b, c));
	}
	cin >> Start >> End;
	for (int i = 1; i <= N; i++) {
		Visited[i] = 0;
		Dist[i] = INF;
	}
}

void Solution() {
	priority_queue<pair<int, int>> PQ;
	PQ.push(make_pair(0, Start));
	Dist[Start] = 0;
	Visited[Start] = 1;

	while (!PQ.empty()) {
		int Cost = -PQ.top().first;
		int Cur = PQ.top().second;
		PQ.pop();

		if (Dist[Cur] < Cost) continue;
		// 현 도시까지 비용이 이미 기록된 비용보다 크면 통과

		for (int i = 0; i < Vertex[Cur].size(); i++) {
			int Next = Vertex[Cur][i].first;
			int nCost = Vertex[Cur][i].second;

			if (Dist[Next] > Cost + nCost) {
				Dist[Next] = Cost + nCost;
				PQ.push(make_pair(-Dist[Next], Next));
			}
		}
	}
	cout << Dist[End];
}
void Solve() {
	Input();
	Solution();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	Solve();
}
