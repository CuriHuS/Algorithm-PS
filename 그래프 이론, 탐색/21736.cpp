#include <iostream>
#include <queue>
using namespace std;
int main() {
	int N, M, ix, iy;
	cin >> N >> M;
	char** campus = new char* [N];
	bool** visit = new bool* [N];
	for (int i = 0; i < N; i++) {
		campus[i] = new char[M];
		visit[i] = new bool[M];
		for (int j = 0; j < M; j++) {
			cin >> campus[i][j];
			visit[i][j] = 0;
			if (campus[i][j] == 'I') {
				ix = i; iy = j;
			}
		}
	}

	int people = 0; // 만난 사람의 수
	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };

	queue<pair<int, int>> q;
	q.push(make_pair(ix, iy));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + x;
			int ny = dy[i] + y;
			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if (visit[nx][ny] == 0) {
					if (campus[nx][ny] != 'X') {
						q.push(make_pair(nx, ny));
						if (campus[nx][ny] == 'P')
							people++;
					}
					visit[nx][ny] = 1;
				}
			}
		}
	}
	if (people == 0) cout << "TT";
	else cout << people;
}
