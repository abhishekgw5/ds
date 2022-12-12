#include <stdio.h>
/* function to implement shellSort */
int shell(int a[], int n)
{
    int count = 0;
    /* Rearrange the array elements at n/2, n/4, ..., 1 intervals */
    for (int interval = n / 2; interval > 0; interval /= 2)
    {
        for (int i = interval; i < n; i += 1)
        {
            /* store a[i] to the variable temp and make the ith position empty */
            int temp = a[i];
            int j;
            for (j = i; j >= interval && a[j - interval] > temp; j -= interval)
            {
                a[j] = a[j - interval];
            }
            // put temp (the original a[i]) in its correct position
            a[j] = temp;
        }
    }
    return count;
}

void printArr(int a[], int n) /* function to print the array elements */
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}
int main()
{
    int count;
    //int a[] = { 33, 31, 40, 8, 12, 17, 25, 42,67 };
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(a) / sizeof(a[0]);
    printf("Before sorting array elements are - \n");
    printArr(a, n);
    shell(a, n);
    printf("\nAfter applying shell sort, the array elements are - \n");
    printArr(a, n);
    printf("\nNo. of swaps = %d", shell(a, n));
    return 0;
}