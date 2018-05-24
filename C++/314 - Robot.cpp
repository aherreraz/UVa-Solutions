#include <bits/stdc++.h>
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
using namespace std;
struct pos { int x, y, dir; };
int n, m;
pos s, e;
char in[10];
vector< vector<bool> > M;
int dist[51][51][4];
int auxDir[2] = {1, 3};
void bfs_visit()
{
	queue<pos> q; q.push(s), dist[s.x][s.y][s.dir] = 0;
	while (!q.empty())
	{
		pos v = q.front(); q.pop();
		if (v.dir == NORTH)
			for (int i = 1; i <= 3; i++)
			{
				pos u = v; u.x -= i;			
				if (u.x >= 0 && u.y >= 0 && u.x < n && u.y < m && !M[u.x][u.y])
				{
					if (dist[u.x][u.y][u.dir] == -1)
						q.push(u), dist[u.x][u.y][u.dir] = dist[v.x][v.y][v.dir] + 1;
				}
				else 
					break;
			}
		else if (v.dir == WEST)
			for (int i = 1; i <= 3; i++)
			{
				pos u = v; u.y -= i;				
				if (u.x >= 0 && u.y >= 0 && u.x < n && u.y < m && !M[u.x][u.y])
				{
					if (dist[u.x][u.y][u.dir] == -1)
						q.push(u), dist[u.x][u.y][u.dir] = dist[v.x][v.y][v.dir] + 1;
				}
				else 
					break;
			}
		else if (v.dir == SOUTH)
			for (int i = 1; i <= 3; i++)
			{
				pos u = v; u.x += i;			
				if (u.x >= 0 && u.y >= 0 && u.x < n && u.y < m && !M[u.x][u.y])
				{
					if (dist[u.x][u.y][u.dir] == -1)
						q.push(u), dist[u.x][u.y][u.dir] = dist[v.x][v.y][v.dir] + 1;
				}
				else 
					break;
			}
		else if (v.dir == EAST)
			for (int i = 1; i <= 3; i++)
			{
				pos u = v; u.y += i;			
				if (u.x >= 0 && u.y >= 0 && u.x < n && u.y < m && !M[u.x][u.y])
				{
					if (dist[u.x][u.y][u.dir] == -1)
						q.push(u), dist[u.x][u.y][u.dir] = dist[v.x][v.y][v.dir] + 1;
				}
				else 
					break;
			}
		for (int i = 0; i < 2; i++)
		{
			pos u = v; u.dir = (v.dir + auxDir[i]) % 4;
			
			if (u.x >= 0 && u.y >= 0 && u.x < n && u.y < m && !M[u.x][u.y] && dist[u.x][u.y][u.dir] == -1)
				q.push(u), dist[u.x][u.y][u.dir] = dist[v.x][v.y][v.dir] + 1;
		}
	}
}
int main()
{
	while (scanf("%d %d", &n, &m) == 2 && (n | m))
	{
		M.assign(n, vector<bool>(m, 1));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				int aux; scanf("%d", &aux); M[i][j] = aux;
				if (M[i][j])
				{
					if (i > 0 && j > 0) M[i - 1][j - 1] = 1;
					if (i > 0) M[i - 1][j] = 1;
					if (j > 0) M[i][j - 1] = 1;
				}
			}
			
		}
		n--, m--;
		scanf("%d %d %d %d %s", &s.x, &s.y, &e.x, &e.y, &in);
		if (in[0] == 's') s.dir = SOUTH;
		else if (in[0] == 'e') s.dir = EAST;
		else if (in[0] == 'n') s.dir = NORTH;
		else if (in[0] == 'w') s.dir = WEST;
		s.x--, s.y--, e.x--, e.y--;
		memset(dist, -1, sizeof(int) * 10404);
		if (s.x >= 0 && s.y >= 0 && s.x < n && s.y < m && !M[s.x][s.y])
		{
			bfs_visit();
			if (dist[e.x][e.y][0] == -1)
				printf("-1\n");
			else
				printf("%d\n", min (min(dist[e.x][e.y][0], dist[e.x][e.y][1]), min(dist[e.x][e.y][2], dist[e.x][e.y][3])));
		}
		else
			printf("-1\n");
	}
}