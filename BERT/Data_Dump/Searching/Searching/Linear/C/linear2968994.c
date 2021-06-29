#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    int number1,number2;
    int readScan = scanf("%d", &number1);
    int array1[number1];
    for(int i=0;i<number1;i++)
    {
        int readScan = scanf("%d", &array1[i]);
    }
    int readScan1 = scanf("%d", &number2);
    int array2[number2];
    for(int i=0;i<number2;i++)
    {
        int readScan = scanf("%d", &array2[i]);
    }
    int key;
    int count=0;
    for(int i=0;i<number2;i++)
    {
        for(int j=0;j<number1;j++)
        {
            key=array2[i];
            if(key == array1[j])
            {
                count++;
                break;
            }
        }
    }
    printf("%d\n", count);
    return (EXIT_SUCCESS);
}
