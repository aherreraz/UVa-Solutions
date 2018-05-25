#include <bits/stdc++.h>
using namespace std;
int n, m, a, p;
vector< vector<int> > g;
vector<int> dist;
int frec[3000];
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
	while (scanf("%d", &n) == 1)
	{
		g.assign(n, vector<int>());
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &m);
			for (int j = 0; j < m; j++)
				scanf("%d", &a), g[i].push_back(a);
		}
		scanf("%d", &p);
		for (int i = 0; i < p; i++)
		{
			dist.assign(n, -1);
			memset(frec, 0, sizeof frec);
			scanf("%d", &a);
			bfs_visit(a);
			for (int j = 0; j < n; j++)
				if (dist[j] > 0)
					frec[dist[j]]++;
			int mayor = 0, pos;
			for (int j = 0; j < 3000; j++)
				if (frec[j] > mayor)
					mayor = frec[j], pos = j;
			if (mayor == 0)
				printf("0\n");
			else
				printf("%d %d\n", mayor, pos);
		}
	}
}