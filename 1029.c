#include<stdio.h>
void Func1(int N)
{
	int count = 0;
	for (int i = 0; i < 2 * N; i++)
	{
		for (int j = 0; j < 2 * N; j++)
		{
			count++;
		}
	}
	for (int k = 0; k < 2 * N; k++)
	{
		count++;
	}
	printf("%d", count);
}
int main()
{
	
	Func1(5);

	return 0;
}
