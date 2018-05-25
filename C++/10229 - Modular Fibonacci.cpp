#include <bits/stdc++.h>
#define MAXN 2
#define TIPO long long
TIPO MOD;

struct Matrix
{
	TIPO M[MAXN][MAXN];
	Matrix operator * (Matrix &X)
	{
		Matrix ret; memset(ret.M, 0, sizeof ret.M);
		for(int i = 0; i < MAXN; i++)
			for(int j = 0; j < MAXN; j++)
				for(int k = 0; k < MAXN; k++)
					ret.M[i][j] += M[i][k] * X.M[k][j] % MOD, ret.M[i][j] %= MOD;
		return ret;
	}
	Matrix pow(int n)
	{
		Matrix ret, aux = *this;
		for(int i = 0; i < MAXN; i++)
			for(int j = 0; j < MAXN; j++)
				ret.M[i][j] = (i == j);
		while(n)
		{
			if(n & 1) ret = ret * aux;
			aux = aux * aux; n >>= 1;
		}
		return ret;
	}
};


int main()
{Matrix m;
	TIPO n, k;
	while (scanf("%lld %lld", &n, &k) != EOF )
	{
		MOD = 1 << k;
		m.M[0][0] = 1;
		m.M[0][1] = 1;
		m.M[1][0] = 1;
		m.M[1][1] = 0;
		
		printf("%lld\n", m.pow(n).M[0][1]);
	}
}
