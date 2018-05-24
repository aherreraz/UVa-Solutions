#include <bits/stdc++.h>
#define MAX 15

int n;
char p1[MAX][MAX], p2[MAX][MAX];
bool comparar(int si, int sj, int ei, int ej, bool r)
{
	for (int i = 0, I = si; i < n; i++, si < ei ? I++ : I--)
		for (int j = 0, J = sj; j < n; j++, sj < ej ? J++ : J--)
		{
			if ((r && p1[i][j] != p2[J][I]) || (!r && p1[i][j] != p2[I][J]))
				return false;
		}
	return true;
}
int main()
{
	int caso = 1;
	while (scanf("%d", &n) == 1)
	{
		for (int i = 0; i < n; i++)
			scanf("%s %s", &p1[i], &p2[i]);
		if (comparar(0, 0, n, n, 0))
			printf("Pattern %d was preserved.\n", caso);
		else if (comparar(n - 1, 0, 0, n, 1))
			printf("Pattern %d was rotated 90 degrees.\n", caso);
		else if (comparar(n - 1, n - 1, 0, 0, 0))
			printf("Pattern %d was rotated 180 degrees.\n", caso);
		else if (comparar(0, n - 1, n, 0, 1))
			printf("Pattern %d was rotated 270 degrees.\n", caso);
		else if (comparar(n - 1, 0, 0, n, 0))
			printf("Pattern %d was reflected vertically.\n", caso);
		else if (comparar(0, 0, n, n, 1))
			printf("Pattern %d was reflected vertically and rotated 90 degrees.\n", caso);
		else if (comparar(0, n - 1, n, 0, 0))
			printf("Pattern %d was reflected vertically and rotated 180 degrees.\n", caso);
		else if (comparar(n - 1, n - 1, 0, 0, 1))
			printf("Pattern %d was reflected vertically and rotated 270 degrees.\n", caso);
		else
			printf("Pattern %d was improperly transformed.\n", caso);
		caso++;
	}
}