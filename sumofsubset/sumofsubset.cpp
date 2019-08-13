#include <iostream>
#include <cstdio>

using namespace std;

int main(void)
{
	FILE *fp = fopen("input.txt", "r");
	freopen("input.txt", "r", stdin);

	int N;
	int S;
	int mask_end;
	int sum;
	int ans;
	int arr[20];

	scanf("%d %d", &N, &S);

	for (int i = 0; i < N; i++)
	{
		int num;
		scanf("%d", &num);
		arr[i] = num;
	}

	mask_end = 0;
	for(int i=0; i<N; i++)
	{
		mask_end |= 1 << i;
	}

	ans = 0;
	for (int mask = 1; mask <= mask_end; mask++)
	{
		sum = 0;
		for (int i = 0; i < N; i++)
		{
			sum += arr[i] * ((mask >> i) & 1);
		}
		if (sum == S)
			++ans;
	}

	printf("%d\n", ans);
	fclose(fp);
	return 0;
}