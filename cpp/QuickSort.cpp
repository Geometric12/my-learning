#include<iostream>
using namespace std;


void swap(int& num1, int& num2)//交换函数实现
{
	int temp;
	temp = num1;
	num1 = num2;
	num2 = temp;
}


int partition(int arr[], int low, int high)//找基准值并分区
{
	int pivot = arr[high];
	int i = low - 1;
	for (int j = low; j < high; j++)
	{
		if (arr[j] <= pivot)//如果小于基准值就放到左边
		{
			i++;
			swap(arr[j], arr[i]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return i + 1;
}


void quicksort(int arr[], int low, int high)
{
	if (low >= high)return;//检测是否是自然排序
	int pi = partition(arr, low, high);
	quicksort(arr, low, pi - 1);//递归排序左半部分
	quicksort(arr, pi + 1, high);//递归排序右半部分
}

int main()
{
	int arr[] = { 1,5,4,3,8,0,2,7,9,6 };
	int n = sizeof(arr) / sizeof(arr[0]);
	quicksort(arr, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
}

//总结
//算法思想：分而治之
//运行时间：O(nlogn) 最糟糕的情况下运行时间为O(n^2)