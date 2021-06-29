#include<stdio.h>
#include<stdlib.h>
#define N 100000
void quicksort(char *,int *,int,int);
int partition(char *,int *,int,int);
int main(){
  int cnt=0,n,i,j,num[N],cnum[N],flag=0;
  char cstr[N],str[N],*check;
  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    scanf(" %c %d",&str[i],&num[i]);
    cnum[i]=num[i];
    cstr[i]=str[i];
  }
  quicksort(str,num,0,n-1);
  for(j=0;j<n;j++){
    cnt=0;
    for(;j<n;j++){
      cnt++;
      if(j!=n-1){
      if(num[j]!=num[j+1])
	break;
      }
    }
    for(i=0;i<n;i++){
      if(num[j]==cnum[i]&&str[j-(cnt-1)]!=cstr[i]){
	flag=1;
	//	printf("%d %d a%c b%c\n",num[j],cnum[i],str[j-(cnt-1)],cstr[i]);
	break;
      }
      else if(num[j]==cnum[i])
       cnt--;
      if(cnt==0)
	break;
    }
    if(flag==1)
      break;
      
  }
  if(flag==1)
    printf("Not stable\n");

  else
    printf("Stable\n");

  for(i=0;i<n;i++){
    printf("%c %d\n",str[i],num[i]);
  }
  
  return 0;
}
int partition(char str[],int A[],int p,int r){
int x,i,j,hoge;
 char foo; 
x=A[r];
i=p-1;
for(j=p;j<=r-1;j++){
if(A[j]<=x){
i=i+1;
hoge=A[i];
A[i]=A[j];
A[j]=hoge;
 foo=str[i];
 str[i]=str[j];
 str[j]=foo;
}
  
}
hoge=A[i+1];
A[i+1]=A[r];
A[r]=hoge;
  foo=str[i+1];
 str[i+1]=str[r];
 str[r]=foo;
return i+1;
}
void quicksort(char str[],int A[],int p,int r ){
  int q;
  if(p<r){
    q=partition(str,A,p,r);
    quicksort(str,A,p,q-1);
    quicksort(str,A,q+1,r);
  }

}

