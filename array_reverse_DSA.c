#include <stdio.h>
void reverseArray (int arr [], int start, int end) {

/*Function to reverse arr[] from start to end*/
    int temp;
    while (start < end) {
        temp = arr[strat];
        arr[start] = arr[end];
        arr[end]   = temp;
        start++;
        end--;
    }
}

/*Utility that prints out an array on a line*/
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++){
        printf(" %d ", arr[i]);
        printf("\n");
    }

}

int main () {
    int arr [] = {1,2,3,4,5,6};
    int n = sizeof(arr) /sizeof (arr[0]);
    printArray(arr, n);
    reverseArray(arr, 0, n -1);
    printf("Reversed array is \n");
    printArray(arr, n);
    return 0;

}