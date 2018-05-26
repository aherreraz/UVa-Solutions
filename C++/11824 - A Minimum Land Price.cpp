#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, n, v[50], m = 5000000;
bool comparar(ll a, ll b)
{
	return a > b;
}
ll cost (ll a, ll y)
{
	ll r = 2;
	for (int i = 0; i < y && r < m; i++)
		r *= a;
	return r;
}
int main()
{
	scanf("%lld", &t);
	while (t--)
	{
		n = 0;
		while (scanf("%lld", &v[n]) && v[n])
			n++;
		sort(v, v + n, comparar);
		ll res = 0;
		for (int i = 0; i < n; i++)
			res += cost(v[i], i + 1);
		if (res > m)
			printf("Too expensive\n");
		else
			printf("%lld\n", res);
	}
}