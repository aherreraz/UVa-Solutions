#include <bits/stdc++.h>
#define INF 200000000
#define MAX 100005
typedef long long ll;
using namespace std;

ll dp[100010];
ll v[15];

ll solve(ll n)
{
	if (dp[n] != -1)
		return dp[n];
	ll minN = INF;
	for (ll i = 1; v[i] <= n; i++)
		minN = min(minN, solve(n - v[i]));
	return dp[n] = 1 + minN;
}

int main()
{
	dp[0] = 0;
	v[0] = 1;
	for (ll i = 1; i < MAX; i++)
		dp[i] = -1;
	for (ll i = 1; i < 15; i++)
		v[i] = v[i - 1] * i;
	ll n;
	while (scanf("%lld", &n) == 1)
	{
		printf("%lld\n", solve(n));
	}
}