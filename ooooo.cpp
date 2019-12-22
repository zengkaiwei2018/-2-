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
int GetHeight( BinTree BT );

int main()
{
    BinTree BT = CreatBinTree();
    printf("%d\n", GetHeight(BT));
    return 0;
}
int GetHeight( BinTree BT )
{
	int HL,HR;
	if(BT != NULL)
	{
		HL=GetHeight(BT->Left);
		HR=GetHeight(BT->Right);
			if(HL>=HR)
				return HL+1;
		else
			return HR+1;
	}
return 0;
}
