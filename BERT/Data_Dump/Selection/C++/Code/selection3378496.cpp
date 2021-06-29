#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, cnt = 0;
	vector<int> A(101);
    cin >> n;
	for(int i = 0; i < n; i++) cin >> A[i];

    int minj;
    for(int i = 0; i < n; i++)
    {
        minj = i;
        for(int j = i+1; j < n; j++)
        {
            if(A[minj] > A[j]) minj = j;
        }
        
        if(i != minj) cnt++;
        
        swap(A[i], A[minj]);

    }

    for(int i = 0; i < n; i++)
    {
        if(i > 0) cout << ' ';
        cout << A[i];
    }

    cout << endl << cnt << endl;
    
    
}
