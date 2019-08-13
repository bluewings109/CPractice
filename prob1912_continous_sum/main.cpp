#include <iostream>
#include <cstdio>

#define MAX(a,b) ((a) > (b) ? (a) : (b))

using namespace std;

int main(void)
{
	FILE *fp = fopen("input.txt", "r");
	freopen("input.txt", "r", stdin);

	int N;
	int A[100002] = { 0, };
	int d[100002] = { 0 , };

	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &A[i]);
	}

	for (int i = 1; i <= N; i++)
	{
		d[i] = MAX(d[i - 1] + A[i], A[i]);

	}

	int ans=-1000;
	for (int i = 1; i <= N; i++)
	{
		ans = MAX(ans, d[i]);
	}

	printf("%d\n", ans);
	fclose(fp);
	return 0;
}
