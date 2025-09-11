#include <iostream>
#include <vector>

using namespace std;

struct conveyor
{
	int isRobot;
	int durability;
};

bool IsStop(vector<conveyor> a, int k)
{
	int cnt = 0;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i].durability == 0) cnt++;
	}
	return k <= cnt;
}


// 벨트 칸이 회전
void Turn(vector<conveyor>& v, vector<int>& r)
{
	for (int i = 0; i < r.size(); i++)
	{
		if (r[i] + 1 == v.size() / 2 -1)
		{
			v[r[i]].isRobot -= 1;
			r.erase(r.begin() + i);
			i--;
		}
		else
		{
			r[i] += 1;
		}
	}

	v.insert(v.begin(), v[v.size() - 1]);
	v.erase(v.end() - 1);
}

// 로봇이 벨트 위에서 이동한다.
void Move(vector<conveyor>& v, vector<int>& r)
{
	for (int i = 0; i < r.size(); i++)
	{
		if (v[r[i] + 1].isRobot == 0 && v[r[i] + 1].durability >= 1)
		{
			r[i] += 1;
			v[r[i]].isRobot += 1;
			v[r[i]].durability -= 1;
			v[r[i] - 1].isRobot -= 1;

			if (r[i] == v.size() / 2 - 1)
			{
				v[r[i]].isRobot -= 1;
				r.erase(r.begin() + i);
				i--;
			}
		}
	}
}

void Upload(vector<conveyor>& v, vector<int>& r)
{
	if (v[0].durability != 0)
	{
		v[0].isRobot += 1;
		v[0].durability -= 1;
		r.push_back(0);
	}
}

int main()
{
	int N, K;
	cin >> N >> K;
	int step = 0;
	vector<conveyor> belt;

	vector<int> robot;

	for (int i = 0; i < 2*N; i++)
	{
		int a;
		cin >> a;
		belt.push_back({0, a});
	}


	while (!IsStop(belt, K))
	{
		// 1번 회전
		Turn(belt, robot);
		// 2번 로봇 이동
		Move(belt, robot);

		// 3번 로봇 올리기
		Upload(belt, robot);
		step++;

	}

	cout << step;
}