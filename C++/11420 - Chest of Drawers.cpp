#include <bits/stdc++.h>
#define MAX 70
using namespace std;
typedef long long ll;
ll M[MAX][MAX][2];

ll solve(ll n, ll s, bool prevLocked)
{
	if (s < 0 || n < 0)
		return 0;
	if (M[n][s][prevLocked] != -1)
		return M[n][s][prevLocked];
		
	ll locked, unlocked;
	if (prevLocked)
	{
		locked = solve(n - 1, s - 1, true);
		unlocked = solve(n - 1, s, false);
	}
	else
	{
		locked = solve(n - 1, s, true);
		unlocked = solve(n - 1, s, false);
	}
	return M[n][s][prevLocked] = locked + unlocked;
}
int main()
{
	for (ll i = 0; i < 70; i++)
		for (ll j = 0; j < 70; j++)
			M[i][j][0] = M[i][j][1] = -1;
	
	M[0][0][0] = M[0][0][1] = 1;
	ll n, s;
	while (scanf("%lld %lld", &n, &s) != EOF)
	{
		if (n < 0 && s < 0)
			return 0;
		
		printf("%lld\n", solve(n, s, true));
	}
}