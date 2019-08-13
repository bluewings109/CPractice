#include <iostream>
#include <cstdio>
#include <cstring>

#define MAX_LEN 2500

#define USE_INPUT_FILE

using namespace std;

int d[MAX_LEN + 1][MAX_LEN + 1];
int d2[MAX_LEN + 1][MAX_LEN + 1];
char A[MAX_LEN + 1] = { 0, };

int dynamic(int i, int j)
{
	if (d[i][j] != -1)
		return d[i][j];

	if (i == j)
		return 1;

	if (j - i == 1 && A[i] == A[j])
		return 1;

	if (A[i] == A[j])
		return dynamic(i + 1, j - 1);
	else
		return 0;
}


int main(void)
{
#ifdef USE_INPUT_FILE
	freopen("input.txt", "r", stdin);
#endif

	scanf("%s", A+1);


	int len = strnlen(A+1, MAX_LEN);

	
	for (int i = 1; i <= len; i++)
	{
		for (int j = 1; j <= len; j++)
		{
			d[i][j] = -1;

		}
	}

	for (int i = 1; i <= len; i++)
	{
		for (int j = i; j <= len; j++)
		{
			d[i][j] = dynamic(i, j);
		}
	}


	for (int i = 1; i <= len; i++)
	{
		d2[1][i] = d[1][i];
	}

	for (int i = 2; i <= len; i++)
	{
		for (int j = i; j <= len; j++)
		{
			if (d[i][j] != 1)
				continue;
			for (int k = 1; k <= i - 1; k++)
			{
				if (d[k][i - 1] == 1)
					++d2[i][j];
			}
		}
	}

	int ans=0;
	for (int i = 1; i <= len; i++)
	{
		ans += d2[i][len]; 
	}
	printf("%d\n", ans);


	return 0;
}