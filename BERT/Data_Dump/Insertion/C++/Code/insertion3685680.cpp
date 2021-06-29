#include<iostream>
using namespace std;
int main(){
int a[100]={};
int n;
cin>>n;
for(int i=0;i<n;i++){
cin>>a[i];
}

for(int i=0;i<n;i++){
int key=a[i];
int j=i-1;
while(j>=0 && a[j]>key){
	a[j+1]=a[j];
	j--;
}
a[j+1]=key;
for(int i=0;i<n;i++){
if(i!=n-1)
cout<<a[i]<<" ";
else
cout<<a[i]<<endl;
}
}
}

