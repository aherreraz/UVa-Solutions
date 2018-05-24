#include <bits/stdc++.h>
using namespace std;
vector< vector<int> > g;
map<int, int> mapa;
vector<int> dist;
int t, n, m, p, c;
int hashValue(char c1, char c2)
{
	return (c1 - 'A') * 26 + c2 - 'A';
}
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
	printf("SHIPPING ROUTES OUTPUT\n\n");
	for (int z = 1; z <= t; z++)
	{
		scanf("%d %d %d", &n, &m, &p);
		mapa.clear(); g.assign(n, vector<int>());
		char s[5], s2[5];
		for (int i = 0; i < n; i++)
			scanf("%s", &s), mapa[hashValue(s[0], s[1])] = i;
		for (int i = 0; i < m; i++)
		{
			scanf("%s %s", &s, &s2);
			int a = hashValue(s[0], s[1]);
			int b = hashValue(s2[0], s2[1]);
			g[mapa[a]].push_back(mapa[b]);
			g[mapa[b]].push_back(mapa[a]);
		}
		printf("DATA SET  %d\n\n", z);
		for (int i = 0; i < p; i++)
		{
			scanf("%d %s %s", &c, &s, &s2);
			dist.assign(n, -1);
			int a = hashValue(s[0], s[1]);
			int b = hashValue(s2[0], s2[1]);
			bfs_visit(mapa[a]);
			int res = dist[mapa[b]];
			if (res == -1)
				printf("NO SHIPMENT POSSIBLE\n");
			else
				printf("$%d\n", res * 100 * c);
		}
		printf("\n");
	}
	printf("END OF OUTPUT\n");
}