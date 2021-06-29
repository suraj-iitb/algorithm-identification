#include <bits/stdc++.h>
#define INT(name) int name; scanf("%d",&name);
#define VINT(name,n) vector<int> name(n); for(int i = 0;i < n;i++) scanf("%d",&name[i]);

using namespace std;

int main(int argc, char const *argv[]){
	INT(x)
	VINT(data,x)

	for(int i = 1;i < x;i++){
		printf("%d",data[0]);
		for(auto it = data.begin()+1;it < data.end();it++)
    		printf(" %d",*it);
    	printf("\n");
   		int key = data[i];
    	int j = i - 1;
    	while(j >= 0 and data[j] > key){
        	data[j+1] = data[j];
        	j--;
        }
    	data[j+1] = key;
    }
    		printf("%d",data[0]);
		for(auto it = data.begin()+1;it < data.end();it++)
    		printf(" %d",*it);
    	printf("\n");
	return 0;
}
