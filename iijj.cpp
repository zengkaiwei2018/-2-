#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree CreatBinTree(); /* ÊµÏÖÏ¸½ÚºöÂÔ */
void InorderTraversal( BinTree BT );
void PreorderTraversal( BinTree BT );
void PostorderTraversal( BinTree BT );
void LevelorderTraversal( BinTree BT );

int main()
{
    BinTree BT = CreatBinTree();
    printf("Inorder:");    InorderTraversal(BT);    printf("\n");
    printf("Preorder:");   PreorderTraversal(BT);   printf("\n");
    printf("Postorder:");  PostorderTraversal(BT);  printf("\n");
    printf("Levelorder:"); LevelorderTraversal(BT); printf("\n");
    return 0;
}
void InorderTraversal( BinTree BT ){
    if(BT){
        if(BT->Left)InorderTraversal(BT->Left);
        printf(" %c",BT->Data);
        if(BT->Right)InorderTraversal(BT->Right);
    }
}
void PreorderTraversal( BinTree BT ){
    if(BT){
        printf(" %c",BT->Data);
        if(BT->Left)PreorderTraversal(BT->Left);
        if(BT->Right)PreorderTraversal(BT->Right);
    }
}
void PostorderTraversal( BinTree BT ){
    if(BT){
        if(BT->Left)PostorderTraversal(BT->Left);
        if(BT->Right)PostorderTraversal(BT->Right);
        printf(" %c",BT->Data);
    }
}
void LevelorderTraversal( BinTree BT ){
    BinTree que[101],t;
    int head=0,rear=0;
    if(BT){
        que[rear++]=BT;
        while(head!=rear){
            t=que[head++];
            printf(" %c",t->Data);
            if(t->Left)que[rear++]=t->Left;
            if(t->Right)que[rear++]=t->Right;
        }
    }
}
