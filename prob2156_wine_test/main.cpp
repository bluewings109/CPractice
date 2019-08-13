#include <iostream>
#include <cstdio>

#define MAX(a,b) ((a) > (b) ? (a) : (b))

using namespace std;

int main(void)
{
	FILE *fp = fopen("input.txt", "r");
	freopen("input.txt", "r", stdin);

	int n;
	int wine[10002] = { 0, };
	int d[2][10002] = { 0, };
	int ans;

	/*
	 * d[0][i] : i번째 와인을 마시지 않을때 최대값 --> 바로 앞걸 마셨던 안마셨던 이번에 안마시는건 무조건 가능하므로, 바로 전 마셨거나 안마셨거나 중 큰값을 가져가면 됨.
	 * d[1][i] : i번째 와인을 마셨을 때 최대 값 --> 두개 전에 안마시고 바로 앞에서 마시고 이번에 마시거나 //  두개전에 마시고, 바로앞에서 안마시고 이번에 마심
	*/
	scanf("%d", &n);

	for (int i = 2; i < n+2; i++)
	{
		scanf("%d", &wine[i]);
	}

	for (int i = 2; i < n + 2; i++)
	{
		d[0][i] = MAX(d[0][i - 1] , d[1][i - 1]);
		d[1][i] = MAX(d[0][i - 2] + wine[i-1], d[1][i - 2]) + wine[i];
	}

	ans = MAX(d[0][n + 1], d[1][n + 1]);

	printf("%d\n", ans);
	

	fclose(fp);
	return 0;
}