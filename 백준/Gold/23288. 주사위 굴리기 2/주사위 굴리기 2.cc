#include <iostream>
#include <vector>

using namespace std;

struct dice
{
	int x;
	int y;
	vector<int> value; // 1: 위쪽 값, 2: 북쪽 이동 시의 값, 3: 동쪽 이동시의 값, 4: 서쪽 이동 시의 값, 5: 남쪽 이동시의 값, 6: 아래쪽 값
	// 0은 임시 값 저장
	dice()
	{
		this->x = 0;
		this->y = 0;
		this->value = vector<int>(7, 0);
		for (int i = 0; i < 7; i++)
		{
			this->value[i] = i;
		}
	}
};

enum direct
{
	EAST = 0,
	SOUTH = 1,
	WEST = 2,
	NORTH = 3
};

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

// 주사위가 굴러갈 때 bottom 값 변환
void changeValue(dice& d, direct dir)
{
	// 동쪽으로 이동시.
	if (dir == EAST)
	{
		d.value[0] = d.value[6]; // 임시 값 저장
		d.value[6] = d.value[3];
		d.value[3] = d.value[1];
		d.value[1] = d.value[4];
		d.value[4] = d.value[0];
	}
	else if (dir == SOUTH)
	{
		d.value[0] = d.value[6];
		d.value[6] = d.value[5];
		d.value[5] = d.value[1];
		d.value[1] = d.value[2];
		d.value[2] = d.value[0];
	}
	else if (dir == WEST)
	{
		d.value[0] = d.value[6];
		d.value[6] = d.value[4];
		d.value[4] = d.value[1];
		d.value[1] = d.value[3];
		d.value[3] = d.value[0];
	}
	else if (dir == NORTH)
	{
		d.value[0] = d.value[6];
		d.value[6] = d.value[2];
		d.value[2] = d.value[1];
		d.value[1] = d.value[5];
		d.value[5] = d.value[0];
	}
}

// 이동 방향 검사(칸 없는지)
bool canMove(vector<vector<int>>& graph, dice& d, direct dir)
{
	int nx = d.x + dx[dir];
	int ny = d.y + dy[dir];

	if (nx < 0 || nx >= graph.size() || ny < 0 || ny >= graph[0].size())
		return false;
	return true;
}

void canContinuousMove(vector<vector<int>>& graph, int x, int y, int value, int& count, vector<vector<bool>>& visited)
{
	visited[x][y] = true;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= graph.size() || ny < 0 || ny >= graph[0].size())
		{
			continue;
		}
		// 해당 칸에서 움직일 수 있으면 다음 칸도 확인한다.
		if (!visited[nx][ny] && graph[nx][ny] == value)
		{
			++count;
			visited[nx][ny] = true;
			//cout << i << "연속 이동 가능: " << nx << "," << ny << "\n";
			canContinuousMove(graph, nx, ny, value, count, visited);
		}
	}
}

int getContinuousMoveCount(vector<vector<int>>& graph, dice& d)
{
	int count = 1; // 자기 자리는 무조건 가능
	vector<vector<bool>> visited(graph.size(), vector<bool>(graph[0].size(), false));

	canContinuousMove(graph, d.x, d.y, graph[d.x][d.y], count, visited);
	
	return count;
}

// 이동 하기(좌표 이동)
void move(dice& d, direct dir)
{
	d.x = d.x + dx[dir];
	d.y = d.y + dy[dir];
}

// 이동 방향 결정
void decideDirect(vector<vector<int>>& graph, dice& d, direct& curDir)
{
	if (graph[d.x][d.y] < d.value[6])
	{
		curDir = (direct)((curDir + 1) % 4);
		return;
	}
	if (graph[d.x][d.y] > d.value[6])
	{
		curDir = (direct)((curDir + 3) % 4);
		return;
	}
}

// 점수 획득
int getPoint(vector<vector<int>>& graph, dice& d)
{
	int canMoveCount = 0;
	for (int i = 0; i < 4; i++)
	{
		canMoveCount = getContinuousMoveCount(graph, d);
	}
	return graph[d.x][d.y] * canMoveCount;
}

// 시뮬레이션 함수
int rollTheDice(vector<vector<int>>& graph, int count)
{
	int point = 0;
	dice d;
	direct dir = EAST;
	while (count--)
	{
		if (!canMove(graph, d, dir))
		{
			dir = (direct)((dir + 2) % 4);
		}
		move(d, dir);
		changeValue(d, dir);
		point += getPoint(graph, d);

		decideDirect(graph, d, dir);
	}

	return point;
}



int main()
{
	int N, M, K;
	cin >> N >> M >> K;

	vector<vector<int>> v(N, vector<int>(M, 0));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> v[i][j];
		}
	}

	cout << rollTheDice(v, K);

}