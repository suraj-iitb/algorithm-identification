#include<stdio.h> 

int main()
{
	int a,b,c,i,j,k,l,N=0,cnt=0;
scanf("%d",&N);
int A[N];
for(k=0;k<N;k++){
 scanf("%d",&A[k]);
}

	for (i=0;i<N-1;i++)
	{
        c=A[i];
		a=i;
		for (j=i;j<N;j++)
		{
            if (c>A[j]){
		    a=j;
            c=A[j];
            }
		}
        if(A[i]!=c){
        b=A[i];
		A[i]=A[a];
		A[a]=b;
        cnt++;
        }
    }
for(l=0;l<N-1;l++){
    printf("%d ",A[l]);
}
printf("%d\n",A[N-1]);
printf("%d\n",cnt);

	return 0;
}
