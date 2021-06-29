#include <iostream>
#include <algorithm>
using namespace std;
int ss(int a[],int n){
    int i,j;
    int min;
    int c=0;
    for(i=0;i<n;i++){
        min = i;
        for(j=i;j<n;j++){
			if(a[j]<a[min]) min = j;
        }
        swap(a[i],a[min]);
        if(i != min) c++;
    }
    return c;
}
int main(){
    int i;
    int n;
    int a[100];
    int ans;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> a[i];
    }
    ans = ss(a,n);
    for(i=0;i<n;i++){
		printf("%d", a[i]);
		if(i!=n-1) printf(" ");
    }
	printf("\n");
    cout << ans << endl;
}


