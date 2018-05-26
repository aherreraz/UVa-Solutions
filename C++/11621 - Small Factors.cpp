#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> v;
vector<ll>::iterator it;
ll v2[32], v3[21], n;
int main()
{
	v.clear();
	v2[0] = v3[0] = 1;
	for (int i = 1; i < 32; i++)
		v2[i] = v2[i - 1] << 1;
	for (int i = 1; i < 21; i++)
		v3[i] = v3[i - 1] * 3;
	for (int i = 0; i < 32; i++)
		for (int j = 0; j < 21; j++)
			v.push_back(v2[i] * v3[j]);
	sort(v.begin(), v.end());
	while (scanf("%lld", &n) && n)
	{
		it = lower_bound(v.begin(), v.end(), n);
		printf("%lld\n", *it);
	}
}