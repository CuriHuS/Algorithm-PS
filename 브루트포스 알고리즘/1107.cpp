#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int main() {
	int N, M;
	bool Button[10];
	for (int i = 0; i < 10; i++) Button[i] = true;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a;
		cin >> a;
		Button[a] = false; // 사용 못하는 버튼 false로
	}

	bool ch[1000001];
	for (int i = 0; i < 1000001; i++) {
		ch[i] = true;
		string a = to_string(i);

		for (int j = 0; j < a.size(); j++) {
			if (!Button[a[j]-'0']) {
				ch[i] = false;
				break;
			}
		}
	}

	int diff = abs(N - 100);

	if (ch[N]) {
		if (to_string(N).size() > diff)
			cout << diff;
		else
			cout << to_string(N).size();
	}
	else {
		if (N == 0) {
			int up = N;
			while (true) {
				up++;
				if (ch[up]) {
					if (to_string(up).size() - N + up < diff)
						cout << to_string(up).size() - N + up;
					else
						cout << diff;
					return 0;
				}
			}
		}
		else {
			int down = N, up = N;
			while (true) {
				down--;
				if (ch[down]) {
					break;
				}
				if (down == 0) {
					down = -999999;
					break;
				}
					
			}
			while (true) {
				up++;
				if (ch[up]) {
					break;
				}
			}

			if (N - down > up - N) {
				if (to_string(up).size() + up - N < diff)
					cout << to_string(up).size() - N + up;
				else
					cout << diff;
			}
			else {
				if (to_string(down).size() + N - down < diff)
					cout << to_string(down).size() + N - down;
				else
					cout << diff;
			}
		}
	}
}
