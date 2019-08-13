#include <iostream>
#include <cstdio>
#include <string>
#include <tuple>
#include <vector>
#include <algorithm>
#include <functional>


using namespace std;

int main(void)
{
	int N;
	FILE *fp;
	fp = fopen("input.txt", "rt");
	freopen("input.txt", "rt", stdin);

	vector<int> data;
	int num;
	int result, temp;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &num);
		data.push_back(num);
	}

	sort(data.begin(), data.end());

	result = 0;
	do
	{
		temp = 0;
		for (int i = 0; i < N - 1; i++)
		{
			temp += (data[i] - data[i + 1])>0 ? data[i]-data[i+1] : data[i+1]-data[i];
		}
		result = (result < temp) ? temp : result;
	} while (next_permutation(data.begin(), data.end()));

	printf("%d\n", result);
	fclose(fp);
	return 0;

}
