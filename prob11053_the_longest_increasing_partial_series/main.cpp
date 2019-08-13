#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define MAX(a,b) ( (a) > (b) ? (a) : (b) )

using namespace std;

int main(void)
{
	FILE *fp = fopen("input.txt", "r");
	freopen("input.txt", "r", stdin);
	
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for (int i = 0; i<n; i++)
	{
		scanf("%d", &a[i]);
	}

	vector<int> d(n);

	for (int i = 0; i<n; i++) 
	{
		d[i] = 1;
		for (int j = 0; j<i; j++) 
		{
			if (a[j] < a[i] && d[j] + 1 > d[i]) {
				d[i] = d[j] + 1;
			}
		}
	}

	cout << *max_element(d.begin(), d.end()) << '\n';
	return 0;

	fclose(fp);
	return 0;
}
