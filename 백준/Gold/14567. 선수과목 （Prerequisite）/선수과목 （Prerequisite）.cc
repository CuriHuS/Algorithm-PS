#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> subjects[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, M;
	cin >> N >> M;

	vector<int> inDegree(N + 1, 0);
	vector<int> result(N + 1, 0);


	for (int i = 0; i < M; ++i)
	{
		int A, B;
		cin >> A >> B;
		subjects[A].push_back(B);
		++inDegree[B];
	}

	queue<pair<int, int>> q;
	for (int i = 1; i <= N; i++)
	{
		if (inDegree[i] == 0)
		{
			q.push({ i, 1 });
		}
	}

	for (int i = 1; i <= N; i++)
	{
		if (q.empty())
		{
			break;
		}

		int x = q.front().first;
		int semester = q.front().second;
		result[x] = semester;
		q.pop();

		for (int j = 0; j < subjects[x].size(); j++)
		{
			int y = subjects[x][j];
			if (--inDegree[y] == 0)
			{
				q.push({y, semester+1});
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		cout << result[i] << " ";
	}
}