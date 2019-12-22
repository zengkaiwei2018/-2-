#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=11000;
const int M=15005;
int n,m,cnt;
int parent[N];
int flag;
struct edge
{
    int u;
    int v;
    int w;
    int equals;///�Ƿ������ñ�Ȩֵ��ͬ��������
    int used;///�ڵ�һ����õ�MST���Ƿ�����ı�
    int del;///���Ƿ�ɾ���ı�־
} edg[N];
int  cmp(edge x,edge y)
{
    return x.w<y.w;
}
void init()
{
    int i;
    for(i=0; i<=N; i++)
    {
        parent[i]=i;
    }
}
int Find(int x)
{
    if(parent[x] != x)
    {
        parent[x] = Find(parent[x]);
    }
    return parent[x];
}//���Ҳ����ؽڵ�x�������ϵĸ��ڵ�
void Union(int x,int y)
{
    x = Find(x);
    y = Find(y);
    if(x == y)
    {
        return;
    }
    parent[y] = x;
}//��������ͬ���ϵ�Ԫ�ؽ��кϲ�
int Kruskal()
{
    init();
    int sum=0;
    int num=0;
    for(int i=0; i<m; i++)
    {
        if(edg[i].del==1)
        {
            continue;
        }
        int u=edg[i].u;
        int v=edg[i].v;
        int w=edg[i].w;
        if(Find(u)!=Find(v))
        {
            sum+=w;
            if(!flag)
            {
                edg[i].used=1;
            }
            num++;
            Union(u,v);
        }
        if(num>=n-1)
        {
            break;
        }
    }
    return sum;
}
int main()
{
    int t,d;
    int i,j;
    int counts1,counts2;
    int flag2;
    scanf("%d",&t);
    while(t--)
    {
        counts1=0;
        scanf("%d%d",&n,&m);
        for(i=0; i<m; i++)
        {
            scanf("%d%d%d",&edg[i].u,&edg[i].v,&edg[i].w);
            edg[i].del=0;
            edg[i].used=0;
            edg[i].equals=0;//һ��ʼ����ط�eqû�г�ʼ����WA�˺ü�������
        }
        for(i=0; i<m; i++)
        {
            for(j=0; j<m; j++)
            {
                if(i==j)
                {
                    continue;
                }
                if(edg[i].w==edg[j].w)//�Ƿ������ͬ��Ȩֵ
                {
                    edg[i].equals=1;
                }
            }
        }
        sort(edg,edg+m,cmp);
        flag=0;//�����ǰѵ�һ����С�������õı߸��������
        counts1=Kruskal();
        flag=1;
        flag2=0;
        for(i=0; i<m; i++)
        {
            if(edg[i].used&&edg[i].equals)//ʹ�ù�����Ȩֵ���ں�����ͬ��
            {
                edg[i].del=1;
                counts2=Kruskal();//printf("%d %d\n",i,s);
                if(counts2==counts1)
                {
                    flag2=1;
                    printf("Not Unique!\n");
                    break;
                }
                edg[i].del=0;
            }
        }
        if(!flag2)
        {
            printf("%d\n",counts1);
        }
    }
    return 0;
}
