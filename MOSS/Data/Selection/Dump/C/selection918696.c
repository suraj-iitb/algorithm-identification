#include <stdio.h>
main(){
  int i,j,a[100],s,mini,p,count=0;
  scanf("%d",&s);
  for(i=0;i<s;i++){
    scanf("%d",&a[i]);
  }
  for(i=0;i<s;i++){
      mini = i;
      for(j=i;j<s;j++){
	if(a[j]<a[mini])
	 mini = j;
       }
       p = a[i];
       a[i] = a[mini];
       a[mini] = p;
       if(i != mini)
       count++;
      
  }
      for(i=0;i<s;i++){
      printf("%d",a[i]);
      if(i != s-1)
	printf(" ");
    }
    printf("\n%d\n",count);
    return 0;
}
 
