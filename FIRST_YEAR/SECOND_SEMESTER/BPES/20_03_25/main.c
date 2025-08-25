#include <stdio.h>
#include <stdlib.h>

int find_largest_line(int *arr,int size){
    int curr_count = 1, max_count = 1;
    int begining = 0, max_begining = 0;
    
    for(int i = 1; i < size; i++){
    
        if(arr[i] == arr[i-1]){
            curr_count++;
        }else{
            if(curr_count > max_count){
                max_count = curr_count;
                max_begining = begining;
            }
            curr_count = 1;
            begining = i;
        }

        if(curr_count > max_count){
            max_count = curr_count;
            max_begining = begining;
        }
    }

    printf("The longest line with the same number %d starts at %d for %d times\n",arr[max_begining],max_begining,max_count);

    return 0;
}

int check_line(int *arr,int size){
    for(int i = 0; i < size; i++){
        if(arr[i] < arr[i+1]){
            return 0;
        }
    }

    return 1;
}

int *reverse_array(int *arr, int size){
    int *arr2 = (int *)malloc(size * sizeof(int));
    
    for(int i = 1; i <= size; i++){
        arr2[i-1] = arr[size-i];
        
    }

    return arr2;
}

int shift_array(int *arr,int size, int k){
    k = k % size;
    int temp[k];
    
    for(int i = 0; i < k; i++){
        temp[i] = arr[i];
    }

    for(int i = 0; i < size-k; i++){
        arr[i] = arr[i+k];
    }

    for(int i = 0; i < k; i++){
        arr[size-k+i] = temp[i];
    }

    return 0;
}

int sort_arr(int *arr,int size){
    for(int i = 0; i < size - 1; i++){
        for(int j = i + 1; j < size; j++){
            if(arr[i] < arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return 0;
}

int find_K_largest(int *arr, int size, int k){
    sort_arr(arr,size);
    return arr[k-1];
}

int find_largest_subs(int *arr, int size){
    int max_len = 1, curr_len = 1;

    for(int i = 1; i <= size; i++){
        if(arr[i] > arr[i-1]){
            curr_len++;
        }else{
            curr_len = 1;
        }

        if(curr_len > max_len){
            max_len = curr_len;
        }
    }

    return max_len;
}

int find_subs_sum(int *arr, int size, int num){
    int sum = 0, start = 0;
    for(int i = 0; i < size; i++){
        if(sum+arr[i] > num){
            sum = 0;
            start = i;
        }

        sum += arr[i];
        
        //printf("i %d start %d, ", i, sum);
        if(sum == num){
            for(int k = 0, j = start; k < size-start-1 ; k++, j++){
                printf("%d ", arr[j]);
            }
            printf("\n");
            return 1;
        }
    }
    printf("No sum of given number.\n");
    return 0;
}

int user_array(int arr[], int size){
    for(int i = 0; i < size/2; i++){
        scanf("%d", &arr[i]);
    }
    int x = 1, pos, i = 0;
    while(x){
        scanf("%d",&x);
        
        if(!x){
            break;
        }

        scanf("%d", &pos);

        if(i > size/2 || pos > size){
            break;
        }

        for(int j = size; j > pos; j--){
            arr[j] = arr[j-1];
        }

        arr[pos] = x;
    
        i++;
    }

    for(int j = 0; j < size; j++){
        printf("%d ",arr[j]);
    }
    printf("\n");

    return 0;
}

int print_longest_subs(int *arr, int size){
    int curr_len = 1 , max_len = 1;
    int curr_num = arr[0], max_num = arr[0];
    for(int i = 0; i < size; i++){
        if(arr[i] == arr[i+1]){
            curr_len++;
        }else{
            curr_len = 1;
            curr_num = arr[i+1];
        }

        if(curr_len > max_len){
            max_len = curr_len;
            max_num = arr[i];
        }
    }

    for(int i = 0; i < max_len; i++){
        printf("%d ", max_num);
    }
    printf("\n");

    return 0;
}

int main() {
    int arr[] = {1,4,5,9,3};
    int arr2[] = {4,3,1,4,2,5,8};
    int arr4[] = {2,1,1,2,3,3,2,2,2,1};
    int size3 = 12;
    int arr3[size3] = {0};
    int size = sizeof(arr) / sizeof(arr[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
    int *rev_arr = reverse_array(arr,size);

    printf("Reversed array: ");
    for(int i = 1; i <= size; i++){
        printf("%d ",rev_arr[i-1]);
    }
    printf("\n");

    printf("Largesr subsequence:%d\n",find_largest_subs(arr,size));
    

    shift_array(arr,size,3);

    printf("Shifted array: ");
    for(int i = 1; i <= size; i++){
        printf("%d ",arr[i-1]);
    }
    printf("\n");
    
    printf("%d\n",find_K_largest(arr,size,2));

    
    find_subs_sum(arr2,size2,11);

    user_array(arr3,size3);

    print_longest_subs(arr4,size4);

    free(rev_arr);

    return 0;
}
