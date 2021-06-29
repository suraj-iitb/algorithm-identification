#include <iostream>
#include<stdio.h>//冒泡排序
#include<algorithm>
using namespace std;
void selection_sort(int a[], int len,int &p)
{
    int i,j;

	for (i = 0 ; i < len - 1 ; i++)
    {
		int min = i;
		for (j = i + 1; j < len; j++)     //走訪未排序的元素
		{
			if (a[j] < a[min])    //找到目前最小值
			{
				min = j;    //紀錄最小值
			}
		}
if(i!=min){
	   	 swap(a[i], a[min]);   //就是那种相同的你们居然不算，有点扯
	   	 p++;
}

    }
}
int main()
{
    int n,arr[100],sum=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    selection_sort(arr,n,sum);
     for(int i=0;i<n;i++)
    {
        if(i!=n-1)
        {
            printf("%d ",arr[i]);
        }
        else printf("%d\n",arr[i]);
    }
    printf("%d\n",sum);

}


