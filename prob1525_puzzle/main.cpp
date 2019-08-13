#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <cstdio>
#include <algorithm>

#define SWAP(a,b)			\
	do						\
	{						\
		(a) = (a) ^ (b);	\
		(b) = (a) ^ (b);	\
		(a) = (a) ^ (b);	\
	} while (0)

using namespace std;

vector<char> v;
map<vector<char>, bool> check;
map<vector<char>, int> dist;
queue<vector<char>> q;

enum {UP, DOWN, LEFT, RIGHT};
vector<char> move(const vector<char> &v, int dir)
{
	vector<char> ret;
	unsigned int i;
//	int temp;
	for (i = 0; i < v.size(); i++)
	{
		if (v[i] == 9)
			break;
	}

	ret = v;
	switch (dir)
	{
	case UP:
		if (i >= 3)
		{
			SWAP(ret[i], ret[i - 3]);
		}
		break;
	case DOWN :
		if (i < 6)
		{
			SWAP(ret[i], ret[i + 3]);
		}
		break;
	case LEFT :
		if (i % 3 > 0)
		{
			SWAP(ret[i], ret[i - 1]);
		}
		break;
	case RIGHT:
		if (i % 3 < 2)
		{
			SWAP(ret[i], ret[i + 1]);
		}
		break;

	}

	return ret;
}

bool check_sort(const vector<char> &v)
{
	bool ret = true;
	for (unsigned int i = 0; i < v.size()-1; i++)
	{
		if (v[i] > v[i + 1])
		{
			ret = false;
			break;
		}
	}

	return ret;
}

int main(void)
{
	FILE *fp = fopen("input.txt", "r");
	freopen("input.txt", "r", stdin);

	for (int i = 0; i < 9; i++)
	{
		int num;
		scanf("%d", &num);
		if (num == 0)
			v.push_back(9);
		else
			v.push_back(num);
	}

	q.push(v);
	check[v] = true;
	dist[v] = 0;

	while (!q.empty())
	{
		vector<char> now = q.front();
		q.pop();
		for (int dir = UP; dir <= RIGHT; dir++)
		{
	//		printf("%s\n", __FUNCTION__);
			vector<char> next = move(now, dir);
			if (check.count(next) == 0)
			{
				q.push(next);
				check[next] = true;
				dist[next] = dist[now] + 1;
				if (check_sort(next))
					goto RESULT;
			}
		}
	}
RESULT:
	printf("%d\n", dist[{1,2,3,4,5,6,7,8,9}]);


	fclose(fp);
	return 0;
}