#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	int N, C;
	cin >> N >> C;
	vector<int> dist;
	vector<int> houses;
	for (int i = 1; i <= N; i++)
	{
		int a;
		cin >> a;
		houses.push_back(a);
	}
	sort(houses.begin(), houses.end());
	int answer = 0;
	
	int start = 1; int end = houses[N - 1] - houses[0];
	while (start <= end)
	{
		int mid = (start + end) / 2;
		int current = houses[0];
		int cnt = 1;
		// 공유기 설치 몇 대 가능한지 확인
		for (int i = 1; i < N; i++)
		{
			if (houses[i] - mid >= current)
			{
				cnt += 1;
				current = houses[i];
			}
		}

		if (cnt >= C)
		{
			answer = mid;
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}

	cout << answer;
}