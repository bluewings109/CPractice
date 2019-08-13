#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>


#define USE_INPUT_FILE

using namespace std;

int main(void)
{
#ifdef USE_INPUT_FILE
	freopen("input.txt", "r", stdin);
#endif

	bool check[200001] = { 0, };
	int d[200001] = { 0, };
	int n;
	int k;
	queue<int> q;

	scanf("%d %d", &n, &k);

	q.push(n);
	check[n] = true;
	d[n] = 0;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		int next;

		next = now - 1;
		if (next >= 0 && check[next]!=true)
		{
			d[next] = d[now] + 1;
			check[next] = true;
			q.push(next);
			if (next == k)
				break;
		}
		
		next = now + 1;
		if (next <= 200000 && check[next] != true)
		{
			d[next] = d[now] + 1;
			check[next] = true;
			q.push(next);
			if (next == k)
				break;
		}

		next = now * 2;
		if (next <= 200000 && check[next] != true)
		{
			d[next] = d[now] + 1;
			check[next] = true;
			q.push(next);
			if (next == k)
				break;
		}
	}

	printf("%d\n", d[k]);


	return 0;
}