#include<stdio.h>

int n=0;
int a[101]={};

void printer(n){
  for(int i=0;i<n;i++){
      if(i==n-1){
          printf("%d\n",a[i]);
          break;
      }
      printf("%d ",a[i]);
  }


}

int main(){


    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printer(n);


    for(int i=1;i<=n-1;i++){
        int v,j;
        v=a[i];
        j=i-1;
        while(j>=0 && a[j]>v){
            a[j+1]=a[j];
            j--;
            a[j+1]=v;
        }
            printer(n);
    }
    return 0;
}

