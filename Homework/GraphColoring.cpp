//
// Created by HyeRyeongSong on 2017. 12. 8..
//
#include<iostream>

using namespace std;

//정점의 수인 n의 값은 여기에서 정해준다
const int n = 25;

class GraphColoring
{
private:
    int m;
    bool W[n+1][n+1];
    int vcolor[n+1];
    int count = 1;
public:
    void m_coloring (int i)
    {
        int color;
        if(promising(i))
        {
            if (i == n)
            {
                cout << "Case " << count++ << endl;
                for(int i=1; i<=n; ++i)
                    cout << "vcolor[" << i <<"] = " << vcolor[i] << endl;
                cout << endl;
            }
            else
            {
                //다음 정점에 모든 색을 시도해 본다
                for(color = 1; color<=m; ++color)
                {
                    vcolor[i+1] = color;
                    m_coloring(i+1);
                }
            }
        }
    }

    bool promising(int i)
    {
        int j;
        bool bSwitch;
        bSwitch = true;
        j=1;
        //인접한 정점에 이 색이 이미 칠해져 이쓴ㄴ지 점검한다
        while(j<i && bSwitch)
        {
            if(W[i][j] && vcolor[i]==vcolor[j])
                bSwitch = false;
            ++j;
        }
        return bSwitch;
    }

    void InputVarables()
    {
        //m: 사용하는 색의 수
        cout << "m: ";
        cin >> m;

        W[0][0] = W[0][1] = W[1][0] = 0;
        vcolor[0] = 0;

        //W: n개의 정점을 가진 비방향그래프
        //W[i][j]=1 --> i정점과 j정점사이에 간선이 있음
        for(int i=1; i<=n; ++i)
        {
            cout << "Input varibles for row number " << i <<": ";
            for(int j=1; j<=n; ++j)
            {
                cin >> W[i][j];
            }
        }
    }
};

int main()
{
    GraphColoring gc;
    gc.InputVarables();
    //m_coloring의 최상위 수준 호출
    gc.m_coloring(0);

    return 0;
}