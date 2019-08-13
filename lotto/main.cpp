#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	FILE *fp = fopen("input.txt", "r");
	freopen("input.txt", "r", stdin);

	int k;
	int S[12];

	while (1)
	{
		vector<int> v;
		scanf("%d", &k);
		if (k == 0)
			break;
		for (int i = 0; i < k; i++)
		{
			scanf("%d", &S[i]);
			if (i < 6)
				v.push_back(0);
			else
				v.push_back(1);
		}

		do
		{
			for (int i = 0; i < k; i++)
			{
				if (v[i] == 0)
					printf("%d ", S[i]);
			}
			printf("\n");
		} while (next_permutation(v.begin(), v.end()));
		printf("\n");
	}

	fclose(fp);
	return 0;
}