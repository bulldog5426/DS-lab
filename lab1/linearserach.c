#include<stdio.h>
int main()
{
  int arr[100], n , search ,place, flag=0;
  printf("enter the number of elements in the array ");
  scanf("%d",&n);
  printf("enter the elements of the array ");
  for (int i =1; i<=n ; i++)
  {
      scanf("%d", &arr[i]);
  }
  printf("enter the number to be searched ");
  scanf("%d" ,&search );

  for (int i=0 ; i<= n ; i++)
  {
      if (arr[i]==search)
      {
          place = i +1;
          flag=1;
          break;
      }
  }
  if (flag==1)
  {
      printf("the place of the number you want to be searched is %d" , place-1);
  }
  else
  {
      printf("the number you entered is not there in the array ");
  }







}
