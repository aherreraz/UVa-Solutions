#include <bits/stdc++.h>
using namespace std;
const int N = 210, M = 105;
int n, m, h, z;

struct event
{
	double x, y1, y2;
	int posY1, posY2;
	int inc;
	event() {}
	event(double px, double py1, double py2, int pinc) : x(px), y1(py1), y2(py2), inc(pinc) {}
};
struct node
{
	int a;
	double b;
	node () {}
	node (int pa, double pb) : a(pa), b(pb) {}
};

double q[2 * N];
event ev[2 * M];
node t[2 * N];
set<double> yCoord;
double s[2 * M]; 
map<double, int> yPos;

bool comparar(event a, event b)
{
	return a.x < b.x;
}
void build()
{
	n = z - 1;
	for (int i = n; i < 2 * n; i++)
		t[i] = node(0, 0), q[i] = s[i + 1 - n] - s[i - n];
	for (int i = n - 1; i > 0; i--)
	{
		q[i] = q[i << 1] + q[i << 1 | 1];
		t[i] = node(0, 0);
	}
	h = sizeof(int) * 8 - __builtin_clz(n);
}

void pull (int i)
{
	do 
	{
		if (t[i].a)
			t[i].b = q[i];
		else if (i < n)
			t[i].b = t[i << 1].b + t[i << 1 | 1].b;
		else
			t[i].b = 0.0;
	} while (i >>= 1);
}

void inc (int l, int r, int val)
{
	int l0 = l + n, r0 = r + n;
	for (l += n, r += n; l <= r; l++, r--, l >>= 1, r >>= 1)
	{
		if (  l & 1 ) t[l].a += val, pull(l);
		if (!(r & 1)) t[r].a += val, pull(r);
	}
}

void compress()
{
	sort (s, s + z);
	sort(ev, ev + 2 * m, comparar);
	for (int i = 0; i < z; i++)
		yPos[s[i]] = i;
	for (int i = 0; i < 2 * m; i++)
		ev[i].posY1 = yPos[ev[i].y1], ev[i].posY2 = yPos[ev[i].y2];
}

int main()
{
	int caso = 1;
	while (scanf("%d", &m) == 1 && m != 0)
	{
		yCoord.clear();
		yPos.clear();
		z = 0;
		for (int i = 0; i < m; i++)
		{
			double x, y, r;
			scanf("%lf %lf %lf", &x, &y, &r);
			ev[i] = event(x - r, y - r, y + r, 1);
			ev[i + m] = event(x + r, y - r, y + r, -1);
			if (yCoord.find (y - r) == yCoord.end())
				yCoord.insert(y - r), s[z++] = y - r;
			if (yCoord.find (y + r) == yCoord.end())
				yCoord.insert(y + r), s[z++] = y + r;
		}
		compress();
		build();
		double res = 0.0;
		for (int i = 0; i < 2 * m; i++)
		{
			if (i > 0)
				res += (t[1].b * (ev[i].x - ev[i - 1].x));
			inc (ev[i].posY1, ev[i].posY2 - 1, ev[i].inc);
		}
		printf("%d %.2lf\n", caso++, res);
	}
}