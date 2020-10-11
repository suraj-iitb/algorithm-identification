int main(){
  int i,j,k,minj,swap,count=0,temp;
  int a[10000];
  scanf("%d",&k);
  for(i=0;i<k;i++){
    scanf("%d",&a[i]);
  }
  for(i=0;i<k;i++){
    minj = i;
    swap = 0;
    for(j=i;j<k;j++){
      if(a[j] < a[minj]){
	        minj = j;
	        swap = 1;
      }
    }
    if(swap == 1){
        temp = a[minj];
        a[minj] = a[i];
        a[i] = temp;
        count++;
    }
  }
  for(i=0;i<k;i++){
    if(i == k -1){
        printf("%d\n",a[i]);
        break;
    }
    printf("%d ",a[i]);
  }
  printf("%d\n",count);
  return 0;
}

