#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 4

int func1(int arr[ROWS][COLS],int size1, int size2){
    for(int i = 0; i < size1; i++){
        for(int j = 1; j < size2; j++){
            if(arr[i][j] < arr[i][j-1]){
                return 0;
            }
        }
    }

    for(int i = 0; i < size2; i++){
        for(int j = 1; j < size1; j++){
            if(arr[j-1][i] < arr[j][i]){
                return 0;
            }

        }
    }

    return 1;
}

int get_surr_sum(int arr[ROWS][COLS], int row, int col) {
    int sum = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int newRow = row + i;
            int newCol = col + j;
            if (newRow >= 0 && newRow < ROWS && newCol >= 0 && newCol < COLS && (i != 0 || j != 0)) {
                sum += arr[newRow][newCol];
            }
        }
    }
    return sum;
}

int find_max_surr_sum(int arr[ROWS][COLS], int size1, int size2) {
    int maxSum = 0;
    int maxVal = 0;
    
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            int sum = get_surr_sum(arr, i, j);
            if (sum > maxSum) {
                maxSum = sum;
                maxVal = arr[i][j];
            }
        }
    }
    
    printf("Max sum: %d (from number %d)\n", maxSum, maxVal);
    return 0;
}

int func3(int arr[ROWS][COLS], int size1, int size2){
    int min = arr[0][0], max = arr[0][0];
    int min_row = 0, max_row = 0, temp;

    printf("Old:\n");
    for(int i = 0; i < size1; i++){
        for(int j = 0; j < size2; j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (min > arr[i][j]) {
                min = arr[i][j];
                min_row = i;
            }
            if (max < arr[i][j]) {
                max = arr[i][j];
                max_row = i;
            }
        }
    }

    if(max_row == min_row){
        return 0;
    }

    for(int i = 0; i < size1; i++){
        for(int j = 0; j < size2; j++){
            temp = arr[max_row][j];
            arr[max_row][j] = arr[min_row][j];
            arr[min_row][j] = temp;
        }
    }

    printf("New:\n");
    for(int i = 0; i < size1; i++){
        for(int j = 0; j < size2; j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}

int add(int *arr,int size, int x){
    size++;
    arr = (int*)realloc(arr,size*sizeof(int));
    arr[size-1] = x;
}

int del(int x){
    return 0;
}

int main() {
    int size = 4;
    int *arr = (int *)malloc(size * sizeof(int *));
    

    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }

    add(arr,size,1);

    printf("%d ",size);
    for (int i = 0; i < size; i++) {
        printf("%d",arr[i]);
    }
    printf("\n");

    free(arr);

    
    
    return 0;
}
