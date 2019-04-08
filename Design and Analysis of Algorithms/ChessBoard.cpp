#include <bits/stdc++.h>
using namespace std;


int title = 0;
int Board[1000][1000] = {0};
void ChessBoard(int tr, int tc, int dr, int dc, int size)
{
    if(size == 1)
        return;
    int s = size/2;
    int num = ++title;


    /*×óÉÏ½Ç¸²¸Ç*/
    if(dr < tr+s && dc < tc+s)
        ChessBoard(tr, tc, dr, dc, s);
    else
    {
        Board[tr+s-1][tc+s-1] = num;
        ChessBoard( tr, tc, tr+s-1, tc+s-1, s);
    }

    /*ÓÒÉÏ½Ç*/
    if(dr < tr+s && dc >= tc+s)
        ChessBoard[tr, tc+s, dr, dc, s];
    else
    {
        Board[tr+s-1][tc+s] = num;
        ChessBoard(tr, tc+s, tr+s-1, tc+s, s);
    }

    /*×óÏÂ½Ç*/
    if(dr >= tr+s && dc < tc+s)
        ChessBoard(tr+s, tc, dr, dc, s);
    else
    {
        Board[tr+s][tc+s-1] = num;
        ChessBoard(tr+s, tc, tr+s, tc+s-1, s);
    }

    /*ÓÒÏÂ½Ç*/
    if(dr >= tr+s && dc >= tc+s)
        ChessBoard(tr+s, tc+s, dr, dc, s);
    else
    {
        Board[tr+s][tc+s] = num;
        ChessBoard(tr+s, tc+s, tr+s, tc+s, s);
    }
}

int main()
{
    int k;
    int tr = 0;
    int tc = 0;
    cin >> k;
    int size = (int)pow(2, k);

    int dr, dc;
    cin >> dr >> dc;

    Board[dr][dc] = -1;
    ChessBoard(tr, tc, dr, dc, size);
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j<size; j++)
            cout << setw(3) << Board[i][j];
        cout << endl;
    }
}

