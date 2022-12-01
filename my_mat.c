#include "my_mat.h"
#include <stdio.h>
#include <math.h>
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
/*
void Mat_Printer(int Mat[SIZE][SIZE])
{
     for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            printf("%d ",Mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
*/
void Floyd_Warshall_algorithm(int Mat[SIZE][SIZE])
{
   
     for(int k=0;k<SIZE;k++)
   {
        for (int row = 0; row < SIZE; row++)
        {
            for (int col = 0; col < SIZE; col++)
            {
                if(row!=col)
                {
                    if(Mat[row][k]==0 || Mat[k][col]==0)
                        continue;

                    if(Mat[row][col]==0)
                    {
                        Mat[row][col] = Mat[row][k] + Mat[k][col];
                        continue;
                    }

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
        printf("False \n");
    else
        printf("True \n");   

  
}

int fun_C(int i ,int j,int Mat[SIZE][SIZE])
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
        return -1;
    else
        return Path_Mat[i][j];  

}
