#include <bits/stdc++.h>
#define MAXSIZE 110
#define MAXINT 2147483648
using namespace std;

int n;
int M[MAXSIZE][MAXSIZE];

int maxSum1D(int v[], int &x, int &y)
{
	int sum = 0, ki = 0, maxsum = -1; x = y = -1;
	for (int i = 0; i < n; i++)
	{
		sum += v[i];
		if (sum > maxsum)
			maxsum = sum, x = ki, y = i;
		if (sum < 0)
			sum = 0, ki = i + 1;
	}
	return maxsum;
}

int maxSum2D()
{
	int tmp[MAXSIZE], y1, y2, cur, maxsum = -1;
	for (int i = 0; i < n; i++)
	{
		memset(tmp, 0, sizeof tmp);
		for (int j = i; j < n; j++)
		{
			for (int k = 0; k < n; k++)
				tmp[k] += M[j][k];
			cur = maxSum1D(tmp, y1, y2);
			maxsum = max(maxsum, cur);
		}
	}
	return maxsum;
}

int main()
{
	while (scanf("%d\n",&n) != EOF)
	{
		for (int i = 0; i < n ; i++)
			for (int j = 0; j < n ; j++)
				scanf("%d", &M[i][j]);
		printf("%d\n", maxSum2D());
	}
}