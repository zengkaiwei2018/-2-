#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* ϸ���ڴ˲��� */
void Print( List L ); /* ϸ���ڴ˲��� */

List Reverse( List L );

int main()
{
    List L1, L2;
    L1 = Read();
    L2 = Reverse(L1);
    Print(L1);
    Print(L2);
    return 0;
}
List Reverse( List L )
{
  List p1=NULL,p2=NULL;
  while (L)
  {
    p2=L->Next;
    L->Next=p1;
    p1=L;
    L=p2;
  }
  return p1;
}
