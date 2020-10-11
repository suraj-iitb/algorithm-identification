  int main () {
  
    int i,j,l,c=0,num,min,arr[100];

    scanf("%d",&l);

    for(i=0;i<l;i++){
      scanf("%d",&arr[i]);
    }
  
    
    for(i=0;i<l;i++){
      min = i;
      for(j=i;j<l;j++){
        if(arr[j] < arr[min]){
          min = j;
        }
      }
      if(arr[i] > arr[min])
        c++;
      num = arr[i];
      arr[i] = arr[min];
      arr[min] = num;
    }

    for(i=0 ; i<l ; i++){
      if(i==l-1)
        printf("%d",arr[i]);
      else
        printf("%d ",arr[i]);
    }
      printf("\n%d\n",c);
         
  return 0;
  }
