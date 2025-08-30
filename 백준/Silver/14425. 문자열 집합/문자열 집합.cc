#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	map<string, int> m;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		m[s] = 1;
	}

	int answer = 0;

	for (int i = 0; i < M; i++)
	{
		string s;
		cin >> s;
		if (m.find(s) != m.end())
		{
			answer++;
		}
	}
	cout << answer;
}