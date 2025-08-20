#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Jewelry
{
	int weight;
	int price;

	bool operator<(const Jewelry &other) const
	{
		if (weight == other.weight)
			return price > other.price;
		return weight < other.weight;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, K;
	cin >> N >> K;

	priority_queue<int> bag;
	vector<Jewelry> jewelrys;

	priority_queue<int> pq;

	for (int i = 0; i < N; i++)
	{
		int m, v;
		cin >> m >> v;
		jewelrys.push_back({m, v});
	}
	sort(jewelrys.begin(), jewelrys.end());
	for (int i = 0; i < K; i++)
	{
		int c;
		cin >> c;
		bag.push(-c);
	}

	long long result = 0;
	int idx = 0;

	while(!bag.empty())
	{
		int weight = -bag.top();
		for (int i = idx; i < N; i++)
		{
			if (weight >= jewelrys[i].weight)
			{
				pq.push(jewelrys[i].price);
				idx++;
			}
			else
			{
				break;
			}
		}

		if (!pq.empty())
		{
			result += pq.top();
			pq.pop();
		}

		bag.pop();
	}

	cout << result;
}