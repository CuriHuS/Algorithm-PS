#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	vector<vector<int>> v(N+1, vector<int>(N+1, 0));

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a][b] = 1;
	}

	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (v[i][k] == 1 && v[k][j] == 1)
				{
					v[i][j] = 1;
				}
			}
		}
	}

	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		bool flag = false;
		for (int j = 1; j <= N; j++)
		{
			if (i == j) continue;
			if (v[i][j] == 0 && v[j][i] == 0)
			{
				//cout << i << ", " << j << "가 없음\n";
				flag = true;
				break;
			}
		}
		if (flag) continue;
		++answer;
	}
	cout << answer;
}