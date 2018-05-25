#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll poly[25];
ll n, t, d, p;
ll eval(ll k)
{
	ll mul = 1, res = 0;
	for (ll i = 0; i <= n; i++)
		res += poly[i] * mul, mul *= k;
	return res;
}
int main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%lld", &n);
		for (ll i = 0; i <= n; i++)
			scanf("%lld", &poly[i]);
		scanf("%lld %lld", &d, &p);
		ll i = 1, j = 1;
		while (j <= p)
		{
			//printf("%lld %lld\n", i, j);
			j += i * d;
			i++;
		}
		printf("%lld\n", eval(i - 1));
	}
}