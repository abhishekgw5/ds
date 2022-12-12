#include<stdio.h>
 
void printArray(int A[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

// void bubbleSort(int A[], int n){
//     int temp;
//     int isSorted = 0;
//     for (int i = 0; i < n-1; i++) // For number of pass
//     {
//         for (int j = 0; j <n-1-i ; j++) // For comparison in each pass
//         {
//             if(A[j]>A[j+1]){
//                 temp = A[j];
//                 A[j] = A[j+1];
//                 A[j+1] = temp;
//             }
//         }  
//     }
// }

void bubbleSort(int A[], int n){
    int temp;
    int isSorted = 0;
    for (int i = 0; i < n; i++) // For number of pass
    {
        for (int j = i; j <n ; j++) // For comparison in each pass
        {
            if(A[i]>A[j]){
                temp = A[j];
                A[j] = A[i];
                A[i] = temp;
            }
        }  
    }
}

int main(){
    int i, n,count, A[20];
    printf("Enter SIZE");
    scanf("%d",&n);
    printf("Enter elements");
    for(i=0;i<n;i++)
    scanf("%d", &A[i]);
    printArray(A, n); // Printing the array before sorting
    bubbleSort(A, n); // Function to sort the array
    printf("Sorted elements are: ");
    for(i=0;i<n;i++)
    printf(" %d",A[i]);
    printf("\n No. of swaps", count);
    return 0;
}


