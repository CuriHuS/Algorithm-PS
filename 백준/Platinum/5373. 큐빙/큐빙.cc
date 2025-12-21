#include <iostream>
using namespace std;

struct cubeFace
{
	char face[3][3];

	cubeFace()
	{
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				face[i][j] = 'w';
			}
		}
	}
};

enum cubeFaceSequence
{
	U = 'U',
	D = 'D',
	F = 'F',
	B = 'B', // 뒷면을 바라볼때는 거꾸로 본다고 가정
	L = 'L',
	R = 'R'
};

cubeFaceSequence toFace(char c)
{
	switch (c)
	{
	case 'U': return U;
	case 'D': return D;
	case 'F': return F;
	case 'B': return B;
	case 'L': return L;
	case 'R': return R;
	}
}

struct cube
{
	cubeFace info[6];
};

int inputTestCase()
{
	int testcases;
	cin >> testcases;
	return testcases;
}

void rotateFaceCCW(cube& c, cubeFaceSequence d)
{
	char temp[3][3];
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			temp[i][j] = c.info[d].face[i][j];

	c.info[d].face[1][2] = temp[2][1];

	c.info[d].face[2][1] = temp[1][0];
	c.info[d].face[2][2] = temp[2][0];

	c.info[d].face[1][0] = temp[0][1];
	c.info[d].face[2][0] = temp[0][0];

	c.info[d].face[0][0] = temp[0][2];
	c.info[d].face[0][1] = temp[1][2];
	c.info[d].face[0][2] = temp[2][2];
}

// 시계 방향으로 보고 있는 면을 돌릴 때 함수
void rotateFaceCW(cube& c, cubeFaceSequence d)
{
	char temp[3][3];
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			temp[i][j] = c.info[d].face[i][j];

	c.info[d].face[0][2] = temp[0][0];
	c.info[d].face[1][2] = temp[0][1];
	c.info[d].face[2][2] = temp[0][2];
	c.info[d].face[2][1] = temp[1][2];
	c.info[d].face[2][0] = temp[2][2];
	c.info[d].face[1][0] = temp[2][1];
	c.info[d].face[0][0] = temp[2][0];
	c.info[d].face[0][1] = temp[1][0];
}

