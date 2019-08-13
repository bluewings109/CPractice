#include <iostream>
#include <cstdio>

#define USE_INPUT_FILE


using namespace std;

int main(void)
{
#ifdef USE_INPUT_FILE
	FILE *fp = fopen("input.txt", "r");
	freopen("input.txt", "r", stdin);
#endif

	int TC;
	scanf("%d", &TC);

	long long d[101] = { 0,1,1,1,2,2,3,4,5,7,9,12,0, };
	
	for (int i = 0; i < TC; i++)
	{
		int n;
		scanf("%d", &n);

		if (d[n] > 0)
		{
			printf("%lld\n", d[n]);
			continue;
		}
		int j = 12;

		while (d[j] != 0)
			++j;

		for (; j <= n; j++)
		{
			d[j] = d[j - 1] + d[j - 5];
		}

		printf("%lld\n", d[n]);


	}
#ifdef USE_INPUT_FILE
	fclose(fp);
#endif
	return 0;
}