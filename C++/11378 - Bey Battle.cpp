#include <bits/stdc++.h>
#define INF 2e8
using namespace std;
typedef long long ll;
struct Point
{
	ll x, y;
	Point() {}
	Point(ll px, ll py) : x(px) , y(py) {}

	bool operator < (const Point &b) const
	{
		return x < b.x || (x == b.x && y < b.y);
	}
};
ll operator ~ (const Point &a)
{
	return max(a.x, a.y);
}
Point operator - (const Point &a, const Point &b)
{
	return Point(abs(a.x - b.x), abs(a.y - b.y));
}
ll closestPair(vector<Point> v)
{
	int n = v.size();
	sort (v.begin(), v.end());
	set<Point> setX, setY;
	set<Point>::iterator it, itX, itY, lb, ub;
	ll res = INF;
	for (int i = 0; i < n; i++)
	{
		for (it = setX.begin(); it != setX.end(); itX = it++, setX.erase(itX))
			if (v[i].x - it->x > res)
				setY.erase(setY.lower_bound(Point(it->y, it->x)));
			else
				break;
		lb = setY.lower_bound(Point(v[i].y - res, -INF));
		ub = setY.upper_bound(Point(v[i].y + res, INF));
		while (lb != ub)
			res = min (res, ~(v[i] - Point(lb->y, lb->x))), lb++;
		setX.insert (v[i]);
		setY.insert (Point(v[i].y, v[i].x));
	}
	return res;
}
int main()
{
	int n;
	vector<Point> v;
	while (scanf("%d", &n) == 1)
	{
		v.clear(), v.resize(n);
		for (int i = 0; i < n; i++)
			scanf("%lld %lld", &v[i].x, &v[i].y);
		printf("%lld\n", closestPair(v));
	}
}