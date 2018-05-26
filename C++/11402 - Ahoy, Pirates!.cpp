#include <bits/stdc++.h>
#define NONE 0
#define ONE 1
#define ZERO 2
#define FLIP 3
const int N = 1024001, M = 200;
int n, T, m, nQuery, cStr[M], lStr[M], h, t[2 * N], mode[N], q[2 * N];
char str[M][51];

void build()
{
	for (int i = n; i < 2 * n; i++)
		q[i] = 1;
	for (int i = n - 1; i > 0; i--)
	{
		q[i] = q[i << 1] + q[i << 1 | 1];
		mode[i] = NONE;
		t[i] = t[i << 1] + t[i << 1 | 1];
	}
	h = sizeof(int) * 8 - __builtin_clz(n);
}

void apply (int i, int modo)
{	
	if (modo == ONE)
	{
		t[i] = q[i];
		if (i < n)
			mode[i] = ONE;
	}
	else if (modo == ZERO)
	{
		t[i] = 0;
		if (i < n)
			mode[i] = ZERO;
	}
	else if (modo == FLIP)
	{
		t[i] = q[i] - t[i];
		if (i < n)
		{
			if (mode[i] == NONE)
				mode[i] = FLIP;
			else if (mode[i] == ONE)
				mode[i] = ZERO;
			else if (mode[i] == ZERO)
				mode[i] = ONE;
			else if (mode[i] == FLIP)
				mode[i] = NONE;
		}
	}
}
void pull (int i)
{
	while (i >>= 1)
	{
		if (mode[i] == NONE)
			t[i] = t[i << 1] + t[i << 1 | 1];
		else if (mode[i] == ONE)
			t[i] = q[i];
		else if (mode[i] == ZERO)
			t[i] = 0;
		else if (mode[i] == FLIP)
			t[i] = q[i] - t[i << 1] - t[i << 1 | 1];
	}
}
void push (int i)
{
	for (int s = h; s > 0; s--)
	{
		int p = i >> s;
		if (p <= 0)
			continue;
		if (mode[p] != NONE)
		{
			apply(p << 1, mode[p]);
			apply(p << 1 | 1, mode[p]);
			mode[p] = NONE;
		}
	}
}

void update (int modo, int l, int r)
{
	int l0 = l + n, r0 = r + n;
	push(l0), push(r0);
	for (l += n, r += n; l <= r; l>>=1, r>>=1)
	{
		if (  l & 1 ) apply(l++, modo);
		if (!(r & 1)) apply(r--, modo);
	}
	pull(l0), pull(r0);
}

int query (int l, int r)
{
	int res = 0;
	push(l + n), push(r + n);
	for (l += n, r += n; l <= r; l>>=1, r>>=1)
	{
		if (  l & 1 ) res += t[l++];
		if (!(r & 1)) res += t[r--];
	}
	return res;
}

int main()
{
	scanf("%d", &T);
	for (int z = 1; z <= T; z++)
	{
		scanf("%d", &m);
		n = 0;
		for (int i = 0; i < m; i++)
		{
			scanf("%d %s\n", &cStr[i], &str[i]);
			lStr[i] = strlen(str[i]);
			n += (cStr[i] * lStr[i]);
		}
		
		for (int i = 0, pos = 0; i < m; i++)
		{
			for (int j = 0; j < cStr[i]; j++)
			{
				for (int k = 0; k < lStr[i]; k++)
				{
					t[pos + n] = str[i][k] - '0';
					pos++;
				}
			}
		}
		build();
		printf("Case %d:\n", z);
		scanf("%d", &nQuery);
		int nQuestion = 1;
		for (int i = 0; i < nQuery; i++)
		{
			char c[5];
			int l, r;
			scanf("%s %d %d", &c, &l, &r);
			switch (c[0])
			{
			case 'F':
				update(ONE, l, r);
				break;
			case 'E':
				update(ZERO, l, r);
				break;
			case 'I':
				update(FLIP, l, r);
				break;
			case 'S':
				printf("Q%d: %d\n", nQuestion++, query(l, r));
				break;
			}
		}
		
	}
}