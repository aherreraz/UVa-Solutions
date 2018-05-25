#include <bits/stdc++.h>
using namespace std;
int t, s, e, n, a;
int dist[10000];
bitset<10000> bs;
int auxN1[8] = {0, 0, 0, 0, 0, 0, 1, 9};
int auxN2[8] = {0, 0, 0, 0, 1, 9, 0, 0};
int auxN3[8] = {0, 0, 1, 9, 0, 0, 0, 0};
int auxN4[8] = {1, 9, 0, 0, 0, 0, 0, 0};
void bfs_visit(int start)
{
	queue<int> q; q.push(start), dist[start] = 0;
	while (!q.empty())
	{
		int v = q.front(); q.pop();
		int v1 = v / 1000, v2 = (v % 1000) / 100, v3 = (v % 100) / 10 , v4 = v % 10;
		for (int i = 0; i < 8; i++)
		{
			int u1 = (v1 + auxN1[i]) % 10;
			int u2 = (v2 + auxN2[i]) % 10;
			int u3 = (v3 + auxN3[i]) % 10;
			int u4 = (v4 + auxN4[i]) % 10;
			int u = u1 * 1000 + u2 * 100 + u3 * 10 + u4;
			if (bs[u] && dist[u] == -1)
				dist[u] = dist[v] + 1, q.push(u);
		}
	}
}
void readNumber(int &num)
{
	num = 0;
	int aux;
	for (int i = 0; i < 4; i++)
		scanf("%d", &aux), num *= 10, num += aux;
}
int main()
{
	scanf("%d", &t);
	while (t--)
	{
		bs.set(), readNumber (s), readNumber (e);
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			readNumber(a), bs[a] = 0;
		memset(dist, -1, sizeof dist);
		bfs_visit(s);
		printf("%d\n", dist[e]);
	}
}