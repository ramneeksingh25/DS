#include <stdio.h>

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void heapify(int arr[], int N, int i)
{
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  if (left < N && arr[left] > arr[largest])
    largest = left;
  if (right < N && arr[right] > arr[largest])
    largest = right;
  if (largest != i)
  {
    swap(&arr[i], &arr[largest]);
    heapify(arr, N, largest);
  }
}

void heapSort(int arr[], int N)
{
  for (int i = N / 2 - 1; i >= 0; i--)
    heapify(arr, N, i);
  for (int i = N - 1; i >= 0; i--)
  {
    swap(&arr[0], &arr[i]);
    heapify(arr, i, 0);
  }
}

void printArray(int arr[], int N)
{
  for (int i = 0; i < N; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void printArr(int arr[], int length)
{
  for (int i = 0; i < length; i++)
  {
    printf("%d\t", arr[i]);
  }
  printf("\n");
}

int main()
{
  int arr[] = {6, 2, 7, 4, 5};
  int length = sizeof(arr) / sizeof(arr[0]);
  printf("Array before selection sorting : \n");
  printArr(arr, length);
  heapSort(arr, length);
  printf("Array after selection sorting : \n");
  printArr(arr, length);
}