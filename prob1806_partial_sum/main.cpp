#include <iostream>
#include <cstdio>

using namespace std;

int main(void)
{
	FILE *fp = fopen("input.txt", "r");
	freopen("input.txt", "r", stdin);
	
	int N;
	int S;
	int arr[100000];

	int right;
	int left;
	int sum;
	int len;

	scanf("%d %d", &N, &S);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	right = 0;
	left = 0;
	sum = arr[0];
	len = 100001;

	while (left<=right && right < N)
	{
		if (sum >= S)
		{
			len = (right - left + 1) < len ? right-left+1 : len;
			sum -= arr[left];
			++left;
		}
		else
		{
			++right;
			sum += arr[right];
		}
	}

	printf("%d\n", len == 100001 ? 0 : len);


	fclose(fp);
	return 0;
}