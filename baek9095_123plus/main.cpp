#include <iostream>
#include <cstdio>

using namespace std;

int main(void)
{
	FILE *fp = fopen("input.txt", "r");
	freopen("input.txt", "r", stdin);

	int T;
	int n;
	int result=0;
	int temp;

	int th[10];

	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		result = 0;
		scanf("%d", &n);

		for (th[0] = 0; th[0] <= 3; th[0]++)
		{
			for (th[1] = 0; th[1] <= 3; th[1]++)
			{
				for (th[2] = 0; th[2] <= 3; th[2]++)
				{
					for (th[3] = 0; th[3] <= 3; th[3]++)
					{
						for (th[4] = 0; th[4] <= 3; th[4]++)
						{
							for (th[5] = 0; th[5] <= 3; th[5]++)
							{
								for (th[6] = 0; th[6] <= 3; th[6]++)
								{
									for (th[7] = 0; th[7] <= 3; th[7]++)
									{
										for (th[8] = 0; th[8] <= 3; th[8]++)
										{
											for (th[9] = 0; th[9] <= 3; th[9]++)
											{
												for (int j = 0; j < 10; j++)
													temp += th[j];
												if (temp == n)
													++result;
												temp = 0;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		printf("%d\n", result);

	}


	fclose(fp);
	return 0;
}