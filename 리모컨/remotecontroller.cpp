#include <iostream>
#include <cstdio>

using namespace std;

int len(int num)
{
	if (num == 0)
		return 1;
	int length=0;
	while (num != 0)
	{
		++length;
		num /= 10;
	}
	return length;
}

int main(void)
{
	FILE *fp = fopen("input.txt", "r");
	freopen("input.txt", "r", stdin);

	int N;
	int dead_cnt;
	bool dead[10] = { 0, };
	bool possible[1000001] = { 0, };
	int j;
	int result;
	int tmp;

	scanf("%d", &N);
	scanf("%d", &dead_cnt);

	for (int i = 0; i < dead_cnt; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		dead[tmp] = true;
	}


	for (int i = 0; i < 1000001; i++)
	{
		int tmp=i;
		while (tmp)
		{
			if (dead[tmp%10])
			{
				possible[i] = false;
				break;
			}
			tmp = tmp / 10;
		}

		if (tmp == 0)
			possible[i] = true;
		
	}

	j = 0;

	while (!(possible[N-j] || possible[N+j]))
	{
		++j;
	}

	if (possible[N - j]) {
		result = j + len(N - j);
//		printf("%d\n", N - j);
	}
	else {
		result = j + len(N + j);
//		printf("%d\n", N + j);
	}
	tmp = N - 100 > 0 ? N - 100 : 100 - N;
	
	result = result > tmp ? tmp : result;
	
	printf("%d\n", result);


	fclose(fp);
	return 0;
}