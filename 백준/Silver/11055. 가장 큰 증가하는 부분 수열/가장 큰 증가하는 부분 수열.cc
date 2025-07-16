#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	int A[1000] = { 0, };
	int dy[1000];
	int sum[1000];
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		dy[i] = 1; sum[i] = A[i];
	}

	for (int i = 0; i < N; i++) {
		vector<int> v(1);
		for (int j = 0; j < i; j++) {
			if (A[i] > A[j] && dy[i] < dy[j] + 1) {
				dy[i] = dy[j] + 1;
		
				v.push_back(sum[j]);
			}
		}
		sum[i] += *max_element(v.begin(), v.end());
	}

	cout << *max_element(sum, sum + N);
}