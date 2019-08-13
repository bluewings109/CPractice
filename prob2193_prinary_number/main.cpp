#include <iostream>
#include <cstdio>

using namespace std;

long long d[91][2] = { 0, };

int main(void)
{
	FILE *fp = fopen("input.txt", "r");
	freopen("input.txt", "r", stdin);

	int n;
	scanf("%d", &n);

	d[1][0] = 0;
	d[1][1] = 1;

	for (int i = 2; i <= n; i++)
	{
		d[i][0] = d[i - 1][0] + d[i - 1][1];
		d[i][1] = d[i - 1][0];
	}
	printf("%lld\n", d[n][0] + d[n][1]);

	fclose(fp);
	return 0;
}