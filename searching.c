#include<stdio.h>

int linearSearch(int A[], int size, int elem){
    for(int i=0;i<size;i++){
        if(A[i]==elem){
            return i;
        }
    }
    return -1;
}

int binarySearch(int A[], int size, int elem){
    int low,mid,high;
    low = 0;
    high = size-1;

    while(low<=high){
        mid=(low+high)/2;
        
        if(A[mid]==elem){
            return mid;
        }
        if(A[mid]<elem){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}

int main(){
    int size,elem;
    int A[20];
    printf("\nHow many elements u want to enter?");
    scanf("%d",&size);

    for(int i=0;i<size;i++){
        printf("\nEnter element: ");
        scanf("%d",&A[i]);
    }

    printf("\nEnter elem you want to search?");
    scanf("%d",&elem);

    int index1 = linearSearch(A,size,elem);
    int index2 = binarySearch(A,size,elem);

    printf("\n Element %d found at index %d",elem,index1);
    printf("\n Element %d found at index %d",elem,index2);

    return 0;
}