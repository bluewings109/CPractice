#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

inline bool isPrime(int n)
{
	if (n <= 3)
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
	int left;
	int right;
	int sum;
	int ans;



	scanf("%d", &N);

	//for (int i = 2; i <= N; i++)
	//{
	//	if (isPrime(i))
	//		v.push_back(i);
	//}

	vector<bool> c(N + 1);
	vector<int> v;
	for (int i = 2; i <= N; i++) {
		if (c[i] == false) {
			v.push_back(i);
			for (int j = i * 2; j <= N; j += i) {
				c[j] = true;
			}
		}
	}

	left = right = 0;
	ans = 0;
	sum = v[0];

	while (left<=right)
	{
		if (sum == N)
		{
			++ans;
			++right;
			if (right >= v.size())
				break;
			sum += v[right];
		}
		else if (sum < N)
		{
			++right;
			if (right >= v.size())
				break;
			sum += v[right];
		}
		else if (sum > N)
		{
			sum -= v[left];
			++left;
		}
	}

	printf("%d\n", ans);
	fclose(fp);
	return 0;
}