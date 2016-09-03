#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int isMatch(const char* s, const char* p)
{
    int sLen = strlen(s);
    int pLen = strlen(p);

    int i = 0;
    int j = 0;
    while (i < sLen && j < pLen)
    {
        if (s[i] == p[j])
        {
            //①如果当前字符匹配成功（即S[i] == P[j]），则i++，j++
            i++;
            j++;
        }
        else
        {
            //②如果失配（即S[i]! = P[j]），令i = i - (j - 1)，j = 0
            i = i - j + 1;
            j = 0;
        }
    }
    //匹配成功，返回模式串p在文本串s中的位置，否则返回-1
    if (j == pLen)
        return i - j;
    else
        return -1;
}

void reverseArray(char *p, int start, int end)
{
    printf("star process %s from %d to %d\n", p, start, end);
    char tmp;
    char tail;
    int len = end - start;
    for(int i=0; i<len/2; i++){
        tmp = *(p + start + i);
        tail = *(p+end-i);
        printf("rev %c %c\n", tmp, tail);
        *(p+start+i) = *(p+end-i);
        *(p+end-i) = tmp;
    }
}

void revserReverseArray(char *p)
{
    int len = strlen(p);
    int start = 0;
    int end = 0;
    int revlen = 0;
    for(int i=0; i<len; i++){
        printf("end %c\n", p[i]);
        if(!isspace(p[i])){
            printf("end %d\n", end);
            end++;
        }else {
            reverseArray(p, start, end);
            printf("after %d\n", start);
            start = i + 1;
            end++;
            printf("new start %d\n", start);
        }
    }
}
int main() {

    //const char* base = "BBC  ABCDAB  ABCDABCDABDE";
    const char* base = "pig loves dog";
    //const char* forCompare = "ABCDABD";
    const char* forCompare = "ABCDE";
    char *s = (char *) malloc(strlen(base) + 1);
    memset(s, '\0', strlen(base)+1);
    char *t = (char *) malloc(strlen(forCompare) + 1);
    memset(t, '\0', strlen(forCompare)+1);
    strcpy(s, base);
    strcpy(t, forCompare);
    int ret = isMatch(s, t);
    printf("%d\n", ret);
    reverseArray(s, 0, strlen(s)-1);
    printf("%s\n", s);
    revserReverseArray(s);
    printf("%s\n", s);

    reverseArray(t, 0, 2);
    printf("%s\n", t);
    reverseArray(t, 3, strlen(t)-1);
    printf("%s\n", t);
    reverseArray(t, 0, strlen(t)-1);

    printf("%s\n", t);
    return 0;
}