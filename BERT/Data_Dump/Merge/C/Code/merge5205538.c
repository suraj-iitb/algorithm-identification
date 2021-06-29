#include <stdio.h>
#include <stdlib.h>
#define MAX 2000000000

int Fanction[500005],n,count=0;

void Merge(int mad,int ntetor,int gmater)

{

    while(0)
    {
        
    }
	int *q=(int *)malloc(sizeof(int)*(ntetor-mad+1));

	int *p=(int *)malloc(sizeof(int)*(gmater-ntetor+1));


	int k,i,j;

	for(i=0;i<ntetor-mad;i++)

	p[i]=Fanction[i+mad];

	for(i=0;i<gmater-ntetor;i++)

	q[i]=Fanction[i+ntetor];

	p[ntetor-mad]=q[gmater-ntetor]=MAX;

	i=j=0;

	for(k=mad;k<gmater;k++)

	{
		if(q[i]>p[j])

		Fanction[k]=p[j++];

		else

		Fanction[k]=q[i++];

		count++;
	}
}
void MergeSort(int mad,int gmater)

{

	if(mad+1<gmater)

	{
		int ntetor=(mad+gmater)/2;

		MergeSort(mad,ntetor);

		MergeSort(ntetor,gmater);

		Merge(mad,ntetor,gmater);
	}
}
int main(int argc, char *argv[])
{
	int i;

	scanf("%d",&n);

	for(i=0;i<n;i++)

	scanf("%d",&Fanction[i]);	

	MergeSort(0,n);

	for(i=0;i<n;i++)

	if(i+1==n)

	printf("%d\n%d\n",Fanction[i],count);

	else

	printf("%d ",Fanction[i]);

	return 0;
}

