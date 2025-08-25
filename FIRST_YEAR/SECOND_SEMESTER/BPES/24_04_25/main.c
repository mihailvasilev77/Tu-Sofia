#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_PRODUCTS 100
#define MAX_ORDERS 100
#define MAX_WORDS 1000
#define WORD_LEN 51

typedef struct {
    char name[50];
    float price;
    int id;
} Product;

typedef struct {
    char address[100];
    int product_id;
} Order;

typedef struct {
    int id;
    float hourly_rate;
    int hours;
    float salary;
} Employee;

Product products[MAX_PRODUCTS];
int product_count = 0;

Order waiting_orders[MAX_ORDERS];
int waiting_count = 0;

int find_product(int id) {
    for (int i = 0; i < product_count; i++) {
        if (products[i].id == id)
            return i;
    }
    return -1;
}

void execute_order(const char *address, int product_id) {
    int index = find_product(product_id);
    if (index != -1) {
        printf("Client %s ordered %s\n", address, products[index].name);
    } else {
        strcpy(waiting_orders[waiting_count].address, address);
        waiting_orders[waiting_count].product_id = product_id;
        waiting_count++;
    }
}

void check_waiting_orders(int product_id) {
    for (int i = 0; i < waiting_count;) {
        if (waiting_orders[i].product_id == product_id) {
            int index = find_product(product_id);
            if (index != -1) {
                printf("Client %s ordered %s\n", waiting_orders[i].address, products[index].name);
            }
            for (int j = i; j < waiting_count - 1; j++) {
                waiting_orders[j] = waiting_orders[j + 1];
            }
            waiting_count--;
        } else {
            i++;
        }
    }
}

int starts_with_last_char(char *prev, char *current) {
    int len = strlen(prev);
    return tolower(prev[len - 1]) == tolower(current[0]);
}

void birthday(){
    int guests;
    float sum = 0;
    scanf("%d",&guests);

    int table=0,chair=0,dishes=0,cups=0;

    char things[10];
    while(1){
        scanf("%s",things);

        if(!strcmp(things,"Table")){
            sum += 42;
            table += 1;
        }else if(!strcmp(things,"Chair")){
            sum += 13.99;
            chair += 1;
        }else if(!strcmp(things,"Cups")){
            sum += 5.98;
            cups += 6;
        }else if(!strcmp(things,"Dishes")){
            sum += 21.02;
            dishes += 6;
        }
        else if(!strcmp(things,"PARTY!")){
            break;
        }
    }

    printf("%.2f\n",sum);

    int needed_t = ceil(guests / 8.0);
    int needed_ch = guests;
    int needed_d = guests;
    int needed_c = guests;
  
    if (table < needed_t)
        printf("%d Table\n", needed_t - table);
    if (chair < needed_ch)
        printf("%d Chair\n", needed_ch - chair);
    if (dishes < needed_d)
        printf("%d Dishes\n", (int)ceil((needed_d - dishes) / 6.0));
    if (cups < needed_c)
        printf("%d Cups\n", (int)ceil((needed_c - cups) / 6.0));

}

void zad2(){
    char command[20];

    while (1) {
        scanf("%s", command);
        if (strcmp(command, "END") == 0)
            break;

        if (strcmp(command, "Product") == 0) {
            char name[50];
            float price;
            int id;
            scanf("%s %f %d", name, &price, &id);

            strcpy(products[product_count].name, name);
            products[product_count].price = price;
            products[product_count].id = id;
            product_count++;

            check_waiting_orders(id);
        } else if (strcmp(command, "Order") == 0) {
            char address[100];
            int product_id;
            scanf("%s %d", address, &product_id);
            execute_order(address, product_id);
        }
    }
}

