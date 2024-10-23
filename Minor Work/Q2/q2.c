#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void displayArray(int arr[], int n) {
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }

    printf("The contents of the array are: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void addElement(int arr[], int *n) {
    if (*n >= MAX) {
        printf("Array is full.\n");
        return;
    }

    int ele;
    printf("Enter the element: ");
    scanf("%d", &ele);
    arr[*n] = ele;
    (*n)++;
    printf("Element %d added successfully into the array.\n", ele);
}

void updateElement(int arr[], int n) {
    int index, newValue;
    printf("Enter the index of the element to update (0 to %d): ", n - 1);
    scanf("%d", &index);

    if (index < 0 || index >= n) {
        printf("Invalid index\n");
        return;
    }

    printf("Enter the new value: ");
    scanf("%d", &newValue);
    arr[index] = newValue;
    printf("Element at index %d updated to %d.\n", index, newValue);
}

void deleteElement(int arr[], int *n) {
    int index, ele;
    printf("Enter the index of the element to delete (0 to %d): ", *n - 1);
    scanf("%d", &index);

    if (index < 0 || index >= *n) {
        printf("Invalid index!\n");
        return;
    }

    ele = arr[index];

    for (int i = index; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
    printf("Element %d at index %d deleted successfully.\n", ele, index);
}

int main() {
    int arr[MAX];
    int n = 0;
    int choice;

    while(1){
        printf("\n1. Add Element\n");
        printf("2. Update Element\n");
        printf("3. Delete Element\n");
        printf("4. Display Elements\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addElement(arr, &n);
                break;
            case 2:
                updateElement(arr, n);
                break;
            case 3:
                deleteElement(arr, &n);
                break;
            case 4:
                displayArray(arr, n);
                break;
            case 5:
                printf("Exiting....\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}
