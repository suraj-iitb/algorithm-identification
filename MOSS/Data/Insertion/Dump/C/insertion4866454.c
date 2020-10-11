 #include <stdio.h> 

 void outResult(int a[],int n)
 {
 	int i;
 	for(i=0;i<n-1;i++)
 		printf("%d ",a[i]);
 	printf("%d\n",a[n-1]);
 }
 void insertSort(int a[],int n)
 {
	int i,j,key;
	for(i=1;i<n;i++)
	{
		key=a[i];
		j=i-1;
		while(j>=0&&a[j]>key)
		{
			a[j+1]=a[j];
			j--;
		}
			
		a[j+1]=key;
		outResult(a,n);
	}
 }
 int main()
 {
 	int a[110],N,i;
 	scanf("%d",&N);
 	for(i=0;i<N;i++)
 		scanf("%d",&a[i]);
 	outResult(a,N);
 	insertSort(a,N);
 	return 0;
 }
