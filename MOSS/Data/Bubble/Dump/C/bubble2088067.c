#include <stdio.h>
void bubbleSort(int A[],int N){ 
   int flag = 1 ;// ????????£??\????´?????????¨??????
   int n,i,j;
   int count=0;
   while(flag){
     flag = 0;
    	for(j=N-1;j>=1;j--){ 
       		if (A[j] < A[j-1]){
       			n=A[j];
         		A[j]=A[j-1];
         		A[j-1]=n;
         		count++;
         		flag = 1;
         	}
    	}
    }
    for(i=0;i<N-1;i++){
    	printf("%d ",A[i]);
    }
    printf("%d\n",A[N-1]);
    printf("%d\n",count);
}

int main()
{
	int i,n;
	int num[100];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	bubbleSort(num,n);
	return 0;
}
