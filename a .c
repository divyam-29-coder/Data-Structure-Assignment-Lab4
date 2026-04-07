//Bubble Sort – Arrange Student Marks
#include <stdio.h>

int main() {
    int n, i, j, temp;

    
    printf("Enter number of students: ");
    scanf("%d", &n);

    int marks[n];

    
    printf("Enter marks:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &marks[i]);
    }

    
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(marks[j] > marks[j + 1]) {
                // Swap
                temp = marks[j];
                marks[j] = marks[j + 1];
                marks[j + 1] = temp;
            }
        }
    }

    
    printf("Sorted marks in increasing order:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", marks[i]);
    }

    return 0;
}


//Selection Sort – Find Minimum Value
#include <stdio.h>

int main() {
    int n, i, j, min_index, temp;

    
    printf("Enter number of products: ");
    scanf("%d", &n);

    int price[n];

    
    printf("Enter product prices:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &price[i]);
    }

    
    for(i = 0; i < n - 1; i++) {
        min_index = i;

        for(j = i + 1; j < n; j++) {
            if(price[j] < price[min_index]) {
                min_index = j;
            }
        }

        
        temp = price[i];
        price[i] = price[min_index];
        price[min_index] = temp;
    }

    
    printf("Sorted prices in increasing order:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", price[i]);
    }

    return 0;
}


//Insertion Sort – Arrange Numbers Step by Step
#include <stdio.h>

int main() {
    int n, i, j, key;

    
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    
    printf("Enter numbers:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    
    for(i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }

    
    printf("Sorted numbers in increasing order:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}


//Quick Sort – Arrange Roll Numbers
#include <stdio.h>


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


int partition(int arr[], int low, int high) {
    int pivot = arr[high];  
    int i = low - 1;

    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}


void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high); 
    }
}

int main() {
    int n;

    
    printf("Enter number of students: ");
    scanf("%d", &n);

    int roll[n];

    
    printf("Enter roll numbers:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &roll[i]);
    }

    
    quickSort(roll, 0, n - 1);

    
    printf("Sorted roll numbers:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", roll[i]);
    }

    return 0;
}


//Merge Sort – Sort Student Roll Numbers
#include <stdio.h>


void merge(int arr[], int left, int mid, int right) {
    int i, j, k;

    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    
    for(i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    
    while(i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(int arr[], int left, int right) {
    if(left < right) {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);       
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    int n;

    
    printf("Enter number of students: ");
    scanf("%d", &n);

    int roll[n];


    printf("Enter roll numbers:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &roll[i]);
    }

    
    mergeSort(roll, 0, n - 1);

    
    printf("Sorted roll numbers:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", roll[i]);
    }

    return 0;
}