#include <stdio.h>
#include <math.h>
int c;
void bubbleSort(int x[], const int y) //バブルソート部
{
  int flag,tmp,j;

  flag=1;
  do {
      flag=0;
      for(j=y-1;j>=1;j--) {
          if(x[j] < x[j-1]) {
              tmp=x[j];
	          x[j]=x[j-1];
	          x[j-1]=tmp;
	          c++;
	          flag=1;
          }
      }
  }while(flag==1);
}


int main(void)
{
  int a[100]={0};
  int n,i;

  scanf("%d",&n);
  for(i=0;i<n;i++) {
    scanf("%d",&a[i]);
  }
 
    bubbleSort(a,n);
    
  printf("%d",a[0]);
  for(i=1;i<n;i++) {
    printf(" %d",a[i]);
  }
  printf("\n");
  printf("%d\n",c);
  return(0);
}

