#include <bits/stdc++.h>
#define MULT 27
using namespace std;
typedef unsigned long long ll;
typedef pair<int, ll> ill;
typedef pair<int, int> ii;

int n, m;
char s[40010];
vector<ll> v;
unordered_map<ll, int> mapa;
unordered_map<ll, int>::iterator it;
ll pot[40010];
int calc (int len)
{
	int res = -1;
	ll hash;
	mapa.clear();
	for (int i = len; i <= n; i++)
	{
		hash = v[i] - v[i - len] * pot[len];
		it = mapa.find(hash);
		int frec = ++mapa[hash];
		if (frec >= m)
			res = i - len;
	}
	return res;
}
int main()
{
	pot[0] = 1;
	for (int i = 1; i < 40010; i++)
		pot[i] = pot[i - 1] * MULT;
	while (scanf("%d", &m) == 1 && m)
	{
		scanf("%s", &s);
		n = strlen(s);
		v.resize(n + 1);
		v[0] = 0;
		for (int i = 1; i <= n; i++)
			v[i] = v[i - 1] * MULT + s[i - 1] - 'a' + 1;
		
		int res = calc(1);
		if (res < 0)
			printf("none\n");
		else
		{
			int maxR = 0, pos;
			
			for (int l = 1, r = n; l <= r ;)
			{
				int mid = (l + r) / 2;
				res = calc(mid);
				if (res >= 0)
					maxR = mid, pos = res, l = mid + 1;
				else
					r = mid - 1;
			}
			printf("%d %d\n", maxR, pos);
		}
	}
}