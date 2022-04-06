#include "head.h"

//以下为查找
//顺序查找算法
int SequentialSearch(float R[], int n, float k)
{
	int i = 0;
	for (i = 0; i < n; i += 0) {
		if (R[i] == k)
		{
			break;
		}
		else
		{
			i++;
			continue;
		}
	}
	if (i >= n)
	{
		return n;
	}
	else
	{
		return i + 1;
	}
}

//折半查找算法，要求线性表是有序的才可以用
int BinarySearch(float R[], int n, float k)
{
	int i = 0;

	return 0;
}

//以下为排序

//插入排序

//直接插入排序（递增）
//时间复杂度O(n^2),最好情况O(n)，最坏O(n^2)；空间复杂度O(1)
void StraightInsertionSort(float R[], int n) {
	int i, j;
	float temp;
	for (i = 1; i < n; i++)
	{
		if (R[i] < R[i - 1])
		{
			temp = R[i];
			/* 教材代码
			j = i - 1;
			do
			{
				R[j + 1] = R[j];
				j--;
			} while (j>=0&&R[j]>temp);
			R[j + 1] = temp;
			 */

			for (j = i - 1; j >= 0;)
			{
				R[j + 1] = R[j];
				j = j - 1;
				if (R[j] < temp)
				{
					R[j + 1] = temp;    //这一步初次撰写时忘记了
					break;
				}
				R[j + 1] = temp;
			}
		}
	}
}

//折半插入排序
//
void BinaryInsertionSort(float R[], int n) {
	int i, j, low, high, mid;
	float temp;
	for (i = 1; i < n; i++)
	{
		if (R[i] < R[i - 1]) {
			temp = R[i];
			low = 0; high = i - 1;
			for (; low <= high;) {
				mid = (low + high) / 2;
				if (temp < R[mid])
				{
					high = mid - 1;
				}
				else
				{
					low = mid + 1;
				}
			}
			for (j = i - 1; j > high; j--) {
				R[j + 1] = R[j];
			}
			R[high + 1] = temp;
			//此处误写为R[high]时输出异常，且主函数退出时显示为堆栈溢出，因为high可能为-1
		}
	}
}

//希尔排序
//
void ShellSort(float R[], int n)
{
	int i, j, d;
	d = n / 2;
	StraightInsertionSort(R, d);
}

//冒泡排序，以下均属于交换排序
//
void BubbleSort(float R[], int n)
{
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n - i; j++) {
			if (R[j] < R[j - 1])
			{
				swap(R[j], R[j - 1]);
			}
		}
	}
}

//快速排序
int QuikSort_partition(float R[], int s, int t) //快速排序单元
{
	int i = s, j = t;
	float temp = R[i];
	for (; i < j;) {
		for (; R[j] >= temp;) {
			j--;
		}
		R[i] = R[j];
		for (; i < j && R[i] <= temp;) { //此处和前四行如果写成>和<，则会在出现相隔较远的一样的值时陷入死循环
			i++;
		}
		R[j] = R[i];
	}
	R[i] = temp;
	return i;
}

void QuickSort(float R[], int s, int t) //对R[s...t]的元素进行快速排序
{
	int i;
	if (s < t) {
		i = QuikSort_partition(R, s, t);
		QuickSort(R, s, i - 1);
		QuickSort(R, i + 1, t);
	}
}

//以下为选择排序
//简单选择排序，时间复杂度O(n^2)
void SimpleSelectionSort(float R[], int n) 
{
	int i, j, k;
	for (i = 0; i < n; i++) {
		k = i;
		for (j = i + 1; j < n; j++) {
			if (R[j]<R[k])
			{
				k = j;
				//break; 要找到最小的才能与i交换，否则出错
			}
		}
		swap(R[i], R[k]);
	}
}


//测试程序
string examination_sort(float R[], int n)
{
	int i;
	for (i = 1; i < n; i++) {
		if (R[i - 1] > R[i]) {
			return "Error!!";
		}
	}
	return "No problem.";
}