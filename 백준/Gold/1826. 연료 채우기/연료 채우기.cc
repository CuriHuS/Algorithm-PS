#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct gas_station
{
	int pos;
	int fuel;

	bool operator< (const gas_station& other)
	{
		return pos < other.pos;
	}
};

int main()
{
	int N;
	cin >> N;

	vector<gas_station> v(N, { 0,0 });
	for (int i = 0; i < N; i++)
	{
		cin >> v[i].pos >> v[i].fuel;
	}

	sort(v.begin(), v.end());
	priority_queue<int> pq;

	int townPos, totalFuel; // 마을위치, 총 연료
	cin >> townPos >> totalFuel;

	// 마지막 목적지인 마을을 넣는다.
	v.push_back({ townPos, 0 });

	int count = 0; // 주유 횟수

	// 첫 주유소도 못 가면 끝내기
	if (v[0].pos > totalFuel)
	{
		cout << -1;
		return 0;
	}

	for (int i = 0; i <= N; i++)
	{
		// 만약 현재 연료로 주유소에 갈 수 있으면
		if (v[i].pos <= totalFuel)
		{
			pq.push(v[i].fuel);
			continue;
		}

		// 만약 더 이상 갈 수 없다면,
		if (v[i].pos > totalFuel)
		{
			// 이미 모든 주유를 했다 -> 실패
			if (pq.empty())
			{
				cout << -1;
				return 0;
			}

			// 갈 수 있을 때까지 주유를 한다.
			while (!pq.empty() && totalFuel < v[i].pos)
			{
				totalFuel += pq.top();
				pq.pop();
				count += 1;
			}

			if (v[i].pos > totalFuel)
			{
				cout << -1;
				return 0;
			}
			--i;
		}
	}
	cout << count;


	// 연료는 무조건 앞에서 많이 먹을 수 이씅면 좋음
	// 결국 연료는 총 이동거리 이상만 챙기면 돼.
	// 현재 연료로 갈 수 있는 주유소까지 저장해둬.
	// 그 주유소 중 가장 연료를 많이 얻을 수 있는 것 저장.
	// 그 주유소 먹었다고 가정했을 때 어디까지 갈 수 있는지 다시 검색
}