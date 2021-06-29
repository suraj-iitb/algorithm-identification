#include<stdio.h>

int n,a[500000],sw=0;


void merge(int left,int mid,int right){
    int l[500000],r[500000],i,j,k,l1,r1;
    j=k=0;
    l1=mid-left;
    r1=right-mid;

    for(i=0;i<l1;i++)l[i]=a[left+i];
    for(i=0;i<r1;i++)r[i]=a[mid+i];

    l[l1]=r[r1]=1000000000;

    for(i=left;i<right;i++){
        sw++;
        if(l[j]>=r[k]){
            a[i]=r[k];
            k++;
        }
        else {
            a[i]=l[j];
            j++;
        }
    }
}


void mergeSort(int left,int right){
    int mid;
    if(left+1<right){
    mid=(left+right)/2;
    mergeSort(left,mid);
    mergeSort(mid,right);
    merge(left,mid,right);
    }
}


int main(){
    int i;

    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    mergeSort(0,n);

    for(i=0;i<n;i++){
        if(i)printf(" ");
        printf("%d",a[i]);
    }
    printf("\n%d\n",sw);
}
