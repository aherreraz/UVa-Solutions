#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int n, m, nb;
vector< vector<bool> > M;
vector< vector<int> > dist;
int auxX[4] = {-1, 0, 0, 1};
int auxY[4] = {0, -1, 1, 0};
void bfs_visit(ii s)
{
	queue<ii> q; q.push(s), dist[s.first][s.second] = 0;
	while (!q.empty())
	{
		ii v = q.front(); q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = v.first + auxX[i];
			int ny = v.second + auxY[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && dist[nx][ny] == -1 && M[nx][ny])
				q.push(ii(nx, ny)), dist[nx][ny] = dist[v.first][v.second] + 1;
		}
	}
}
int main()
{
	while (scanf("%d %d", &n, &m) == 2 && (n | m))
	{
		M.assign(n, vector<bool>(m, 1));
		scanf("%d", &nb);
		for (int i = 0; i < nb; i++)
		{
			int r, nr, c;
			scanf("%d %d", &r, &nr);
			for (int j = 0; j < nr; j++)
				scanf("%d", &c), M[r][c] = 0;
		}
		ii s, e;
		scanf("%d %d %d %d", &s.first, &s.second, &e.first, &e.second);
		dist.assign(n, vector<int>(m, -1));
		bfs_visit(s);
		printf("%d\n", dist[e.first][e.second]);
	}
}