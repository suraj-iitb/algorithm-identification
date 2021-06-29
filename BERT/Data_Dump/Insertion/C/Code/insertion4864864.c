#include <stdio.h>
#include <stdlib.h>
void display(int a[],int n)
{
	int i;
	for(i=0;i<n;i++){
        if(i>0) 
            printf(" ");
        printf("%d",a[i]); 
    }
    printf("\n");
}
void insertionSort(int a[],int n)
{ 
	int i,v,j;
	for (i=1; i<n; i++)
	{
		display(a,n);
	    v = a[i];						 
	    j=i-1;
	    while (j >= 0 && a[j] > v)
	    {
	        a[j+1] = a[j];
	        j--;
		}
		a[j+1] = v;
		
	}
	display(a,n);
}
int main(int argc, char *argv[]) {
	
	int i,n,a[100];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	insertionSort(a,n);
	return 0;
}
