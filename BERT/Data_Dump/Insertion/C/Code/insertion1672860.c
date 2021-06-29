int main(){
    long long elements[100],key;
    int n,i,j;
 
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%lld",&elements[i]);
    }
 
    for(j=0;j<n;j++){
        printf("%lld",elements[j]);
        if(j<(n-1)) printf(" ");
    }
    printf("\n");
 
    for(i=1;i<n;i++){
        key = elements[i];
        j=i-1;
        while(j>=0 && elements[j]>key){
            elements[j+1]=elements[j];
            j--;
        }
        elements[j+1]=key;
 
        for(j=0;j<n;j++){
            printf("%lld",elements[j]);
            if(j<(n-1)) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
