#include <bits/stdc++.h>
#define INF 1e13
using namespace std;
typedef long long ll;
ll n, k;
ll v[1010];
ll check(ll sz)
{
	ll sum = 0, containers = 0;
	for (ll i = 0; i < n; i++)
	{
		sum += v[i];
		if (sum == sz)
			containers++, sum = 0;
		else if (sum > sz)
			containers++, sum = v[i];
	}
	return containers + (sum > 0);
}
int main()
{
	while (scanf("%d %d", &n, &k) == 2)
	{
		ll totN = 0, maxN = 0;
		for (int i = 0; i < n; i++)
			scanf("%lld", &v[i]), totN += v[i], maxN = max(maxN, v[i]);
		ll l = maxN, r = totN, minR = INF;
		for (ll l = maxN, r = totN; l <= r; )
		{
			ll m = (l + r) / 2;
			if (check(m) <= k)
			{
				r = m - 1;
				if (m < minR)
					minR = m;
			}
			else
				l = m + 1;
		}
		printf("%lld\n", minR);
	}
}