#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<int> v2;
vector<int> v;
vector<int> order;
ll inversionCounting ()
{
	ll cont = 0;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (order[v[i]] > order[v[j]])
				cont++;
	return cont;
}
int main()
{
	
	while (scanf("%d", &n) == 1)
	{
		v.clear(), v2.clear(), order.clear();
		v.resize(n), v2.resize(n), order.resize(n);
		for (int i = 0; i < n; i++)
			scanf("%d", &v[i]), v[i]--;
		for (int i = 0; i < n; i++)
			scanf("%d", &v2[i]), v2[i]--, order[v2[i]] = i;
		printf("%lld\n", inversionCounting());
	}
}