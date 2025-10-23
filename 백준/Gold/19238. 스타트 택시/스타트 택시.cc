#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

struct point
{
	int x; // row
	int y; // col

	bool operator< (const point& other)
	{
		if (x != other.x)
			return x < other.x;
		return y < other.y;
	}

	bool operator== (const point& other)
	{
		return x == other.x && y == other.y;
	}
};

struct passenger
{
	point start;
	point end;

	bool operator< (const passenger& other)
	{
		return start < other.start;
	}
};

// 택시에게 승객에 대한 정보 제공
struct passInfo
{
	int index; // 배열 내 인덱스 위치
	int dist; // 이동 거리
};

struct taxi
{
	point pos;
	int fuel;
};

// 승객에 대해 최소 거리 측정 -> point로 바꿔서 재사용
int calculateMinDistance(vector<vector<int>> graph, point target, point cur)
{
	// 만약 승객과 택시가 같은 위치라면..?
	if (cur == target)
	{
		return 0;
	}

	// 방문 지점 체크 리스트
	vector<vector<bool>> visited(graph.size(), vector<bool>(graph.size(), false));

	queue<point> q; //방문 큐
	q.push(cur); //현재 위치 기준
	visited[cur.x][cur.y] = true;

	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			// 이동 예정인 좌표가 그래프 밖이거나 벽이거나 방문했을 때 
			if (nx < 0 || ny < 0 || nx >= graph.size() || ny>=graph.size())
			{
				continue;
			}

			if (graph[nx][ny] == INT_MAX || visited[nx][ny])
			{
				continue;
			}

			visited[nx][ny] = true;
			graph[nx][ny] = graph[x][y] + 1;

			// 승객 위치에 도달하면 즉시 종료
			// bfs이므로 도착 즉시 최단 거리임
			if (nx == target.x && ny == target.y)
			{
				return graph[nx][ny];
			}

			q.push({ nx, ny });
		}
	}
	return -1;
}

// 다음 손님 얻는 함수(다음 손님의 손님 벡터 내 인덱스로 주어짐)
passInfo getPassenger(vector<vector<int>> graph, vector<passenger>& pass, taxi& baekjoon)
{
	int minDist = INT_MAX;
	int minPassengerIndex = pass.size();	
	passInfo temp = { minDist, minPassengerIndex };

	for (int i = 0; i < pass.size(); i++)
	{
		int dist = calculateMinDistance(graph, pass[i].start, baekjoon.pos);

		// 도착 불가 판정
		if (dist == -1)
		{
			temp.dist = -1;
			return temp;
		}

		if (dist < minDist)
		{
			minDist = dist;
			minPassengerIndex = i;
		}
	}

	temp.dist = minDist;
	temp.index = minPassengerIndex;

	return temp;
}

int solution(int& N, int& M, vector<vector<int>>& graph, taxi& bj, vector<passenger>& pass)
{
	sort(pass.begin(), pass.end());

	// 택시 기사 로직
	// 가장 가까운 승객 탐색
	while (!pass.empty())
	{
		passInfo info = getPassenger(graph, pass, bj);
		if (info.dist == -1 || info.index == pass.size())
		{
			// 도착 불가 판정
			return -1;
		}
		passenger target = pass[info.index];

		pass.erase(pass.begin() + info.index);

		// 해당 승객까지 이동 (만약 연료 부족시 즉시 종료)
		if (bj.fuel < info.dist)
		{
			return -1;
		}

		bj.pos = target.start;
		bj.fuel -= info.dist;

		// 승객에서 도착지까지 이동(만약 연료 부족시 즉시 종료)
		int dist = calculateMinDistance(graph, target.end, bj.pos);
		if (bj.fuel < dist)
		{
			return -1;
		}

		bj.pos = target.end;
		bj.fuel += dist;
	}

	return bj.fuel;
}

void input(int& N, int& M, vector<vector<int>>& graph, taxi& bj, vector<passenger>& pass)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> bj.fuel;

	graph.assign(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> graph[i][j];
			if (graph[i][j] == 1)
			{
				graph[i][j] = INT_MAX; // 벽 처리
			}
		}
	}

	cin >> bj.pos.x >> bj.pos.y;
	bj.pos.x--; bj.pos.y--;
	for (int i = 0; i < M; i++)
	{
		passenger a;
		cin >> a.start.x >> a.start.y >> a.end.x >> a.end.y;
		a.start.x--; a.start.y--; a.end.x--; a.end.y--;
		pass.push_back(a);
	}
}

int main()
{
	int N, M;
	vector<vector<int>> graph;
	vector<passenger> pass;

	taxi baekjoon = { {0,0}, 0 };

	input(N, M, graph, baekjoon, pass);

	cout << solution(N, M, graph, baekjoon, pass);
}