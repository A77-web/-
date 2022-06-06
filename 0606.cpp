//归并排序
void _MergeSort(int ar[], int left, int right, int* tmp)
{
	//分解
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	_MergeSort(ar, left, mid, tmp);
	_MergeSort(ar, mid + 1, right, tmp);

	//归并
	int begin1, end1, begin2, end2;
	begin1 = left, end1 = mid;  //左数据
	begin2 = mid + 1, end2 = right; //右数据

	int k = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (ar[begin1] < ar[begin2])
			tmp[k++] = ar[begin1++];
		else
			tmp[k++] = ar[begin2++];
	}

	while (begin1 <= end1)
		tmp[k++] = ar[begin1++];
	while (begin2 <= end2)
		tmp[k++] = ar[begin2++];

	memcpy(ar+left, tmp +left, sizeof(int) * (right - left + 1));
}

void MergeSort(int ar[], int left, int right)
{
	int n = right - left;
	int* tmp = (int*)malloc(sizeof(int) * n);

	_MergeSort(ar, left, right - 1, tmp);

	free(tmp);
}
