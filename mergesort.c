#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100
typedef struct
{
	int key;
}element;
element list[MAX_SIZE];
element sorted[MAX_SIZE];
/*merge函数实现的是数组元素的一次排序*/
void merge(element list[],element sorted[],int i,int m,int n)
{
	int j, k, t;
	j = m + 1;
	k = i;
	while (i <= m&&j <= n)
	{
		if (list[i].key < list[j].key)
			sorted[k++] = list[i++];
		else sorted[k++] = list[j++];

	}
	if (i<m)
	{
		for (t = j; t <= n; t++)
		{
			sorted[k + t - j] = list[t];
		}
	}
	else
	{
		for (t = i; t <= m; t++)
			sorted[k + t - i] = list[t];
	}
}
/*单遍归并*/
void merge_pass(element list[], element sorted[], int n, int length)
{   int i, j;
	for (i = 0; i < n - 2 * length; i += 2 * length)
		merge(list, sorted, i, i + length - 1, i +2 * length - 1);
	if (i + length < n)
		merge(list, sorted, i, i + length - 1, n - 1);
	else
		for (j = i; j< n; j++)
			sorted[j] = list[j];
		
			
}

void merge_sort(element list[], int n)
{
	//int i;
	int length = 1;
	element extra[MAX_SIZE];
	while (length<n)
	{
		merge_pass(list, extra, n, length);
		length *= 2;
		merge_pass(extra, list, n, length);
		length *= 2;
	
	}
	
			
}
void printarr(element list[],int n)
{
	int i = 0;
	for (; i < n; i++)
		printf("%d\n",list[i].key);
}
int  main()
{
element sort[6] = { 10, 5, 7, 1,15, 2 };
	//求数组长度
	int sort_size = sizeof(sort) / sizeof(sort[0]);
   merge_sort(sort, sort_size);
	printf("merged array is:\n");
printarr(sort ,sort_size);
	 
	return 0;
}
