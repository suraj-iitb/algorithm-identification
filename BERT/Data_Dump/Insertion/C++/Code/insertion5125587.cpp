#include<bits/stdc++.h>

using namespace std;
  
int main(){
int n;
cin >> n;
vector<int> a(n);

for(int i = 0;i < n;i++){
	cin >> a[i];
}//入力

for(int i = 0;i < n-1;i++){
	cout << a[i] << ' ';
}
cout <<a[n-1] <<endl;//最初の配列出力


int v,j ;
for(int i = 1;i < n;i++){
	v = a[i];
j = i-1;// jはiの左隣
while(a[j] > v&& j >= 0){
	a[j+1] = a[j]; 
	j--;
	a[j+1] = v;
}
for(int k = 0;k < n-1;k++){
	cout << a[k] <<' ' ;
}
cout <<a[n-1] << endl;//変えた分出力




}


}
