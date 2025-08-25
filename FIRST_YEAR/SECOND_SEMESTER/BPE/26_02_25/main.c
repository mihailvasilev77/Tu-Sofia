#include <stdio.h>
#include <stdlib.h>

int func1(){
    int n = 0;
    scanf("%d",&n);

    return n > 6;
}

int tf(int boolean){
    switch (boolean)
    {
    case 1:
        printf("True\n");
        break;
    case 0:
        printf("False\n");
        break;
    default:
        break;
    }
    return 0;
}

int func2(){
    int n = 0;
    scanf("%d",&n);
    
    int remainder = n % 8;

    if (remainder > 4){
        printf("Remainder %d is greater than 4", remainder);
    }else if(remainder < 4){
        printf("Remainder %d is lower than 4", remainder);
    }else{
        printf("Remainder is equal to 4");
    }

    return 0;
}

int func3(){
    int a = 0,b = 0,c = 0;
    scanf("%d %d %d",&a,&b,&c);
    int min = a;

    if(min > b){
        min = b;
    }
    if(min > c){
        min = c;
    }

    return min;
}

int func4(int number){
    switch (number)
    {
    case 1:
        printf("One\n");
        break;
    case 0:
        printf("Zero\n");
        break;
    case 2:
        printf("Two\n");
        break;
    case 3:
        printf("Three\n");
        break;
    case 4:
        printf("Four\n");
        break;
    case 5:
        printf("Five\n");
        break;
    case 6:
        printf("Six\n");
        break;
    case 7:
        printf("Seven\n");
        break;
    case 8:
        printf("Eight\n");
        break;
    case 9:
        printf("Nine\n");
        break;
    default:
        printf("Not a single digit\n");
        break;
    }
    return 0;
}

int func5(int number){
    switch (number)
    {
    case 1:
        printf("Monday\n");
        break;
    case 2:
        printf("Tuesday\n");
        break;
    case 3:
        printf("Three\n");
        break;
    case 4:
        printf("Four\n");
        break;
    case 5:
        printf("Five\n");
        break;
    case 6:
        printf("Six\n");
        break;
    case 7:
        printf("Seven\n");
        break;
    case 8:
        printf("Eight\n");
        break;
    case 9:
        printf("Nine\n");
        break;
    default:
        printf("Not a single digit\n");
        break;
    }
    return 0;
}

int func6(){
    int n = 0;
    printf("Enter a number: ");
    scanf("%d",&n);

    for(int i=1; i <= n; i++){
        for(int j = 1; j <=i;j++){
            printf("%d ",i);
        }
        printf("\n");
    }

    return 0;
}

int func7(){
    int n, m,sum = 0;
    printf("Enter two numbers: ");
    scanf("%d %d",&n,&m);

    for(n=n+1;n<m;n++){
        sum += n;
    }

    return sum;
}

int func8(){
    int n, m,arr[2];
    printf("Enter two numbers: ");
    scanf("%d %d",&n,&m);

    for(n=n+1;n<m;n++){
        if(n % 2 == 0){
            arr[0] += n;
        }else{
            arr[1] *= n;
        }
    }

    printf("Sum:%d Mult:%d\n",arr[0],arr[1]);

    return 0;
}


int func9(){
    int n, m, x, count = 0;
    printf("Enter two numbers: ");
    scanf("%d %d",&n,&m);

    for(int i = 0; i < n;i++){
        scanf("%d",&x);
        if(x > m && x%3 == 0){
            count += 1;
        }
    }
    return count;
}

int func10(){
    int sum = 0;
    int x;
    while(1){
        scanf("%d",&x);
        sum += x;
        if(x == 0) break;
    }
    return sum;
}

int func11(){
    float x1,x2;
    scanf("%f %f",&x1, &x2);

    for(; x1 < x2; x1=x1+0.01){
        printf("%f\n",(x1*x1-4));
    }
    
    return 0;
}


int main(){
    //printf("%d\n",func10());
    func11();
}