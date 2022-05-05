#include <bits/stdc++.h>
using namespace std;
const int N = 2e7 + 5, mod = 1e9 + 7;
int f[N];
long long dfs(long long x)
{
	// cout << x << '\n';
	if(x < N - 5)
	{
		if(f[x]) return f[x];
		if(x == 1) f[x] = 1;
		else if(x == 2) f[x] = 2;
		else if(x % 2 == 0) f[x] = (dfs(x / 2) % mod * dfs(x / 2) % mod + 1) % mod;
		else f[x] = (dfs(x / 2) % mod * dfs(x - x / 2) % mod * 2 % mod + 1) % mod;
		return f[x];
	}else
	{
		if(x % 2 == 0){
			long long t = dfs(x / 2) % mod;
			t = (t * t + 1) % mod;
			return t;
		}else
			return (dfs(x / 2) % mod * dfs(x - x / 2) % mod * 2 % mod + 1) % mod;
	}
}
int main()
{
	long long n = 1152921504606846976;
	// long long n = 5;
	cout << dfs(5) << '\n';
	// for(int i = 1; i <= n; i ++ )cout << f[i] << '\n';
	return 0;
}