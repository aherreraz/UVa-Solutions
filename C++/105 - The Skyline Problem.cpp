#include <bits/stdc++.h>
using namespace std;
struct building { int l, r, h; };

int main()
{
	building b;
	vector<building> v;
	vector<int> h;
	h.resize(10010,0);
	while (scanf("%d %d %d", &b.l , &b.h, &b.r) == 3)
		v.push_back(b);
	
	int n = v.size();
	int last = 0;
	for (int i = 0; i < n; i++)
		for (int j = v[i].l; j < v[i].r; j++)
		{
			h[j] = max(h[j], v[i].h);
			last = max(last, j);
		}
	for (int i = v[0].l; i <= last; i++)
		if (h[i] != h[i - 1])
			printf("%d %d ", i, h[i]);
	printf("%d %d\n", last + 1, 0);
}
