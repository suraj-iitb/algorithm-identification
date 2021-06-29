#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	int n; cin>>n;
	vector<int> A(n);
	for(int i=0; i<n; i++) cin>>A[i];
	int cnt{};
   bool flag = 1; // 逆の隣接要素が存在する
   while (flag){
   	
     flag = 0;
     for (int j = n-1; j>=1; j--){
       if (A[j] < A[j-1]){
         swap(A[j] , A[j-1]);
         cnt ++;
         flag = 1;
        }
    }
	}
	for(int i=0; i<n; i++) cout << A.at(i) <<(i<n-1?' ':'\n');
	cout << cnt << endl;
}

