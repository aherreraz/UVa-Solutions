#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
vector<ii> v;
ll k;
int main()
{
	while (scanf("%lld", &k) == 1)
	{
		v.clear();
		for (ll i = k + 1; i <= 2 * k; i++)
		{
			ll j = (k * i) / (i - k);
			if ((k * i) % (i - k) == 0)
				v.push_back(ii(i, j));
		}
		int n = v.size();
		printf("%d\n", n);
		for (int i = 0; i < n; i++)
			printf("1/%lld = 1/%lld + 1/%lld\n", k, v[i].second, v[i].first);
	}
}
