#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int n, m, k, aux;

vector< vector<ii> > g;
vector< int > p;
int main()
{
	while (scanf("%d %d", &n, &m) == 2)
	{
		g.assign(m, vector<ii>());
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &k);
			p.resize(k);
			for (int j = 0; j < k; j++)
				scanf("%d", &p[j]), p[j]--;
			for (int j = 0; j < k; j++)
				scanf("%d", &aux), g[p[j]].push_back(ii(i, aux));
		}
		printf("%d %d\n", m, n);
		for (int i = 0; i < m; i++)
		{
			k = g[i].size();
			printf("%d", k);
			for (int j = 0; j < k; j++)
				printf(" %d", g[i][j].first + 1);
			printf("\n");
			for (int j = 0; j < k; j++)
				if (j == 0)
					printf("%d", g[i][j].second);
				else
					printf(" %d", g[i][j].second);
			printf("\n");
		}
	}
}