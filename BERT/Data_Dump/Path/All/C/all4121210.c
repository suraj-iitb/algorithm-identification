#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int x = 2000000001;
	int V, E;
	cin >> V >> E;
	long long int A[101][101];
	for (int i = 0;i < V;i++) {
		for (int j = 0;j < V;j++) {
			if (i == j) {
				A[i][j] = 0;
			}
			else {
				A[i][j] = x;
			}
		}
	}
int s, t, d;
	for (int i = 0;i < E;i++) {
		cin >> s >> t >> d;
		A[s][t] = d;
	}
	
	for (int k = 0;k < V;k++) {
		for (int i = 0;i < V;i++) {
		    if(A[i][k]==x)continue;
			for (int j = 0;j < V;j++) {
			    if (A[k][j]==x) continue;
			    A[i][j] = min(A[i][j], A[i][k] + A[k][j]);}
		}
	}

	int flag=1;
		for (int i = 0;i < V;i++) {
			if (A[i][i]<0) {
			    flag=0;
			}
		}

	

	for (int i = 0;i < V;i++) {
	      if(flag==0){
		        cout<<"NEGATIVE CYCLE"<<endl;break;
		    }
		for (int j = 0;j < V;j++) {
			if (A[i][j] == x) {
				cout << "INF" ;
			}
			else {
				cout << A[i][j];
			}
			if(j!=V-1){cout<<" ";}
		}
			
		cout << endl;
	}

	return 0;
}


