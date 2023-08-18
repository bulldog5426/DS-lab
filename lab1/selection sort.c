#include<stdio.h>
int main ()
{

     int arr[100], n , search ,flag =0;
    int i,j,position ,swap;
    printf("enter the number of elements in the array ");
    scanf("%d" , &n);
    printf("enter the elements of the array ");
    //array input
    for ( i = 0 ; i<n ; i++)
    {
        scanf("%d", &arr[i]);
    }
    //sorting the array using selection sort
    for (i=0 ; i<(n-1);i++)
    {
        position = i ;
        for (j=i+1; j<n ; j++)
        {
            if (arr[position] > arr[j])
            {
                position = j ;
            }
        }
        if(position !=i)
        {
            swap = arr[i];
            arr[i] = arr[position];
            arr[position]= swap;
        }

    }
    for (i = 0 ;i<n;i++)
    {
        printf("%d \t", arr[i]);
    }
}
