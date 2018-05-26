#include <bits/stdc++.h>
#define INF 2000000
using namespace std;
const int N = 505;
int r, c, n, q;
int tMin[2 * N][2 * N];
int tMax[2 * N][2 * N];
int build()
{
	for (int x = 2 * r - 1; x > 0; x--)
		for (int y = 2 * c - 1; y > 0; y--)
			if (x >= r && y >= c)
				continue;
			else if (x >= r)
			{			
				tMin[x][y] = min(tMin[x][y << 1], tMin[x][y << 1 | 1]);
				tMax[x][y] = max(tMax[x][y << 1], tMax[x][y << 1 | 1]);
			}
			else
			{
				tMin[x][y] = min(tMin[x << 1][y], tMin[x << 1 | 1][y]);
				tMax[x][y] = max(tMax[x << 1][y], tMax[x << 1 | 1][y]);
			}
}
void update(int x, int y, int val)
{
	x += r;
	y += c;
	for (tMin[x][y] = tMax[x][y] = val; x > 0; x >>= 1)
		for (int i = y; i > 0; i >>= 1)
			if (x >= r && i >= c)
				continue;
			else if (x >= r)
			{			
				tMin[x][i] = min(tMin[x][i << 1], tMin[x][i << 1 | 1]);
				tMax[x][i] = max(tMax[x][i << 1], tMax[x][i << 1 | 1]);
			}
			else
			{
				tMin[x][i] = min(tMin[x << 1][i], tMin[x << 1 | 1][i]);
				tMax[x][i] = max(tMax[x << 1][i], tMax[x << 1 | 1][i]);
			}
			
}
int queryMin(int x1, int y1, int x2, int y2)
{
	int res = INF;
	for (x1 += r, x2 += r; x1 <= x2; x1++, x2--, x1>>=1, x2>>=1)
		for (int i1 = y1 + c, i2 = y2 + c; i1 <= i2; i1++, i2--, i1>>=1, i2>>=1)
		{
			if ((x1&1) && (i1&1)) res = min(res, tMin[x1][i1]);
			if ((x1&1) && !(i2&1)) res = min(res, tMin[x1][i2]);
			if (!(x2&1) && (i1&1)) res = min(res, tMin[x2][i1]);
			if (!(x2&1) && !(i2&1)) res = min(res, tMin[x2][i2]);
		}
	return res;
}
int queryMax(int x1, int y1, int x2, int y2)
{
	int res = -INF;
	for (x1 += r, x2 += r; x1 <= x2; x1++, x2--, x1>>=1, x2>>=1)
		for (int i1 = y1 + c, i2 = y2 + c; i1 <= i2; i1++, i2--, i1>>=1, i2>>=1)
		{
			if ((x1&1) && (i1&1)) res = max(res, tMax[x1][i1]);
			if ((x1&1) && !(i2&1)) res = max(res, tMax[x1][i2]);
			if (!(x2&1) && (i1&1)) res = max(res, tMax[x2][i1]);
			if (!(x2&1) && !(i2&1)) res = max(res, tMax[x2][i2]);
		}
	return res;
}
int main()
{
	while (scanf("%d", &n) == 1)
	{
		r = c = n;
		for (int x = 0; x < r; x++)
		{
			for (int y = 0; y < c; y++)
			{
				scanf("%d", &tMin[x + r][y + c]);
				tMax[x + r][y + c] = tMin[x + r][y + c];
			}
		}
		build();
		scanf("%d", &q);
		for (int i = 0; i < q; i++)
		{
			char c[5];
			scanf("%s", &c);
			if (c[0] == 'q')
			{
				int x1, x2, y1, y2;
				scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
				printf("%d %d\n", queryMax(x1-1,y1-1,x2-1,y2-1), queryMin(x1-1,y1-1,x2-1,y2-1));
			}
			else
			{
				int x, y, val;
				scanf("%d %d %d", &x, &y, &val);
				update(x-1, y-1, val);
			}
		}
	}
}