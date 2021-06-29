#include<stdio.h>
#define NotFound -1
#define Found 1
int search(int *a,int n,int keyword);
int main()
  {
    int num1,num2,i,A[10001],keyword,sum=0;
    scanf("%d",&num1);
    for(i=0;i<num1;i++){
      scanf("%d",&A[i]);
    }
    scanf("%d",&num2);
    for(i=0;i<num2;i++){
      scanf("%d",&keyword);
      if(search(A,num1,keyword)==Found)sum++;
    }
    printf("%d\n",sum);

    return 0;
  }

int search(int *a,int n,int keyword){
  int i=0;
  a[n]=keyword;
  while(a[i]!=keyword)i++;
  if(i==n)return NotFound;
  else return Found;
}
