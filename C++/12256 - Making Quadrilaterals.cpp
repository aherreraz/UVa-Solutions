#include <bits/stdc++.h>
typedef long long ll;

ll v[61];

int main()
{
	v[0] = v[1] = v[2] = 1;
	for (int i = 3; i < 61; i++)
		v[i] = v[i - 1] + v[i - 2] + v[i - 3];
	
	int n, caso = 1;
	while (scanf("%d", &n) == 1 && n != 0)
	{
		printf("Case %d: %lld\n", caso++, v[n - 1]);
	}
}