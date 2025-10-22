#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct star
{
	int x;
	int y;

	bool operator< (const star& a)
	{
		if (x != a.x)
			return x < a.x;
		return y < a.y;
	}
};

int main()
{
	int N, M, L, K;
	cin >> N >> M >> L >> K;

	vector<star> stars;

	for (int i = 0; i < K; i++)
	{
		int a, b;
		cin >> a >> b;
		stars.push_back({ a,b });
	}


	int maxCover = 0;

	for (int i = 0; i < K; i++)
	{
		for (int j = 0; j < K; j++)
		{
			// i,j 번째 별을 기준으로 사각형을 만들자.
			int cnt = 0;
			for (int k = 0; k < K; k++)
			{
				int curX = stars[k].x;
				int curY = stars[k].y;
				if (stars[i].x <= curX && curX <= stars[i].x + L && stars[j].y <= curY && curY <= L+ stars[j].y)
				{
					++cnt;
				}
			}
			maxCover = max(maxCover, cnt);
		}
	}


	cout << K - maxCover;
}