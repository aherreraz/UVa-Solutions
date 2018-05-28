#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
ii v[3010];

int main()
{
	ll n;
	while (scanf("%lld", &n) == 1)
	{
		for (ll i = 0; i < n; i++)
			scanf("%lld %lld", &v[i].first, &v[i].second);
		sort(v, v + n);
		ll res = 0;
		for (ll i = 0; i < n; i++)
		{
			ll maxN = INF, minN = -INF;
			for (ll j = i + 1; j < n; j++)
			{
				if (v[j].second > v[i].second)
				{
					// arriba
					if (v[j].second < maxN)
					{
						res++;
						maxN = v[j].second;
					}					
				}
				else
				{
					// abajo
					if (v[j].second > minN)
					{
						res++;
						minN = v[j].second;
					}		
				}
			}
		}
		printf("%lld\n", res);
	}
}