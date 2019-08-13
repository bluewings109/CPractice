#include <iostream>
#include <cstdio>

using namespace std;

int main(void)
{
	FILE *fp = fopen("input.txt", "r");
	freopen("input.txt", "r", stdin);

	int n;
	scanf("%d", &n);

	int A[1000] = { 0, };
	int d1[1000] = { 0 , };
	int d2[1000] = { 0 , };

	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);

	for (int i = 0; i < n; i++)
	{
		d1[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (A[j] < A[i] && d1[i] < d1[j] + 1)
				d1[i] = d1[j] + 1;
		}
	}

	for (int i = n - 1; i >= 0; i--)
	{
		d2[i] = 1;
		for (int j = n - 1; j > i; j--)
		{
			if(A[i] < A[j] && d2[j] < d2[i] +1)
		}
	}
	fclose(fp);
	return 0;
}
