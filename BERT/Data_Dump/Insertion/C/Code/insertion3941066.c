 #include<stdio.h>
 #include<stdlib.h>
 int main()
 {
 	int n;
 	scanf("%d",&n);
 	int *a;
 	a=(int *)malloc(sizeof(int)*n);
	int i,j,t;
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{
		for(j=0;j<=i-1;j++)
		{
			if(a[i]<a[j])
				{t=a[j];
				a[j]=a[i];
				a[i]=t; }
			} 
		for(j=0;j<n-1;j++)printf("%d ",a[j]);
		printf("%d\n",a[n-1]); 
		}
	return 0;	 
 }
