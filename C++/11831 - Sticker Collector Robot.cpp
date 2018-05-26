#include <bits/stdc++.h>
using namespace std;
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
struct pos
{
	int x, y, dir;
	pos() {}
	pos(int px, int py, int pdir) : x(px), y(py), dir(pdir) {}
};
int auxX[4] = {-1, 0, 1, 0};
int auxY[4] = {0, 1, 0, -1};
vector<string> M;
string orders;
int n, m, k;
pos curr;
int main()
{
	while (scanf("%d %d %d\n", &n, &m, &k) == 3 && (n | m | k))
	{
		M.resize(n);
		for (int i = 0; i < n; i++)
		{
			getline(cin, M[i]);
			for (int j = 0; j < m; j++)
				if (M[i][j] == 'N')
					curr = pos(i, j, NORTH);
				else if (M[i][j] == 'S')
					curr = pos(i, j, SOUTH);
				else if (M[i][j] == 'L')
					curr = pos(i, j, EAST);
				else if (M[i][j] == 'O')
					curr = pos(i, j, WEST);
		}
		getline(cin, orders);
		int res = 0;
		for (int i = 0; i < k; i++)
		{
			if (orders[i] == 'D')
				curr.dir = (curr.dir + 1) % 4;
			else if (orders[i] == 'E')
				curr.dir = (curr.dir + 3) % 4;
			else if (orders[i] == 'F')
			{
				pos newPos = pos(curr.x + auxX[curr.dir], curr.y + auxY[curr.dir], curr.dir);
				if (newPos.x >= 0 && newPos.x < n && newPos.y >= 0 && newPos.y < m && M[newPos.x][newPos.y] != '#')
				{
					curr = newPos;
					if (M[newPos.x][newPos.y] == '*')
						res++, M[newPos.x][newPos.y] = '.';
				}
			}
		}
		printf("%d\n", res);
	}
}