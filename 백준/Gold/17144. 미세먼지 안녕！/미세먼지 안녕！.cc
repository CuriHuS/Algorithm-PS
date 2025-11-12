#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct grid
{
	int x;
	int y;
};

struct dust
{
	grid pos;
	int amount;
};

class airCleaner
{
	int upRow; // 위 행 번호
	int downRow; // 아래 행 번호
	vector<grid> upPath;
	vector<grid> downPath;
public:
	airCleaner(int x, int y)
	{
		this->upRow = x;
		this->downRow = y;
	}

	void setPath(vector<vector<int>>& graph)
	{
		setUpPath(graph);
		setDownPath(graph);
	}

	void setUpPath(vector<vector<int>>& graph)
	{
		this->upPath.clear();
		int x = this->upRow;
		int y;
		for (y = 1; y < (int)graph[x].size(); ++y)
		{
			this->upPath.push_back({ x,y });
		}
		--y;
		for (x-=1; x >= 0; --x)
		{
			this->upPath.push_back({ x,y });
		}
		++x;
		for (y; y >= 0; --y)
		{
			this->upPath.push_back({ x,y });
		}
		++y;
		for (x+=1; x < this->upRow; ++x)
		{
			this->upPath.push_back({ x,y });
		}
	}

	void setDownPath(vector<vector<int>>& graph)
	{
		this->downPath.clear();
		int x = this->downRow;
		int y;
		for (y = 1; y < (int)graph[x].size(); ++y)
		{
			this->downPath.push_back({ x,y });
		}
		--y;
		for (x+=1; x < (int)graph.size(); ++x)
		{
			this->downPath.push_back({ x,y });
		}
		--x;
		for (y; y >= 0; --y)
		{
			this->downPath.push_back({ x,y });
		}
		++y;
		for (x-=1; x > this->downRow; --x)
		{
			this->downPath.push_back({ x,y });
		}
	}
	
	void clean(vector<vector<int>>& graph)
	{
		for (int i = upPath.size()-2; i>=0; --i)
		{
			grid next = upPath[i + 1];
			grid cur = upPath[i];
			graph[next.x][next.y] = graph[cur.x][cur.y];
		}
		graph[upPath[0].x][upPath[0].y] = 0;

		for (int i = downPath.size() - 2; i >= 0; --i)
		{
			grid next = downPath[i + 1];
			grid cur = downPath[i];
			graph[next.x][next.y] = graph[cur.x][cur.y];
		}
		graph[downPath[0].x][downPath[0].y] = 0;
	}
};

void enqueueDust(queue<dust>& q, vector<vector<int>>& graph)
{
	for (int i = 0; i < graph.size(); i++)
	{
		for (int j = 0; j < graph[i].size(); j++)
		{
			if (graph[i][j] <= 0) continue;
			q.push({ {i,j}, graph[i][j] });
		}
	}
}

int calcDust(vector<vector<int>>& graph)
{
	int result = 0;
	for (int i = 0; i < graph.size(); i++)
	{
		for (int j = 0; j < graph[i].size(); j++)
		{
			result += max(0, graph[i][j]);
		}
	}
	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int R, C, T;
	cin >> R >> C >> T;
	vector<vector<int>>v(R, vector<int>(C, 0));
	vector<int> x;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> v[i][j];
			if (v[i][j] == -1)
			{
				x.push_back(i);
			}
		}
	}
	airCleaner air(x[0], x[1]);
	air.setPath(v); // 공기청정기 경로 설정
	
	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };
	
	while (T--)
	{
		// 미세 먼지 확산
		queue<dust> q;
		enqueueDust(q, v);
		while (!q.empty())
		{
			grid pos = q.front().pos;
			int value = q.front().amount;
			q.pop();

			int spread = 0; // 먼지 퍼진 공간 수

			for (int i = 0; i < 4; i++)
			{
				int nx = pos.x + dx[i];
				int ny = pos.y + dy[i];

				if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;

				if (v[nx][ny] == -1) continue;

				v[nx][ny] += value / 5;
				++spread;
			}
			
			v[pos.x][pos.y] -= value / 5 * spread;
			
		}
		
		// 공기청정기 작동
		air.clean(v);
	}
	
	cout << calcDust(v);
}