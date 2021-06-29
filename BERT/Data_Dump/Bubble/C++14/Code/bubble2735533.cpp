#include <iostream>
using namespace std;

#define is_uruu main
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ROF(i,a,b) for(int i=(a);i>(b);--i)
    
int bubble(int A[],int N){
	int j,count=0;
	bool flag = 1;
	while(flag){
		flag = 0;
		ROF(j,N-1,0){
			if(A[j] < A[j-1]){
				swap(A[j], A[j-1]);
				count++;
				flag = 1;
			}
		}
	}
	return count;
}
    
int is_uruu() {
    int N,count,A[100];
    cin >> N;
    FOR(i,0,N)cin >> A[i];
    
    count = bubble(A,N);
    
    FOR(i,0,N-1)cout << A[i] << " ";
    cout << A[N-1] << endl << count << endl;
    return 0;
}
