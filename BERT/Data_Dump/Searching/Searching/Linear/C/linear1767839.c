#include<stdio.h>
#define MAX 100000

int main(){
  
  int i,j,n1,n2,ans=0,flag=0;
  int arr1[MAX],arr2[MAX];

  
  scanf("%d",&n1);
  for(i=0;i<n1;i++){
    scanf("%d",&arr1[i]);
  }

  scanf("%d",&n2);
  for(i=0;i<n2;i++){
    scanf("%d",&arr2[i]);
  }

  for(i=0;i<n2;i++){
    for(j=0;j<n1;j++){
      if(arr2[i]==arr1[j]){
	flag = 1;
	ans++;
	if(flag = 1){
	  break;
	}
      }
    }
  }
 


  printf("%d\n",ans);

  return 0;
}
