#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;
long long d[110][110];
long long inf=10000000000;

int main(void){
	int v,e,i,j,k,x,y,z;
	cin >> v >> e;
	for(i=0;i<v;i++) {
		for(j=0;j<v;j++){
			if(i==j) d[i][j] = 0;
			else d[i][j] = inf;
		}
	}
	for(i=0;i<e;i++){
		cin >> x >> y >> z;
		d[x][y]=z;
	}
/*for(i=0;i<v;i++) {
for(j=0;j<v-1;j++) {
cout << d[i][j] << " ";
}
cout << d[i][v-1] << endl;
}*/
	for(k=0;k<v;k++) {
		for(i=0;i<v;i++) {
			for(j=0;j<v;j++) {
				if(d[i][k] != inf && d[k][j] != inf) d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
/*	for(i=0;i<v;i++) {
                for(j=0;j<v;j++) {
                        for(k=0;k<v;k++) {
                                if(d[i][k] != inf && d[k][j] != inf) d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
                        }
                }
        }
	for(i=0;i<v;i++) {
                for(j=0;j<v;j++) {
                        for(k=0;k<v;k++) {
                                if(d[i][k] != inf && d[k][j] != inf) d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
                        }
                }
        }*/
	bool ch = false;
	for(i=0;i<v;i++) {
		if(d[i][i] < 0) ch = true;
	}
	if(ch) {
		cout << "NEGATIVE CYCLE\n";
	} else {
		for(i=0;i<v;i++) {
			for(j=0;j<v-1;j++) {
				if(d[i][j] == inf) cout << "INF ";
				else cout << d[i][j] << " ";
			}
			if(d[i][v-1] == inf) cout << "INF\n";
			else cout << d[i][j] << endl;
		}
	}
}

