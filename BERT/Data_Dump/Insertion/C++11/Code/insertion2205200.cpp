#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    int N,v;
    vector<int> A;
    scanf("%d",&N);
    for(int i=0; i<N; i++){
        int a;
        scanf("%d",&a);
        A.push_back(a);
    }
    for(int j=0; j<N-1; j++){
        printf("%d ",A[j]);
    }
	printf("%d\n",A[N-1]);
    int j;
    for(int i=1; i<N; i++){
        v = A[i];
        j = i - 1;
        while(j>=0 && A[j] > v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        for(int j=0; j<N-1; j++){
            printf("%d ",A[j]);
        }
	    printf("%d\n",A[N-1]);
    }
}
