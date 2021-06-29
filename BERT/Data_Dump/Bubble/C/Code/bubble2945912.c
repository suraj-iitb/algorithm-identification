#include <stdio.h>
#include <stdlib.h>

int main(){
    int N, numArray[100];
    // read input
    scanf("%d\n",&N);
    for ( int ixArray = 0 ; ixArray < N ; ixArray++ )
        scanf("%d",&numArray[ixArray]);
        
    int counter = 0;
    for ( int ixArray = 0 ; ixArray < N ; ixArray++ )
        for ( int jxArray = N-1 ; jxArray > ixArray ; jxArray-- )
            if ( numArray[jxArray] < numArray[jxArray-1] ){
                int temp = numArray[jxArray];
                numArray[jxArray] = numArray[jxArray-1];
                numArray[jxArray-1] = temp;
                counter++;
            }
    for ( int ixArray = 0 ; ixArray < N ; ixArray++ ){
            if ( ixArray == N-1 ) printf("%d\n",numArray[ixArray]);
            else printf("%d ",numArray[ixArray]);
        }
        printf("%d\n",counter);
    
    return 0;
}

