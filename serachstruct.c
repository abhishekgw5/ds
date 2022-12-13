#include <stdio.h>
#include<stdlib.h>

struct employee
{
    int emp_no;
    char emp_name[50];
    float emp_salary;
};

int linearSearch(struct employee A[], int size, int elem){
    for(int i=0;i<size;i++){
        if(A[i].emp_no==elem){
            return i;
        }
    }
    return -1;
}

int binarySearch(struct employee A[], int size, int elem){
    int low,mid,high;
    low = 0;
    high = size-1;

    while(low<=high){
        mid=(low+high)/2;
        
        if(A[mid].emp_no==elem){
            return mid;
        }
        if(A[mid].emp_no<elem){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}

int main(){
    int n,find;
    printf("Enter number of employees \n");
    scanf("%d", &n);
    struct employee A[n];

    for (int i = 0; i < n; i++)
    {
        printf("\n Sr No. %d", i + 1);
        printf("\n Enter emp_no = ");
        scanf("%d", &A[i].emp_no);
        printf("\n Enter emp_name = ");
        scanf("%s", &A[i].emp_name);
        printf("\n Enter emp_salary = ");
        scanf("%f", &A[i].emp_salary);
    }

    printf("\nEnter employee number to br search: ");
    scanf("%d",&find);

    int index1 = binarySearch(A,n,find);

    printf("\n Element %d found at Sr No. %d",find,index1+1);
    printf("\n emp_no = %d \n emp_name = %s \n emp_salary = %f",A[index1].emp_no,A[index1].emp_name,A[index1].emp_salary);

    return 0;
}