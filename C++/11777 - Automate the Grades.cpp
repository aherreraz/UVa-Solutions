#include <bits/stdc++.h>
using namespace std;
int t, t1, t2, f, a, c1, c2, c3, r;

int main()
{
	scanf("%d", &t);
	for (int z = 1; z <= t; z++)
	{
		scanf("%d %d %d %d %d %d %d", &t1, &t2, &f, &a, &c1, &c2, &c3);
		r = 2 * (t1 + t2 + f + a) + c1 + c2 + c3 - min(c1, min(c2, c3));
		if (r >= 180)
			printf("Case %d: A\n", z);
		else if (r >= 160)
			printf("Case %d: B\n", z);
		else if (r >= 140)
			printf("Case %d: C\n", z);
		else if (r >= 120)
			printf("Case %d: D\n", z);
		else
			printf("Case %d: F\n", z);
	}
}