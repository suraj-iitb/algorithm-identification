#include <stdio.h>
int sort(int *a,int n);
int pt(int *a,int n);
int main()
{
    int a[100],n;
    scanf("%d",&n);
    for(int i =0;i<n;i++)
     {scanf("%d",a+i);}
     sort(a,n);
    
    return 0;
}

int sort(int *a,int n)
{    
    int v,j;
    for(int i = 1;i<n;i++)
    {  v=a[i];
       j=i-1;
      pt(a,n);
      while( j>=0 && a[j]>v )
      {
          a[j+1]=a[j];
          j--;
          a[j+1]=v;
          
         
      }
      
}
	pt(a,n);
}

int pt(int *a,int n)
{
	for(int i =0;i<n;i++)
	{printf("%d",a[i]);
	 if(i!=n-1)printf(" ");
		
	}
	printf("\n");
	return 1;
}
