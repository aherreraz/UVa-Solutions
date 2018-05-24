#include <bits/stdc++.h>
#define MAX 1000
struct data
{
	char name[15];
	int b;
	int by;
	int m;
	int lb[15];
	int ub[15];
	int c[15];
};
int n, r;

data v[MAX];
int c[MAX];
int q[MAX];
char qname[15];

int main()
{
	while (scanf("%d %d", &n, &r) == 2)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%s %d %d %d", &v[i].name, &v[i].b, &v[i].by, &v[i].m);
			for (int j = 1; j <= v[i].m; j++)
				scanf("%d %d", &v[i].lb[j], &v[i].ub[j]);
			
			v[i].c[v[i].m] = v[i].by;
			
			for (int j = v[i].m - 1; j > 0; j--)
				v[i].c[j] = v[i].c[j + 1] * (v[i].ub[j + 1] - v[i].lb[j + 1] + 1);
			
			v[i].c[0] = v[i].b;
			for (int j = 1; j <= v[i].m; j++)
				v[i].c[0] -= v[i].c[j] * v[i].lb[j];
		}
		for (int i = 0; i < r; i++)
		{
			scanf("%s", &qname);
			int p;
			for (p = 0; p < n; p++)
				if (strcmp(qname, v[p].name) == 0)
					break;
			int res = v[p].c[0];
			for (int j = 0; j < v[p].m; j++)
			{
				scanf("%d", &q[j]);
				res += q[j] * v[p].c[j + 1];
			}
			printf("%s[", v[p].name);
			for (int j = 0; j < v[p].m; j++)
				if (j == 0)
					printf("%d", q[j]);
				else
					printf(", %d", q[j]);
			printf("] = %d\n", res);
		}
	}
}