#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

int main_dig(int arr[][SIZE], int size1, int size2){
    printf("Main diagonal: ");
    for(int i = 0; i < size1; i++){
        for(int j = 0; j < size2; j++){
            if(i == j){
                printf("%d ",arr[i][j]);
            }
        }
    }
    printf("\n");

    return 0;
}

int sec_dig(int arr[][SIZE], int size1, int size2){
    printf("Secondary diagonal: ");
    for(int i = 0; i < size1; i++){
        for(int j = 0; j < size2; j++){
            if((size2-i-1) == j){
                printf("%d ", arr[i][j]);
            }
        }
    }
    printf("\n");

    return 0;
}

int over_main_dig(int arr[][SIZE], int size1, int size2){
    printf("Over main diagonal: ");
    for(int i = 0; i < size1; i++){
        for(int j = 0; j < size2; j++){
            if(i < j){
                printf("%d ",arr[i][j]);
            }
        }
    }
    printf("\n");

    return 0;
}

int under_main_dig(int arr[][SIZE], int size1, int size2){
    printf("Under main diagonal: ");
    for(int i = 0; i < size1; i++){
        for(int j = 0; j < size2; j++){
            if(i > j){
                printf("%d ",arr[i][j]);
            }
        }
    }
    printf("\n");

    return 0;
}

int magic_square(int arr[][SIZE], int size1, int size2){
    int msum = 0;
    int sum = 0;

    if(size1 != size2){
        return 0;
    }

    for(int i = 0; i < size1; i++){
        msum += arr[0][i];
    }

    for(int i = 0; i < size1; i++){
        for(int j = 0; j < size2; j++){
            sum += arr[i][j];
        }
        if(sum != msum){
            return 0;
        }
        sum = 0;
    }

    for(int i = 0; i < size1; i++){
        for(int j = 0; j < size2; j++){
            sum += arr[j][i];
        }
        if(sum != msum){
            return 0;
        }
        sum = 0;
    }

    for(int i = 0; i < size1; i++){
        for(int j = 0; j < size2; j++){
            if(i == j){sum += arr[i][j];}
        }
    
    }

    if(sum != msum){
        return 0;
    }
    sum = 0;

    for(int i = 0; i < size1; i++){
        for(int j = 0; j < size2; j++){
            if((size1-i-1) == j){ sum += arr[i][j];}
        }
    }

    if(sum != msum){
        return 0;
    }
    sum = 0;

    return 1;
}



int main() {

    int a[SIZE][SIZE];

    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            scanf("%d",&a[i][j]);
        }
    }

    printf("Array:\n");

    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

    main_dig(a,SIZE,SIZE);
    sec_dig(a,SIZE,SIZE);
    over_main_dig(a,SIZE,SIZE);
    under_main_dig(a,SIZE,SIZE);

    printf("%d\n",magic_square(a,SIZE,SIZE));

    return 0;
}
