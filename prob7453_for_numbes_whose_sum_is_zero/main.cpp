#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

#define __FP__

using namespace std;

int main(void)
{
#ifdef __FP__
	FILE *fp = fopen("input.txt", "r");
	freopen("input.txt", "r", stdin);
#endif
	int N;

	int A[4000] = { 0, };
	int B[4000] = { 0, };
	int C[4000] = { 0, };
	int D[4000] = { 0, };

	long long ans = 0;

	scanf("%d", &N);


	for (int i = 0; i < N; i++)
	{
		scanf("%d %d %d %d", &A[i], &B[i], &C[i], &D[i]);
	}


	vector<int> first;
	vector<int> second;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			first.push_back(A[i] + B[j]);
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			second.push_back(C[i] + D[j]);
		}
	}


	sort(first.begin(), first.end());
	//	sort(second.begin(), second.end(), greater<int>());
	sort(second.begin(), second.end());
	reverse(second.begin(), second.end());
	int i, j;
	i = 0; j = 0;

	while (i < N*N && j < N*N)
	{
		if (first[i] + second[j] == 0)
		{
			int c1, c2;

			c1 = count(first.begin(), first.end(), first[i]);
			c2 = count(second.begin(), second.end(), second[i]);

			ans += c1*c2;
			i += c1;
			j += c2;
		}
		else if (first[i] + second[j] < 0)
		{
			++i;
		}
		else if (first[i] + second[j] > 0)
		{
			++j;
		}
	}

	printf("%lld\n", ans);

#ifdef __FP__
	fclose(fp);
#endif

	return 0;
}