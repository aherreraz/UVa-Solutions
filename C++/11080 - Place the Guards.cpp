#include <bits/stdc++.h>
using namespace std;
vector < vector<int> > g;
int color[210], ncolor[2];
int n, m;
bool bfs_visit(int start)
{
	queue<int> q; q.push(start); color[start] = 1, ncolor[1]++;
	while (!q.empty())
	{
		int v = q.front(); q.pop();
		for (int i = 0; i < g[v].size(); i++)
		{
			int u = g[v][i];
			if (color[u] == -1)
				q.push(u), color[u] = color[v] ^ 1, ncolor[color[u]]++;
			if (color[v] == color[u])
				return false;
		}
	}
	return true;
}
int bfs()
{
	int menor = 0;
	memset(color, -1, sizeof color);
	for (int i = 0; i < n; i++)
		if (color[i] == -1) // No descubierto
		{
			ncolor[0] = ncolor[1] = 0;
			if (!bfs_visit(i))
				return -1;
			if (ncolor[0] == 0 || ncolor[1] == 0)
				menor += max(ncolor[0], ncolor[1]);
			else
				menor += min(ncolor[0], ncolor[1]);
		}
	return menor;
}
int main()
{
	int t;
	scanf ("%d", &t);
	while (t--)
	{
		scanf("%d %d", &n, &m);
		g.clear(), g.resize(n);
		for (int i = 0; i < m; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			g[a].push_back(b);
			g[b].push_back(a);
		}
			printf("%d\n", bfs());
	}
}