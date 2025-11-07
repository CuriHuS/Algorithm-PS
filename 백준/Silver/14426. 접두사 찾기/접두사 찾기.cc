#include <iostream>

using namespace std;

class Trie
{
	bool finish;
	Trie* node[26];
public:
	Trie() : finish(false)
	{
		for (int i = 0; i < 26; i++)
		{
			node[i] = nullptr;
		}
	}

	~Trie()
	{
		for (int i = 0; i < 26; i++)
		{
			if (node[i])
				delete node[i];
		}
	}

	void insert(const char* str)
	{
		if (*str == '\0')
		{
			finish = true;
		}
		else
		{
			int cur = *str - 'a';

			if (node[cur] == nullptr)
			{
				node[cur] = new Trie();
			}
			node[cur]->insert(str + 1);
		}
	}

	bool find(const char* str)
	{
		if (*str == '\0')
		{
			if (finish)
			{
				return true;
			}
			for (int i = 0; i < 26; i++)
			{
				if (node[i] != nullptr)
				{
					return true;
				}
			}
			return false;
		}

		int cur = *str - 'a';
		if (node[cur] == nullptr)
		{
			return false;
		}
		return node[cur]->find(str + 1);
	}
	
};


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int N, M;
	cin >> N >> M;
	Trie root;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		root.insert(s.c_str());
	}

	int answer = 0;
	for (int i = 0; i < M; i++)
	{
		string s;
		cin >> s;
		if (root.find(s.c_str()))
		{
			answer += 1;
		}
	}
	cout << answer;
}