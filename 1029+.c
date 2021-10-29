#include<stdio.h>
void Func2(int N)
{
	int count = 0;
	for (int k = 0; k < 100; k++)
	{
		++count;
	}
	printf("%d\n", count);
}

int main()
{
	
	Func2(5);

	return 0;
}
