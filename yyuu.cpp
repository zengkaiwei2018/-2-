#include <stdio.h>

#define N 1000
int arr[N];

/* �Գ���Ϊn������arrִ��ð������ */
void bubbleSort(int arr[], int n);

/* ��ӡ����Ϊn������arr */
void printArray(int arr[], int n);

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int main() {
    int n, i;
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    bubbleSort(arr, n);
    printArray(arr, n);
    return 0;
}
/* ��ӡ����Ϊn������arr */
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1)    /* �±�0..n-2ÿ��Ԫ�غ����и��ո� */
            printf(" ");   /*�±�n-1,Ҳ�������һ��Ԫ�غ���û�пո�*/
    }
    printf("\n");  /* һ�д�ӡ����� */
}
void bubbleSort(int arr[], int n){
int i,j,t;
for(i=0;i<n;i++){
for(j=0;j<n-1;j++)
{
if(arr[j]>arr[j+1]){
t=arr[j];
arr[j]=arr[j+1];
arr[j+1]=t;
}
}
}
}
