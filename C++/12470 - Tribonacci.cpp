#include <bits/stdc++.h>
#define MAXN 3
#define TIPO long long
TIPO MOD;

struct Matrix
{
	TIPO M[MAXN][MAXN];
	Matrix operator * (Matrix &X)
	{
		Matrix ret;
		memset (ret.M, 0, sizeof ret.M);
		for (int i = 0; i < MAXN; i++)
			for (int j = 0; j < MAXN; j++)
				for (int k = 0; k < MAXN; k++)
				{
					ret.M[i][j] += M[i][k] * X.M[k][j] % MOD;
					ret.M[i][j] %= MOD;
				}
		return ret;
	}
	
	Matrix pow (TIPO n)
	{
		Matrix ret, aux = *this;
		for (int i = 0; i < MAXN; i++)
			for (int j = 0; j < MAXN; j++)
				ret.M[i][j] = (i == j);
			
		while (n)
		{
			if (n & 1)
				ret = ret * aux;
			aux = aux * aux;
			n >>= 1;
		}
		return ret;
	}
};

int main()
{
	MOD = 1000000009LL;
	Matrix v;
	v.M[0][0] = 1LL;
	v.M[0][1] = 0LL;
	v.M[0][2] = 0LL;
	v.M[1][0] = 0LL;
	v.M[1][1] = 0LL;
	v.M[1][2] = 0LL;
	v.M[2][0] = 1LL;
	v.M[2][1] = 0LL;
	v.M[2][2] = 0LL;
	TIPO n;
	while (scanf("%lld\n", &n) == 1 && n != 0)
	{
		Matrix m;
		m.M[0][0] = 1LL;
		m.M[0][1] = 1LL;
		m.M[0][2] = 1LL;
		m.M[1][0] = 1LL;
		m.M[1][1] = 0LL;
		m.M[1][2] = 0LL;
		m.M[2][0] = 0LL;
		m.M[2][1] = 1LL;
		m.M[2][2] = 0LL;
		m = m.pow(n);
		m = m * v;
		printf("%lld\n", m.M[2][0]);
	}
	
}