#include<iostream>
using namespace std;

//注：结果是以1为开头计算的

//BF算法 简单的串匹配算法 旨在通过暴力的方式进行破解
int BF(string s, string t)//传入主串和字串
{
	int i = 0, j = 0, start = 0;//start用于保存匹配的初始位置
	while (i < s.length() && j < t.length())//超出主串长度，退出循环 超出字串长度，退出循环
	{
		if (s[i] == t[j])//每次匹配成功，匹配下一位
		{
			j++;
			i++;
		}
		else//一旦匹配失败，匹配初始位置进一位，字串重新从第一位开始匹配
		{
			start++;
			i = start;
			j = 0;
		}
	}
	if (j == t.length())
	{
		return start+1;//主串子串完全匹配，返回匹配初始位置
	}
	else
	{
		return 0;//匹配失败退出程序
	}
}


//KMP算法
//***方法一***//
void GetNext(string t,int next[])//创建next数组，以此来确定字串开始匹配位置
{
	int i = 1;
	int j = 0;
	int len = 0;
	while (i < t.length())
	{
		if (t[len] == t[i])//匹配成功，前后缀长度+1，长度返回给子串的匹配位置对应的next数组位置中
		{
			len++;
			j++;
			next[j] = len;
			i++;
		}
		else
		{
			if (len == 0)//第一个字符就匹配失败，和下一位开始比
			{
				next[j] = 0;
				i++;
			}
			else//匹配不成功，看看有没有更短的，有就继续匹配，没有继续看有没有更短的，是一个循环
			{
				len = next[len - 1];
			}
		}
	}
}

int kmpsearch(string s, string t)
{
	int* next = new int[t.length()]();//()的作用全部初始化为零，在堆区开辟空间，动态分配内存，防止溢出
	GetNext(t, next);
	int i = 0;
	int j = 0;
	while (i<s.length())
	{
		if (s[i] == t[j])//如果匹配成功，下一位继续
		{
			i++;
			j++;
		}
		else if (j > 0)//如果匹配不成功，匹配位置跳到next数组给的位置
		{
			j = next[j - 1];
		}
		else
		{
			i++;
		}
		if (j == t.length())//返回原始匹配位置
		{
			return i - j+1;
		}
	}
}

//***方法二****//
void getnext(string t, int next[])//该next数组本质是靠暴力算法来求的
{
	int i, j, len;
	next[0] = -1;//一种经典的实现约定，核心原因是为了让代码逻辑更加统一，简洁
	for (j = 1; t[j] != '\0'; j++)
	{
		for (len = j - 1; len>=1; len--)
		{
			for (i = 0; i < len; i++)
			{
				if (t[i] != t[j - len + i])//匹配不成功，len减小，差越来越大，匹配成功，i增加，差越来越大，注意约束条件
				{
					break;
				}
			}
			if (i == len)
			{
				next[j] = len;
				break;
			}
		}
		if (len < 1)
		{
			next[j] = 0;
		}
	}
}

int KMP(string s, string t)
{
	int i = 0, j = 0;
	int* next = new int[t.length()]();//设置初始值
	getnext(t, next);
	while (s[i] != '\0' && t[j] != '\0')
	{
		if (s[i] == t[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];//第一个字符就匹配失败
			if (j == -1)
			{
				i++;
				j++;//此时j==-1（说明没有相同前后缀），j++即为0
			}
		}
	}
	if (t[j] == '\0')//完全匹配，返回初始位置
	{
		return i - t.length() + 1;
	}
	else
	{
		return 0;
	}
}



int main()
{
	string s = "abcabccaacbaac";
	string t = "caa";
	int start1 = BF(s, t);
	int start2 = kmpsearch(s, t);
	int start3 = KMP(s, t);
	cout << "BF算法匹配结果：" << start1 << endl;
	cout << "kmp算法方法1匹配结果：" << start2 << endl;
	cout << "kmp算法方法2匹配结果：" << start3 << endl;

}