int main(){
    int i,n,j,tem;
    int swap=0;
    int a[100];
    scanf("%d",&n);
    for(i =0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if (a[j]>a[j+1]){
            tem=a[j];
            a[j]=a[j+1];
            a[j+1]=tem;
            swap++;
           
            }
        }
    }
    for(i=0;i<n;i++){
        printf("%d",a[i]);
        if(i!=n-1){
            printf(" ");
        }
    }
    printf("\n");
    printf("%d\n",swap);
    
    return 0;
}

