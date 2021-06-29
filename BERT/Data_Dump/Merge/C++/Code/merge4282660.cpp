#include<iostream>
using namespace std;
const int MAX=500005;
int s[MAX],n,cnt=0;int temp1[MAX/2],temp2[MAX/2];
void pr(){
	for(int i=0;i<n;i++)cout<<s[i]<<" ";
	cout<<endl;
} 
void merge(int a[],int left,int right){
	int mid=left+(right-left)/2;
	int len1=mid-left,len2=right-mid;
	for(int i=0;i<len1;i++)temp1[i]=a[left+i];
	for(int i=0;i<len2;i++)temp2[i]=a[mid+i];
	int k=left,i=0,j=0;
	while(i<len1&&j<len2){
		if(temp1[i]>=temp2[j]){
			a[k++]=temp2[j++];
		}else if(temp1[i]<temp2[j]){
			a[k++]=temp1[i++];
		}
		cnt++;
	}
	cnt+=len1+len2-i-j;
	while(i<len1)a[k++]=temp1[i++];
	while(j<len2)a[k++]=temp2[j++];
	
}
void MergeSort(int a[],int left,int right){
	if(right==left+1)return;
	if(left<right){
		int mid=left+(right-left)/2; 
		MergeSort(a,left,mid);
		MergeSort(a,mid,right);
		merge(a,left,right);
	}
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>s[i];
	MergeSort(s,0,n);
	int first=1;
	for(int i=0;i<n;i++){
		if(first)first=0;else cout<<" ";
		cout<<s[i];
	}
	cout<<endl<<cnt<<endl;
	return 0;
}
