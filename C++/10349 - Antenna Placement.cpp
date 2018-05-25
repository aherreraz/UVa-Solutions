#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

int t, n, m, l, r;

vector<string> M;
vector<int> match;
vector<bool> visit;
vector< vector<int> > g;
vector< vector<int> > pos;

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
	match.assign(n * m, -1);
	for (int i = 0; i < left; i++)
		visit.assign(left, 0), res += augmentingPath(i);
	return res;
}
int main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf ("%d %d\n", &n, &m);
		M.resize(n);
		for (int i = 0; i < n; i++)
			getline(cin, M[i]);
		g.assign(n * m, vector<int>());
		pos.assign(n, vector<int>(m, 0));
		l = 0, r = (n * m + 1) / 2;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				if ((i ^ j) & 1)
					pos[i][j] = r++;
				else
					pos[i][j] = l++;
		}
		int cont = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (M[i][j] == '*')
				{
					cont++;
					if (i < n - 1 && M[i + 1][j] == '*')
						g[pos[i][j]].push_back(pos[i + 1][j]),
						g[pos[i + 1][j]].push_back(pos[i][j]);
					if (j < m - 1 && M[i][j + 1] == '*')
						g[pos[i][j]].push_back(pos[i][j + 1]),
						g[pos[i][j + 1]].push_back(pos[i][j]);
				}
		int res = MCBM(l);
		printf("%d\n", cont - res);
	}
}