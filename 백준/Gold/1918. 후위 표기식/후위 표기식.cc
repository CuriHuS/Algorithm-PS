#include <iostream>
#include <vector>
using namespace std;

int main()
{
	string result = "";

	string input;
	cin >> input;

	vector<char> stack;


	for (int i = 0; i < input.size(); i++)
	{

		char temp = input[i];

		if (temp >= 'A' && temp <= 'Z') // 피연산자임
		{
			result += temp;
		}

		// 만약에 곱하기, 나누기가 들어왔으면
		else if (temp == '*' || temp == '/')
		{
			// 지금까지 쌓인 스택이 있고 마지막에 있는 연산자가 동순위(곱하기, 나누기)이면 이제 넣어도 돼
			while (!stack.empty() && (stack[stack.size()-1] == '*' || stack[stack.size()-1] == '/'))
			{
				result += stack[stack.size()-1];
				stack.pop_back();
			}
			stack.push_back(temp);
		}

		// 더하기나 빼기면
		else if (temp == '+' || temp == '-')
		{
			// 만약에 괄호 안에 있는 연산자가 아니면,
			while (!stack.empty() && stack[stack.size()-1] != '(')
			{
				// 스택에 존재하는 연산자들은 적어준다(+, -는 후순위이므로 이전에 다 적어야 됨)
				result += stack[stack.size() - 1];
				stack.pop_back();
			}
			// +, -는 스택 삽입
			stack.push_back(temp);
		}

		// 괄호가 끝났을 때
		else if (temp == ')')
		{
			// 스택 쌓였고, 마지막 부분이 ( 아니어야 돼.
			while (!stack.empty() && stack[stack.size() - 1] != '(')
			{
				result += stack[stack.size() - 1];
				stack.pop_back();
			}
			// 괄호 안에 연산자 다 작성 이후 ( 삭제
			stack.pop_back();
		}

		// ( 인 경우 스택에 넣고 우선 순위 판단
		else
			stack.push_back(temp);
	}

	while (!stack.empty())
	{
		result += stack[stack.size() - 1];
		stack.pop_back();
	}
	cout << result;
}