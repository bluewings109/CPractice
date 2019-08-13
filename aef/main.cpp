#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>

#define MAX(a,b) ((a) > (b) ? (a) : (b) )

using namespace std;

int ans;

int main(void)
{
	int T, test_case;

	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{

		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		Implement your algorithm here.
		The answer to the case will be stored in variable Answer.
		*/
		/////////////////////////////////////////////////////////////////////////////////////////////
		int N;
		int max_hak;
		int arr[10000] = { 0, };

		scanf("%d %d", &N,&max_hak);

		for (int i = 0; i < N; i++)
		{
			scanf("%d", &arr[i]);
		}
		
		for (int i = 1; i <= N; i++)
		{
			vector<int> mask;

			for (int j = N; j > i; j--)
			{
				mask.push_back(0);
			}
			for (int j = i; j > 0; j--)
			{
				mask.push_back(1);
			}

			do 
			{
				int temp = 0;
				for (int i = 0; i < N; i++)
				{
					temp += arr[i] * mask[i];
				}
				if (temp <= max_hak)
				{
					ans = MAX(ans, temp);
					if (ans == max_hak)
						break;
				}
				
			} while (next_permutation(mask.begin(), mask.end()));


		}


		// Print the answer to standard output(screen).

		printf("Case #%d\n", test_case + 1);
		printf("%d\n", ans);

	}

	return 0;//Your program should return 0 on normal termination.
}