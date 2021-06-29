#include "iostream"

void merge(int A[],int left,int right,int* count){
  if(left<right){
    int mid=(left+right)/2;
    int n1=mid-left+1,
        n2=right-mid;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++){
      L[i]=A[left+i];
    }
    for(int i=0;i<n2;i++){
      R[i]=A[mid+i+1];
    }
    int p=0,j=0;
    for(int i=left;i<=right;i++){
      *count+=1;
      if(p==n1){
        A[i]=R[j];
        j++;
      }else if(j==n2){
        A[i]=L[p];
        p++;
      }else if(L[p]>R[j]){
        A[i]=R[j];
        j++;
      }else if(L[p]<=R[j]){
        A[i]=L[p];
        p++;
      }else{
        std::cout<<"error"<<std::endl;
        break;
      }
    }
  }
}

void merge_sort(int A[],int left,int right,int *count){
  if(right-left>0){
    int mid=(right+left)/2;
    merge_sort(A,left,mid,count);
    merge_sort(A,mid+1,right,count);
    merge(A,left,right,count);
  }
}

int main(){
  int n;
  std::cin>>n;
  int S[n];
  for(int i=0;i<n;i++){
    std::cin>>S[i];
  }
  int count=0;
  merge_sort(S,0,n-1,&count);
  for(int i=0;i<n;i++){
    std::cout<<S[i];
    if(i==n-1){
      std::cout<<std::endl;
    }else{
      std::cout<<" ";
    }
  }
  std::cout<<count<<std::endl;
}

