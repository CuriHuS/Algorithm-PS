#include <iostream>
using namespace std;

char graph[21][21];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int R, C;
int answer;

void dfs(int x, int y, bool* visited, int& cnt, int step)
{
	if (visited[graph[x][y] - 'A'])
	{
		cnt = max(cnt, step);
		return;
	}
	visited[graph[x][y] - 'A'] = true;
	step++;
	for (int i = 0; i < 4; i++)
	{
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		if (nx > 0 && nx <= R && ny > 0 && ny <= C)
		{
			dfs(nx, ny, visited, cnt, step);
		}
	}
	step--;
	visited[graph[x][y] - 'A'] = false;
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> R >> C;

	bool visited[26];
	for (int i = 0; i < 26; i++)
	{
		visited[i] = false;
	}

	for (int i = 0; i < 21; i++)
	{
		for (int j = 0; j < 21; j++) graph[i][j] = 0;
	}

	string s;
	for (int i = 1; i <= R; i++)
	{
		cin >> s;
		for (int j = 1; j <= C; j++)
		{
			graph[i][j] = s[j-1];
		}
	}

	int answer = 0;
	dfs(1, 1, visited, answer, 0);
	if (answer == 0) answer = 1;
	cout << answer;
}