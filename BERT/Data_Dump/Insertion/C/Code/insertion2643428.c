#include <stdio.h>
#include <stdlib.h>

int main( void )
{
    char tmp;
    unsigned char i = 0;
    unsigned char k = 0;
    unsigned char Num = 0;
    
    int j = 0;
    int v = 0;

    while( (tmp = getchar()) != '\n' )
    {
        Num = (Num * 10) + (tmp - '0');
    };
   
    int Array[Num];

    for(k=0; k<Num; k++ )
    {
        Array[k]=0;
    
        do{
            tmp = getchar();
            printf("%c",tmp);
            
            if(tmp == '\n')
            {
                break;
            }
            
            if( tmp != ' ' )
            {
                Array[k] = Array[k] * 10 + (tmp - '0');
            }
        }while(tmp != ' ' && tmp != '\n');
    }

    for( i = 1; i < Num; i++ )
    {
        v = Array[i];
        j = i - 1;
     
        while( j >= 0 && Array[j] > v )
        {
            Array[j+1] = Array[j];
            j--;
            Array[j+1] = v;
        }
    
        for(k=0; k<Num; k++ )
        {
            printf("%d",Array[k]);
            if( k == Num-1 )
            {
               printf("\n");
            }
            else
            {
               printf(" ");
            }
        }
    }
    
    return 0;
}
