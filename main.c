#include <stdio.h>
#include "my_mat.h"

#define SIZE 10
int main()
{
    char menu ='F';
    int flag =1;
    int Mat[SIZE][SIZE];
    int i,j;
    while(flag)
    {
        scanf("%c",&menu);
        switch (menu)
        {
            case 'A': 
                fun_A(Mat);
                //Mat_Printer(Mat);
                break; 
            case 'B':
                scanf("%d %d",&i,&j);
                fun_B(i,j,Mat); 
                break;    
            case 'C':
                scanf("%d %d",&i,&j);
                fun_C(i,j,Mat);
                //printf("%d \n",fun_C(i,j,Mat));
                break;
            case 'D':
                flag = 0;
                break;
            default:
                break;
        }
    }

    return 0;

}