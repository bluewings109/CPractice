#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
int sum(int *arr, int N, int mask)
{
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += arr[i] * ((mask >> i)&1);
	}

	return sum;
}

using namespace std;

int main(void)
{
	FILE *fp = fopen("input.txt", "r");
	freopen("input.txt", "r", stdin);

	int N, S;
	int arr[20];
	int ans = 0;

	scanf("%d %d", &N, &S);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);	
	}

	for (int i = 1; i < (int)pow(2,N); i++)
	{
		if (sum(arr, N, i) == S)
		{
			++ans;
		//	printf("mask : %X\n", i);
		}
	}

	//printf("%d\n", (int)pow(2, N));

	printf("%d\n", ans);
	fclose(fp);
	return 0;
}