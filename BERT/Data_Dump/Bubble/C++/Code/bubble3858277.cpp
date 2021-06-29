#include <iostream>
#include<stdio.h>//冒泡排序
using namespace std;
int count;
template<typename T> //整数或浮点数皆可使用,若要使用类(class)或结构体(struct)时必须重载大于(>)运算符  //所以？？？？？
void bubble_sort(T arr[],int len,int *p)
{
    int i,j,count=0;
    for(i=0;i<len-1;i++)
    {
        for(j=0;j<len-1-i;j++)
            if(arr[j]>arr[j+1])
            {
                swap(arr[j], arr[j + 1]);
                count++;//看交换了几次
            }
            *p=count;
            //所以加了句 using...and  template是干嘛的，，
    }
}
int main()
{
    int array[300];
    int n,sum;//为了将交换次数传送出去
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
    }

     bubble_sort(array,n,&sum);

    /* for(int i=0;i<n;i++)
    {
       printf("%d ",array[i]);
    }
    printf("\n%d",sum); 这是我正常的输出         */
    for(int i=0;i<n;i++)
    {
        if(i!=n-1)
        {
            printf("%d ",array[i]);
        }
        else printf("%d\n",array[i]);
    }
printf("%d\n",sum);
}

