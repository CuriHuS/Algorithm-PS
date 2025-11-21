#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

struct inputData
{
	int N;
	int M;
	vector<vector<int>> v;
};

struct point
{
	int x;
	int y;
};

inputData input()
{
	inputData temp;
	cin >> temp.N >> temp.M;
	temp.v.assign(temp.N, vector<int>(temp.M, 0));
	for (int i = 0; i < temp.N; i++)
	{
		for (int j = 0; j < temp.M; j++)
		{
			cin >> temp.v[i][j];
		}
	}
	return temp;
}

void melt(vector<vector<int>>& v)
{
	vector<vector<int>> meltAmount = v;
	for (int i = 1; i < v.size() - 1; i++)
	{
		for (int j = 1; j < v[0].size() - 1; j++)
		{
			meltAmount[i][j] = 0;
		}
	}

	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };
	for (int i = 1; i < v.size()-1; i++)
	{
		for (int j = 1; j < v[0].size()-1; j++)
		{
			if (v[i][j] == 0) continue;
			for (int k = 0; k < 4; k++)
			{
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (v[nx][ny] != 0) continue;
				meltAmount[i][j] += 1;
			}
		}
	}

	for (int i = 1; i < v.size() - 1; i++)
	{
		for (int j = 1; j < v[0].size() - 1; j++)
		{
			v[i][j] = max(0, v[i][j] - meltAmount[i][j]);
		}
	}
}

bool isAllMelt(vector<vector<int>>& v)
{
	for (int i = 1; i < v.size()-1; i++)
	{
		for (int j = 1; j < v[0].size()-1; j++)
		{
			if (v[i][j] != 0) return false;
		}
	}
	return true;
}

bool dfs(vector<vector<int>>& v, point p)
{
	if (p.x < 0 || p.x >= v.size() || p.y < 0 || p.y >= v[0].size())
		return false;
	if (v[p.x][p.y] != 0)
	{
		v[p.x][p.y] = 0;
		dfs(v, { p.x + 1, p.y });
		dfs(v, { p.x - 1, p.y });
		dfs(v, { p.x, p.y + 1 });
		dfs(v, { p.x, p.y - 1 });
		return true;
	}
	return false;
}

int solution()
{
	inputData inputs = input();
	vector<vector<int>> v = inputs.v;
	int time = 0;
	queue<point> q;
	while (!isAllMelt(v))
	{
		int count = 0;
		vector<vector<int>> temp = v;
		for (int i = 1; i < v.size()-1; i++)
		{
			for (int j = 1; j < v[0].size()-1; j++)
			{
				if (dfs(temp, { i,j }))
				{
					count += 1;
				}
			}
		}
		if (count > 1)
		{
			return time;
		}
		++time;
		melt(v);
	}

	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << solution();
}