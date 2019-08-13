#include <iostream>
#include <cstdio>

using namespace std;

int d[1001] = { 0, 1, 3,0, };

int go(int n)
{
	if (d[n] > 0)
		return d[n] % 10007;

	d[n] = go(n - 1) + 2*go(n - 2);
	return d[n] % 10007;
}

int main(void)
{
	FILE *fp = fopen("input.txt", "r");
	freopen("input.txt", "r", stdin);

	int n;

	scanf("%d", &n);

	printf("%d\n", go(n) % 10007);
	fclose(fp);
	return 0;
}