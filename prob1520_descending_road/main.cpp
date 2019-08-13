#include <iostream>
#include <cstdio>

#define USE_INPUT_FILE
#define MAX 50
using namespace std;

int M, N;
int A[MAX][MAX] = { 0, };
int d1[MAX][MAX] = { 0, };
int d2[MAX][MAX] = { 0, };
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int dynamic(int i, int j)
{
	if (d1[i][j] == 0 || i < 0 || i >= N || j < 0 || j >= M)
	{
		d2[i][j] = 0;
		return 0;
	}
	if (d2[i][j] != -1)
		return d2[i][j];

	int temp = 0;
	for (int k = 0; k < 4; k++)
	{
		if(0 <= i + dx[k] && i+dx[k] <N && 0<= j + dy[k] && j + dy[k] <M)
			temp += dynamic(i + dx[k], j + dy[k]);
	}
		d2[i][j] = temp;
	return temp;
	
}


int main(void)
{
#ifdef USE_INPUT_FILE
	freopen("input.txt", "r", stdin);
#endif


	scanf("%d %d", &M, &N);



	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &A[i][j]);
		}
	}

	d1[0][0] = 1;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				if (A[0][0] > A[i][j]  && 0 <= i + dx[k] && i + dx[k] < M && 0 <= j + dy[k] && +dy[k] < N)
				{
					if (A[i + dx[k]][j + dy[k]] > A[i][j])
						d1[i][j] = 1;
				}
			}
		}
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			d2[i][j] = -1;
		}
	}
	d2[0][0] = 1;

	//for (int i = 0; i < M; i++)
	//{
	//	for (int j = 0; j < N; j++)
	//	{
	//		for (int k = 0; k < 4; k++)
	//		{
	//			if (A[0][0] > A[i][j] && 0 <= i + dx[k] && i + dx[k] < M && 0 <= j + dy[k] && +dy[k] < N)
	//			{
	//				if (d1[i + dx[k]][j + dy[k]]  == 1 && A[i + dx[k]][j + dy[k]] > A[i][j])
	//					d2[i][j] += d2[i + dx[k]][j + dy[k]];
	//			}
	//		}
	//	}
	//}

	//for (int i = 0; i < M; i++)
	//{
	//	for (int j = 0; j < N; j++)
	//	{
	//		printf("%4c", d1[i][j] ==1 ? 'O' : 'X');
	//	}
	//	printf("\n");
	//}
	d2[M-1][N-1] = dynamic(M-1, N-1);
	printf("%d\n", d2[M-1][N-1]);
	

	return 0;
}