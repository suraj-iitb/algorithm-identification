#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print(int a[],int n){
    bool isFirst = true; 

    for(int i=0;i<n;i++){
        if(isFirst){
            cout<<a[i];
            isFirst=false;
        }else{
            cout<<" "<<a[i];
        }
    }
    cout<<"\n";
}

double insertionSort(int A[],int N){
    int i,j,k;
    int tmp;
    for (i=1;i<N; i++){
        tmp=A[i];
        j=i-1;
        while (j>=0 and A[j]>tmp)
        {
            A[j+1]=A[j];
            j--;
            A[j+1] = tmp;
        }
        print(A,N);
    }
    return 0;

}

int main()
{
    int n;
    std::cin >> n;
    int a[n];

    for(int i=0; i<n; i++) std::cin >> a[i];

    print(a,n);
    insertionSort(a,n);

    return 0;

}



