#include <bits/stdc++.h>
using namespace std;
typedef pair<string, string> ss;
string in;
int n;
set<string> ignr;
multimap<string, string> idx;
multimap<string, string>::iterator it;
int main()
{
	while (getline(std::cin, in) && in.compare("::") != 0)
		ignr.insert(in);
	while (getline(std::cin, in))
	{
		n = in.length();
		for (int i = 0; i < n; i++)
			in[i] = tolower(in[i]);
		for (int i = 0; i < n; i++)
		{
			if (!isalpha(in[i]))
				continue;
			int j = i;
			string word;
			while (j < in.length() && isalpha(in[j]))
				word += in[j++];
			if (ignr.find(word) == ignr.end())
			{
				for (int k = 0; k < word.size(); k++)
					word[k] = toupper(word[k]);
				string ns(in);
				ns.replace(i, word.size(), word);
				idx.insert(ss(word, ns));
			}
			i = j;
		}
	}
	for (it = idx.begin(); it != idx.end(); it++)
		printf("%s\n", it->second.c_str());
}