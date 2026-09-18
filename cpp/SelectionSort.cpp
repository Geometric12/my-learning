#include<iostream>
using namespace std;


void swap(int&num1, int&num2)
{
	int temp = 0;
	temp = num1;
	num1 = num2;
	num2 = temp;
}

void SelectionSort(int*arr,int len)
{

	for (int i = 0; i < len - 1; i++)
	{
		int minIndex = i;//最关键的一步 记录最小索引
		{
			for (int j = i+1; j < len; j++)//前i个已经排好，从i后一位继续开始排序
			{
				if (arr[minIndex] > arr[j])//比较，如果有比记录的最小值还小的，交换
				{
					minIndex = j;
				}
			}
		}
		swap(arr[i], arr[minIndex]);//完成最小索引的搜索后，将数值进行交换
	}
	for (int i = 0; i < 9; i++)
	{
		cout << arr[i] << " ";
	}
}

int main()
{
	int arr[] = { 2,3,4,1,5,8,6,9,7 };
	int len = sizeof(arr) / sizeof(arr[0]);//arr 在SelectionSort函数中已经退化成指针 int*,sizeof(arr) 是 8(64 位下指针大小),
										   //sizeof(arr[0]) 是 4 → len = 2，就会报错
										   //所以数组长度必须由调用方传进来，也就是main函数中定义

	SelectionSort(arr,len);
	
}