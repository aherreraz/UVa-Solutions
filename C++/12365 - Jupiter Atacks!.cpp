#include <bits/stdc++.h>
typedef long long ll;
const int N = 100010;
ll n, q, B, P;

struct node
{
	ll a, q;
	bool dummy;
	node () { dummy = 1; }
	node (ll pa, ll pq) : a(pa), q(pq), dummy(0) {}
};
ll square (ll a)
{
	return a * a;
}
ll modPow (ll a, ll b, ll mod)
{
	if(b == 0) return 1;
	if(b & 1) return ((a % mod) * modPow(a, b - 1, mod)) % mod;
	return square(modPow(a, b / 2, mod)) % mod;
}
node combine (node a, node b)
{
	if (a.dummy) return b;
	if (b.dummy) return a;
	node res;
	res.a = (a.a * modPow (B, b.q, P) + b.a) % P;
	res.q = a.q + b.q;
	res.dummy = false;
	return res;
}
node t[2 * N];

void build ()
{
	for (int i = n; i < 2 * n; i++)
		t[i] = node (0, 1);
	for (int i = n - 1; i > 0; i--)
		t[i] = combine (t[i << 1], t[i << 1 | 1]);
}
void update (int i, ll val)
{
	for (t[i += n] = node (val, 1); i >>= 1; )
		t[i] = combine (t[i << 1], t[i << 1 | 1]);
}
ll query (int l, int r)
{
	node resL, resR;
	for (l += n, r += n; l <= r; l >>= 1, r >>= 1)
	{
		if (l & 1) resL = combine (resL, t[l++]);
		if (!(r & 1)) resR = combine (t[r--], resR);
	}
	return combine (resL, resR).a;
}
int main ()
{
	while (scanf("%lld %lld %lld %lld", &B, &P, &n, &q) && (B | P | n | q))
	{
		ll a, b;
		char s[5];
		build();
		for (int i = 0; i < q; i++)
		{
			scanf("%s %lld %lld", &s, &a, &b);
			if (s[0] == 'E')
				update (a - 1, b);
			else
				printf ("%lld\n", query(a - 1, b - 1));
		}
		printf("-\n");
	}
}