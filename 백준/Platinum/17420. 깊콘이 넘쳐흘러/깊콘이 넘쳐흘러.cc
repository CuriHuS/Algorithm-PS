#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

struct gifticon
{
	long long leftDay;
	long long usePlan;

	bool operator< (const gifticon& a)
	{
		if (usePlan != a.usePlan)
			return usePlan < a.usePlan;
		return leftDay < a.leftDay;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;

	vector<gifticon> v(N, { 0,0 });
	for (int i = 0; i < N; i++)
	{
		cin >> v[i].leftDay;
	}

	for (int i = 0; i < N; i++)
	{
		cin >> v[i].usePlan;
	}

	long long answer = 0;

	for (int i = 0; i < N; i++)
	{
		if (v[i].leftDay < v[i].usePlan)
		{

			long long extension = (long long)ceil((v[i].usePlan - v[i].leftDay) / (double)30);
			v[i].leftDay += extension * 30;
			answer += extension;
		}
	}

	// 사용기한대로 정렬
	sort(v.begin(), v.end());

	long long maxDays = 0;
	for (int i = 0; i < N; i++)
	{
		long long next = i;
		while (next < N)
		{
			if (v[next].usePlan != v[i].usePlan)
				break;
			++next;
		}

		// next까지 동일한 leftDay(기한)

		for (int j = i; j < next; j++)
		{
			// 이전에 사용했던 깊티의 기한보다 적게 남아있었다면 기한 연장 해줘야함
			if (maxDays > v[j].leftDay)
			{
				long long extension = (long long)ceil((maxDays - v[j].leftDay) / (double)30);
				v[j].leftDay += extension * 30;
				answer += extension;
			}
		}

		sort(v.begin() + i, v.begin() + next);

		maxDays = max(maxDays, v[next - 1].leftDay);
		i = next - 1;
	}

	cout << answer;
}