#include <bits/stdc++.h>
#define MAX_BOXES 31
#define MAX_DIMENSIONS 11
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> graph;

int boxes[MAX_BOXES][MAX_DIMENSIONS];
int n, m;
graph g;
vi sorted, color, parent, dist;

void init()
{
	g = graph(n);
	dist = vi(n, 0);
	parent = vi(n, -1);
}

void dfs_visit(int v) 
{
	color[v] = 1;
	for (int i = 0; i < g[v].size(); i++)
	{
		ii u = g[v][i];
		if (color[u.second] == 0)
			dfs_visit(u.second);
	}
	color[v] = 2;
	sorted.push_back(v);
}
void topsort()
{
	color = vi(n, 0);
	sorted.clear();
	for (int i = 0; i < n; i++)
		if (color[i] == 0)
			dfs_visit(i);
	reverse(sorted.begin(), sorted.end());
}
void dag_sp()
{
	topsort();
	for (int k = 0; k < sorted.size(); k++)
	{
		int v = sorted[k];
		for (int i = 0; i < g[v].size(); i++)
		{
			int u = g[v][i].second;
			int w = g[v][i].first;
			if (dist[v] + w < dist[u])
			{
				dist[u] = dist[v] + w;
				parent[u] = v;
			}
		}
	}
}

int main()
{
	while (scanf("%d %d", &n, &m) == 2)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				scanf("%d", &boxes[i][j]);

		for (int i = 0; i < n; i++)
			sort(boxes[i], boxes[i] + m);
		
		init();
		bool ij, ji;
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
			{
				ij = ji = true;
				for (int k = 0; k < m; k++)
				{
					if(boxes[i][k] >= boxes[j][k])
						ij = false;
					if(boxes[j][k] >= boxes[i][k])
						ji = false;
				}
				if(ij)
					g[i].push_back(ii(-1, j));
				else if(ji)
					g[j].push_back(ii(-1, i));
			}
		dag_sp();
		int min = 1;
		int fin;
		for (int i = 0; i < n; i++)
			if(dist[i] < min)
				min = dist[i], fin = i;
		int o = - (min - 1);
		stack<int> st;
		printf("%d\n", o);
		int k = fin;
		for (int i = 0; i < o; i++)
		{
			st.push(k);
			k = parent[k];
		}
		int a = 0;
		while (!st.empty())
		{
			if (a == 0)
				printf("%d", st.top() + 1);
			else
				printf(" %d", st.top() + 1);
			st.pop();
			a++;
		}
		printf("\n");
	}
}