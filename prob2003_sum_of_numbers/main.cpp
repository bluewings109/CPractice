#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(void)
{
	FILE *fp = fopen("input.txt", "r");
	freopen("input.txt", "r", stdin);

	int N;
	int M;
	int arr[10000];

	int left, right;
	int cnt;
	int sum;

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	left = 0;
	right = 0;
	cnt = 0;
	sum = 0;

	sum = arr[0];
	while (1)
	{
		if (sum == M)
			++cnt;
		if (left == right || sum <= M)
		{
			++right;
			if (right == N)
				break;
			sum += arr[right];
		}
		else
		{
			sum -= arr[left];
			++left;
		}


	}

	printf("%d\n", cnt);
	fclose(fp);
	return 0;
}