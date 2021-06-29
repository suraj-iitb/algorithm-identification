#include <stdio.h>


/*
void printInsertsort(int a[],int n)
{
	
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}

void insertsort(int a[],int n)
{

	int i,j,key;

	for(i=0;i<n;i++)
		printf("%d ",a[i]);

	for(i=1;i<n;i++)
	{
		j=i-1;
		key=a[i];
		while(j>=0 && a[j]>key)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
		
		printInsertsort(a,n);
		printf("\n");
	}
}

main()
{

	int n,i,a[100];
	scanf("%d",&n);

	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	insertsort(a,n);
	

}
*/


void trace(int a[], int n) {
    for(int i=0; i<n; ++i) {
        if(i) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
}
 
void insertionSort(int a[], int n) {
    for(int i=1; i<n; ++i) {
        int j = i-1, v = a[i];
        while(j>=0 && a[j]>v) {
            a[j+1] = a[j];
            --j;
        }
        a[j+1] = v;
		for(int i=0; i<n; ++i) {
        if(i) printf(" ");
        printf("%d", a[i]);
    }
		printf("\n");
        //ace(a, n);
    }
}
 
int main()
{
   
    int n, a[110];
    scanf("%d", &n);
    for(int i=0; i<n; ++i) scanf("%d", &a[i]);
    
    trace(a, n);
    insertionSort(a, n);
 
    return 0;
}



