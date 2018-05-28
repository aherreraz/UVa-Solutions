#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sieve_size;
bitset<100010> bs;
vector<ll> primes;
void sieve (ll upperbound)
{
	sieve_size = upperbound + 1;
	bs.set(); bs[0] = bs[1] = 0;
	for (ll i = 2; i <= sieve_size; i++)
		if (bs[i])
		{
			for (ll j = i * i; j <= sieve_size; j += i)
				bs[j] = 0;
			primes.push_back(i);
		}
}
vector<ll> primeFactors (ll N)
{
	vector<ll> factors;
	ll idx = 0, PF = primes[idx];
	while (N != 1 && PF * PF <= N)
	{
		if (N % PF == 0) factors.push_back(PF);
		while (N % PF == 0) N /= PF;
		PF = primes[++idx];
	}
	if (N != 1) factors.push_back(N);
	return factors;
}
ll EulerPhi (ll N)
{
	vector<ll> factors = primeFactors(N);
	ll res = N;
	int n = factors.size();
	for (int i = 0; i < n; i++)
		res = res - res / factors[i];
	return res;
}

int main()
{
	sieve(100001);
	ll n;
	while (scanf("%lld", &n) == 1)
	{
		printf("%lld\n", EulerPhi(n) / 2);
	}
}