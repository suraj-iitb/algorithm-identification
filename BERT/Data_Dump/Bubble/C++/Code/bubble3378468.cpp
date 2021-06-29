#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, cnt = 0, flag;
	vector<int> A(100);
    cin >> n;
	for(int i = 0; i < n; i++) cin >> A[i];

	flag = 1;
	while(flag){
		flag = 0;
        for(int i = n-1; i > 0; i--)
        {
            if (A[i] < A[i-1]) {
                swap(A[i], A[i-1]);
                flag = 1;
                cnt++;
            }
        }
	}

    for(int i = 0; i < n; i++)
    {
        if(i > 0) cout << ' ';
        cout << A[i];
    }

    cout << endl << cnt << endl;
    

	
}
