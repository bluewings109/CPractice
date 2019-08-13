#include <iostream>
#include <cstdio>
#include <deque>

using namespace std;

bool isPrime(int n)
{
	if (n < 2)
		return false;

	if (n == 2)
		return true;

	for (int i = 2; i <= n / 2; i++)
	{
		if (n%i == 0)
			return false;
	}
	return true;
}

int main(void)
{
	FILE *fp = fopen("input.txt", "r");
	freopen("input.txt", "r", stdin);

	int N;

	int sum;
	int ans;
	deque<int> d;

	scanf("%d", &N);

	ans = 0;
	sum = 2;
	d.push_back(2);
	
	while (!d.empty())
	{
		bool flg = false;

		if (sum <= N)
		{
			if (sum == N)
			{
				++ans;
			}
			for (int i = d.front() + 1; i <= N; i++)
			{
				if (isPrime(i))
				{
					flg = true;
					d.push_front(i);
					sum += i;
					break;
				}
			}
			if (!flg)
			{
				break;
			}
		}
		else
		{
			sum -= d.back();
			d.pop_back();
		}
	}


	printf("%d\n", ans);

	fclose(fp);
	return 0;
}