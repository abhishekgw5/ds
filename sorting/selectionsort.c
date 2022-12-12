#include<stdio.h>

void printArray(int A[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void selectionSort(int A[], int n){
    int indexOfMin, temp;
    printf("Running Selection sort...\n");
    for (int i = 0; i < n-1; i++)
    {
        indexOfMin = i;
        for (int j = i+1; j < n; j++)
        {
            if(A[j] < A[indexOfMin]){
                indexOfMin = j;
            }
        }
        // Swap A[i] and A[indexOfMin]
        temp = A[i];
        A[i] = A[indexOfMin];
        A[indexOfMin] = temp;
    }
}

int main(){
    int i, n, A[20];
    printf("Enter SIZE");
    scanf("%d",&n);
    printf("Enter elements");
    for(i=0;i<n;i++)
    scanf("%d", &A[i]);
    printArray(A, n);
    selectionSort(A, n);
    printArray(A, n);
    printf("Sorted elements are: ");
    for(i=0;i<n;i++)
    printf(" %d",A[i]);

    return 0;
}
