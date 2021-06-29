/*#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;*/
#include<stdio.h>
#include<stdlib.h>

#define MAX 2000001
#define VMAX 10000

int main()
{
    unsigned short *A,*B;
    int C[VMAX+1];
    int n,i;
    //cin>>n;
    scanf("%d",&n);

    A=(unsigned short *)malloc(sizeof(unsigned short)*n+1);
    B=(unsigned short *)malloc(sizeof(unsigned short)*n+1);
  // A=malloc(sizeof(short) * n+1);
   // B=malloc(sizeof(short) * n+1);

    for(i=0;i<VMAX;i++)
        C[i]=0;

    for(i=0;i<n;i++)
    {
       // cin>>A[i+1];
       scanf("%hu",&A[i+1]);
        C[A[i+1]]++;
    }

    for(i=1;i<=VMAX;i++)C[i]=C[i]+C[i-1];

    for(i=1;i<=n;i++)
    {
        B[C[A[i]]]=A[i];
        C[A[i]]--;
    }

    for(i=1;i<=n;i++)
    {
        if(i>1) printf(" ");// cout<<" ";
        //cout<<B[i];
        printf("%d",B[i]);
    }
    //cout<<endl;
    printf("\n");
    return 0;
}
