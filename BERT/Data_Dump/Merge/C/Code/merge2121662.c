#include<stdio.h>
#define inf 1000000001

int count=0;

void merge(int s[],int left,int mid,int right){
    int n1=mid-left;
    int n2=right-mid;
    int L[n1+1],R[n2+1];
    int i;
    for(i=0;i<=n1-1;i++)L[i]=s[left+i];
    for(i=0;i<=n2-1;i++)R[i]=s[mid+i];
    L[n1]=inf,R[n2]=inf;
    i=0;
    int j=0,k;
    for(k=left;k<=right-1;k++){
        if(L[i]<=R[j]){
            s[k]=L[i];
            i++;
            
        }else{
            s[k]=R[j];
            j++;
            
        }
        count++;
    }
}

void mergeSort(int s[],int left,int right){
    if(left+1<right){
        int mid=(left+right)/2;
        mergeSort(s,left,mid);
        mergeSort(s,mid,right);
        merge(s,left,mid,right);
    }
}


int main(){
    int n;
    scanf("%d",&n);
    int s[n];
    int i;
    for(i=0;i<=n-1;i++)scanf("%d",&s[i]);
    
    mergeSort(s,0,n);
    
    for(i=0;i<=n-2;i++)printf("%d ",s[i]);
    printf("%d\n",s[n-1]);
    printf("%d\n",count);
    
    return 0;
}
