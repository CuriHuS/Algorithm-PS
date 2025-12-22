#include <iostream>
#include <vector>
#include <deque>
using namespace std;

struct tree
{
	int age;
};

struct treeInfo
{
	int x;
	int y;
	int z;
}; 

struct ground
{
	int nutrient;
	deque<tree> trees;
	deque<tree> deadTrees;
};

struct inputInfo
{
	int N;
	int M;
	int K;
	vector<vector<int>> A;
	vector<treeInfo> trees;
};

inputInfo input()
{
	inputInfo temp;
	cin >> temp.N >> temp.M >> temp.K;
	temp.A.assign(temp.N, vector<int>(temp.N, 0));
	for (int i = 0; i < temp.N; ++i)
	{
		for (int j = 0; j < temp.N; ++j)
		{
			cin >> temp.A[i][j];
		}

	}
	for (int i = 0; i < temp.M; ++i)
	{
		int x, y, z;
		temp.trees.push_back({ 0,0,0 });
		cin >> x >> y >> temp.trees[i].z;
		temp.trees[i].x = x - 1;
		temp.trees[i].y = y - 1;
	}
	return temp;
}

void plantTrees(vector<vector<ground>>& g, vector<treeInfo>& info)
{
	for (const treeInfo& i : info)
	{
		g[i.x][i.y].trees.push_back({ i.z });
	}
}

void doSpring(vector<vector<ground>>& g)
{
	for (int i = 0; i<int(g.size()); ++i)
	{
		for (int j = 0; j<int(g.size()); ++j)
		{
			if (g[i][j].trees.empty()) continue;

			deque<tree> temp;
			while (!g[i][j].trees.empty())
			{
				tree youngTree = g[i][j].trees.front();
				// 나무가 영양분이 먹을 수 없는 경우
				if (youngTree.age > g[i][j].nutrient)
				{
					break;
				}
				g[i][j].nutrient -= youngTree.age;
				youngTree.age += 1;
				temp.push_back(youngTree);
				g[i][j].trees.pop_front();
			}
			g[i][j].deadTrees = g[i][j].trees;
			g[i][j].trees = temp;
		}
	}
}

void doSummer(vector<vector<ground>>& g)
{
	for (int i = 0; i<int(g.size()); ++i)
	{
		for (int j = 0; j<int(g.size()); ++j)
		{
			while (!g[i][j].deadTrees.empty())
			{
				tree temp = g[i][j].deadTrees.front();
				g[i][j].nutrient += temp.age / 2;
				g[i][j].deadTrees.pop_front();
			}
		}
	}
}

int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };

void doFall(vector<vector<ground>>& g)
{
	int N = int(g.size());
	vector<vector<ground>> temp = g;
	for (int i = 0; i<N; ++i)
	{
		for (int j = 0; j<N; ++j)
		{
			for (const tree& t : g[i][j].trees)
			{
				if (t.age % 5 != 0) continue;
				for (int k = 0; k < 8; ++k)
				{
					int nx = dx[k] + i;
					int ny = dy[k] + j;
					if (nx < 0 || ny < 0 || nx >= N || ny >= N)
					{
						continue;
					}
					tree newTree = { 1 };
					temp[nx][ny].trees.push_front(newTree);
				}
			}
		}
	}
	g = temp;
}

void doWinter(vector<vector<ground>>& g, vector<vector<int>> A)
{
	int N = int(g.size());
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			g[i][j].nutrient += A[i][j];
		}
	}
}

int getAliveTreeCount(vector<vector<ground>>& g)
{
	int result = 0;
	int N = int(g.size());
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			result += int(g[i][j].trees.size());
		}
	}
	return result;
}

int solution()
{
	inputInfo info = input();
	vector<vector<ground>> g(info.N, vector<ground>(info.N, { 5,deque<tree>(), deque<tree>()}));
	plantTrees(g, info.trees);
	while (info.K--)
	{
		doSpring(g);
		doSummer(g);
		doFall(g);
		doWinter(g, info.A);
	}
	return getAliveTreeCount(g);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << solution();
}