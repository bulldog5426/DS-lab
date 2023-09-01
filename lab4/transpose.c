

#include<stdio.h>
#define ROW 4
#define COL 5


int sparse[ROW][COL] = {
{0, 0, 0, 0, 3},
{0, 0, 0, 7, 0},
{6, 0, 0, 0, 0},
{0, 4, 0, 0, 0}
};

int main()
{
    int sparseSize = 0;
    int arr[100][3] = {};

    for(int i=0; i<ROW; i++)
    {
        for(int j=0; j<COL; j++)
        {
            if(sparse[i][j] != 0)
            {

                arr[sparseSize][0] = i;
                arr[sparseSize][1] = j;
                arr[sparseSize][2] = sparse[i][j];
                sparseSize++;
            }
        }

    }



    for(int i=0; i<sparseSize; i++)
    {
        for(int j=0; j<3; j++)
        {
            printf("%d ",arr[i][j]);

        }
        printf("\n");
    }


    return 0;
}
