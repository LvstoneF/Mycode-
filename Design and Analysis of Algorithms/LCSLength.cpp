
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
    1.当x,y 有一个长度位0的时候，最长公共子序列长度位0
    2.每一个c[i][j]表示，这个时候下x,y长度位i,j时的 最长子序列长度
    3.当x[i],y[j]相等的时候，最长子序列中的最后一项一定是x[[i]=y[j]=z[m]
    4.这个时候就只需要把前面i-1,j-1的最长子序列求出来，在加上后面的最后一项+1，就ok
    5.当最后一个元素不相等的时候，就是i-1,或j-1的最长子序列和x,y，比较一下
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
////    cout << "创建序列X" << endl;
////    cout << "输入系列x长度：" ;
////    scanf("%d %d", &m, &n);
////    for(i = 1; i<=m; i++)
////        cin >> x[i]
////    //cout << "创建序列y" << endl;
////    //cout << "输入系列y长度：" ;
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
