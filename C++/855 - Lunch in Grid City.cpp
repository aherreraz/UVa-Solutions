#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

int x, y, n, t;
vector <ii> v;
bool compY(ii a, ii b)
{
	return a.second < b.second || (a.second == b.second && a.first < b.first);
}
int main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d %d", &x, &y, &n);
		v.resize(n);
		for (int i = 0; i < n; i++)
			scanf("%d %d", &v[i].first, &v[i].second);
		sort (v.begin(), v.end());
		printf("(Street: %d, ", v[(n - 1) / 2].first);
		sort (v.begin(), v.end(), compY);
		printf("Avenue: %d)\n", v[(n - 1) / 2].second);
	}
}