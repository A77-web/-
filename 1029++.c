#include<stdio.h>
#include<assert.h>
int BinarySearch(int* a, int N, int x)
{
	assert(a);
	int begin = 0;
	int end = N - 1;
	while (begin < end)
	{
		int mid = begin + ((end - begin) >> 1);
		if (x > a[mid])
			begin = mid + 1;
		else if (x < a[mid])
			end = mid - 1;
		else
			return mid;
	}
	return -1;
}
int main()
{
	
	BinarySearch(1, 7, 3);

	return 0;
}
