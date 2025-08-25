#include <stdio.h>
#include <stdlib.h>

void print_array(int *arr, int size){
    printf("Array: ");
    for(int i = 0; i < size; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int find_sum(int *arr, int size){
    int sum = 0;
    for(int i = 0; i < size; i++){
        sum += arr[i];
    }

    return sum;
}

int find_max(int *arr, int size){
    int max = *arr;

    for(int i = 0; i < size; i++){
        if(max < arr[i]){
            max = *(arr+i);
        }
    }

    return max;
}

int find_even_sum(int *arr, int size){
    int sum = 0;
    for(int i = 0; i < size; i++){
        if(*(arr+i) % 2 == 0){
            sum += *(arr+i);
        }
    }

    return sum;
}

int find_min(int *arr, int size){
    int min = *arr;
    
    for(int i = 0; i < size; i++){
        if(min > arr[i]){
            min = *(arr+i);
        }
    }

    return min;
}

void create_array(int *arr, int *n){
    printf("Enter size of array:");
    scanf("%d",&n);

    arr = (int*)malloc(n*sizeof(int));

    if(arr == NULL) { 
        printf("Unable to allocate memory.\n"); 
        exit(0); 
    } 

    for(int i = 0; i < n; i++){
        printf("Enter %d number:",i+1);
        scanf("%d",(arr+i));
    }
    printf("\n");
}

int main() {
    while(1){
        int x;
        int n;
        int *arr;
        printf("Enter option (1-7): ");
        scanf("%d",&x);
        switch (x){
        case 1:
            create_array(arr,n);
            break;
        case 2:
            print_array(arr,n);
            break;
        case 3:
            printf("The sum of the arrays is:%d\n",find_sum(arr,n));
            break;
        case 4:
            printf("The largest number is:%d\n",find_max(arr,n));
            break;
        case 5:
            printf("The least number is:%d\n",find_min(arr,n));
            break;
        case 6:
            printf("The sum of even numbers is:%d\n",find_even_sum(arr,n));
            break;
        case 7:
            free(arr);
            printf("Goodbye!");
            exit(1);
            break;
        default:
            printf("Exceeded option range.\nType option again:");
            scanf("%d",&x);
            break;
        }
    }
}
