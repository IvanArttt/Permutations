#include <iostream>
#include <string>




void LexPermute(int n)
{
	int i, j, left, right;
	int* Permute = new int[n];
	for (j = 0; j < n; ++j) Permute[j] = j + 1;
	for (;;)
	{
		for (i = 0; i < n; ++i) std::cout << Permute[i] << " ";
		std::cout << std::endl;
		for (i = n - 2; i > -1 && Permute[i] > Permute[i + 1]; --i);
		if (i == -1) break;
		j = n - 1;
		while (Permute[i] > Permute[j]) --j;
		std::swap(Permute[i], Permute[j]);
		left = i + 1;
		right = n - 1;
		while (right > left) std::swap(Permute[right--], Permute[left++]);
	}
	delete[] Permute;
}


void PermTr(int n)
{
	int* Permut = new int[n + 2];
	int* PermutIn = new int[n + 2];
	int* d = new int[n + 1];
	int i, j, k, m;
	Permut[0] = Permut[n + 1] = m = n + 1;
	for (i = 1; i < n + 1; ++i)
	{
		Permut[i] = PermutIn[i] = i;
		d[i] = -1;
	}
	d[1] = 0;
	for (;;)
	{
		for (i = 1; i < n + 1; ++i) std::cout << Permut[i] << " ";
		std::cout << std::endl;
		m = n;
		while (Permut[PermutIn[m] + d[m]] > m)
		{
			d[m] = -d[m--];
			if (m == 1) return;
		}
		j = Permut[PermutIn[m]];
		Permut[PermutIn[m]] = Permut[PermutIn[m] + d[m]];
		Permut[PermutIn[m] + d[m]] = j;
		j = PermutIn[Permut[PermutIn[m]]];
		PermutIn[Permut[PermutIn[m]]] = PermutIn[m];
		PermutIn[m] = j;
	}
}

void CodeGrey(int n)
{
	int* Stack = new int[n];
	int top = -1;
	int* G = new int[n];
	int i, j, k, m;
	int* Set = new int[n];
	for (i = 0; i < n; ++i) G[i] = 0;
	for (i = 0; i < n; ++i) Set[i] = i + 1;
	for (i = 0; i < n + 1; ++i) Stack[i] = i + 1;
	i = Stack[0];
	while (i < n + 1)
	{
		for (j = 0; j < n; ++j) std::cout << (G[j] ? std::to_string(Set[j]) + " " : "");
		std::cout << std::endl;
		G[n - i] = (G[n - i] + 1) % 2;
		Stack[0] = 1;
		Stack[i - 1] = Stack[i];
		Stack[i] = i + 1;
		i = Stack[0];
	}
	for (j = 0; j < n; ++j) std::cout << (G[j] ? std::to_string(Set[j]) + " " : "");
	std::cout << std::endl;
}


int main()
{
	//LexPermute(6);
	//PermTr(6);
	//CodeGrey(6);
	double sum = 0;
	for (size_t i = 1; i < 1000; i++)
	{
		sum = sum + (double)((double)1 / (double)(i * i));
	}
	printf("%d", sum);
	return 0;
}