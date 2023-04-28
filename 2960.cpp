#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	vector<int>number(N - 1, 0);
	for (int i = 0; i < number.size(); i++) {
		number[i] = i + 2;
	}
	int remove = 0;
	bool go = true;
	while (go) {
		int P = number[0];
		remove++;
		number.erase(number.begin());
		if (remove == K) {
			cout << P;
			break;
		}
		for (int i = 0; i < number.size(); i++) {
			if (number[i] % P == 0) {
				int P2 = number[i];
				number.erase(number.begin() + i);
				i--;
				remove++;
				if (remove == K) {
					cout << P2;
					go = false;
					break;
				}
			}
		}
	}
}
