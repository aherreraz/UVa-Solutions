#include <bits/stdc++.h>
using namespace std;
int t, n, m, a, b;
vector< vector<int> > g;
vector<int> dist;
void bfs_visit(int start)
{
	queue<int> q; q.push(start), dist[start] = 0;
	while (!q.empty())
	{
		int v = q.front(); q.pop();
		for (int i = 0; i < g[v].size(); i++)
		{
			int u = g[v][i];
			if (dist[u] == -1)
				dist[u] = dist[v] + 1, q.push(u);
		}
	}
}
int main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		g.assign(n, vector<int>());
		for (int i = 0; i < n; i++)
		{
			scanf("%d %d", &a, &m);
			for (int j = 0; j < m; j++)
				scanf("%d", &b), g[a].push_back(b);
		}
		scanf("%d %d", &a, &b);
		dist.assign(n, -1);
		bfs_visit(a);
		printf("%d %d %d\n", a, b, dist[b] - 1);
		if (t) printf("\n");
	}
}