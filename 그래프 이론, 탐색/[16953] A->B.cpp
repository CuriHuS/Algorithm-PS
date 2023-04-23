// int범위로는 감당이 안 됨-> long long으로 해결
// 원래 2차원 vector 이용했는데 범위가 커서 deque로 변경
// deque에서는 2차원 다루기가 힘들어 배열을 두 개로 나눠서 관리

#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
	deque<long long>q; // 숫자가 저장되는 큐
	deque<int>c; // count가 저장되는 큐
	vector<int> answer; // A->B를 만들었을 때 몇 번 걸렸는지 기록 후 나중에 최솟값을 찾음
	long long A, B;
	cin >> A >> B;
	bool find_answer = false;
	q.push_back(A);
	c.push_back(1);

	while (!q.empty()) {
    // 만약 결과값이 B보다 크면 큐에 추가하지 않음
    // B와 같은 결과가 나온 경우 answer 배열에 count를 추가함
		long long q1 = q.back();
		int count = c.back();
		q.pop_back();
		c.pop_back();

		if (q1 * 2 == B) {
			answer.push_back(count + 1);
			find_answer = true;
		}
		else if (q1 * 2 < B) {
			q.push_back(q1*2);
			c.push_back(count + 1);
		}
		string str_q1 = to_string(q1) + to_string(1);
		q1 = stoull(str_q1); // stoi는 int로 못 버텨서 unsigned long long으로 바꿔줬음
		if (q1 == B) {
			answer.push_back(count + 1);
			find_answer = true;
		}
		else if (q1 < B) {
			q.push_back(q1);
			c.push_back(count+1);
		}
	}

	if (!find_answer) cout << -1;
	else cout << *min_element(answer.begin(), answer.end());
}
