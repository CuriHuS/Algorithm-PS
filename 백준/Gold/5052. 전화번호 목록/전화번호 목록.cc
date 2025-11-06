#include <iostream>

using namespace std;

struct Trie
{
	bool finish; // 끝나는 지점 표시
	Trie* node[26]; // 26가지 알파벳에 대한 트라이

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
			{
				delete node[i];
			}
		}
	}

	// insert 함수가 false를 반환하면 일관성 깨짐
	bool insert(const char* str)
	{
		if (*str == '\0')
		{
			finish = true;
			
			// 만약 현재 노드 밑에 다른 번호가 이어진다면 -> 현재 번호가 접두어
			for (int i = 0; i < 10; i++)
			{
				if (node[i] != nullptr)
				{
					return false;
				}
			}
			return true;
		}
		else
		{
			int cur = *str - '0';
			if (finish)
			{
				return false; // 이전 번호가 현재 번호의 접두어이다.
			}

			if (node[cur] == nullptr)
			{
				node[cur] = new Trie(); // 탐색이 처음되는 지점일 경우 동적 할당
			}

			return node[cur]->insert(str + 1); // 다음 문자 삽입
		}
	}

	Trie* find(const char* str)
	{
		if (*str == '\0')
		{
			return this; // 문자열이 끝나는 위치 반환
		}
		int cur = *str - '0';
		if (node[cur] == nullptr) // 찾는 값이 존재하지 않음
		{
			return nullptr;
		}
		return node[cur]->find(str + 1); // 다음 문자 탐색
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	
	int n;
	while (t--)
	{
		cin >> n;
		Trie trie;
		bool flag = true;

		for (int i = 0; i < n; i++)
		{
			string s;
			cin >> s;
			if (!trie.insert(s.c_str()))
			{
				flag = false;
			}
		}

		cout << (flag ? "YES" : "NO") << "\n";
	}
}