/*ALDS1_2B*/

#include <iostream>
#define abs(a) (a<0?-(a):a)
#define square(x) ((x)*(x))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define swap(a,b) ((a!=b)?(a+=b,b=a-b,a-=b):0)
#define This
#define True true
#define False false
#define null Null


using namespace std;

int selectionSort(int[],int);

int main(){
    int n;
    cin>>n;
    int num[n];
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    cout<<selectionSort(num,n)<<endl;
    

}

int selectionSort(int num[],int N){
    int cnt=0;
    for(int i=0;i<N;i++){
        int minj=i;
        for(int j=i;j<N;j++){
            if(num[j]<num[minj]){
                minj=j;
            }
        }
        swap(num[i],num[minj]);
        if(i!=minj)cnt++;
    }
    for(int i=0;i<N-1;i++){
		cout<<num[i]<<" ";
	}
	cout<<num[N-1]<<endl;
    return cnt;
}
