//
// Created by HyeRyeongSong on 2017. 11. 5..
//
#include<iostream>

#define NUM 5

using namespace std;

int P[NUM][NUM];

void floyd(int n, int W[][NUM], int D[][NUM], int P[][NUM]);

void path(int q, int r);

int main()
{
    int q, r;

    int W[NUM][NUM];
    int D[NUM][NUM];

    for(int i=0; i<NUM; ++i)
    {
        cout << "Input varibles for row number " << i+1 <<": ";
        for(int j=0; j<NUM; ++j)
        {
            cin >> W[i][j];
        }
    }

    floyd(NUM, W, D, P);

    cout << "D =" << endl;

    for(int i=0; i<NUM; ++i) {
        for (int j = 0; j < NUM; ++j)
            cout << D[i][j] << " ";
        cout << endl;
    }

    cout << "\nP =" <<endl;

    for(int i=0; i<NUM; ++i) {
        for (int j = 0; j < NUM; ++j)
            cout << P[i][j] << " ";
        cout << endl;
    }


    cout << "\nInput 'starting point' number: ";
    cin >> q;

    cout << "Input 'destination' number: ";
    cin >> r;

    cout << endl;

    path(q, r);

    return 0;
}

void floyd(int n, int W[][NUM], int D[][NUM], int P[][NUM]) //const int** W 값 어떻게..?ㅠㅠ
{
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            P[i][j] = 0;
        }
    }

    copy(&(W[0][0]), &(W[0][0])+NUM*NUM,&(D[0][0]));

    for(int k=0; k<n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if(D[i][k] + D[k][j] < D[i][j])
                {
                    P[i][j] = k + 1;
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }
    }

}

void path(int q, int r)
{
    if(P[q-1][r-1] != 0)
    {
        path(q, P[q-1][r-1]);
        cout << " v" << P[q-1][r-1];
        path(P[q-1][r-1], r);
    }
}
