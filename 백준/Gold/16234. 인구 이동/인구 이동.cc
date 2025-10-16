#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct country
{
	int population;
	int unionNum;
};

void Input(int& N, int& L, int& R, vector<vector<country>>& A)
{
	cin >> N >> L >> R;
	A.assign(N, vector<country>(N, { 0,0 }));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> A[i][j].population;
		}
	}
}

bool isUnited(country a, country b)
{
	if (a.unionNum == 0 || b.unionNum == 0)
	{
		return false;
	}

	if (a.unionNum != b.unionNum)
	{
		return false;
	}

	return true;
}

// 연합 초기화 함수
void initUnion(vector<vector<country>>& A)
{
	int N = A.size();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			A[i][j].unionNum = 0;
		}
	}
}

void unite(vector<vector<country>>& A, unordered_map<int, vector<pair<int, int>>>& unitedCountries, int origin, int merger)
{
	vector<pair<int, int>> temp = unitedCountries[merger];
	for (int i = 0; i < temp.size(); i++)
	{
		int x = temp[i].first;
		int y = temp[i].second;
		A[x][y].unionNum = origin;
	}
	unitedCountries.erase(merger);
	for (int i = 0; i < temp.size(); i++)
	{
		unitedCountries[origin].push_back(temp[i]);
	}
}


bool bfs(vector<vector<country>>& A, int L, int R)
{
	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };
	int N = A.size();
	vector<vector<bool>> visited(N, vector<bool>(N, false));

	initUnion(A);
	
	int unionCnt = 1;
	unordered_map<int, vector<pair<int, int>>> unitedCountries;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			//if (visited[i][j]) continue;

			visited[i][j] = true;

			for (int k = 0; k < 4; k++)
			{
				int nx = i + dx[k];
				int ny = j + dy[k];

				// 땅 밖을 벗어나는 경우
				if (nx < 0 || nx >= N || ny < 0 || ny >= N)
				{
					continue;
				}

				int populationDiff = abs(A[nx][ny].population - A[i][j].population);

				// 이미 연합이면
				if (isUnited(A[i][j], A[nx][ny]))
				{
					continue;
				}

				// 연합 생성
				if (populationDiff >= L && populationDiff <= R)
				{
					// 나도 이미 연합이 있어.
					if (A[i][j].unionNum != 0)
					{
						// 근데 새로운 왕국은 연합이 없네?
						if (A[nx][ny].unionNum == 0)
						{
							visited[nx][ny] = true;
							A[nx][ny].unionNum = A[i][j].unionNum;
							unitedCountries[A[i][j].unionNum].push_back({ nx, ny });
						}
						else
						{
							// 이 때가 문제인게, 새로운 왕국 및 모든 왕국이 동일한 연합으로 바꿔야 돼.	
							unite(A, unitedCountries, A[i][j].unionNum, A[nx][ny].unionNum);
						}
						continue;
					}

					// 나는 연합이 없는 상태에서
					// 상대도 연합이 없어
					if (A[nx][ny].unionNum == 0)
					{
						visited[nx][ny] = true;
						A[nx][ny].unionNum = unionCnt;
						A[i][j].unionNum = unionCnt;
						unitedCountries[unionCnt].push_back({ nx, ny });
						unitedCountries[unionCnt].push_back({ i,j });
						unionCnt++;
					}
					// 상대는 연합이 있어.
					else
					{
						A[i][j].unionNum = A[nx][ny].unionNum;
						unitedCountries[A[nx][ny].unionNum].push_back({ i,j });
					}
				}
			}

		}
	}

	// 더 이상 교환이 이루어지지 않음
	if (unitedCountries.size() == 0) return false;
	// 인구 계산
	for (auto& units : unitedCountries)
	{

		int sum = 0;
		for (int i = 0; i < units.second.size(); i++)
		{
			int x = units.second[i].first;
			int y = units.second[i].second;
			sum += A[x][y].population;
		}

		int population = sum / units.second.size();
		for (int i = 0; i < units.second.size(); i++)
		{
			int x = units.second[i].first;
			int y = units.second[i].second;
			A[x][y].population = population;
		}
	}
	return true;
}

int solution(int N, int L, int R, vector<vector<country>> A)
{
	int answer = 0;
	while (bfs(A, L, R))
	{
		answer++;
	}
	return answer;
}

int main()
{
	int N, L, R;
	vector<vector<country>> A;
	Input(N, L, R, A);
	int ans = solution(N, L, R, A);
	cout << ans;

}