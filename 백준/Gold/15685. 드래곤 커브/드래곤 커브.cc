#include <iostream>
#include <vector>
using namespace std;

struct pos
{
	int y;
	int x;

	pos(int b, int a) : y(b), x(a) {}
};

struct curve
{
	pos start;
	pos end;
	int dir;

	curve(pos s, pos e, int d = 0) : start(s), end(e), dir(d) {}
};

struct dragonCurve
{
	int x;
	int y;
	int d;
	int g;
	vector<curve> history;
	
	// 기본 생성자 추가
	dragonCurve() : x(0), y(0), d(0), g(0) {}  // 기본값으로 초기화

	dragonCurve(int x, int y, int d, int g, vector<curve> h) : x(x), y(y), d(d), g(g), history(h)
	{
	}
};

// 드래곤 커브 입력
vector<dragonCurve> input(int n)
{
	vector<dragonCurve> temp(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> temp[i].x >> temp[i].y >> temp[i].d >> temp[i].g;
	}
	return temp;
}

void drawLine(dragonCurve& dg)
{
	if (dg.d == 0)
	{
		dg.history.push_back({ {dg.y, dg.x}, {dg.y, dg.x+1}, dg.d });
		dg.x += 1;
	}
	else if (dg.d == 1)
	{
		dg.history.push_back({ {dg.y, dg.x}, {dg.y-1, dg.x}, dg.d });
		dg.y -= 1;
	}
	else if (dg.d == 2)
	{
		dg.history.push_back({ {dg.y, dg.x}, {dg.y, dg.x-1}, dg.d });
		dg.x -= 1;
	}
	else if (dg.d == 3)
	{
		dg.history.push_back({ {dg.y, dg.x}, {dg.y+1, dg.x}, dg.d });
		dg.y += 1;
	}
}

void drawGeneration(dragonCurve& dg)
{
	int end = int(dg.history.size()) - 1;
	for (int i = end; i >= 0; --i)
	{
		if (dg.history[i].dir == 3)
		{
			dg.history.push_back({ {dg.y, dg.x}, {dg.y, dg.x+1}, 0 });
			dg.x += 1;
		}
		else if (dg.history[i].dir == 2)
		{
			dg.history.push_back({ {dg.y, dg.x}, {dg.y+1, dg.x}, 3 });
			dg.y += 1;
		}
		else if (dg.history[i].dir == 1)
		{
			dg.history.push_back({ {dg.y, dg.x}, {dg.y, dg.x-1}, 2 });
			dg.x -= 1;
		}
		else if (dg.history[i].dir == 0)
		{
			dg.history.push_back({ {dg.y, dg.x}, {dg.y-1, dg.x}, 1 });
			dg.y -= 1;
		}
	}
}

void draw(dragonCurve& dg)
{
	drawLine(dg);
	for (int i = 1; i <= dg.g; ++i)
	{
		drawGeneration(dg);
	}
}

void applyDragonCurveInGraph(vector<dragonCurve>& dragons)
{
	for (int i = 0; i<int(dragons.size()); ++i)
	{
		draw(dragons[i]);
	}
}

int checkSquareIsDragonCurve(vector<dragonCurve>& dragons)
{
	vector<vector<bool>> graph(101, vector<bool>(101, false));
	for (int i = 0; i<int(dragons.size()); ++i)
	{
		for (int j = 0; j<int(dragons[i].history.size()); ++j)
		{
			graph[dragons[i].history[j].start.y][dragons[i].history[j].start.x] = true;
			graph[dragons[i].history[j].end.y][dragons[i].history[j].end.x] = true;
		}
	}

	int result = 0;
	for (int i = 0; i < 100; ++i)
	{
		for (int j = 0; j < 100; ++j)
		{
			if (graph[i][j] && graph[i + 1][j] && graph[i][j + 1] && graph[i + 1][j + 1])
			{
				result += 1;
			}
		}
	}
	return result;
}

int solution()
{
	int n;
	cin >> n;
	vector<dragonCurve> dragons = input(n);
	applyDragonCurveInGraph(dragons);
	return checkSquareIsDragonCurve(dragons);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << solution();
}