#include <stdio.h>
int cccc;

void merge(int a[],int left,int mid,int right){
    int n1,n2,i,j,k;
    int l[250002],r[250002];
    n1 = mid-left; n2 = right-mid;
    for(i=0;i<n1;i++){
        l[i] =a[i+left];
    }
    for(i=0;i<n2;i++){
        r[i] =a[i+mid];
    }
    l[n1]=1000000001;r[n2]=1000000001;
    i=0;j=0;
    for(k=left;k<right;k++){
        if(l[i]<=r[j]){
            a[k] = l[i];
            i++;
        }else{
            a[k] = r[j];
            j++;
        }
        cccc++;
    }
    
}

void mergesort(int a[],int left,int right){
    int mid;
    if(left+1<right){
        mid = (left+right)/2;
        mergesort(a,left,mid);
        mergesort(a,mid,right);
        merge(a,left,mid,right);
    }
}

int main(void){
    int n,i;
    int a[500000];
    cccc=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    mergesort(a,0,n);
    for(i=0;i<n;i++){
        printf("%d",a[i]);
        if(i!=n-1){printf(" ");}
    }
    printf("\n%d\n",cccc);
}

