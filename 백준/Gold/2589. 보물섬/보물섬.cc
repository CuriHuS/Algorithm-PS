#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int bfs(vector<vector<char>>& v, int x, int y)
{
	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };
	int row = (int)v.size();
	int col = (int)v[0].size();
	vector<vector<int>> dist(row, vector<int>(col, 0));
	vector<vector<bool>>visited(row, vector<bool>(col, false));
	queue<pair<int, int>> q;
	q.push({ x,y });
	int maxDist = 0;
	dist[x][y] = 0;
	visited[x][y] = true;

	while (!q.empty())
	{
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();
		visited[curX][curY] = true;

		for (int i = 0; i < 4; i++)
		{
			int nx = curX + dx[i];
			int ny = curY + dy[i];

			if (nx < 0 || nx >= row || ny < 0 || ny >= col) continue;

			if (visited[nx][ny]) continue;

			if (v[nx][ny] == 'W') continue;

			visited[nx][ny] = true;
			dist[nx][ny] = dist[curX][curY] + 1;

			if (dist[nx][ny] > maxDist)
			{
				maxDist = dist[nx][ny];
			}

			q.push({ nx, ny });
		}
	}
	return maxDist;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	vector<vector<char>> v(N, vector<char>(M, '.'));

	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); j++)
		{
			v[i][j] = s[j];
			if (s[j] == 'L')
				q.push({ i,j });
		}
	}

	int answer = 0;
	while (!q.empty())
	{
		answer = max(answer, bfs(v, q.front().first, q.front().second));
		q.pop();
	}
	cout << answer;
}