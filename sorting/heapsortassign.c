//heap sort
#include <stdio.h>

struct employee
{
    int emp_no;
    char emp_name[50];
    float emp_salary;
};

void heapify(struct employee arr[], int n, int i)
{
    struct employee temp;
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].emp_no > arr[largest].emp_no)
        largest = left;

    if (right < n && arr[right].emp_no > arr[largest].emp_no)
        largest = right;

    if (largest != i)
    {
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

int heapSort(struct employee arr[], int n)
{
    struct employee temp;
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

int main()
{
    int n;
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

    heapSort(A, n);
    printf("Sorted data = \n");
    printf("emp_no \t\t  emp_name \t\t emp_salary \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d \t\t %s \t\t %f \n", A[i].emp_no, A[i].emp_name, A[i].emp_salary);
    }

    return 0;
}