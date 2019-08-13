#include <iostream>
#include <cstdio>

#define USE_INPUT_FILE

using namespace std;

int main(void)
{
#ifdef USE_INPUT_FILE
	freopen("input.txt", "r", stdin);
#endif

	int n;
	int k;

	scanf("%d %d", &n, &k);

	int A[101] = { 0, };
	int d[10001] = { 0, };

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &A[i]);
	}

	d[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if(j-A[i] >= 0)
				d[j] += d[j - A[i]];
		}
	}

	printf("%d\n", d[k]);
	
	return 0;
}