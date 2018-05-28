#include <bits/stdc++.h>
#define INF 2e8
using namespace std;
const int N = 510;
int n, m, nq, a, b;
int M[N][N];
int tUB[2 * N], tLB[2 * N];
void build()
{
    for (int i = n - 1; i > 0; i--)
        tUB[i] = min(tUB[i << 1], tUB[i << 1 | 1]),
        tLB[i] = max(tLB[i << 1], tLB[i << 1 | 1]);
}
int queryUB(int l, int r)
{
    int res = INF;
    for (l += n, r += n; l <= r; l >>= 1, r >>= 1)
    {
        if (l & 1) res = min(res, tUB[l++]);
        if (!(r & 1)) res = min(res, tUB[r--]);
    }
    return res;
}
int queryLB(int l, int r)
{
    int res = -INF;
    for (l += n, r += n; l <= r; l >>= 1, r >>= 1)
    {
        if (l & 1) res = max(res, tLB[l++]);
        if (!(r & 1)) res = max(res, tLB[r--]);
    }
    return res;
}
int main()
{
    while (scanf ("%d %d", &n, &m) == 2 && (n | m))
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                scanf("%d", &M[i][j]);
        scanf("%d", &nq);
        for (int z = 0; z < nq; z++)
        {
            scanf("%d %d", &a, &b);
            for (int i = 0; i < n; i++)
                tLB[i + n] = lower_bound(M[i], M[i] + m, a) - M[i],
                tUB[i + n] = upper_bound(M[i], M[i] + m, b) - M[i];
            build();
            int res = 0, l, r, lb, ub, b, h;
            for (l = 0, r = 0; r < n; r++)
            {
                while (1)
                {
                    lb = queryLB(l, r);
                    ub = queryUB(l, r);
                    b = r - l + 1;
                    h = ub - lb;
                    res = max (res, min(b, h));
                    if (l == r || b < h)
                        break;
                    l++;
                }
            }
            printf("%d\n", res);
        }
        printf("-\n");
    }
}