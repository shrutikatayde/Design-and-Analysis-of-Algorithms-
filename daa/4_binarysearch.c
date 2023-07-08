#include <stdio.h>

int binarySearch(int arr[], int beg, int X, int end)
{
  if (end >= 1)
  {
    int mid = (beg + end) / 2;

    if (arr[mid] == X)
    {
      return mid;
    }

    if (arr[mid] > X)
    {
      return binarySearch(arr, beg, X, mid - 1);
    }
    else
    {
      return binarySearch(arr, mid + 1, X, end);
    }
  }
  return -1;
}

int main()
{
  int n;

  printf("Enter the size of an array : ");
  scanf("%d", &n);

  int arr[n];

  printf("Enter the elements: ");

  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }

  int X;
  printf("Enter the Element to be found : ");
  scanf("%d", &X);

  // int beg=0,end=n-1;
  int result = binarySearch(arr, 0, X, n - 1);
  if (result == -1)
  {
    printf("Element Not Found \n");
  }
  else
  {
    printf("Element Found at index position : %d \n", result);
  }
}
