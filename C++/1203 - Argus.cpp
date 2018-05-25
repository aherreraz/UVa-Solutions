#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int v[3010];
priority_queue<ii, vector<ii>, greater<ii> > pq;
char in[20];
int id, frec, k;
int main()
{
	memset(v, 0, sizeof v);
	while (scanf("%s", &in) == 1 && in[0] != '#')
		scanf("%d %d", &id, &frec), v[id] = frec, pq.push(ii(frec, id));
	scanf("%d", &k);
	while (k--)
	{
		ii a = pq.top(); pq.pop();
		printf("%d\n", a.second);
		pq.push(ii(a.first + v[a.second], a.second));
	}
}