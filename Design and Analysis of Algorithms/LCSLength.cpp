
#include <stdio.h>
#include <iostream>
using namespace std;

#define N 1000

int i, j;
int **c;
int **b;
void LCSLength(int m, int n, char x[N], char y[N], int c[N][N], int b[N][N])
{
    //int i,j;
    /*
    1.��x,y ��һ������λ0��ʱ������������г���λ0
    2.ÿһ��c[i][j]��ʾ�����ʱ����x,y����λi,jʱ�� ������г���
    3.��x[i],y[j]��ȵ�ʱ����������е����һ��һ����x[[i]=y[j]=z[m]
    4.���ʱ���ֻ��Ҫ��ǰ��i-1,j-1�����������������ڼ��Ϻ�������һ��+1����ok
    5.�����һ��Ԫ�ز���ȵ�ʱ�򣬾���i-1,��j-1��������к�x,y���Ƚ�һ��
    */
    for(int i = 1; i<=m; i++)
        c[i][0] = 0;
    for(int i = 1; i<=n; i++)
        c[0][i] = 0;
    for(int i = 1; i<=m; i++)
    {
        for(int j = 1; j<=n; j++)
        {
            if(x[i] == y[j])
            {
                c[i][j] = c[i-1][j-1]+1;
                          c[i][j] = 1;
            }
            else if(c[i-1][j] >= c[i][j-1])
            {
                c[i][j] = c[i-1][j];
                          b[i][j] = 2;
            }
            else if(c[i-1][j] < c[i][j-1])
            {
                c[i][j] = c[i][j-1];
                b[i][j] = 3;
            }
        }
    }
}

void LCS(int i, int j, char *x, int **b)
{
    if(i == 0 || j == 0)
        return;
    if(b[i][j] == 1)
    {
        LCS(i-1, j-1, x, b);
        cout << x[i];
    }
    else if(b[i][j] == 2)
        LCS(i-1, j, x, b);
    else
        LCS(i, j-1, x, b);
}


////
////int main()
////{
////
////    int b[N][N];
////    int c[N][N];
////    char x[N];
////    char y[N];
////    int m, n;
////    cout << "��������X" << endl;
////    cout << "����ϵ��x���ȣ�" ;
////    scanf("%d %d", &m, &n);
////    for(i = 1; i<=m; i++)
////        cin >> x[i]
////    //cout << "��������y" << endl;
////    //cout << "����ϵ��y���ȣ�" ;
////    for(j = 1; j<=n; j++)
////        cin >> y[j];
////   // LCSLength(m, n, x, y, c, b);
////
////}
////
////


int main()
{
    int m, n;
    cin >> m;
    char x[10];
    char y[10];
    int c[10][10];
    int b[10][10];
    for(i = 0; i<m; i++)
   {
        cin >> x[i];
   }
   cin >> n;
    for(j = 0; j<n; j++)
    {
        cin >> y[j];
    }
    LCSLength(m, n, x, y, c, b);
    LCS(i, j, x, b);

}
