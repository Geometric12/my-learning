#include<iostream>
using namespace std;

class SqStack
{
private:
	int top;
	int maxsize;
	int* elem;
public:
	SqStack(int size)//构造函数初始化
	{
		elem = new int[size];
		maxsize = size;
		top = -1;
	}
	SqStack(const SqStack& st)//复制构造函数
	{
		maxsize = st.maxsize;
		elem = new int[maxsize];
		top = st.top;
		for (int i = 0; i <= top; i++)
		{
			elem[i] = st.elem[i];
		}
	}
	~SqStack()//析构函数
	{
		delete[]elem;
	}
	bool pop(int e)//入栈操作
	{
		if (top == maxsize - 1)
		{
			return false;
		}
		elem[++top] = e;
		return true;
	}
	bool push(int&e)//出栈操作
	{
		if (top == -1)
		{
			return false;
		}
		e = elem[top--];//top--先用再减 即e=elem[top],然后top-1
		return true;
	}
	bool empty()
	{
		return top == -1;
	}
};


void Binary_conversion(int n)//十进制转化为二进制
{
	SqStack st(n);
	int e = 0;
	if (n > 0)
	{
		while (n != 0)//二进制运算后入栈
		{
			e = n % 2;
			st.pop(e);
			n = n / 2;
		}
		while (!st.empty())//输出时出栈
		{
			st.push(e);
			cout << e;
		}
	}
	else if (n == 0)
	{
		cout << "0" << endl;
	}
	else
	{
		cout << "请输入正确的数值" << endl;
	}
}


int main()
{
	int n = 0;
	cout << "输入一个非负十进制整数" << endl;
	cin >> n;
	Binary_conversion(n);
	return 0;
}