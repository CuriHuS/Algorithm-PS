#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	vector<int> v(N, 0);
	vector<int> ans(N, -1);
	stack<int> st;
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	st.push(v[N - 1]);
	for (int i = N-2; i >= 0; --i)
	{
		// 제일 가까운 우측에서 큰 거.
		if (st.empty())
		{
			st.push(v[i]);
			continue;
		}
		if (st.top() > v[i])
		{
			ans[i] = st.top();
			st.push(v[i]);
			continue;
		}
		
		// 만약에 같거나 작으면, 계속 pop해야지.
		while (!st.empty())
		{
			if (st.top() <= v[i])
			{
				st.pop();
				continue;
			}

			ans[i] = st.top();
			break;
		}
		st.push(v[i]);

	}

	for (int i = 0; i < N; i++)
	{
		cout << ans[i] << " ";
	}
}