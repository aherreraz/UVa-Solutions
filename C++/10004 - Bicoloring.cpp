#include <bits/stdc++.h>
using namespace std;
vector < vector<int> > g;
int color[210];
int n, m;
bool bfs(int start)
{
	queue<int> q; q.push(start); color[start] = 1;
	while (!q.empty())
	{
		int v = q.front(); q.pop();
		for (int i = 0; i < g[v].size(); i++)
		{
			int u = g[v][i];
			if (color[u] == 0)
				q.push(u), color[u] = color[v] * -1;
			if (color[v] == color[u])
				return false;
		}
	}
	return true;
}
int main()
{
	while (scanf("%d %d", &n, &m) == 2)
	{
		g.clear(), g.resize(n);
		memset(color, 0, sizeof color);
		for (int i = 0; i < m; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			g[a].push_back(b);
			g[b].push_back(a);
		}
		if (bfs(0))
			printf("BICOLORABLE.\n");
		else
			printf("NOT BICOLORABLE.\n");
	}
}