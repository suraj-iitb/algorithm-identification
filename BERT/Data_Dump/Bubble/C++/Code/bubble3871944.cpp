#include <bits/stdc++.h>
using namespace std;
 
int main() {
int n,counter;
bool flag=true;
cin>>n;
vector<int> vec(n);
  
for(int i=0;i<n;i++){
	cin>>vec[i];
}

while(flag){
	flag=false;
	for(int j=n-1;0<j;j--){
		if(vec[j]<vec[j-1]){
			int temp = vec[j];
			vec[j] =vec[j-1];
			vec[j-1] = temp;
			flag = true;
          	counter ++;
		}
	}

}

for(int i=0;i<n;i++){
	if(i==n-1){
      cout<<vec[i]<<endl;
    }else{
      cout<<vec[i]<<" ";
    }
}
cout<<counter<<endl;

}
