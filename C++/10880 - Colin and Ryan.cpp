#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, c, r, x, y;
stack<ll> s;
int main()
{
	scanf("%lld", &t);
	for (int z = 1; z <= t; z++)
	{
		scanf("%lld %lld", &c, &r), x = c - r;
		printf("Case #%d:", z);
		if (c == r)
			printf(" 0\n");
		else
		{
			for (ll i = 1; i * i <= x; i++)
				if (x % i == 0)
				{
					if (i > r)
						printf(" %lld", i);
					y = x / i;
					if (y > r && y != i)
						s.push(y);
				}
			while (!s.empty())
				printf(" %lld", s.top()), s.pop();
			printf("\n");
		}
	}
}