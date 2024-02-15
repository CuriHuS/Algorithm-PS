#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int A, B;
		cin >> A >> B;
		queue<pair<string, int>> q;
		q.push(make_pair("0", A));

		bool visit[10000] = {};
		visit[A] = true;
		while (1) {
			string answer = q.front().first;
			int n = q.front().second;
			q.pop();
			if (n == B) {
				for (int i = 1; i < answer.length(); i++)
					cout << answer[i];
				cout << "\n";
				break;
			}

			int next;
			next = (2 * n) % 10000;
			if (!visit[next]) {
				q.push(make_pair(answer + "D", next));
				visit[next] = true;
			}

			next = (n == 0 ? 9999 : n - 1);
			if (!visit[next]) {
				q.push(make_pair(answer + "S", next));
				visit[next] = true;
			}

			next = (n % 1000) * 10 + n / 1000;
			if (!visit[next]) {
				q.push(make_pair(answer + "L", next));
				visit[next] = true;
			}

			next = (n % 10) * 1000 + n / 10;
			if (!visit[next]) {
				q.push(make_pair(answer + "R", next));
				visit[next] = true;
			}
		}
	}
}
