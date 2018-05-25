#include <bits/stdc++.h>
#define MAX 55
int n;
struct card
{
	char card[5];
	int sz;
};
struct res
{
	int next;
	char card[5];
};
char aux[25];
card v[MAX];
res r[MAX];
int main()
{
	while (scanf("%d", &n) && n)
	{
		for (int i = 0; i < n; i++)
			scanf("%s %s", &v[i].card, &aux), v[i].sz = strlen(aux);
		for (int i = 0; i < n; i++)
			r[i].next = (i + 1) % n, strcpy(r[i].card, "");
		int pos = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = i == 0? 1 : 0; j < v[i].sz; j++)
			{
				while (strlen(r[r[pos].next].card) != 0)
					r[pos].next = r[r[pos].next].next;
				pos = r[pos].next;				
			}
			strcpy(r[pos].card, v[i].card);
		}
		for (int i = 0; i < n; i++)
			if (i == 0)
				printf ("%s", r[i].card);
			else
				printf (" %s", r[i].card);
		printf("\n");
	}
}