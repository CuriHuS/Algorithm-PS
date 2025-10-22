#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct building
{
	int height;
	int nums;
};

struct answer
{
	int count;
	int distance;
	int num;
};


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	vector<building> buildings(N, { 0,0 });
	for (int i = 0; i < N; i++)
	{
		cin >> buildings[i].height;
		buildings[i].nums = i + 1;
	}
	vector<answer> ans(N, { 0,N+1, N+1 });

	stack<building> front;
	front.push(buildings[0]);
	for (int i = 1; i < N; i++)
	{
		while (!front.empty() && buildings[i].height >= front.top().height)
		{
			front.pop();
		}
		if (front.empty()) front.push(buildings[i]);
		else
		{
			ans[i].count += front.size();

			int topDist = abs(i+1 - front.top().nums);

			if (ans[i].distance > topDist)
			{
				ans[i].distance = topDist;
				ans[i].num = front.top().nums;
			}

			else if (ans[i].distance == topDist)
			{
				ans[i].num = min(ans[i].num, front.top().nums);
			}

			if (front.top().height > buildings[i].height)
			{
				front.push(buildings[i]);
			}
		}
	}

	stack<building> back;
	back.push(buildings[N - 1]);
	for (int i = N-2; i >=0; i--)
	{
		while (!back.empty() && buildings[i].height >= back.top().height)
		{
			back.pop();
		}

		if (back.empty()) back.push(buildings[i]);
		else
		{
			ans[i].count += back.size();

			int topDist = abs(i+1-back.top().nums);

			if (ans[i].distance > topDist)
			{
				ans[i].distance = topDist;
				ans[i].num = back.top().nums;
			}

			else if (ans[i].distance == topDist)
			{
				ans[i].num = min(ans[i].num, back.top().nums);
			}
			if (back.top().height > buildings[i].height)
			{
				back.push(buildings[i]);
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		if (ans[i].count == 0)
		{
			cout << 0 << "\n";
		}
		else
		{
			cout << ans[i].count << " " << ans[i].num << "\n";
		}
	}

}