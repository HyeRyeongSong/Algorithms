//
// Created by HyeRyeongSong on 2017. 11. 5..
//
#include<iostream>

//배열의 행과 열의 수를 NUM이라는 변수로 치환하였다
#define NUM 5

using namespace std;

//path 함수에서 사용하기 위해 P 배열을 전역으로 선언함
int P[NUM][NUM];

//가중치 포함 그래프의 각 정점에서 다른 모든 정점까지의 최단거리를 계산하고 각각의 최단경로를 구해줌
void floyd(int n, int W[][NUM], int D[][NUM], int P[][NUM]);

//최단 경로 상에 놓여 있는 정점을 출력
void path(int q, int r);

int main()
{
    int q, r;

    int W[NUM][NUM];
    int D[NUM][NUM];

    //W 배열의 원소를 입력 받음
    for(int i=0; i<NUM; ++i)
    {
        cout << "Input varibles for row number " << i+1 <<": ";
        for(int j=0; j<NUM; ++j)
        {
            cin >> W[i][j];
        }
    }

    //floyd 함수를 통해 D와 P 배열을 완성함
    floyd(NUM, W, D, P);

    //D 배열을 출력
    cout << "D =" << endl;

    for(int i=0; i<NUM; ++i) {
        for (int j = 0; j < NUM; ++j)
            cout << D[i][j] << " ";
        cout << endl;
    }

    //P 배열을 출력
    cout << "\nP =" <<endl;

    for(int i=0; i<NUM; ++i) {
        for (int j = 0; j < NUM; ++j)
            cout << P[i][j] << " ";
        cout << endl;
    }

    //출발 노드 번호를 입력받음
    cout << "\nInput 'starting point' number: ";
    cin >> q;

    //도착 노드 번호를 입력받음
    cout << "Input 'destination' number: ";
    cin >> r;

    cout << endl;

    //출발 노드로부터 도착 노드까지의 최단경로 상에 놓여 있는 정점을 출력함
    path(q, r);

    return 0;
}

void floyd(int n, int W[][NUM], int D[][NUM], int P[][NUM])
{
    //P 배열의 원소를 0으로 초기화함
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            P[i][j] = 0;
        }
    }

    //W 배열을 D 배열로 복사함
    copy(&(W[0][0]), &(W[0][0])+NUM*NUM,&(D[0][0]));

    for(int k=0; k<n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                //vk를 경유할 때의 가중치가 경유하지 않을 때의 가중치보다 효율적인 경우에 한해 조건문을 실행
                if(D[i][k] + D[k][j] < D[i][j])
                {
                    //P[i][j]와 D[i][j]의 값을 갱신해줌
                    P[i][j] = k + 1;
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }
    }

}

void path(int q, int r)
{
    //vq에서 vp까지 가는 길이 direct가 아닌 경우 조건문 실행
    if(P[q-1][r-1] != 0)
    {
        path(q, P[q-1][r-1]);
        //더 이상의 경유지가 없고 direct 경로일 때 해당 노드를 출력
        cout << " v" << P[q-1][r-1];
        path(P[q-1][r-1], r);
    }
}
