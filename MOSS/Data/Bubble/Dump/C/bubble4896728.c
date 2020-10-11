#include <stdio.h>
void BubbleSort (int a[],int n)
{
    int sum=0;
    for (int i=0;i<n;i++)
        for (int j=0;j<n-i-1;j++)
            if(a[j]>a[j+1])
           {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                sum++;
           }
    for (int i=0;i<n;i++)
        printf("%d%c",a[i],i==n-1? '\n':' ');
    printf("%d\n",sum);
}
int main()
{
	int length;
	scanf("%d",&length);
	int arr[length];
	for(int i=0;i<length;i++)
	{
		scanf("%d",&arr[i]);
	}
	BubbleSort(arr,length);
	return 0;
}
