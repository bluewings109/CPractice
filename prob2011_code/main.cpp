#include <iostream>
#include <cstdio>
#include <cstring>

#define USE_INPUT_FILE

using namespace std;

int main(void)
{
#ifdef USE_INPUT_FILE
	FILE *fp = fopen("input.txt", "r");
	freopen("input.txt", "r", stdin);
#endif

	char A[5001] = { 'a', };
	long long d[5001] = { 0, };

	scanf("%s", A+1);

	d[0] = 1;

	for (int i = 1; i <= strnlen(A, 5000); i++)
	{
//		printf("adsfadsfads");
		int temp = A[i] - '0';
		if (1 <= temp && temp <= 9)
			d[i] += (d[i - 1]% 1000000);
		if (i == 1)
			continue;
		
		temp = (A[i - 1] - '0') * 10 + A[i]-'0';

		if (10 <= temp && temp <= 26)
		{
			d[i] += d[i - 2];
			d[i] %= 1000000;
		}
	}

	printf("%lld\n", d[strnlen(A, 5000)-1] % 1000000);
#ifdef USE_INPUT_FILE
	fclose(fp);
#endif
	return 0;
}


