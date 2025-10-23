#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N,a,b;
	cin >> N >> a >> b;
	
	// a, b개가주어짐
	// 제일 높은 건물 높이는 k임.
	// N개의 건물들이 주어지며
	// k를 기준으로 안보이면 무조건 1 출력?
	// N - (a+b-1)개 / a개 / (b-1)개.
	// a+b-1 <= N개
	// N-(a+b-1) = 2개를 1만큼 높이로 하면 된다.

	if (a + b - 1 > N)
	{
		cout << -1;
		return 0;
	}
	int front = N - (a + b - 1);
	vector<int> buildings(N, 1);

	if (a != 1)
	{
		for (int i = front + 1; i < front + a; i++)
		{
			buildings[i] = buildings[i - 1] + 1;
		}
	}
	if (b > 1) buildings[N - 1] = 1;
	for (int i = 1; i < b - 1; i++)
	{
		buildings[N - 1 - i] = buildings[N - i] + 1;
	}

	if (a < b)
	{
		if (a == 1)
		{
			buildings[0] = b;
			if (front + a-1 > 0)
				buildings[front + a - 1] = 1;
		}
		else
		{
			buildings[N - b] = b;
		}
	}
	
	for (int i = 0; i < N; i++)
	{
		cout << buildings[i] << " ";
	}
}