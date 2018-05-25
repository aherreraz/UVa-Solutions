#include <bits/stdc++.h>
using namespace std;
int t, m, p, a, b;
typedef pair<int, int> ii;
vector< vector<int> > g;
vector<int> dist;
vector<int> parent;
string s1, s2;
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
				dist[u] = dist[v] + 1, q.push(u), parent[u] = v;
		}
	}
}
int main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d", &m, &p);
		g.assign(26, vector<int>());
		for (int i = 0; i < m; i++)
		{
			cin >> s1 >> s2;
			a = s1[0] - 'A', b = s2[0] - 'A';
			g[a].push_back(b), g[b].push_back(a);
		}
		for (int i = 0; i < p; i++)
		{
			cin >> s1 >> s2;
			a = s1[0] - 'A', b = s2[0] - 'A';
			dist.assign(26, -1);
			parent.assign(26, -1);
			bfs_visit(a);
			stack<int> res;
			res.push(b);
			while (res.top() != a)
				res.push(parent[res.top()]);
			while (!res.empty())
				printf("%c", res.top() + 'A'), res.pop();
			printf("\n");
		}
		if (t) printf("\n");
	}
}