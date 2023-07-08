#include <stdio.h>
#include <math.h>

void Merge(int arr[], int low, int mid, int high)
{
  int h, i, j, k;
  int n = sizeof(arr);
  int b[n];
  h = low;
  i = low;
  j = mid + 1;

  while (h <= mid & j <= high)
  {
    if (arr[h] <= arr[j]){}
      b[i] = arr[h];
    h++;}
    else
    {
      b[i] = arr[j];
      j++;
    }
    i++;
  }

  if (h > mid)
  {
    for (k = j; k <= high; k++)
    {
      b[i] = arr[k];
      i++;
    }
    else
    {
      for (k = h; k >= mid; k--)
      {
        b[i] = arr[k];
        i++;
      }
    }

    for (k = low; k <= high; k++)
    {
      arr[k] = b[k];
      printf(arr[k]);
    }
  }

  void MergeSort(int arr[], int low, int high)
  {
    if (low < high)
    {
      int mid = floor((low + high) / 2);
      MergeSort(arr, low, mid);
      MergeSort(arr, mid + 1, high);
      Merge(arr, low, mid, high);
    }
  }

  void printArray(int A[], int size)
  {
    int i;
    for (i = 0; i < size; i++)
      printf("%d ", A[i]);
    printf("\n");
  }

  int main()
  {
    printf("Enter size of array : \n");
    scanf("%d", &n);

    printf("Enter the element in array : \n");

    int arr[n];
    for (int i = 0; i < n; i++)
    {
      scanf("%d", &arr[i]);
    }

    int low = 0, high = n - 1;
    MergeSort(arr, low, high);
    printf("Sorted Array : ");
    printArray(arr, n);
  }
