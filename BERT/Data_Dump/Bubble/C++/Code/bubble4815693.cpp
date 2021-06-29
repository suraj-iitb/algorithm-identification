#include <iostream>
#include <cstdlib>


#define PRINTARRAY std::cout << array[0]; for (int v = 1; v < len; v++){ std::cout << ' ' << array[v]; } std::cout << "\n"

int main () {
        int len, i, j, k;
        int c = 0;
        std::cin >> len;
        int * array = (int *) malloc(sizeof(int) * len);
        for (i = len; i > 0; i--){
                std::cin >> array[len-i];
        }

        //PRINTARRAY;

        for (i = 0; i <= len - 1; i++){
                for (j = len -1; j >= i + 1; j--){
                        if (array[j] < array[j - 1]){
                                k = array[j];
                                array[j] = array[j - 1];
                                array[j - 1] = k;
                                c++;
                        }
                }
                //PRINTARRAY;
        }

        PRINTARRAY;
        std::cout << c << "\n";
        free(array);
}
