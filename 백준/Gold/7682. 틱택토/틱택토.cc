#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (true)
	{
		string s;
		cin >> s;

		if (s == "end") break;

		vector<vector<char>> v;
		for (int i = 0; i < 3; i++)
		{
			vector<char> temp;
			for (int j = 0; j < 3; j++)
			{
				temp.push_back(s[i * 3 + j]);
			}
			v.push_back(temp);
		}

		// O가 더 많은지 체크

		int cntO = 0;
		int cntX = 0;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (v[i][j] == 'O') cntO++;
				else if (v[i][j] == 'X') cntX++;
			}
		}

		if (cntX > cntO + 1)
		{
			cout << "invalid" << endl;
			continue;
		}

		if (cntO > cntX)
		{
			cout << "invalid" << endl;
			continue;
		}

		int X3[3] = { 0,0,0 };
		int O3[3] = { 0,0,0 };

		// 가로, 세로 확인
		for (int i = 0; i < 3; i++)
		{
			int sumH = 0; // 가로
			int sumV = 0; // 세로
			for (int j = 0; j < 3; j++)
			{
				sumH += v[i][j];
				sumV += v[j][i];
			}

			if (sumH == 3 * 'O' || sumH == 3 * 'X')
			{
				if (v[i][0] == 'O') O3[0] ++;
				else X3[0] ++;
			}
			if (sumV == 3 * 'O' || sumV == 3 * 'X')
			{
				if (v[0][i] == 'O') O3[1] ++;
				else X3[1] ++;
			}
		}
		
		// 대각선 확인
		if (v[0][0] == v[1][1] && v[1][1] == v[2][2])
		{
			if (v[0][0] == 'O')
			{
				O3[2] += 1;
			}

			else if (v[0][0] == 'X')
			{
				X3[2] += 1;
			}
		}

		if (v[2][0] == v[1][1] && v[1][1] == v[0][2])
		{
			if (v[1][1] == 'O')
			{
				O3[2] += 1;
			}

			else if (v[1][1] == 'X')
			{
				X3[2] += 1;
			}
		}
		int Xsum = 0;
		int Osum = 0;

		for (int i = 0; i < 3; i++)
		{
			Xsum += X3[i];
			Osum += O3[i];
		}

		if (Xsum + Osum == 1)
		{
			if (cntX == cntO && Xsum == 1)
			{
				cout << "invalid" << endl;
				continue;
			}
			if (cntX > cntO && Osum == 1)
			{
				cout << "invalid" << endl;
				continue;
			}
			cout << "valid" << endl;
			continue;
		}

		if (Xsum >= 1 && Osum >= 1)
		{
			cout << "invalid" << endl;
			continue;
		}

		if (Xsum > 1)
		{
			bool flag = false;
			for (int i = 0; i < 2; i++)
			{
				if (X3[i] >= 2)
				{
					cout << "invalid" << endl;
					flag = true;
					break;
				}
			}
			if (flag) continue;
			if (Xsum == 2)
			{
				cout << "valid" << endl;
				continue;
			}
		}

		else if (Osum >= 1)
		{
			bool flag = false;
			for (int i = 0; i < 2; i++)
			{
				if (O3[i] >= 2)
				{
					cout << "invalid" << endl;
					flag = true;
					break;
				}
			}
			if (flag) continue;
			if (Osum == 2)
			{
				cout << "valid" << endl;
				continue;
			}
		}

		int cntNone = 0;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (v[i][j] == '.')
				{
					cntNone++;
				}
			}
		}
		if (cntNone == 0) cout << "valid" << endl;
		else cout << "invalid" << endl;
	}
}