#include <iostream>
#include <cstdio>

//#define DBG
#ifdef DBG
#define DBG_TRACE 		printf("TRACE : %d\n", __LINE__)
#else
#define DBG_TRACE 
#endif

using namespace std;

enum {
	BLANK=0,
	HEAD,
	BODY,
	APPLE
};

enum {
	UP,
	RIGHT,
	DOWN,
	LEFT
};

char map[101][101] = { 0, };
char dirmap[101][101] = { -1, };

inline bool canGo(int row, int col, int n, int dir)
{

	switch (dir)
	{
	case UP: row--; break;
	case DOWN: row++; break;
	case LEFT: col--; break;
	case RIGHT: col++; break;
	}

	if (1 <= row && row <= n && 1 <= col && col <= n)
		return true;
	
	return false;
}

inline void moveHead(int *head, int *nextHead, int dir)
{
	switch (dir)
	{
	case UP: nextHead[0] = head[0] - 1; break;
	case DOWN: nextHead[0] = head[0] + 1; break;
	case LEFT: nextHead[1] = head[1] - 1; break;
	case RIGHT: nextHead[1] = head[1] + 1; break;
	}
	return;
}

inline bool isApple(int *head)
{
	if (map[head[0]][head[1]] == APPLE)
		return true;

	return false;
}

inline bool isBody(int *head)
{
	DBG_TRACE;
	if (map[head[0]][head[1]] == BODY)
	{
		DBG_TRACE;
		return true;
	}
	return false;
}

inline int turnDir(int sec, int L, int (*change)[2])
{
	int i;
	for (i = 0; i < L; i++)
	{
		if (change[i][0] == sec)
			return change[i][1];
	}
	
	return 0;
}

inline void print(int N, int dir, int sec)
{
	printf("sec : %d\n", sec);
	for (int k = 0; k <= N + 1; k++)
		printf("=");
	printf("\n");
	for (int i = 1; i <= N; i++)
	{
		printf("=");
		for (int j = 1; j <= N; j++)
		{
			switch (map[i][j])
			{
			case BODY: printf("#"); break;
			case HEAD:
				if (dir == UP)
					printf("U");
				else if (dir == DOWN)
					printf("D");
				else if (dir == LEFT)
					printf("L");
				else
					printf("R");
				break;

			case APPLE: printf("@"); break;
			case BLANK: printf(" "); break;
			}
		}
		printf("=");
		printf("\n");

	}
	for (int k = 0; k <= N + 1; k++)
		printf("=");
	printf("\n\n");
}

inline void moveTail(int *tail, int dir)
{
	switch (dir)
	{
	case UP: tail[0]--; break;
	case DOWN: tail[0]++; break;
	case LEFT: tail[1]--; break;
	case RIGHT: tail[1]++; break;
	}
	return;
}

int main(void)
{
	FILE *fp = fopen("input.txt", "r");
	freopen("input.txt", "r", stdin);

	int N;
	int K;
	int L;

	int dir;
	int sec;

	int head[2];
	int next_head[2];
	
	int tail[2];

	int change[100][2] = { 0, };


	scanf("%d", &N);
	scanf("%d", &K);
	for (int i = 0; i < K; i++)
	{
		int row, col;

		scanf("%d %d", &row, &col);
		map[row][col] = APPLE;
	}

	scanf("%d", &L);
	for (int i = 0; i < L; i++)
	{
		int sec;
		char direction;
		scanf("%d %c", &sec, &direction);
		change[i][0] = sec;
		change[i][1] = direction == 'D' ? 1 : -1;
	}


	map[1][1] = HEAD;
	dirmap[1][1] = RIGHT;
	dir = RIGHT;
	head[0] = 1;
	head[1] = 1;
	next_head[0] = 1;
	next_head[1] = 1;
	tail[0] = 1;
	tail[1] = 1;



	sec = 0;
	while (1)
	{

		DBG_TRACE;
		dir = (dir + turnDir(sec, L, change));
		if (dir == -1)
			dir = UP;
//		print(N, dir,sec);
		dirmap[head[0]][head[1]] = dir;
		DBG_TRACE;
		if (canGo(head[0], head[1], N, dir))
		{
			DBG_TRACE;
			moveHead(head, next_head, dir);
			DBG_TRACE;
			if (isBody(next_head))
			{
				DBG_TRACE;
				break;
			}
			DBG_TRACE;
			if (isApple(next_head))
				map[head[0]][head[1]] = BODY;
			else
			{
				map[tail[0]][tail[1]] = BLANK;
				moveTail(tail,dirmap[tail[0]][tail[1]]);
				map[tail[0]][tail[1]] = BODY;
			}
			DBG_TRACE;

			head[0] = next_head[0];
			head[1] = next_head[1];

			map[head[0]][head[1]] = HEAD;


		}
		else
			break;
		
		++sec;
	}

	printf("%d\n", ++sec);

	fclose(fp);
	return 0;
}