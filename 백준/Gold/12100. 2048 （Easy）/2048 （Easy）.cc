#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Block
{
	int value;
	bool isMerge;
};

int N;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int answer = 0;

void ResetFlag(vector<vector<Block>>& board)
{
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[i].size(); j++)
		{
			board[i][j].isMerge = false;
		}
	}
}

void moveBlock(vector<vector<Block>>& v, int& x, int& y, int dir)
{
	while (true)
	{
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		// 보드 밖으로 벗어났을 때
		if (nx >= N || nx < 0 || ny >= N || ny < 0) return;

		// 병합 가능할 때
		if ((v[x][y].value == v[nx][ny].value) && !v[x][y].isMerge && !v[nx][ny].isMerge)
		{
			v[nx][ny].value *= 2;
			v[x][y].value = 0;
			v[nx][ny].isMerge = true;
			return;
		}

		// 다른 블록이 존재할 때
		if (v[nx][ny].value != 0) return;

		// 0일 때 이동
		v[nx][ny] = v[x][y];
		v[x][y] = { 0, false };
		x = nx;
		y = ny;
	}
}

int GetMaxBlock(vector<vector<Block>>& board)
{
	int maxValue = 0;
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[i].size(); j++)
		{
			maxValue = max(maxValue, board[i][j].value);
		}
	}
	return maxValue;
}

void BackTracking(vector<vector<Block>> board, int count)
{
	if (count == 5)
	{
		answer = max(answer, GetMaxBlock(board));
		return;
	}

	if (GetMaxBlock(board) * pow(2, 5 - count) <= answer)
	{
		return;
	}


	for (int i = 0; i < 4; i++)
	{
		vector<vector<Block>> temp = board;
		if (i == 1) // 위로 이동
		{
			for (int x = 0; x < N; x++)
			{
				for (int y = 0; y < N; y++)
				{
					if (temp[x][y].value == 0) continue;
					moveBlock(temp, x, y, i);
				}
			}
		}
		else if (i == 0) // 아래로 이동
		{
			for (int x = N - 1; x >= 0; x--)
			{
				for (int y = 0; y < N; y++)
				{
					if (temp[x][y].value == 0) continue;
					moveBlock(temp, x, y, i);
				}
			}
		}
		else if (i == 2) // 오른쪽
		{
			for (int y = N - 1; y >= 0; y--)
			{
				for (int x = 0; x < N; x++)
				{
					if (temp[x][y].value == 0) continue;
					moveBlock(temp, x, y, i);
				}
			}
		}
		else if (i == 3) //왼쪽
		{
			for (int y = 0; y < N; y++)
			{
				for (int x = 0; x < N; x++)
				{
					if (temp[x][y].value == 0) continue;
					moveBlock(temp, x, y, i);
				}
			}
		}
		ResetFlag(temp);
		BackTracking(temp, count + 1);
	}
}



int main()
{
	cin >> N;
	vector<vector<Block>> board;

	for (int i = 0; i < N; i++)
	{
		vector<Block> temp;
		for (int j = 0; j < N; j++)
		{
			int c;
			cin >> c;
			temp.push_back({ c,false });
		}
		board.push_back(temp);
	}
	BackTracking(board, 0);
	cout << answer;
}