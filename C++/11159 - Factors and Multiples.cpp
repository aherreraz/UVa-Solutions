#include <bits/stdc++.h>
using namespace std;
int t, n, m, a;

vector<int> match;
vector<bool> visit;
vector< vector<int> > g;
vector<int> V;

int augmentingPath (int v)
{
	if (visit[v])
		return 0;
	visit[v] = 1;
	for (int i = 0; i < (int)g[v].size(); i++)
	{
		int u = g[v][i];
		if (match[u] == -1 || augmentingPath(match[u]))
		{
			match[u] = v;
			return 1;
		}
	}
	return 0;
}
int MCBM (int left)
{
	int res = 0;
	match.assign(n + m, -1);
	for (int i = 0; i < left; i++)
		visit.assign(left, 0), res += augmentingPath(i);
	return res;
}

int main()
{
	scanf("%d", &t);
	for (int z = 1; z <= t; z++)
	{
		V.clear();
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a), V.push_back(a);
		scanf("%d", &m);
		for (int i = 0; i < m; i++)
			scanf("%d", &a), V.push_back(a);
		g.assign(n + m, vector<int>());
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (V[i] == 0 && V[n + j] == 0)
					g[i].push_back(n + j);
				else if (V[n + j] == 0)
					g[i].push_back(n + j);
				else if (V[i] == 0)
					continue;
				else if (V[n + j] % V[i] == 0)
					g[i].push_back(n + j);
		printf("Case %d: %d\n", z, MCBM(n));
	}
}