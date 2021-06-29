  #include<stdio.h>

  int main(){

    int a[100],t,j,i,length,minj,count=0;
    scanf("%d",&length);
    for(i=0;i<length;i++){
      scanf("%d",&a[i]);
    }

    for(i=0;i<length;i++){
      minj = i;

      for(j=i;j<length;j++){

  if(a[j] < a[minj]){
  minj =  j; 
  }
      }

      if(minj != i){
        t=a[i];
        a[i]=a[minj];
        a[minj]=t;

        count++;
      }
    }
    for(j=0;j<length;j++){

      printf("%d",a[j]);
      if(j != length-1)
      printf(" ");
    }
    printf("\n");
    printf("%d\n",count);

    return 0;
  }
