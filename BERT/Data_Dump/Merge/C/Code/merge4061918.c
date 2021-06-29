#include <stdio.h>
long int a[500000],l[500000],r[500000];
int c=0;
void ms(int,int);
void m(int,int,int);
int main(){
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    
    ms(0,n);
    
    for(i=0;i<n-1;i++){
        printf("%d ",a[i]);
    }
    printf("%d\n%d\n",a[n-1],c);
    
    return 0;
}

void ms(int left, int right){
    int mid;
    if(left+1<right){
        mid=(left+right)/2;
        ms(left,mid);
        ms(mid,right);
        m(left,mid,right);
    }
}

void m(int left,int mid,int right){
    int n,m,i,j,k;
    n = mid-left;
    m = right -mid;
    for(i=0;i<n;i++)l[i]=a[left+i];
    for(i=0;i<m;i++)r[i]=a[mid+i];
    i=0;
    j=0;
    l[n]=10000000000;
    r[m]=10000000000;
    for(k=left;k<right;k++){
        c++;
        if(l[i]<=r[j]){
            a[k]=l[i];
            i++;
        }
        else{
            a[k]=r[j];
            j++;
        }
    }
}

