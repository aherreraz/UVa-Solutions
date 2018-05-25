#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 10010;
ll v[N];
ll n, sum;

bool erdosGallai()
{
	if (sum & 1LL)
		return false;
	
	ll S = 0;
	for (ll k = 0; k < n; k++)
	{
		S += v[k];
		ll aux = k * (k + 1);
		for (ll i = k + 1; i < n; i++)
			aux += min(k + 1, v[i]);
		if (S > aux)
			return false;
	}
	return true;
}
bool comparar(ll a, ll b)
{
	return a > b;
}
int main()
{
	while (scanf("%lld", &n) == 1 && n)
	{
		sum = 0;
		for (ll i = 0; i < n; i++)
			scanf("%lld", &v[i]), sum += v[i];
		sort(v, v + n, comparar);
		if (erdosGallai())
			printf("Possible\n");
		else
			printf("Not possible\n");
	}
}