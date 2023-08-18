#include <stdio.h>
int BinarySearch(int array[], int start_index, int end_index, int element)
{
   while (start_index <= end_index){
      int middle = start_index + (end_index- start_index )/2;
      if (array[middle] == element)
         return middle;
      if (array[middle] < element)
         start_index = middle + 1;
      else
         end_index = middle - 1;
   }
   return -1;
}
int main()
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
    printf("enter the element to be searched");
    scanf("%d" ,&search);
    int foundindex = BinarySearch(arr , 0 , n-1 , search);
    if (foundindex == -1)
    {
        printf("element not found");
    }
    else
    {
        printf("element found at index : %d" , foundindex);
    }


}
