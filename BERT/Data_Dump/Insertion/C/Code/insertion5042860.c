#include<stdio.h>
int main()
{
  int N,i,j,h,key;
    scanf("%d",&N);\

    int data[N];
    for(i=0;i<N;i++){
        scanf("%d",&data[i]);
    }
		for(h=0;h<N;h++){
	  if(h == N-1) printf("%d",data[h]);
	  else printf("%d ",data[h]);
	}
	printf("\n");
    for(i=1;i<N;i++){
        key=data[i];
        for(j=i-1;j>=0;j--){
	  if(data[j] > key){
	    data[j+1]=data[j];
	    data[j] = key;
	  }
	  else break;
        }
	for(h=0;h<N;h++){
	  if(h == N-1) printf("%d",data[h]);
	  else printf("%d ",data[h]);
	}
	printf("\n");
    }

    return 0;
}

