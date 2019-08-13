#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
	int N, S;
	cin >> N >> S;
	vector<int> a(N);
	
	for (int i = 0; i<N; i++) 
	{
		cin >> a[i];
	}

	int M = N / 2;
	N = N - M;
	
	vector<int> first(1 << N);
	for (int i = 0; i<(1 << N); i++) 
	{
		for (int k = 0; k<N; k++) 
		{
			if (i&(1 << k)) 
			{
				first[i] += a[k];
			}
		}
	}

	vector<int> second(1 << M);

	for (int i = 0; i<(1 << M); i++) 
	{
		for (int k = 0; k<M; k++) 
		{
			if (i&(1 << k)) 
			{
				second[i] += a[k + N];
			}
		}
	}

	sort(first.begin(), first.end());
	sort(second.begin(), second.end());
	reverse(second.begin(), second.end());

	N = (1 << N);
	M = (1 << M);

	int i = 0;
	int j = 0;
	long long ans = 0;

	while (i < N && j < M) 
	{
		if (first[i] + second[j] == S)
		{
			long long c1 = 1;
			long long c2 = 1;
			i += 1;
			j += 1;
			while (i < N && first[i] == first[i - 1]) 
			{
				c1 += 1;
				i += 1;
			}
			while (j < M && second[j] == second[j - 1])
			{
				c2 += 1;
				j += 1;
			}
			ans += c1*c2;
		}
		else if (first[i] + second[j] < S) 
		{
			i += 1;
		}
		else 
		{
			j += 1;
		}
	}

	if (S == 0) 
		ans -= 1;

	cout << ans << '\n';
	return 0;
}