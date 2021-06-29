#include<stdio.h>

int main(){
  int i,s[10000],j,t[500],n=0,q=0,count=0,count2=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }


  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&t[i]);
  }


  for(i=0;i<q;i++){
    for(j=0;j<n;j++){
      if(t[i]==s[j]){
	count2++;
	if(count2>=2){
	  count--;
	}
	count++;
      }
    }
    count2=0;
  }
  
  printf("%d\n",count);
  
  return 0;
}

