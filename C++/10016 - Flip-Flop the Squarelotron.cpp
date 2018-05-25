#include <bits/stdc++.h>
#define MAX 110
using namespace std;
int n, r;
int M[MAX][MAX];
int M2[MAX][MAX];
struct ring
{
	int si, sj, ei, ej, r;
	ring () {}
	ring (int s, int e) : si(s), sj(s), ei(e), ej(e), r(0) {}
	void oper(int op)
	{
		switch (op)
		{
			case 1: swap(si, ei); return;
			case 2: swap(sj, ej); return;
			case 3: r = !r; swap(si, sj); swap(ei, ej); return;
			case 4: r = !r; swap(si, ej); swap(sj, ei); return;
		}
	}
};
ring R[MAX];

void copy(int SI, int SJ, int EI, int EJ, bool r)
{
	int si = min(SI, EI), ei = max(SI, EI);
	int sj = min(SJ, EJ), ej = max(SJ, EJ);
	for (int i = si, I = SI; i <= ei; i++, SI < EI ? I++ : I--)
		for (int j = sj, J = SJ; j <= ej; j++, SJ < EJ ? J++ : J--)
			if (I == SI || I == EI || J == SJ || J == EJ)
				r ? M2[I][J] = M[j][i] : M2[I][J] = M[i][j];
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &M[i][j]);
		r = (n + 1) / 2;
		for (int i = 0; i < r; i++)
			R[i] = ring(i, n - i - 1);
		int o, aux;
		for (int i = 0; i < r; i++)
		{
			scanf("%d", &o);
			for (int j = 0; j < o; j++)
			{
				scanf("%d", &aux);
				R[i].oper(aux);
			}
		}
		for (int i = 0; i < r; i++)
			copy(R[i].si, R[i].sj, R[i].ei, R[i].ej, R[i].r);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				j == 0 ? printf("%d", M2[i][j]) : printf(" %d", M2[i][j]);
			printf("\n");
		}
	}
}