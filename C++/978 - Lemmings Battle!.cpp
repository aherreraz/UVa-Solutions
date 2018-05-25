#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
priority_queue<int> v1;
priority_queue<int> v2;
vector<ii> bf;
int t, n, n1, n2, aux;

int main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d %d", &n, &n1, &n2);
		for (int i = 0; i < n1; i++)
			scanf("%d", &aux), v1.push(aux);
		for (int i = 0; i < n2; i++)
			scanf("%d", &aux), v2.push(aux);
		bf.assign(n, ii(0, 0));
		while (!v1.empty() && !v2.empty())
		{
			for (int i = 0; i < n; i++)
				if (!v1.empty() && !v2.empty())
					bf[i] = ii(v1.top(), v2.top()), v1.pop(), v2.pop();
				else
					bf[i] = ii(0, 0);
			for (int i = 0; i < n; i++)
				if (bf[i].first > bf[i].second)
					v1.push(bf[i].first - bf[i].second);
				else if (bf[i].second > bf[i].first)
					v2.push(bf[i].second - bf[i].first);
		}
		if (v1.empty() && v2.empty())
			printf("green and blue died\n");
		else if (v2.empty())
		{
			printf("green wins\n");
			while (!v1.empty())
				printf("%d\n", v1.top()), v1.pop();
		}
		else if (v1.empty())
		{
			printf("blue wins\n");
			while (!v2.empty())
				printf("%d\n", v2.top()), v2.pop();
		}
		if (t) printf("\n");
	}
}
