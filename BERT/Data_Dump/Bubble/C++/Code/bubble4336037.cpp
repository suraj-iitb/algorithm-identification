#include<iostream>
#include<utility>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[110];
    for(int i=0;i<n;i++)cin>>a[i];
    int cnt=0;
    //BubbleSort
    // for(int i=0;i<n-1;i++){
    //     for(int j=i+1;j<n;j++){
    //         if(a[i]>a[j]){
    //             swap(a[i],a[j]);
    //             cnt++;
    //         }
    //     }
    // }
    int tmp = 0;
	for(int i = n-1;i > 0;i--){
		for(int j = 0; j < i;j++){
			if(a[j] > a[j+1]){
				tmp = a[j+1];
				a[j+1] = a[j];
				a[j] = tmp;
				cnt++;
			}
		}
	}
    //Output
    for(int i=0;i<n;i++){
        cout<<a[i];
        if(i<n-1)cout<<" ";
        else cout<<"\n";
    }
    cout<<cnt<<endl;
    return 0;
}
