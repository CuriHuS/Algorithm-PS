#include <iostream>
#include <queue>
#define MAX 1000001
using namespace std;

bool visit[MAX];
int map[MAX];

int main() {
	int F, S, G, U, D;
	cin >> F >> S >> G >> U >> D;
	queue<int>q;
	q.push(S);
	visit[S] = 1; visit[0] = 1;
	int i, result = 0;
	if (S == G) cout << 0;
	else {
		while (!q.empty()) {
			i = q.front();
			q.pop();
			if (i + U <= F && visit[i + U] == 0) {
				visit[i + U] = 1;
				q.push(i + U);
				map[i + U] = map[i] + 1;
				if (i + U == G) {
					result = map[i + U];
					break;
				}
			}
			if (i - D > 0 && visit[i - D] == 0) {
				visit[i - D] = 1;
				q.push(i - D);
				map[i - D] = map[i] + 1;
				if (i - D == G) {
					result = map[i - D];
					break;
				}
			}
		}
		if (result == 0) cout << "use the stairs";
		else cout << result;
	}
}
