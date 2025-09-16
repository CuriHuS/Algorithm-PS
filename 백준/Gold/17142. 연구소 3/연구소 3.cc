#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;
//nx,ny 오타로 2시간 걸림

enum ObjType
{
	blank = 0,
	wall = 1,
	virus = 2,
	activeVirus = 3,
	visited = 4
};

struct block
{
	ObjType type;
	int time;
};

int N, M;
vector<vector<block>> graph;
vector<pair<int, int>> viruses;
int answer = 99999;
bool flag = true;

void print(vector<vector<block>> v)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << v[i][j].time << " ";
		}
		cout << endl;
	}
}

int bfs(vector<vector<block>> v, vector<int> virusNums)
{
	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };

	queue<pair<int, int>> q;
	for (int i = 0; i < virusNums.size(); i++)
	{
		int idx = virusNums[i];
		q.push({ viruses[idx] });

		//cout << idx << " ";
		v[viruses[idx].first][viruses[idx].second].type = activeVirus;
	}
	//cout << endl;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

			if (v[nx][ny].type == ObjType::blank)
			{
				v[nx][ny].time = v[x][y].time + 1;
				q.push({ nx, ny });
				v[nx][ny].type = ObjType::visited;
			}
			else if (v[nx][ny].type == ObjType::virus)
			{
				v[nx][ny].type = ObjType::activeVirus;
				v[nx][ny].time = v[x][y].time + 1;
				q.push({ nx, ny });
			}
		}
	}

	int maxTime = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (v[i][j].type == ObjType::blank)
			{
				return 99999;
			}
			else if (v[i][j].type == ObjType::visited)
			{
				maxTime = max(maxTime, v[i][j].time);
			}

		}
	}
	//cout << maxTime << endl;
	//print(v);
	return maxTime;
}

// 0 ~ n-1까지 수 중 m개를 고른다.
void combi(int n, int m, vector<int> arr, int visited[], int cnt)
{
	if (cnt == m)
	{
		answer = min(answer, bfs(graph, arr));
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (visited[i] == 0)
		{
			if (cnt > 0 && arr[cnt - 1] > i) continue;
			visited[i] = 1;
			arr.push_back(i);
			combi(n, m, arr, visited, cnt + 1);
			arr.erase(arr.end() - 1);
			visited[i] = 0;
		}
	}
	return;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		vector<block> temp;
		for (int j = 0; j < N; j++)
		{
			int a;
			cin >> a;
			if (a == 2)
			{
				viruses.push_back({ i, j });
			}
			temp.push_back({ (ObjType)a, 0 });
		}
		graph.push_back(temp);
	}

	int visited[10] = {};
	vector<int> nums;
	combi(viruses.size(), M, nums, visited, 0);
	if (answer == 99999) cout << -1;
	else	cout << answer;
}