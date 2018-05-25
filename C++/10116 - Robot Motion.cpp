#include <bits/stdc++.h>
#define EXIT 1
#define LOOP 2
using namespace std;
typedef pair<int, int> ii;

int n, m;
ii s;
ii res;
vector<string> M;
vector< vector<int> > dist;
int auxX[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0};
int auxY[26] = {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0};
int bfs()
{
	queue<ii> q; q.push(s), dist[s.first][s.second] = 0;
	while (!q.empty())
	{
		ii v = q.front(); q.pop();
		ii u = ii(v.first + auxX[M[v.first][v.second] - 'A'], v.second + auxY[M[v.first][v.second] - 'A']);
		if (u.first < 0 || u.first >= n || u.second < 0 || u.second >= m)
		{
			res = ii(dist[v.first][v.second] + 1, 0);
			return EXIT;
		}
		if (dist[u.first][u.second] != -1)
		{
			res = ii(dist[u.first][u.second], dist[v.first][v.second]);
			return LOOP;
		}
		dist[u.first][u.second] = dist[v.first][v.second] + 1;
		q.push(u);
	}
	return 0;
}
int main()
{
	while (scanf("%d %d %d\n", &n, &m, &s.second) == 3 && (n | m | s.second))
	{
		s.second--, s.first = 0;
		M.resize(n), dist.assign(n, vector<int>(m, -1));
		for (int i = 0; i < n; i++)
			getline(cin, M[i]);
		int ans = bfs();
		if (ans == EXIT)
			printf("%d step(s) to exit\n", res.first);
		else
			printf("%d step(s) before a loop of %d step(s)\n", res.first, res.second - res.first + 1);
	}
}