void zad3(char input[], char output[]){
    FILE *input = fopen(input, "r");
    FILE *bin = fopen(output, "wb");
    char words[MAX_WORDS][WORD_LEN];
    int count = 0;

    while (fscanf(input, "%50s", words[count]) == 1 && count < MAX_WORDS)
        count++;

    char selected[MAX_WORDS][WORD_LEN];
    int sel_count = 0;

    strcpy(selected[sel_count++], words[0]);

    for (int i = 1; i < count; i++) {
        if (starts_with_last_char(selected[sel_count - 1], words[i])) {
            strcpy(selected[sel_count++], words[i]);
        }
    }

    for (int i = 0; i < sel_count; i++) {
        fwrite(selected[i], sizeof(char), strlen(selected[i]), bin);
        if (i < sel_count - 1)
            fwrite(" ", sizeof(char), 1, bin);
    }

    fclose(input);
    fclose(bin);

    FILE *read_bin = fopen(output, "rb");
    char ch;
    while (fread(&ch, sizeof(char), 1, read_bin)) {
        putchar(ch);
    }
    putchar('\n');
    fclose(read_bin);
}

void encode(){
    char filename[100], outputname[100] = "encoded.txt";
    int key;

    printf("Enter filename to encode: ");
    scanf("%s", filename);

    printf("Enter key (2-10): ");
    scanf("%d", &key);

    if (key < 2 || key > 10) {
        printf("Invalid key!\n");
        return 1;
    }

    FILE *in = fopen(filename, "r");
    FILE *out = fopen(outputname, "w");

    if (!in || !out) {
        printf("File error!\n");
        return 1;
    }

    char ch;
    while ((ch = fgetc(in)) != EOF) {
        fputc(ch + key, out);
    }

    fclose(in);
    fclose(out);
    printf("File encoded into %s\n", outputname);
}

void display_word(char *word, int guessed[]) {
    for (int i = 0; i < strlen(word); i++) {
        if (guessed[i])
            printf("%c", word[i]);
        else
            printf("_");
    }
    printf("\n");
}

void besenica(){
    char word[] = "concatenation";
    int guessed[100] = {0};
    int tries = 0;
    int length = strlen(word);
    int correct = 0;

    while (correct < length && tries <= length + 2) {
        display_word(word, guessed);
        printf("Enter letter: ");
        char c;
        scanf(" %c", &c);
        c = tolower(c);
        int found = 0;

        for (int i = 0; i < length; i++) {
            if (tolower(word[i]) == c && !guessed[i]) {
                guessed[i] = 1;
                correct++;
                found = 1;
            }
        }

        tries++;
        if (!found)
            printf("No match!\n");
    }

    if (correct == length && tries <= length + 2)
        printf("You won in %d tries!\n", tries);
    else
        printf("You lost! The word was: %s\n", word);
}

int is_anagram(char *s1, char *s2) {
    int count[256] = {0};

    for (int i = 0; s1[i]; i++)
        count[tolower(s1[i])]++;

    for (int i = 0; s2[i]; i++)
        count[tolower(s2[i])]--;

    for (int i = 0; i < 256; i++)
        if (count[i] != 0)
            return 0;

    return 1;
}

void calc_salary(Employee *e) {
    int overtime = e->hours > 40 ? e->hours - 40 : 0;
    float base = e->hourly_rate * (e->hours - overtime);
    float over = overtime * e->hourly_rate * 1.5;
    float gross = base + over;
    e->salary = gross * (1 - 0.0365);
}

int main() {
    FILE *f;
    Employee emp;
    int choice;

    do {
        printf("1. Add employee\n2. Show salaries\n0. Exit\nChoice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            f = fopen("employees.dat", "ab");
            if (!f) {
                printf("File error!\n");
                return 1;
            }
            printf("Enter ID, hourly rate, hours: ");
            scanf("%d %f %d", &emp.id, &emp.hourly_rate, &emp.hours);
            calc_salary(&emp);
            fwrite(&emp, sizeof(Employee), 1, f);
            fclose(f);
        } else if (choice == 2) {
            f = fopen("employees.dat", "rb");
            if (!f) {
                printf("File error!\n");
                return 1;
            }
            printf("ID\tHours\tSalary\n");
            while (fread(&emp, sizeof(Employee), 1, f)) {
                printf("%d\t%d\t%.2f\n", emp.id, emp.hours, emp.salary);
            }
            fclose(f);
        }
    } while (choice != 0);

    return 0;
}
