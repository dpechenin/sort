#include <stdio.h>
#include <stdlib.h>

//сортировка пузырьком
void bubble(int *a, int n) {
    for(int i = n - 1; i >= 0; i--) {
        for(int j = 0; j < i; j++) {
            if (a[j] > a[j + 1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

//сортировка вставками
void insert_sort(int *a, int n) {
    int i, j, value;
    for(i = 1; i < n; i++) {
        value = a[i];
        for (j = i - 1; j >= 0 && a[j] > value; j--) {
            a[j + 1] = a[j];
        }
        a[j + 1] = value;
    }
}

//сортировка выбором
void select_sort(int *a, int n) {
    for (int i = 0; i < n; i++) {
        int min_i = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_i]) {
                min_i = j;
            }
        }
        int tmp = a[i];
        a[i] = a[min_i];
        a[min_i] = tmp;
    }
}

//сортировка слиянием
void merge(int *a, int low, int mid, int high){
    int *b = (int*)malloc((high+1-low)*sizeof(int));
    int h,i,j,k;
    h=low;
    i=0;
    j=mid+1;
    while((h<=mid)&&(j<=high)) {
        if(a[h]<=a[j]) {
            b[i]=a[h];
            h++;
        }
        else {
            b[i]=a[j];
            j++;
        }
        i++;
    }
    if(h > mid) {
        for(k = j; k <= high; k++) {
            b[i] = a[k];
            i++;
        }
    }
    else{
        for(k = h ; k <= mid; k++) {
            b[i] = a[k];
            i++;
        }
    }
    for(k = 0; k <= high - low; k++) {
        a[k + low] = b[k];
    }
    free(b);
}
void merge_sort(int *a, int low, int high) {
    int mid;
    if(low<high) {
        mid =(low+high)/2;
        merge_sort(a, low, mid);
        merge_sort(a, mid+1,high);
        merge(a, low, mid, high);
    }
}

void shakerSort(int a[], long size) //шейкер сортировка
{
    long j, k = size-1;
    long lb = 1, ub = size - 1; // bounds of unsorted part of the array
    int x;

    do
    {
        // from bottom to top passage
        for( j=ub; j>=lb; j-- )
        {
            if ( a[j-1] > a[j] )
            {
                x=a[j-1]; a[j-1]=a[j]; a[j]=x;
                k=j;
            }
        }

        lb = k+1;

        // passage from top to bottom
        for (j=lb; j<=ub; j++)
        {
            if ( a[j-1] > a[j] )
            {
                x=a[j-1]; a[j-1]=a[j]; a[j]=x;
                k=j;
            }
        }

        ub = k-1;
    }
    while ( lb <= ub );
}


void qSort(int *a, int first, int last) {
    if (first < last) {
        int left = first, right = last, middle = a[(left + right) / 2];
        do
        {
            while (a[left] < middle) left++;
            while (a[right] > middle) right--;
            if (left <= right)
            {
                int tmp = a[left];
                a[left] = a[right];
                a[right] = tmp;
                left++;
                right--;
            }
        } while (left < right);
        qSort(a, first, right);
        qSort(a, left, last);
    }
}
void quickSort(int *a, int n) {
    qSort(a, 0, n-1);
}

void downHeap(int *a, long k, long n) {
    long child;
    int new_elem = a[k];
    while (k <= n / 2) {
        child = 2 * k;
        if (child < n && a[child] < a[child + 1]) {
            child++;
        }
        if (new_elem >= a[child]) {
            break;
        }
        a[k] = a[child];
        k = child;
    }
    a[k] = new_elem;
}

void heapSort(int *a, long size)
{
    long i;
    int tmp;
    for(i = size/2; i >= 0; i--)
    {
        downHeap(a, i, size-1);
    }
    for(i = size-1; i > 0; i--)
    {
        tmp = a[i];
        a[i] = a[0];
        a[0] = tmp;
        downHeap(a, 0, i-1);
    }
}

int main(void) {
    int n = 0;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int *a = (int*)malloc(n * sizeof(int));
    if (a) {
        for (int i = 0; i < n; i++) {
            printf("Enter [%d] element of your array: ", i);
            scanf("%d", &a[i]);
        }
        printf("your array: ");
        for (int i = 0; i < n; i++) {
            printf("%d\t", a[i]);
        }
        printf("\n");
    }
    else {
        printf("no memory");
        return 0;
    }
    int sw;
    printf("Choose type:\n"
           "0 - bubble\n"
           "1 - insert sort\n"
           "2 - select sort\n"
           "3 - merge sort\n"
           "4 - shaker sort\n"
           "5 - quick sort\n"
           "6 - heap sort: ");
    scanf("%d", &sw);
    switch (sw) {
        case 0:
            bubble(a, n);
            break;
        case 1:
            insert_sort(a, n);
            break;
        case 2:
            select_sort(a, n);
            break;
        case 3:
            merge_sort(a, 0, n - 1);
            break;
        case 4:
            shakerSort(a, n);
            break;
        case 5:
            quickSort(a, n);
            break;
        case 6:
            heapSort(a, n);
            break;
        default:
            printf("no number\n");
            free(a);
            return 0;
    }
    printf("your sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
    free(a);
    return 0;
}

