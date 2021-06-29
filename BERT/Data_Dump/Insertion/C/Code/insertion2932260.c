#include <stdio.h>
#include <stdlib.h>

int main(){
    int elementNumber, *numberArray;
    // read input
    scanf("%d\n",&elementNumber);
    numberArray = ( int* )malloc( elementNumber*sizeof( int ));
    for ( int ixArray = 0 ; ixArray < elementNumber ; ixArray++ ){
        scanf("%d",&numberArray[ixArray]);
        if ( ixArray == elementNumber-1 ) printf("%d\n",numberArray[ixArray]); // print result of initial step
        else printf("%d ",numberArray[ixArray]);
    }
    // sort in ascending order
    for (int jxArray = 1 ; jxArray < elementNumber ; jxArray++ ){        
        int keyNumber = numberArray[jxArray];
        int ixArray = jxArray-1;
        while ( ixArray >= 0 && numberArray[ixArray] > keyNumber ){
            numberArray[ixArray+1] = numberArray[ixArray];
            ixArray = ixArray-1;
        }
        numberArray[ixArray+1] = keyNumber;
        //print result after each step
        for ( int kxArray = 0 ; kxArray < elementNumber ; kxArray++ ){
            if ( kxArray == elementNumber-1 ) printf("%d\n",numberArray[kxArray]);
            else printf("%d ",numberArray[kxArray]);
        }
    }
    free(numberArray);
    return EXIT_SUCCESS;
}

