#include <bits/stdc++.h>
using namespace std;
int t, n;
string in;
int main()
{
	scanf("%d\n", &t);
	while (t--)
	{
		getline(cin, in);
		n = in.length();
		stack<char> s;
		for (int i = 0; i < n; i++)
			if (in[i] == '(' || in[i] == '[' || (s.empty() && (in[i] == ')' || in[i] == ']')))
				s.push(in[i]);
			else if ((in[i] == ')' && s.top() == '(') || (in[i] == ']' && s.top() == '['))
				s.pop();
		if (s.empty())
			printf("Yes\n");
		else
			printf("No\n");
	}
}