#include<stdio.h>

#define MAX 500000
#define SENTINEL 2000000000

int cnt=0;

void mergeSort(int a[],int left,int right){
    int mid;
    if(left+1==right)return;
    mid=(left+right)/2;
    mergeSort(a,left,mid);
    mergeSort(a,mid,right);
    merge(a,left,mid,right);

}

void merge(int a[],int left,int mid,int right){
    int l1=mid-left;
    int r1=right-mid;
    int i,j=0,k=0;
    int l[l1],r[r1];
    l[l1]=SENTINEL;
    r[r1]=SENTINEL;
    for(i=0;i<l1;i++)l[i]=a[left+i];
    for(i=0;i<r1;i++)r[i]=a[mid+i];
    for(i=left;i<right;i++){
        if(l[j]>r[k]){
            a[i]=r[k];
            k++;
        }
        else{
            a[i]=l[j];
            j++;
        }
        cnt++;
    }
}

int main(){
    int n,a[MAX],i;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    mergeSort(a,0,n);
    for(i=0;i<n;i++){
        if(i)printf(" ");
        printf("%d",a[i]);
    }
    printf("\n%d\n",cnt);
    return 0;
}
