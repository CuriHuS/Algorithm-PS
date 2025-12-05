#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

struct favorList
{
	int N;
	vector<pair<int, unordered_set<int>>> v;
};

void input(favorList& fL)
{
	cin >> fL.N;
	int students = fL.N * fL.N;
	for (int i = 0; i < students; i++)
	{
		int num;
		cin >> num;
		fL.v.push_back({ num, unordered_set<int>() });
		for (int j = 0; j < 4; j++)
		{
			int a;
			cin >> a;
			fL.v[i].second.insert(a);
		}
	}
}

pair<int, int> findPos(int num, favorList& f, vector<vector<int>>& map)
{
	pair<int, int> pos = { 0,0 };
	vector<int> posInfo = { -1, -1 };

	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };
	int N = f.N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] != 0) continue;
			int likeAdjacentStudents = 0;
			int freeSpace = 0;
			for (int k = 0; k < 4; k++)
			{
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx < 0 || ny < 0 || nx >= N || ny >= N)
				{
					continue;
				}
				if (map[nx][ny] == 0)
				{
					freeSpace += 1;
				}
				else if (f.v[num].second.find(map[nx][ny]) != f.v[num].second.end())
				{
					likeAdjacentStudents += 1;
				}
			}

			if (likeAdjacentStudents > posInfo[0])
			{
				pos = { i,j };
				posInfo = { likeAdjacentStudents, freeSpace };
				continue;
			}
			else if (likeAdjacentStudents == posInfo[0])
			{
				if (freeSpace > posInfo[1])
				{
					pos = { i,j };
					posInfo = { likeAdjacentStudents, freeSpace };
					continue;
				}
			}
			continue;
		}
	}
	return pos;
}

int findStudentIndexInFavorList(const int num, const favorList& f)
{
	for (int i = 0; i < f.N*f.N; i++)
	{
		if (f.v[i].first == num)
		{
			return i;
		}
	}
}

int calculateSatisfaction(vector<vector<int>>& room, favorList& f)
{
	int result = 0;
	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };
	int N = f.N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int studentNum = room[i][j];
			int student = findStudentIndexInFavorList(studentNum, f);
			int temp = 0;
			for (int k = 0; k < 4; k++)
			{
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx < 0 || ny < 0 || nx >= N || ny >= N)
				{
					continue;
				}
				if (f.v[student].second.find(room[nx][ny]) != f.v[student].second.end())
				{
					temp += 1;
				}
			}

			if (temp == 4) result += 1000;
			else if (temp == 3) result += 100;
			else if (temp == 2) result += 10;
			else if (temp == 1) result += 1;
		}
	}

	return result;
}

int solution()
{
	favorList f;
	input(f);
	int students = f.N * f.N;
	vector<vector<int>> classRoom(f.N, vector<int>(f.N, 0));
	for (int i = 0; i < students; i++)
	{
		pair<int, int> pos = findPos(i, f, classRoom);
		classRoom[pos.first][pos.second] = f.v[i].first;
	}
	return calculateSatisfaction(classRoom, f);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << solution();
}