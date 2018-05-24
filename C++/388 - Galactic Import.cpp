#include <bits/stdc++.h>
#define EPS 1e-7
using namespace std;
vector< vector<int> > g;
map<int, int> mapa;
vector<int> dist;
vector<double> value;
int n;
int comparar(double a, double b)
{
	if (a - b > EPS) return 1;
	if (b - a > EPS) return -1;
	return 0;
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
	while (scanf("%d", &n) == 1)
	{
		mapa.clear(); g.assign(27, vector<int>()); value.assign(27, -1.0);
		char s[30];
		for (int i = 0; i < n; i++)
		{
			scanf("%s", &s);
			int a = s[0] - 'A';
			scanf("%lf %s", &value[a], &s);
			int m = strlen(s);
			for (int j = 0; j < m; j++)
			{
				int b = (s[j] == '*') ? 26 : s[j] - 'A';
				g[a].push_back(b);
				g[b].push_back(a);
			}
		}
		dist.assign(27, -1);
		bfs_visit(26);
		double mayor = -1.0;
		int posMayor;
		for (int i = 0; i < 26; i++)
		{
			double curr = value[i] * pow (0.95, dist[i] - 1);
			//printf("%c %d %lf %lf\n", i + 'A', dist[i], value[i], curr);
			if (comparar(curr, mayor) > 0)
				mayor = curr, posMayor = i;
		}
		printf("Import from %c\n", posMayor + 'A');
	}
}