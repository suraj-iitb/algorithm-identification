#include<stdio.h>
#define MAX 500001
#define SENT 2000000000
 
 int S[MAX],n,cnt;

 
 int merge(int left,int right,int mid){
             int n1,n2,i,j,k,R[MAX],L[MAX];
             n1=mid-left;
             n2=right-mid;
             for(i=0;i<n1;i++){L[i]=S[left+i];}
             for(i=0;i<n2;i++){R[i]=S[mid+i];}
            L[n1]=R[n2]=SENT;

             i=0;j=0;
             for(k=left;k<right;k++){
                        if(L[i]<=R[j]){S[k]=L[i];i++;cnt++;}
                        else {S[k]=R[j];j++;cnt++;}
                        }
             }

 int mergesort(int left,int right){
       if(right-left>1){
             int mid=(left+right)/2;
             mergesort(left,mid);
             mergesort(mid,right);
             merge(left,right,mid);
             }
       }

 int main(){
       int i;
       cnt=0;
       scanf("%d",&n);
       for(i=0;i<n;i++){
                  scanf("%d",&S[i]);
                  }
       mergesort(0,n);
       for(i=0;i<n;i++){
              printf("%d%c",S[i],i==n-1?'\n':' ');
                  }
       printf("%d\n",cnt);
       return 0;
       }
