#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

void reverseArray(char *p, int len)
{
    char tmp = '\0';
    for(int i=0; i<len/2; i++){
        tmp = *(p + i);
        char tail = *(p+len-i-1);
        *(p+i) = *(p+len-i-1);
        *(p+len-i-1) = tmp;
    }
}

void revserReverseArray(char *p)
{
    int len = strlen(p);
    for(int i=0; i<len; i++){
        char *tmp = p;

    }
}
int main() {

    const char* base = "BBC ABCDAB ABCDABCDABDE";
    const char* forCompare = "ABCDABD";
    char *s = (char *) malloc(strlen(base) + 1);
    memset(s, '\0', strlen(base)+1);
    char *t = (char *) malloc(strlen(forCompare) + 1);
    memset(t, '\0', strlen(forCompare)+1);
    strcpy(s, base);
    strcpy(t, forCompare);
    int ret = isMatch(s, t);
    printf("%d\n", ret);
    reverseArray(s, strlen(s));
    printf("%s\n", s);

    return 0;
}