int main(){
    int n,k,i,j,count=0;
    int a[10000];
    int b[10000];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
     scanf("%d",&k);
    for(i=0;i<k;i++){
        scanf("%d",&b[i]);
    }
    for(i=0;i<k;i++){
        for(j=0;j<n;j++){
            if(a[j]==b[i]){
                count++;
                break;
            }
        }
    }
    printf("%d\n",count);
}