void rollCubeCCW(cube& c, cubeFaceSequence direct)
{
	if (direct == cubeFaceSequence::L)
	{
		char temp[3][3];
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				temp[i][j] = c.info[F].face[i][j];
		// 아래 [i][0] -> 앞면[i][0]
		for (int i = 0; i < 3; ++i)
			c.info[F].face[i][0] = c.info[D].face[i][0];
		// 뒷면 [i][0] -> 아래 [i][0]
		for (int i = 0; i < 3; ++i)
			c.info[D].face[i][0] = c.info[B].face[i][0];
		// 윗면 [i][0] -> 뒷면 [i+2][0]
		for (int i = 0; i < 3; ++i)
			c.info[B].face[i][0] = c.info[U].face[i][0];
		// 앞면 [i][0] -> 윗면 [i][0]
		for (int i = 0; i < 3; ++i)
			c.info[U].face[i][0] = temp[i][0];
	}

	else if (direct == cubeFaceSequence::R)
	{
		char temp[3][3];
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				temp[i][j] = c.info[U].face[i][j];

		// 뒷면 -> 윗면
		for (int i = 0; i < 3; ++i)
			c.info[U].face[i][2] = c.info[B].face[i][2];

		// 아래 -> 뒷면
		for (int i = 0; i < 3; ++i)
			c.info[B].face[i][2] = c.info[D].face[i][2];

		// 앞면 [i][2] -> 아래 [i][2]
		for (int i = 0; i < 3; ++i)
			c.info[D].face[i][2] = c.info[F].face[i][2];

		// 윗면 [i][2] -> 앞면 [i][2]
		for (int i = 0; i < 3; ++i)
			c.info[F].face[i][2] = temp[i][2];
	}

	else if (direct == cubeFaceSequence::U)
	{
		char temp[3][3];
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				temp[i][j] = c.info[B].face[i][j];

		// 오른쪽 [0][i] => 뒷면 [2][2-i]
		for (int i = 0; i < 3; ++i)
			c.info[B].face[2][2-i] = c.info[R].face[0][i];
		// 앞면 [0][i] => 오른쪽 [0][i]
		for (int i = 0; i < 3; ++i)
			c.info[R].face[0][i] = c.info[F].face[0][i];
		// 왼쪽 [0][i] => 앞면 [0][i]
		for (int i = 0; i < 3; ++i)
			c.info[F].face[0][i] = c.info[L].face[0][i];
		// 뒷면 [2][i] => 왼쪽 [0][2-i]
		for (int i = 0; i < 3; ++i)
			c.info[L].face[0][2-i] = temp[2][i];
	}

	else if (direct == cubeFaceSequence::D)
	{
		char temp[3][3];
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				temp[i][j] = c.info[F].face[i][j];

		// 오른쪽[2][i] -> 앞면[2][i]
		for (int i = 0; i < 3; ++i)
			c.info[F].face[2][i] = c.info[R].face[2][i];
		// 뒷면[0][2-i] -> 오른쪽[2][i]
		for (int i = 0; i < 3; ++i)
			c.info[R].face[2][i] = c.info[B].face[0][2 - i];
		// 왼쪽[2][i] -> 뒷면[0][2-i]
		for (int i = 0; i < 3; ++i)
			c.info[B].face[0][2 - i] = c.info[L].face[2][i];
		// 앞면[2][i] -> 왼쪽[2][i]
		for (int i = 0; i < 3; ++i)
			c.info[L].face[2][i] = temp[2][i];
	}
	else if (direct == cubeFaceSequence::F)
	{
		char temp[3][3];
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				temp[i][j] = c.info[U].face[i][j];

		// 오른쪽[i][0] -> 위쪽[2][i]
		for (int i = 0; i < 3; ++i)
			c.info[U].face[2][i] = c.info[R].face[i][0];
		// 아래쪽[0][i] -> 오른쪽[2-i][0]
		for (int i = 0; i < 3; ++i)
			c.info[R].face[2-i][0] = c.info[D].face[0][i];

		// 왼쪽[i][2] -> 아래쪽[0][i]
		for (int i = 0; i < 3; ++i)
			c.info[D].face[0][i] = c.info[L].face[i][2];
		// 위쪽[2][2-i] -> 왼쪽[i][2]
		for (int i = 0; i < 3; ++i)
			c.info[L].face[i][2] = temp[2][2-i];

	}
	else if (direct == cubeFaceSequence::B)
	{
		char temp[3][3];
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				temp[i][j] = c.info[U].face[i][j];

		// 왼쪽[2-i][0] -> 위쪽[0][i]
		for (int i = 0; i < 3; ++i)
			c.info[U].face[0][i] = c.info[L].face[2 - i][0];
		// 아래[2][i] -> 왼쪽[i][0]
		for (int i = 0; i < 3; ++i)
			c.info[L].face[i][0] = c.info[D].face[2][i];
		// 오른쪽[2-i][2] -> 아래[2][i]
		for (int i = 0; i < 3; ++i)
			c.info[D].face[2][i] = c.info[R].face[2 - i][2];
		// 위쪽[0][i] ->  오른쪽[i][2]
		for (int i = 0; i < 3; ++i)
			c.info[R].face[i][2] = temp[0][i];
	}
	rotateFaceCCW(c, direct);
}


