#include <iostream>
#include <cstdio>

using namespace std;

int d[11] = {0, 1,2,4,0, };

int go(int n)
{
	if (d[n] > 0)
		return d[n];

	d[n] = go(n - 3) + go(n - 2) + go(n - 1);

	return d[n];
}

int main(void)
{
	FILE *fp = fopen("input.txt", "r");
	freopen("input.txt", "r", stdin);

	int T;
	scanf("%d", &T);
	
	for (int i = 0; i < T; i++)
	{
		int n;
		scanf("%d", &n);

		printf("%d\n", go(n));
	}

	fclose(fp);
	return 0;
}