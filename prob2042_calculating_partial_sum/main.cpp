#include <cstdio>

typedef long long int int64;

int N, M, K;

//100������ ū 2�� ������ : 1048576 -> �ִ� �� 210������ �迭�� �ʿ�, �뷫 �������� 4�������� ���
int64 tree[1000000 * 4];

int init() // Ʈ�� �ʱ� 
{
	for (int i = 0; i < 4 * N; i++) 
		tree[i] = 0;
	// ó������ n���� ū 2�� ������ ���ϱ�
	int ret = 1;
	while (ret < N) 
		ret *= 2;
	ret--;// 1 base �Է�ó���� ���� 1�� �̸� ���ֱ�
	return ret;
}

// ���� �Լ�
void update(int node, int64 delta)
{
	int cur = node;
	while (cur > 0)
	{
		tree[cur] += delta; // Ʈ���� �����͸� ����
		cur /= 2; // �θ� ���� �̵�
	}

}

// ���� ���� �Լ�
int64 sum(int start, int end)
{
	int64 ret = 0;
	while (start <= end)
	{
		if (start % 2 == 1) ret += tree[start];
		if (end % 2 == 0) ret += tree[end];
		start = (start + 1) / 2;
		end = (end - 1) / 2;
	}
	return ret;
}

int main()
{
	freopen("input.txt", "r", stdin);
	
	scanf("%d %d %d", &N, &M, &K);

	// Ʈ�� �ʱ�ȭ �� �������� ù �ε��� ���ϱ�
	int Nidx = init();

	for (int i = 1; i <= N; i++)
	{
		// �ε��� Ʈ���� ���� ��忡 ������ �Է�
		scanf("%lld", &tree[Nidx + i]);
	}

	// Ʈ�� ���� �ϱ�
	for (int i = Nidx; i >= 0; i--) tree[i] = tree[i * 2] + tree[i * 2 + 1];
	for (int i = 0; i < M + K; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a == 1)
		{
			// ������ ���� �ϱ�
			update(Nidx + b, (int64)c - tree[Nidx + b]);
		}
		else
		{
			// ������ �� ���ϱ�
			printf("%lld\n", sum(Nidx + b, Nidx + c));
		}
	}
}