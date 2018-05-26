#include <bits/stdc++.h>
using namespace std;
int v[100010];
int v2[100010];
int main()
{
	int t;
	scanf("%d", &t);
	for (int z = 1; z <= t; z++)
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &v[i]);
		v2[0] = v[0];
		for (int i = 1; i < n; i++)
			v2[i] = v[i] - v[i - 1];
		int m;
		m = v2[0];
		for (int i = 1; i < n; i++)
			m = max(v2[i], m);
		bool cumple = true;
		int m2 = m;
		for (int i = 0; i < n && cumple; i++)
			if (m < v2[i])
				cumple = false;
			else if (m == v2[i])
				m--;
				
		printf("Case %d: %d\n", z, cumple ? m2 : m2 + 1);
	}
}