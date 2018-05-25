#include <bits/stdc++.h>
using namespace std;

int tiempo[3][15];
int dp[4100][300][3];
int n;
int solve(int solved, int timeLeft, int lastPerson)
{
	if (timeLeft < 0)
		return 0;
	if (dp[solved][timeLeft][lastPerson] != -1)
		return dp[solved][timeLeft][lastPerson];
	
	int res = 0;
	//printf("ENTRO %d %d %d\n", solved, timeLeft, lastPerson);
	for (int i = 0; i < n; i++)
	{
		int t1 = 0, t2 = 0, t3 = 0, aux;
		if (timeLeft >= tiempo[0][i] && lastPerson != 1 && !(solved & (1 << i)))
			t1 = 1 + solve(solved | (1 << i), timeLeft - tiempo[0][i], 1);
		if (timeLeft >= tiempo[1][i] && lastPerson != 2 && !(solved & (1 << i)))
			t2 = 1 + solve(solved | (1 << i), timeLeft - tiempo[1][i], 2);
		if (timeLeft >= tiempo[2][i] && lastPerson != 3 && !(solved & (1 << i)))
			t3 = 1 + solve(solved | (1 << i), timeLeft - tiempo[2][i], 3);
		
		aux = max(t1, max(t2, t3));
		if (aux > res)
			res = aux;
	}
	
	return dp[solved][timeLeft][lastPerson] = res;
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		for (int i = 0; i < 4100; i++)
			for (int j = 0; j < 300; j++)
				dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = -1;
				
		scanf("%d", &n);
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &tiempo[i][j]);
		
		printf("%d\n", solve(0, 280, 0));
	}
}