#include <bits/stdc++.h>
#define ARRIBA 0
#define ABAJO 1
#define IZQUIERDA 2
#define DERECHA 3
using namespace std;
typedef pair<int, int> ii;
bool mov[610][610][4];
bool visited[610][610];
// ARRIBA // ABAJO // IZQUIERDA // DERECHA
int auxX[4] = {-1, 1, 0, 0};
int auxY[4] = {0, 0, -1, 1};
int n, N, M;

void bfs_visit(ii s)
{
	queue<ii> q; q.push(s), visited[s.first][s.second] = 1;
	while (!q.empty())
	{
		ii v = q.front(); q.pop();
		for (int i = 0; i < 4; i++)
		{
			if (!mov[v.first][v.second][i]) continue;
			ii u = ii(v.first + auxX[i], v.second + auxY[i]);
			if (u.first >= 0 && u.first < N && u.second >= 0 && u.second < M && !visited[u.first][u.second])
				q.push(u), visited[u.first][u.second] = 1;
		}
	}
}
int bfs()
{
	int res = 0;
	memset(visited, 0, sizeof visited);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (!visited[i][j])
			{
				bfs_visit(ii(i, j));
				res++;
			}
	return res;
}
int main()
{
	while (scanf("%d\n", &n) == 1)
	{
		memset(mov, 1, sizeof mov);
		for (int i = 0; i < 2 * n - 1; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int x = i, y = 2 * j + (i & 1);
				char c;	scanf("%c", &c);
				if (c == 'H')
					mov[x][y][ABAJO] = mov[x][y + 1][ABAJO] = mov[x + 1][y][ARRIBA] = mov[x + 1][y + 1][ARRIBA] = 0;
				else
					mov[x][y][DERECHA] = mov[x + 1][y][DERECHA] = mov[x][y + 1][IZQUIERDA] = mov[x + 1][y + 1][IZQUIERDA] = 0;
			}
			scanf("\n");
		}
		N = 2 * n, M = 2 * n + 1;
		printf("%d\n", bfs() - 1);
	}
}