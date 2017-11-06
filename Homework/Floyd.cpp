//
// Created by HyeRyeongSong on 2017. 11. 5..
//
#include<iostream>

using namespace std;

int** P;
int iNum;

void floyd(int n, int** W, int** D, int** P);

void path(int q, int r);

int main()
{
    int q, r;
    cout << "Number for row & colums for square matrix: ";
    cin >> iNum;
    cout <<endl;

    int** W = new int *[iNum];
    int** D = new int *[iNum];
    P = new int *[iNum];

    for( int i = 0 ; i < iNum ; i++ )
    {
        W[i] = new int[iNum];
        D[i] = new int[iNum];
        P[i] = new int[iNum];
    }

    for(int i=0; i<iNum; ++i)
    {
        cout << "Input varibles for row number " << i+1 <<": ";
        for(int j=0; j<iNum; ++j)
        {
            cin >> W[i][j];
        }
    }

    floyd(iNum, W, D, P);

    cout << "Input 'starting point' number: ";
    cin >> q;

    cout << "Input 'destination' number: ";
    cin >> r;

    path(q, r);

    for( int i = 0 ; i < iNum ; i++ )
    {
        delete[] W[i];
        delete[] D[i];
        delete[] P[i];
    }
    delete [] W;
    delete [] D;
    delete [] P;


    return 0;
}

void floyd(int n, int** W, int** D, int** P) //const int** W 값 어떻게..?ㅠㅠ
{
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            P[i][j] = 0;
        }
    }

    copy(&(W[0][0]), &(W[0][0])+iNum*iNum,&(D[0][0]));

    for(int k=0; k<n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if(D[i][k] + D[k][j] < D[i][j])
                {
                    P[i][j] = k;
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }
    }

}

void path(int q, int r) //const int** P 값 어떻게..?ㅠㅠ
{
    if(P[q][r] != 0)
    {
        path(q, P[q][r]);
        cout << " v" << P[q][r];
        path(P[q][r], r);
    }
}
