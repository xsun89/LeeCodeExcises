#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct tagSNode {
    int val;
    tagSNode* pNext;
    tagSNode(int v):val(v),pNext(NULL){}
}SNode;

void creadeList(SNode* pHead, int n)
{
   for(int i=0; i<n; i++)
   {
      int v = rand()%10;
      printf("%d\n", v);
      SNode* p = new SNode(v);
      p->pNext = pHead->pNext;
      pHead->pNext = p;
   }
}

void printList(SNode* pHead)
{
   SNode* p = pHead;
   if(p->pNext != NULL){
      printf("%d", p->pNext->val);
   }
   p = p->pNext;
   while(p){
      printf("->%d", p->pNext->val);
      p = p->pNext;
   }

   return;
}

void destroyList(SNode* pHead)
{
   SNode* p = pHead;
   while(p){
      SNode* tmp = p;
      p = p->pNext;
      delete tmp;
   }
}
int main() {
   SNode* head1 = new SNode(0);
   creadeList(head1, 6);
   printList(head1);
   destroyList(head1);

   return 0;
}