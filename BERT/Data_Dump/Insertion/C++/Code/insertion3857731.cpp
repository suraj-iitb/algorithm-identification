#include<stdio.h>
void insert_sort(int arr[],int len)
{
     for(int m=0;m<len;m++)//将原来的数组进行输出
                {
                     if(m>0) printf(" ");
                    printf("%d",arr[m]);
                }
                printf("\n");//换行，进行下一步输入
    for(int i=1;i<len;i++)
    {
        int key=arr[i];
        int j=i-1;
        while((j>=0)&&(key<arr[j]))
              {
                  arr[j+1]=arr[j];//此时while循环里只有j可以用啊
                  j--;
              }
              arr[j+1]=key;
            for(int k=0;k<len;k++)//将每一次的排序值输出
                {
                    if(k>0) printf(" ");
                    printf("%d",arr[k]);
                }

                printf("\n");
    }

}
int main()
{
    int n,A[1000];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&A[i]);
    insert_sort(A,n);
    return 0;


}

