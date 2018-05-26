#include <bits/stdc++.h>
using namespace std;

stack<int> s;
queue<int> q;
priority_queue<int> pq;
int n, a, b;
bool canStack, canQueue, canPQ;
int main()
{
	while (scanf("%d", &n) == 1)
	{
		while (!s.empty()) s.pop();
		while (!q.empty()) q.pop();
		while (!pq.empty()) pq.pop();
		canStack = canQueue = canPQ = 1;
		for (int i = 0; i < n; i++)
		{
			scanf("%d %d", &a, &b);
			if (a == 1)
				s.push(b), q.push(b), pq.push(b);
			else
			{
				if (canStack)
				{
					if (s.empty())
						canStack = 0;
					else
					{
						if (s.top() != b)
							canStack = 0;
						s.pop();
					}
				}
				if (canQueue)
				{
					if (q.empty())
						canQueue = 0;
					else
					{
						if (q.front() != b)
							canQueue = 0;
						q.pop();
					}
				}
				if (canPQ)
				{
					if (pq.empty())
						canPQ = 0;
					else
					{
						if (pq.top() != b)
							canPQ = 0;
						pq.pop();
					}
				}
			}
		}
		if (!canStack && !canQueue && !canPQ)
			printf("impossible\n");
		else if (canStack && !canQueue && !canPQ)
			printf("stack\n");
		else if (!canStack && canQueue && !canPQ)
			printf("queue\n");
		else if (!canStack && !canQueue && canPQ)
			printf("priority queue\n");
		else
			printf("not sure\n");
	}
}