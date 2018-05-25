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
			if (bfs_visit(i))
				res += max(ncolor[0], ncolor[1]);
		}
	return res;
}
bool has (int k, int e)
{
	int sz = g[k].size();
	for (int i = 0; i < sz; i++)
		if (g[k][i] == e)
			return true;
	return false;
}
int main()
{
	int t, ni, a;
	scanf ("%d", &t);
	while (t--)
	{
		scanf("%d", &n); g.assign(n, vector<int>());
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &ni);
			for (int j = 0; j < ni; j++)
			{
				scanf("%d", &a); a--;
				if (a < n)
				{
					if (!has(i, a)) g[i].push_back(a);
					if (!has(a, i)) g[a].push_back(i);
				}
			}
				
		}
		printf("%d\n", bfs());
	}
}