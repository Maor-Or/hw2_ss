#include "my_mat.h"
#include <stdio.h>
#define SIZE 10


void fun_A(int Mat[SIZE][SIZE])
{
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            scanf("%d", &Mat[i][j]);
        }
    }

}

void Floyd_Warshall_algorithm(int Mat[SIZE][SIZE])
{
   
     for(int k=0;k<SIZE;k++)
   {
        for (int row = 0; row < SIZE; row++)
        {
            for (int col = 0; col < SIZE; col++)
            {
                if(row!=col) // if not on the main diagonal of the matrix
                {
                    if(Mat[row][k]==0 || Mat[k][col]==0) //if one of the matrixes have INF (presented with a 0) then we take the other option
                        continue;

                    if(Mat[row][col]==0)//if the left side of the equation is INF (presented by 0) then we take the other way (which can't be INF because we just checked!)
                    {
                        Mat[row][col] = Mat[row][k] + Mat[k][col];
                        continue;
                    }
                        //the normal case when no side is INF, we will take the lighter path
                    if ((Mat[row][k] + Mat[k][col]) < Mat[row][col])
                        Mat[row][col] = Mat[row][k] + Mat[k][col];
                }
            }   
        }
    
   }
  
}

void fun_B(int i ,int j,int Mat[SIZE][SIZE])
{
    int Path_Mat[SIZE][SIZE];

     for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
           Path_Mat[i][j]=Mat[i][j];
        }
    }
    Floyd_Warshall_algorithm(Path_Mat);
   
    if(Path_Mat[i][j] == 0)
        printf("False\n");
    else
        printf("True\n");   

  
}

void fun_C(int i ,int j,int Mat[SIZE][SIZE])
{
  int Path_Mat[SIZE][SIZE];

     for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
           Path_Mat[i][j]=Mat[i][j];
        }
    }
    Floyd_Warshall_algorithm(Path_Mat);
   
    if(Path_Mat[i][j] == 0)
        printf("-1\n");
    else
        printf("%d\n",Path_Mat[i][j]);  

}
