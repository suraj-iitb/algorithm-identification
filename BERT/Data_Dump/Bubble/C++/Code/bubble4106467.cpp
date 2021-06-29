#include <stdio.h>
#include <iostream>
using namespace std;
void bubble_sort(int a[], int n);   //申明函数"bubble_sort"
int number[10000000];   //在主函数外面定义数组可以更长
int num = 0;
void bubble_sort(int a[], int n)    //下面是函数bubble_sort的程序
{
    int i,j,temp;    //定义三个整型变量
    for (j=0;j<n-1;j++)    //用一个嵌套循环来遍历一遍每一对相邻元素 （所以冒泡函数慢嘛，时间复杂度高）
    {
        for (i=0;i<n-1-j;i++)
        {
            if(a[i]>a[i+1])  //从大到小排就把左边的">"改为"<" ！！！
            {
                temp=a[i];      //a[i]与a[i+1](即a[i]后面那个) 交换
                a[i]=a[i+1];    //基本的交换原理"c=a;a=b;b=c"
                a[i+1]=temp;
                num++;
            }
        }
    }
}

int main()      //主函数
{
    int i,n;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> number[i];
    }
    bubble_sort(number,n);
    for (i = 0; i < n; i++)
    {
        if (i != 0)
        {
            cout << " ";
        }
        cout << number[i];
    }
    cout << endl;
    cout << num << endl;

    return 0;
}

