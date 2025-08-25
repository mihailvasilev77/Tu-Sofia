#include <stdio.h>
#include <stdlib.h>

int strlen(const char *s){
    int cnt = 0;
    while(s[cnt] != '\0'){
        cnt++;
    }
    return cnt;
}

int strcmp(const char *s1, const char *s2){
    int s1len = strlen(s1);
    int s2len = strlen(s2);

    return s1len-s2len;

    for(int i = 0; i < s1len; i++){
        if(s1[i] != s2[i]){
            return s1-s2;
        }
    }

    return 0;
}

int strncmp(const char *s1, const char *s2, int maxlen){
    for(int i = 0; i < maxlen; i++){
        if(s1[i] != s2[i]){
            return s1-s2;
        }
    }

    return 0;
}

int stricmp(const char *s1, const char *s2){
    int s1len = strlen(s1);
    int s2len = strlen(s2);

    if(s2len > s1len){
        return -1;
    }else if(s1len > s2len){
        return 1;
    }
    
    for(int i = 0; i < s1len; i++){
        if(s1[i] != s2[i]){
            if((s2[i]-s1[i]==32) || (s1[i]-s2[i]==32)){
                continue;
            }

            return s1-s2;
        }
    }

    return 0;
}

int wordcnt(const char *s){
    int len = strlen(s);
    int cnt = 1;
    
    for(int i = 0; i < len; i++){
        if(s[i] == ' '){
            cnt++;
        }
    }

    return cnt;
}

void lettercnt(const char *s){
    int len = strlen(s);
    int freq[256] = {0};

    for (int i = 0; i < len; i++) {
        freq[(unsigned char)s[i]]++;
    }

    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0 && ((i >= 'A' && i <= 'Z') || (i >= 'a' && i <= 'z'))) {
            printf("'%c' -> %d times\n", i, freq[i]);
        }
    }
}

int vowcnt(const char *s){
    char vows[] = {"aeoiuAEOUI"};
    int len = strlen(s), cnt = 0;

    for(int i = 0; i < len; i++){
        for(int j = 0; j < strlen(vows); j++){
            if(s[i] == vows[j]){
                cnt++;
            }
        }
    }

    return cnt;
}

char *toupper(char *s){
    int len = strlen(s);

    for(int i = 0; i < len; i++){
        if(s[i] > 64 && s[i] < 91){
            s[i] += 32;
        }
    }

    return s;
}



int main() {
    char str[20];
    fgets(str, sizeof(str), stdin);

    printf("string %s:\nSize is %d!\nWord count is %d\n",str,strlen(str),wordcnt(str));
    lettercnt(str);

    return 0;
}