void rollCubeCW(cube& c, cubeFaceSequence direct)
{
	if (direct == cubeFaceSequence::L)
	{
		char temp[3][3];
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				temp[i][j] = c.info[U].face[i][j];

		// 뒷면 -> 윗면
		for (int i = 0; i < 3; ++i)
			c.info[U].face[i][0] = c.info[B].face[i][0];

		// 아래 -> 뒷면
		for (int i = 0; i < 3; ++i)
			c.info[B].face[i][0] = c.info[D].face[i][0];

		// 앞면 -> 아래
		for (int i = 0; i < 3; ++i)
			c.info[D].face[i][0] = c.info[F].face[i][0];

		// 위쪽 -> 앞면
		for (int i = 0; i < 3; ++i)
			c.info[F].face[i][0] = temp[i][0];
	}

	else if (direct == cubeFaceSequence::R)
	{
		char temp[3][3];
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				temp[i][j] = c.info[U].face[i][j];

		// 앞면 [i][2] -> 윗면 [i][2]
		for (int i = 0; i < 3; ++i)
			c.info[U].face[i][2] = c.info[F].face[i][2];

		// 아래 [i][2] -> 앞면 [i][2]
		for (int i = 0; i < 3; ++i)
			c.info[F].face[i][2] = c.info[D].face[i][2];

		// 뒷면 -> 아래
		for (int i = 0; i < 3; ++i)
			c.info[D].face[i][2] = c.info[B].face[i][2];

		// 윗면 -> 뒷면
		for (int i = 0; i < 3; ++i)
			c.info[B].face[i][2] = temp[i][2];
	}

	else if (direct == cubeFaceSequence::U)
	{
		char temp[3][3];
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				temp[i][j] = c.info[B].face[i][j];

		// 왼쪽 [0][2-i] => 뒷면 [2][i]
		for (int i = 0; i < 3; ++i)
			c.info[B].face[2][i] = c.info[L].face[0][2 - i];
		// 앞면 [0][i] => 왼쪽 [0][i]
		for (int i = 0; i < 3; ++i)
			c.info[L].face[0][i] = c.info[F].face[0][i];
		// 오른쪽 [0][i] => 앞면[0][i]
		for (int i = 0; i < 3; ++i)
			c.info[F].face[0][i] = c.info[R].face[0][i];
		// 뒷면 [2][2-i] => 오른쪽[0][i];
		for (int i = 0; i < 3; ++i)
			c.info[R].face[0][i] = temp[2][2 - i];
	}

	else if (direct == cubeFaceSequence::D)
	{
		char temp[3][3];
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				temp[i][j] = c.info[F].face[i][j];

		// 왼쪽[2][i] -> 앞면[2][i]
		for (int i = 0; i < 3; ++i)
			c.info[F].face[2][i] = c.info[L].face[2][i];
		// 뒷면[0][2-i] -> 왼쪽[2][i] 
		for (int i = 0; i < 3; ++i)
			c.info[L].face[2][i] = c.info[B].face[0][2 - i];
		// 오른쪽[2][i] -> 뒷면[0][2-i]
		for (int i = 0; i < 3; ++i)
			c.info[B].face[0][2 - i] = c.info[R].face[2][i];
		// 앞면[2][i] -> 오른쪽[2][i]
		for (int i = 0; i < 3; ++i)
			c.info[R].face[2][i] = temp[2][i];
	}
	else if (direct == cubeFaceSequence::F)
	{
		char temp[3][3];
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				temp[i][j] = c.info[U].face[i][j];

		// 왼쪽[i][2] -> 위쪽[2][2-i]
		for (int i = 0; i < 3; ++i)
			c.info[U].face[2][2-i] = c.info[L].face[i][2];
		// 아래쪽[0][i] -> 왼쪽[i][2]
		for (int i = 0; i < 3; ++i)
			c.info[L].face[i][2] = c.info[D].face[0][i];
		// 오른쪽[i][0] -> 아래쪽[0][2-i]
		for (int i = 0; i < 3; ++i)
			c.info[D].face[0][2-i] = c.info[R].face[i][0];
		//  위쪽[2][i] -> 오른쪽[i][0]
		for (int i = 0; i < 3; ++i)
			c.info[R].face[i][0] = temp[2][i];
	}
	else if (direct == cubeFaceSequence::B)
	{
		char temp[3][3];
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				temp[i][j] = c.info[U].face[i][j];

		// 오른쪽[i][2] -> 위쪽[0][i]
		for (int i = 0; i < 3; ++i)
			c.info[U].face[0][i] = c.info[R].face[i][2];
		// 아래[2][i] -> 오른쪽[2-i][2]
		for (int i = 0; i < 3; ++i)
			c.info[R].face[2 - i][2] = c.info[D].face[2][i];
		// 왼쪽[i][0] -> 아래[2][i]
		for (int i = 0; i < 3; ++i)
			c.info[D].face[2][i] = c.info[L].face[i][0];
		// 위쪽[0][i] -> 왼쪽[2-i][0]
		for (int i = 0; i < 3; ++i)
			c.info[L].face[2 - i][0] = temp[0][i];
	}
	rotateFaceCW(c, direct);
}

void paint(cube& c, cubeFaceSequence d, char color)
{
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			c.info[d].face[i][j] = color;
}

void clear(cube& c)
{
	paint(c, U, 'w');
	paint(c, D, 'y');
	paint(c, F, 'r');
	paint(c, B, 'o');
	paint(c, L, 'g');
	paint(c, R, 'b');
}

void output(cube& c)
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout << c.info[U].face[i][j];
		}
		cout << '\n';
	}
}

int inputRollNums()
{
	int temp;
	cin >> temp;
	return temp;
}

void solution()
{
	int testcase = inputTestCase();
	while (testcase--)
	{
		cube c;
		clear(c);
		int tries = inputRollNums();
		for (int i = 0; i < tries; ++i)
		{
			string command;
			cin >> command;
			if (command[1] == '+')
				rollCubeCW(c, toFace(command[0]));
			else if (command[1] == '-')
				rollCubeCCW(c, toFace(command[0]));
		}
		output(c);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	solution();
}