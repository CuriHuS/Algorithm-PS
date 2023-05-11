#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int l;
		cin >> l;
		int** map = new int* [l];
		int** visit = new int* [l];
		for (int i = 0; i < l; i++) {
			map[i] = new int[l];
			visit[i] = new int[l];
		}
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < l; j++) {
				map[i][j] = 0;
				visit[i][j] = 0;
			}
		}
		int x, y, end_x, end_y;
		cin >> x >> y >> end_x >> end_y;
		int dx[8] = { 1,2,2,1,-1,-2,-2,-1 };
		int dy[8] = { 2,1,-1,-2,-2,-1,1,2 };
		if (x == end_x && y == end_y) cout << 0;
		else {
			int min = 99999; // 초기화 안 해줘도 됨
			queue<pair<int, int>> q;
			q.push(make_pair(x, y));
			while (!q.empty()) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();
				for (int i = 0; i < 8; i++) {
					int nx = dx[i] + x;
					int ny = dy[i] + y;
					if (nx >= 0 && nx < l && ny >= 0 && ny < l) {
						if (visit[nx][ny] == 0) {
							map[nx][ny] = map[x][y] + 1;
							visit[nx][ny] = 1;
							q.push(make_pair(nx, ny));
							if (nx == end_x && ny == end_y) { // bfs 특성상 먼저 도착하면 그 횟수가 최소이므로 반복 종료
								min = map[nx][ny];
								for (int a = 0; a < q.size(); a++) q.pop();
							}
						}
					}
				}
			}
			cout << min;
		}
		if (t<T-1)	cout << "\n"; // 마지막 출력 전까지는 줄바꿈을 해준다.
    
		for (int i = 0; i < l; i++) { // 정답과 관련 없는 코드
			delete[] map[i];
			delete[] visit[i];
		}
		delete[] map;
		delete[] visit;
		
	}
}
