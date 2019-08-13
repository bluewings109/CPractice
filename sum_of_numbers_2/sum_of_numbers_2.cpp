#include <iostream>
#include <cstdio>

using namespace std;

int main(void)
{
	FILE *fp = fopen("input.txt", "r");
	freopen("input.txt", "r", stdin);

	int N;
	int M;
	int arr[10000];
	int tmp;
	int sum;
	int ans;

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &tmp);
		arr[i] = tmp;
	}
	
	ans = 0;
	for (int i = 0; i < N; i++)
	{
		sum = 0;
		for (int j = i; j < N; j++)
		{
			sum += arr[j];
			if (sum >= M)
			{
				if(sum==M)
					++ans;
				break;
			}
		}
	}
	printf("%d\n", ans);

	fclose(fp);
	return 0;
}