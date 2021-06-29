#include <stdio.h>

void bubblesort(int[],int);

int main(){
  int a[100],i,n;

    scanf("%d",&n);

    for(i=0;i<n;i++){
      scanf("%d",&a[i]);
    }

    bubblesort(a,n);

    return 0;
}

void bubblesort(int a[],int n){
  int key=0,flag=1;
  int i,j,status;
    
    for(i=0;flag;i++){
      flag=0;
      for(j=n-1;j>=i+1;j--){
	if(a[j]<a[j-1]){
	  status=a[j];
	  a[j]=a[j-1];
	  a[j-1]=status;
	  flag=1;
	  key++;
	}
      }
    }

    for(i=0;i<n;i++){
      if(i>0) printf(" ");
      printf("%d",a[i]);
    }
    printf("\n%d\n",key);
}

