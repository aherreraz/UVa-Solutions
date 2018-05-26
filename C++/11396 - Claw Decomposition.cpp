#include <bits/stdc++.h>
using namespace std;
vector <vector<int> > g;
vector<int> color;
int ncolor[2];
int n;
bool bfs_visit(int start)
{
	queue<int> q; q.push(start); color[start] = 0, ncolor[0]++;
	bool cumple = true;
	while (!q.empty())
	{
		int v = q.front(); q.pop();
		for (int i = 0; i < g[v].size(); i++)
		{
			int u = g[v][i];
			if (color[u] == -1) // No descubierto
				q.push(u), color[u] = color[v] ^ 1, ncolor[color[u]]++;
			else if (color[v] == color[u]) // No es bipartito
				cumple = false;
		}
	}
	return cumple;
}
int bfs()
{
	int res = 0;
	color.assign(n, -1);
	for (int i = 0; i < n; i++)
		if (color[i] == -1) // No descubierto
		{
			ncolor[0] = ncolor[1] = 0;
			if (!bfs_visit(i)) // No es bipartito
				return -1;
			if (ncolor[0] == 0 || ncolor[1] == 0)
				res += max(ncolor[0], ncolor[1]);
			else
				res += min(ncolor[0], ncolor[1]);
		}
	return res;
}
int main()
{
	while (scanf("%d", &n) == 1 && n)
	{
		g.assign(n, vector<int>());
		int a, b;
		while (scanf("%d %d", &a, &b) == 2 && (a || b))
		{
			g[a - 1].push_back(b - 1);
			g[b - 1].push_back(a - 1);
		}
		(bfs() == -1) ? printf("NO\n") : printf("YES\n");
	}
}