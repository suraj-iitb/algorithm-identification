#include<bits/stdc++.h>
 
typedef long long ll;
 
using namespace std;
 
int a[110];
 
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i = 1 ; i<=n ; i++){
		cin>>a[i];
	}
	for(int i = 1 ; i<=n ; i++){
		if(i == 1)
			cout<<a[i];
		else
		cout<<" "<<a[i];
	}
	cout<<endl;
	
	//由小到大插入排序 
	for(int i = 2 ; i<=n ; i++){
		for(int j = 0 ; j<=i-1 ; j++){
			if(a[i]<a[j]){            //找到已经排序的序列中第一个比待插入元素大的 
				int t = a[i];
				for(int k = i ; k>=j+1 ; k--){    //把待插入大的都向后意一位 
					a[k] = a[k-1]; 
				}
				a[j] = t;                         //插入空
                break;
            }
        }
        for(int j = 1 ; j<=n ; j++){
            if(j == 1)
                cout<<a[j];
            else
                cout<<" "<<a[j];
        }
        cout<<endl;
    }
    return 0;
}
