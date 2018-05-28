#include <stdio.h>
#include <string.h>

char in[110];
int main()
{
	int t, n;
	scanf("%d", &t);
	for (int z = 1; z <= t; z++)
	{
		scanf("%d %s", &n, &in);
		int res = 0;
		for (int i = 0; i < n; i++)
		{
			if (in[i] == '.')
				res++, in[i + 1] = in[i + 2] = '#';
		}
		printf("Case %d: %d\n", z, res);
	}
}
