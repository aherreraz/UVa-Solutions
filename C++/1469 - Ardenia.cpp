#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b)
{
	return (b == 0) ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
	return a * (b / gcd(a , b));
}
struct Fraction
{
	ll num, deno;
	Fraction(ll n = 0, ll d = 1)
	{
		ll GCD = gcd(n, d);
		num = n / GCD;
		deno = d / GCD;
	}
};
Fraction operator + (const Fraction &a, const Fraction &b)
{
	ll deno = a.deno == b.deno ? a.deno : lcm(a.deno, b.deno);
	ll num = (deno / a.deno) * a.num + (deno / b.deno) * b.num;
	ll GCD = gcd(num, deno);
	return Fraction(num / GCD, deno / GCD);
}
Fraction operator - (const Fraction &a, const Fraction &b)
{
	ll deno = a.deno == b.deno ? a.deno : lcm(a.deno, b.deno);
	ll num = deno / a.deno * a.num - deno / b.deno * b.num;
	ll GCD = gcd(num, deno);
	return Fraction(num / GCD, deno / GCD);
}
Fraction operator * (const Fraction &a, const Fraction &b)
{
	ll gcd1 = gcd(a.num, b.deno);
	ll gcd2 = gcd(b.num, a.deno);
	return Fraction((a.num / gcd1) * (b.num / gcd2), (a.deno / gcd2) * (b.deno / gcd1));
}
Fraction operator * (const Fraction &a, const ll &s)
{
	ll GCD = gcd(a.num * s, a.deno);
	return Fraction(a.num * s / GCD, a.deno / GCD);
}
Fraction operator / (const Fraction &a, const Fraction &b)
{
	ll gcd1 = gcd(a.num, b.num);
	ll gcd2 = gcd(a.deno, b.deno);
	return Fraction((a.num / gcd1) * (b.deno / gcd2), (a.deno / gcd2) * (b.num / gcd1));
}
Fraction ZERO(0, 1);

struct Point
{
	Fraction x, y, z;
	Point(ll px = 0, ll py = 0, ll pz = 0) : x(px, 1) , y(py, 1), z(pz, 1) {}
	Point(Fraction px, Fraction py, Fraction pz) : x(px) , y(py), z(pz) {}
};
struct Segment
{
	Point p0, p1;
	Segment() {}
	Segment(Point pa, Point pb) : p0(pa), p1(pb) {}
	Segment(ll p0x, ll p0y, ll p1x, ll p1y, ll p0z, ll p1z) : p0(p0x, p0y, p0z) , p1(p1x, p1y, p1z) {}
};
Point operator + (const Point &a, const Point &b)
{
	return Point(a.x + b.x, a.y + b.y, a.z + b.z);
}
Point operator - (const Point &a, const Point &b)
{
	return Point(a.x - b.x, a.y - b.y, a.z - b.z);
}
Point operator * (const Point &a, const double &s)
{
	return Point(a.x * s, a.y * s, a.z * s);
}
Point operator * (const Point &a, const Fraction &s)
{
	return Point(a.x * s, a.y * s, a.z * s);
}
Fraction operator * (const Point &a, const Point &b)
{
	return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}
Fraction operator ~ (const Point &a)
{
	return (a.x * a.x) + (a.y * a.y) + (a.z * a.z);
}
Fraction operator < (const Fraction &a, const Fraction &b)
{
	return a.num * b.deno < a.deno * b.num ? a : b;
}

Fraction distanciaSegmentos(const Segment &a, const Segment &b)
{
	Point u = a.p1 - a.p0;
	Point v = b.p1 - b.p0;
	Point w0 = a.p0 - b.p0;

	Fraction A = u * u;
	Fraction B = u * v;
	Fraction C = v * v;
	Fraction D = u * w0;
	Fraction E = v * w0;

	Fraction num1 = (B * E) - (C * D);
	Fraction num2 = (A * E) - (B * D);
	Fraction deno = (A * C) - (B * B);
	Fraction s, t;
	
	if (deno.num == 0)
	{
		s.num = 0;
		t = E / C;
	}
	else
	{
		s = num1 / deno;
		t = num2 / deno;

		if (s.num < 0 || s.deno < 0)
		{
			s.num = 0;
			t = E / C;
		}
		else if (s.num > s.deno)
		{
			s.num = s.deno;
			t = (E + B) / C;
		}
	}

	bool recalcular = false;
	if (t.num < 0 || t.deno < 0)
	{
		t.num = 0;
		D.num *= -1;
		recalcular = true;
	}
	else if (t.num > t.deno)
	{
		t.num = t.deno;
		D = B - D;
		recalcular = true;
	}

	if (recalcular)
	{
		Fraction m = ZERO < D;
		Fraction M = A < D;
		if (m.num == D.num && m.deno == D.deno)
			s.num = 0;
		else if (M.num == A.num && M.deno == A.deno)
			s.num = s.deno;
		else
			s = D / A;
	}
	return ~(w0 + (u * s) - (v * t));
}
int main()
{
	int T;
	scanf("%d", &T);
	
	while(T--)
	{
		Segment a, b;
		scanf("%lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld", &a.p0.x, &a.p0.y, &a.p0.z, &a.p1.x, &a.p1.y, &a.p1.z, &b.p0.x, &b.p0.y, &b.p0.z, &b.p1.x, &b.p1.y, &b.p1.z);
		Fraction r = distanciaSegmentos(a, b);
		printf("%lld %lld\n", r.num, r.deno);
	}
}
