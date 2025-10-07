#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX 1001
vector<int> v[MAX];
int inDegree[MAX];
int buildTime[MAX];
int result[MAX]; // 해당 건물 단계 도착까지 걸리는 최대 시간



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		// 컨테이너 초기화
		for (int i = 0; i < MAX; i++)
		{
			v[i].clear();
			inDegree[i] = 0;
			buildTime[i] = 0;
			result[i] = 0;
		}


		int N, K, W;
		cin >> N >> K;
		for (int i = 1; i <= N; i++)
		{
			cin >> buildTime[i];
		}

		for (int i = 0; i < K; i++)
		{
			int X, Y, D;
			cin >> X >> Y;
			inDegree[Y]++;
			v[X].push_back(Y);
		}

		cin >> W;

		queue<int> q;
		for (int i = 1; i <= N; i++)
		{
			if (inDegree[i] == 0) q.push(i);
		}

		sort(v->begin(), v->end());

		for (int i = 1; i <= N; i++)
		{
			if (q.empty())
			{
				// 사이클 발생
				break;
			}
			int x = q.front();
			q.pop();
			
			//result[i] = x;
			for (int j = 0; j < v[x].size(); j++)
			{
				int y = v[x][j];
				int d = buildTime[x];
				result[y] = max(result[y], result[x] + d);

				if (--inDegree[y] == 0)
					q.push(y);

			}
		}


		cout << result[W] + buildTime[W] << endl;
	}
}