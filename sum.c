/*一个数组两个数的求和
用C语言实现
*/

#include<stdio.h>
int main()
{
	int i,j,temp,target=11;
	int a[5] = { 1, 5, 6, 8 };
	int size = sizeof(a) / sizeof(a[0]);
	for (i = 0; i < size; i++)
	{

		for (j = i + 1; j < size; j++)
		{
			if (a[i] < target)
				temp = target - a[i];
			if (a[j] == temp)
				printf("%d %d", a[i], a[j]);
		}
	}
	return 0;
}