#include <iostream>
#include <vector>
using namespace std;

struct presidentCandidateData
{
	int presidentCandidateScore;
	int presidentCandidateNumbers;
	vector<int> presidentCandidate;
};

void output(presidentCandidateData& pd)
{
	cout << pd.presidentCandidateScore << " " << pd.presidentCandidateNumbers << '\n';
	for (int i = 0; i<int(pd.presidentCandidate.size()); i++)
	{
		cout << pd.presidentCandidate[i] << " ";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	int graph[51][51] = {};
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
			{
				graph[i][j] = 1;
				continue;
			}
			graph[i][j] = 500;
		}
	}
	
	while (true)
	{
		int a, b;
		cin >> a >> b;
		if (a == -1 && b == -1) break;

		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				graph[i][j] = min(graph[i][k] + graph[k][j], graph[i][j]);
			}
		}
	}


	presidentCandidateData pd;
	
	vector<int> members(n + 1, 1);
	int minScore = 100;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			members[i] = max(members[i], graph[i][j]);
		}
		minScore = min(minScore, members[i]);
	}

	pd.presidentCandidateScore = minScore;
	pd.presidentCandidateNumbers = 0;

	for (int i = 1; i <= n; i++)
	{
		if (minScore == members[i])
		{
			pd.presidentCandidateNumbers += 1;
			pd.presidentCandidate.push_back(i);
		}
	}

	output(pd);
	return 0;
}