#include <iostream>
#include <vector>
using namespace std;

struct boardInfo
{
	int R;
	int C;
};

struct sharkInfo
{
	int r; // x좌표
	int c; // y좌표
	int s; // 속력
	int d; // 이동 방향(1: 위, 2: 아래, 3: 오른쪽, 4: 왼쪽)
	int z; // 크기
};

struct problemInfo
{
	boardInfo b;
	vector<sharkInfo> s;
};

struct board
{
	vector<sharkInfo> s;
};

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };

/* 격자판 정보 입력 */
void inputBoardInfo(boardInfo& b)
{
	cin >> b.R >> b.C;
}

/* 상어 정보 입력 함수 */
void inputSharkInfo(problemInfo& info, int M)
{
	vector<sharkInfo>& s = info.s;
	boardInfo& b = info.b;
	s.assign(M, { 0,0,0,0,0 });
	int r, c;

	for (int i = 0; i < M; ++i)
	{
		cin >> r >> c >> s[i].s >> s[i].d >> s[i].z;
		s[i].r = r - 1;
		s[i].c = c - 1;

		if (s[i].d <= 2) s[i].s %= (b.R - 1) * 2;
		else s[i].s %= (b.C - 1) * 2;
	}
}

void input(problemInfo& info)
{
	inputBoardInfo(info.b);
	int M;
	cin >> M;
	inputSharkInfo(info, M);
}

/* 해당 칸에 있는 상어 제거 함수 */
int removeShark(vector<vector<board>>& v, int x, int y)
{
	int result = v[x][y].s[0].z;
	v[x][y].s.clear();
	return result;
}

/* 가장 가까운 상어 낚시 함수 */
int fishingNearestShark(vector<vector<board>>& v, int pos)
{
	for (int i = 0; i < int(v.size()); ++i)
	{
		if (v[i][pos].s.empty()) continue;
		return removeShark(v, i, pos);
	}
	return 0;
}

/* 상어 이동 함수 */
void moveShark(vector<vector<board>>& v)
{
	vector<sharkInfo> sharks;
	for (int i = 0; i<int(v.size()); ++i)
	{
		for (int j = 0; j<int(v[i].size()); ++j)
		{
			if (v[i][j].s.empty()) continue;
			sharks.push_back(v[i][j].s[0]);
			v[i][j].s.clear();
		}
	}
	

	int R = int(v.size());
	int C = int(v[0].size());
	for (int i = 0; i<int(sharks.size()); ++i)
	{
		for (int j = 0; j < sharks[i].s; ++j)
		{
			int nx = sharks[i].r + dx[sharks[i].d - 1];
			int ny = sharks[i].c + dy[sharks[i].d - 1];
			if (nx < 0 || ny < 0 || nx >= R || ny >= C)
			{
				if (sharks[i].d % 2 == 0) sharks[i].d -= 1;
				else sharks[i].d += 1;
				nx = sharks[i].r + dx[sharks[i].d - 1];
				ny = sharks[i].c + dy[sharks[i].d - 1];
			}
			sharks[i].r = nx;
			sharks[i].c = ny;
		}
		v[sharks[i].r][sharks[i].c].s.push_back(sharks[i]);
	}
}

/* 하나의 칸에 여러 상어가 겹치는 상어 제거 함수 */
void removeOverlapShark(vector<vector<board>>& v)
{
	for (int i = 0; i<int(v.size()); ++i)
	{
		for (int j = 0; j<int(v[i].size()); ++j)
		{
			if (v[i][j].s.empty()) continue;
			sharkInfo temp = { 0,0,0,0,0 };
			for (int k = 0; k < int(v[i][j].s.size()); ++k)
			{
				if (temp.z < v[i][j].s[k].z)
				{
					temp = v[i][j].s[k];
				}
			}
			v[i][j].s.clear();
			v[i][j].s.push_back(temp);
		}
	}
}

/* 입력 정보 격자 적용 함수 */
void applyBoard(vector<vector<board>>& v, problemInfo& info)
{
	for (int i = 0; i < int(info.s.size()); ++i)
	{
		sharkInfo s = info.s[i];
		v[s.r][s.c].s.push_back(s);
	}
}

int solution()
{
	problemInfo info;
	input(info);
	
	vector<vector<board>> v;
	v.assign(info.b.R, vector<board>(info.b.C, {vector<sharkInfo>()}));
	applyBoard(v, info);

	int fishingKingPos = 0;
	int answer = 0;
	while (fishingKingPos < info.b.C)
	{
		answer += fishingNearestShark(v, fishingKingPos);
		moveShark(v);
		removeOverlapShark(v);
		fishingKingPos += 1;
	}
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << solution();
}