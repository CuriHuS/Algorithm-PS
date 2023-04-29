#include <iostream>
#include <vector>
using namespace std;

int GCD(int n, int m) { // 최대 공약수 함수
	if (m == 0)
		return n;
	return GCD(m, n % m);
}

int main() {
	int t;
	cin >> t;
	for (int c = 0; c < t; c++) {
		int a, num;
		vector<int>list; // 매 테스트 케이스에 들어갈 list
		cin >> a;
		for (int i = 0; i < a; i++) {
			cin >> num;
			list.push_back(num);
		}
		long long result = 0; // 값이 int의 범위를 넘어가서 long long으로 처리해줘야됨
		for (int i = 0; i < list.size()-1; i++) {
			for (int j = i + 1; j < list.size(); j++) {
				result += (list[i] > list[j]) ? GCD(list[i], list[j]) : GCD(list[j], list[i]); // 최대 공약수를 result에 더해줌
			}
		}
		cout << result << endl;
	}
}
