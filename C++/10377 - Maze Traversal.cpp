#include <bits/stdc++.h>
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
using namespace std;
struct pos
{
	int x, y, dir;
	pos() {}
	pos(int px, int py, int pdir) : x(px), y(py), dir(pdir) {}
};
int t, n, m;
char c;
pos curr;
vector<string> M;
int auxX[4] = {-1, 0, 1, 0};
int auxY[4] = {0, 1, 0, -1};
int main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d\n", &n, &m);
		M.resize(n);
		for (int i = 0; i < n; i++)
			getline(cin, M[i]);
		scanf("%d %d\n", &curr.x, &curr.y);
		curr.x--, curr.y--, curr.dir = NORTH;
		while (scanf("%c", &c) && c != 'Q')
		{
			if (c == 'R')
				curr.dir = (curr.dir + 1) % 4;
			else if (c == 'L')
				curr.dir = (curr.dir + 3) % 4;
			else if (c == 'F')
			{
				pos newPos = pos(curr.x + auxX[curr.dir], curr.y + auxY[curr.dir], curr.dir);
				if (newPos.x >= 0 && newPos.x < n && newPos.y >= 0 && newPos.y < m && M[newPos.x][newPos.y] == ' ')
					curr = newPos;
			}
		}
		if (curr.dir == NORTH)
			printf("%d %d N\n", ++curr.x, ++curr.y);
		if (curr.dir == EAST)
			printf("%d %d E\n", ++curr.x, ++curr.y);
		if (curr.dir == SOUTH)
			printf("%d %d S\n", ++curr.x, ++curr.y);
		if (curr.dir == WEST)
			printf("%d %d W\n", ++curr.x, ++curr.y);
		if (t) printf("\n");
	}
}