#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	FILE *fp = fopen("input.txt", "r");
	freopen("input.txt", "r", stdin);

	int N;
	int cost[10][10];
	int ans;
	int temp;
	bool possible;
	vector<int> v;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		v.push_back(i);
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &cost[i][j]);
		}
	}
	
	ans = 0;
	possible = true;
	do
	{
		temp = 0;
		possible = true;
		for (int i = 0; i < N; i++)
		{
			if (cost[v[i]][v[i + 1]] == 0)
			{
				possible = false;
				break;
			}
			temp += cost[v[i]][v[i + 1]];
		}
		if (possible)
		{
			ans = ans > temp ? temp : ans;
		}



	} while (next_permutation(v.begin(), v.end()));

	printf("%d\n", ans);

	fclose(fp);
	return 0;
}