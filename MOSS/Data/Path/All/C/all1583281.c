#include<iostream>

using namespace std;

int V,E,s,t;
long long d;
const long long inf=100000000000000;
long long K[100][100];

int main(){
	cin >> V >> E;

	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			if(i==j){
				K[i][j]=0;
			}else{
				K[i][j]=inf;
			}
		}
	}

	for(int i=0;i<E;i++){
		cin >> s >> t >> d;
		K[s][t]=d;
	}

	for(int k=0;k<V;k++){
		for(int i=0;i<V;i++){
			for(int j=0;j<V;j++){
				long long temp;
				if(K[i][k]==inf||K[k][j]==inf){
					temp=inf;
				}else{
					temp=K[i][k]+K[k][j];
				}
				if(temp<K[i][j]){
					K[i][j]=temp;
				}
			}
		}
	}
	
	bool ans=false;
	for(int i=0;i<V;i++){
		ans=ans||(K[i][i]<0);
	}
	if(ans){
		cout << "NEGATIVE CYCLE" << endl;
	}else{
		for(int i=0;i<V;i++){
			for(int j=0;j<V;j++){
				if(K[i][j]==inf){
					cout << "INF";
				}else{
					cout << K[i][j];
				}
				if(j!=V-1){
					cout << " ";
				}
			}
			cout << endl;
		}
	}
}
