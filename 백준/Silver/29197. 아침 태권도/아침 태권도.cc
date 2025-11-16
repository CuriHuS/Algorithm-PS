#include <iostream>
#include <set>
#include <vector>
using namespace std;

struct student
{
	int x;
	int y;
	int quadrant;

	bool operator== (const student& other) const
	{
		return x == other.x && y == other.y && quadrant == other.quadrant;
	}

	bool operator< (const student& other) const
	{
		if (x == other.x)
		{
			if (y == other.y)
			{
				return quadrant < other.quadrant;
			}
			return y < other.y;
		}
		return x < other.x;
	}
};

int findQuadrant(int x, int y)
{
	if (x >= 0)
	{
		if (y >= 0) return 1;
		return 4;
	}
	if (y >= 0) return 2;
	return 3;
}

int gcd(int a, int b)
{
	if (a < b)
	{
		swap(a, b);
	}

	int n;
	while (b != 0)
	{
		n = a % b;
		a = b;
		b = n;
	}
	return a;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin >> N;
	set<student> s;
	int answer = 0;

	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		int k = gcd(x, y);
		int quad = findQuadrant(x, y);
		student temp = { x / k, y / k, quad };
		if (s.find(temp) != s.end())
		{
			continue;
		}
		answer += 1;
		s.insert(temp);
	}

	cout << answer;
}