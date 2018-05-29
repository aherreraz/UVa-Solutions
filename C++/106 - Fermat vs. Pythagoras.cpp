#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll triples, notInTriples, n, a, b, c;
bitset<1000010> bs;

int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a % b); }

int main()
{
	while (scanf("%lld", &n) == 1)
	{
		bs.reset();
		triples = 0;
		for (ll i = 1; i * i <= n; i++)
			for (ll j = i + 1; j * j <= n; j += 2)
				if (gcd(i, j) == 1)
				{
					// Euler Formula
					a = j * j - i * i;
					b = 2 * i * j;
					c = i * i + j * j;
					if (c > n)
						break;
					for (ll k = 1; k * c <= n; k++)
						bs[k * a] = bs[k * b] = bs[k * c] = 1;
					triples++;						
				}
		notInTriples = n;
		for (ll i = 1; i <= n; i++)
			notInTriples -= bs[i];
		printf("%lld %lld\n", triples, notInTriples);
	}
}