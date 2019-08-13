#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
	FILE *fp = fopen("input.txt", "r");
	freopen("input.txt", "r", stdin);

	vector<int> v;
	int N;
	int num;
	int ans;
	int temp;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &num);
		v.push_back(num);
	}

	sort(v.begin(), v.end());
	ans = 0;
	do
	{
		temp = 0;
		for (int i = 0; i <= N - 2; i++)
		{
			temp += abs(v[i] - v[i + 1]);
		}
		ans = ans > temp ? ans : temp;
	} while (next_permutation(v.begin(), v.end()));

	printf("%d\n", ans);
	
	fclose(fp);
	return 0;
}