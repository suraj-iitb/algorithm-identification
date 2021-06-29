#include<iostream>
using namespace std;

const int maxn=500001;
const int INFTY=1e9+1;
int n,a[maxn];
int L[maxn/+1],R[maxn/2+1];
int cnt;

void merge(int a[],int n,int l,int mid,int r){
  int n1=mid-l;
  int n2=r-mid;
  for(int i=0;i<n1;i++){
    L[i]=a[l+i];//把前半部分给L
  }
  for(int i=0;i<n2;i++){
    R[i]=a[mid+i];//把后半部分给R
  }
  L[n1]=INFTY;//设为无穷大
  R[n2]=INFTY;
  int i=0,j=0;//3个变量依次控制 L数组，R数组，a数组，
  for(int k=l;k<r;k++){//开始比较
    cnt++;//每比较一次，+1；
    if(L[i]<=R[j])  {  a[k]=L[i]; i++; }
    else  {  a[k]=R[j]; j++; }
  }
}
void mergeSort(int a[],int n,int l,int r){
  if(l+1<r){//这样写，就可以直接，l=mid，r=mid种写法，约等于l=mid+1，r=mid
  int mid=(l+r)/2;
  mergeSort(a,n,l,mid);//前半部分
  mergeSort(a,n,mid,r);//后半部分
  merge(a,n,l,mid,r);//合并两个已经排序的数组
  }
}
int main(){
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  mergeSort(a,n,0,n);
  for(int i=0;i<n;i++){
    if(i)  cout<<" ";
    cout<<a[i];
  }
  cout<<endl;
  cout<<cnt<<endl;
return 0;
}

