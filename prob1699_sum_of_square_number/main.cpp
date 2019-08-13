#include <iostream>
#include <cstdio>

#define SQUARE(i) (i)*(i)

#define USE_INPUT_FILE

using namespace std;

int main(void)
{
#ifdef USE_INPUT_FILE
	FILE *fp = fopen("input.txt", "r");
	freopen("input.txt", "r", stdin);
#endif

	long long N;
	long long k;
	long long d[100000] = { 0, };

	scanf("%lld", &N);

	k = N;
	do {
		if (d[k] > 0)
		{
			d[N]+=d[k];
			break;
		}

		for (long long i = 1; i <= N; i++)
		{
			if (SQUARE(i) <= k && k<SQUARE(i+1))
			{
				d[SQUARE(i)] = 1;
				if(k != SQUARE(i))
					d[k]+=1;
				k -= SQUARE(i);
				break;
			}
		}

	} while (k != 0);

	printf("%d\n", d[N]);

#ifdef USE_INPUT_FILE
	fclose(fp);
#endif
	return 0;
}
