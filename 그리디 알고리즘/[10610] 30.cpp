#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	string N;
	string answer;
	vector<int> count(10, 0);
	cin >> N;
	for (int i = 0; i < N.length(); i++) {
		count[static_cast<int>(N[i]) - '0']++;
	}
	if (count[0] == 0) {
		cout << -1;
	}
	else {
		int sum = 0;
		for (int i = 0; i < 10; i++) {
			sum += i * count[i];
		}
		if (sum % 3 == 0) {
			for (int i = 9; i >= 0; i--) {
				for (int j = 0; j < count[i]; j++) answer.append(to_string(i));
			}
			cout << answer;
		}
		else cout << -1;
	}
}
