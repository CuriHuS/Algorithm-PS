#include <iostream>
#include <map>
using namespace std;

#define MOD 1000000007

map<long long, long long> f;

long long fibo(long long n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	if (n == 2) return 1;
	if (f.count(n) > 0) return f[n];
	if (n % 2 == 0)
	{
		long long m = n / 2;
		long long f_m1 = fibo(m - 1);
		long long f_m = fibo(m);
		f[n] = (f_m * (2LL * f_m1 + f_m)) % MOD;
		return f[n];
	}
	else
	{
		long long m = (n + 1) / 2;
		long long f_m1 = fibo(m);
		long long f_m = fibo(m - 1);
		f[n] = (f_m1 * f_m1 + f_m * f_m) % MOD;
		return f[n];
	}
}

int main()
{
	long long n;
	cin >> n;
	cout << fibo(n);
}