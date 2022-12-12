#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);

        // Recursively heapify the affected
        // sub-tree
        heapify(arr, n, largest);
    }
}

// Main function to do heap sort
void heapSort(int arr[], int n)
{

    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)

        heapify(arr, n, i);

    // Heap sort
    for (int i = n - 1; i >= 0; i--)
    {

        swap(&arr[0], &arr[i]);

        // Heapify root element to get highest element at
        // root again
        heapify(arr, i, 0);
    }
}

// A utility function to print array of size n
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver's code
int main()
{
    int A[100],n,i;
    printf("Enter size");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d",&A[i]);
    heapSort(A, n);
    printf("Sorted array is\n");
    printArray(A, n);
}