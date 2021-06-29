#include<stdio.h>
int view(int *,int);// 1 hairetu 2 nagasa
int swap(int *,int*);

int main(){
  int t,i,j,n,a[100],cn=0,*min;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  for(i=0;i<n-1;i++){
    min=&a[i];
    for(j=i+1;j<n;j++){
      if(*min>a[j]){
	min=&a[j];
      }
    }
    if(min !=&a[i]){
    swap(&a[i],min);
    cn++;
    }
  }
  view(a,n);
  printf("%d\n",cn);
return 0;  
  
return 0;
}
int view(int *a,int n){
  int i;
  for(i=0;i<n;i++){
    printf("%d",a[i]);
    if(i==n-1)printf("\n");
    else printf(" ");
  }

}
int swap(int *a,int *b){
  int t;
        t = *a;
	*a = *b;
	*b = t;
}

