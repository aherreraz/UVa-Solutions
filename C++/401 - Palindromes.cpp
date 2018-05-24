#include <bits/stdc++.h>
char m[36] = {'A','*','*','*','3','*','*','H','I','L','*','J','M','*','O','*','*','*','2','T','U','V','W','X','Y','5','1','S','E','*','Z','*','*','8','*'};

char mirror(char a)
{
	if (a >= 'A' && a <= 'Z') return m[a - 'A'];
	return m[a - '1' + 26];
}
char in[30];
int main()
{
	while (scanf("%s", &in) == 1)
	{
		bool isMirror = 1, isPalindrome = 1;
		int n = strlen(in);
		for (int i = 0; i < (n + 1) / 2; i++)
		{
			if (in[i] != in[n - i - 1]) isPalindrome = false;
			if (in[i] != mirror(in[n - i - 1])) isMirror = false;
		}
		if (isMirror && isPalindrome) printf("%s -- is a mirrored palindrome.\n\n", in);
		else if (isMirror) printf("%s -- is a mirrored string.\n\n", in);
		else if (isPalindrome) printf("%s -- is a regular palindrome.\n\n", in);
		else printf("%s -- is not a palindrome.\n\n", in);
	}
}