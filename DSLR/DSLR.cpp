#include <iostream>
#include <cstdio>
#include <string>
#include <queue>

using namespace std;

int shift(int n, bool left)
{
	int d1, d2, d3, d4;
	
	d4= n / 1000;
	n = n % 1000;
	d3 = n / 100;
	n = n % 100;
	d2 = n / 10;
	n = n % 10;
	d1 = n;

	if (left)
		return d3 * 1000 + d2 * 100 + d1 * 10 + d4;
	else
		return d1 * 1000 + d4 * 100 + d3 * 10 + d2;
}



int main(void)
{
	FILE *fp = fopen("input.txt", "r");
	freopen("input.txt", "r", stdin);

	int T;
	int n, m;
	int now, next;

	
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		queue<int> q;
		string d[10000];
		bool check[10000];

		fill(check, check + 10000, false);

		scanf("%d %d", &n, &m);

		q.push(n);
		check[n] = true;
		d[n] = "";

		while (!q.empty())
		{
			now = q.front();
			q.pop();

			next = (now * 2) % 10000;
			if (check[next] == false)
			{
				q.push(next);
				check[next] = true;
				d[next] = d[now] + "D";
				if (next == m)
					break;
			}

			next = (now == 0) ? 9999 : now - 1;
			if (check[next] == false)
			{
				q.push(next);
				check[next] = true;
				d[next] = d[now] + "S";
				if (next == m)
					break;
			}

			next = shift(now, true);
			if (check[next] == false)
			{
				q.push(next);
				check[next] = true;
				d[next] = d[now] + "L";
				if (next == m)
					break;
			}

			next = shift(now, false);
			if (check[next] == false)
			{
				q.push(next);
				check[next] = true;
				d[next] = d[now] + "R";
				if (next == m)
					break;
			}
		}

		printf("%s\n",d[m].c_str());
		
	}


	fclose(fp);
	return 0;
}