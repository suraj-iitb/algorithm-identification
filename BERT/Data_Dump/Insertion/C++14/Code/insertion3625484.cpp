#include<bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	vector<int> sor(N);
	int roop,roop2;
	for(roop=0;roop<N;roop++){
		cin >> sor[roop];
	}
	int v,j;
	for(roop=0;roop<N;roop++){
		v=sor[roop];
		j=roop-1;
		while(j>=0&&sor[j]>v){
			sor[j+1]=sor[j];
			j--;
		}
		sor[j+1]=v;
		for(roop2=0;roop2<N;roop2++){
			cout << sor[roop2];
			if(roop2<N-1){
				cout << " ";
			}else{
				cout << endl;
			}
		}
	}
	return 0;
}
