#include <bits/stdc++.h>
using namespace std;
int n, q, a, b;
string in;
char cIn[200];
vector< vector<int> > g, dist, parent;
void bfs_visit(int start)
{
	queue<int> q; q.push(start), dist[start][start] = 0;
	while (!q.empty())
	{
		int v = q.front(); q.pop();
		for (int i = 0; i < g[v].size(); i++)
		{
			int u = g[v][i];
			if (dist[start][u] == -1)
				dist[start][u] = dist[start][v] + 1, q.push(u), parent[start][u] = v;
		}
	}
}
vector<string> split(char *input, char *tokens)
{
	vector<string> res;
	char *p;
	p = strtok(input, tokens);
	while(p != NULL)
		res.push_back(p), p = strtok(NULL, tokens);
	return res;
}
void bfs_all()
{
	for (int i = 0; i < n; i++)
		bfs_visit(i);
}

int main()
{
	while (scanf("%d\n", &n) == 1)
	{
		g.assign(n, vector<int>());
		dist.assign(n, vector<int>(n, -1));
		parent.assign(n, vector<int>(n, -1));
		for (int i = 0; i < n; i++)
		{
			getline(cin, in);
			strcpy(cIn, in.c_str());
			vector<string> v = split(cIn, "-,");
			int m = v.size();
			sscanf(v[0].c_str(), "%d", &a), a--; 
			for (int i = 1; i < m; i++)
				sscanf(v[i].c_str(), "%d", &b), b--, g[a].push_back(b); 
		}
		bfs_all();
		scanf("%d", &q);
		printf("-----\n");
		for (int i = 0; i < q; i++)
		{
			scanf("%d %d", &a, &b), a--, b--;
			if (dist[a][b] == -1)
				printf("connection impossible\n");
			else
			{
				stack<int> res;
				res.push(b);
				while (res.top() != a)
					res.push(parent[a][res.top()]);
				while (!res.empty())
				{
					printf("%d", res.top() + 1);
					res.pop();
					if (!res.empty())
						printf(" ");
				}
				printf("\n");
			}
		}
	}
}