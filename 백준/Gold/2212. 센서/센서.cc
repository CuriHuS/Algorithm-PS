#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, K;
	cin >> N >> K;

	vector<int> sensors(N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> sensors[i];
	}
	sort(sensors.begin(), sensors.end());
	vector<int> dist(N - 1, 0);
	for (int i = 0; i < N - 1; i++)
	{
		dist[i] = sensors[i + 1] - sensors[i];
	}
	sort(dist.begin(), dist.end());

	long long answer = 0;
	for (int i = 0; i < N-K; i++)
	{
		answer += dist[i];
	}
	cout << answer;
}