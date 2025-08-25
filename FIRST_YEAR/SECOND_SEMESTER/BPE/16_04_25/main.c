#include <stdio.h>
#include <stdlib.h>

void writeToFile(char *fileName, char *str){
    char *temp;
    FILE *f = fopen(fileName,"w");

    if(f == NULL){
        printf("Cant open file.\n");
        exit(1);
    }

    temp = str;

    while(*temp){
        if(putc(*temp,f) == NULL){
            printf("Error writing file.\n");
            exit(2);
        }
        temp++;
    }

    printf("Success.\n");
    fclose(f);
}

int *countOddEven(int arr[], int N){
    int *count = (int*)calloc(2,sizeof(int));

    for(int i = 0; i < N; i++){
        if(arr[i] % 2 == 0){
            count[0]++;
        }else{
            count[1]++;
        }
    }

    return count;
}

void readFile(char *fileName, char *str){
    FILE *f = fopen(fileName,"r");

    if(f == NULL){
        printf("Cant open file.\n");
        exit(1);
    }
    char i;
    while(1){
        i = getc(f);
        if(i == EOF){
            break;
        }
        putchar(i);
    }
    fclose(f);
}

void bubbleSort(int *arr, int N){
    int temp;
    for(int i = 0; i < N-1; i++){
        for(int j = 0; j < N - i - 1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

FILE* createFile1(char *fileName, char *mode, int N){
    FILE *f = fopen(fileName, mode);

    if(f == NULL){
        printf("Cant open file.\n");
        exit(1);
    }

    int arr[N];
    for(int i = 0; i < N; i++){
        printf("Enter a number: ");
        scanf("%d",&arr[i]);
    }
    bubbleSort(arr,N);
    
    fwrite(&N,sizeof(int),1,f);
    fwrite(arr, sizeof(int), N, f);

    fclose(f);

    return f;
}

int *countOddEven2(char *fileName){
    int *count = (int*)calloc(2,sizeof(int));
    FILE *f = fopen(fileName, "rb");

    if(f == NULL){
        printf("Cant open file.\n");
        exit(1);
    }

    fseek(f, 0, SEEK_END);
    long file_size = ftell(f);
    rewind(f);  

    int count = file_size / sizeof(int); 

    int *numbers = (int*)malloc(file_size);
    if (numbers == NULL) {
        perror("Memory allocation failed");
        fclose(f);
        exit(1);
    }

    fread(numbers, sizeof(int), count, f);
    fclose(f);



    /*printf("Count: %d\n", count);
    for (int i = 0; i < count; i++) {
        printf("Number[%d] = %d\n", i, numbers[i]);
    }*/

    free(numbers);
    return countOddEven(numbers,count);
}


int main() {
    char fileName[30] = "zad1.bin";
    
   // FILE *f = createFile1(fileName, "wb",3);
    countOddEven2(fileName);

    return 0;
}
