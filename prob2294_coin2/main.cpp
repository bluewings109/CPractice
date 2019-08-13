#include <iostream>
#include <cstdio>

#define USE_INPUT_FILE
#define MAX_INT32 0x7FFFFFFF

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

	for (int i = 1; i <= k; i++)
		d[i] = -1;
	d[0] = 0;

	for (int i = 1; i <= k; i++)
	{
		int temp = MAX_INT32;
		for (int j = 1; j <= n; j++)
		{

			if (i - A[j] >= 0 && d[i - A[j]] != -1)
			{
				temp = (temp > d[i-A[j]]) ? d[i - A[j]] : temp; 
			}
		}

		if (temp != MAX_INT32)
			d[i] = temp + 1;
	}

	printf("%d\n", d[k]);

	return 0;
}