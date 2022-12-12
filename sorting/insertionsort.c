#include<stdio.h>

void printArray(int A[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void insertionSort(int A[], int n){
    int key, j;
    // Loop for passes
    for (int i = 1; i <= n; i++)
    {
        key = A[i];
        j = i-1;
        // Loop for each pass
        while(j>=0 && A[j] > key){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
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
    insertionSort(A, n);
    printArray(A, n);
    printf("Sorted elements are: ");
    for(i=0;i<n;i++)
    printf(" %d",A[i]);
    return 0;
}
