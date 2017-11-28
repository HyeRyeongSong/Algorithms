//
// Created by HyeRyeongSong on 2017. 11. 28..
//
#include<iostream>
#include <vector>

using namespace std;

//전체집합이 가지고 있는 요소의 개수
const int n = 5;

typedef int set_pointer;

//가중치(weight)가 포함된 edge를 의미하는 구조체
struct edge
{
    int src;
    int dst;
    int weight;
};

//edge들의 집합
typedef vector<edge> set_of_edges;

//parent: 해당 트리에서 특정 vertex의 부모 노드
//depth: 해당 트리에서 특정 vertex의 depth
struct nodetype
{
    int parent;
    int depth;
};

//전체집합은 1부터 n까지로 인덱스된다
typedef nodetype universe[n];

class Kruskal
{
private:
    universe U;

public:

    //vertex가 하나뿐인 disjoint set을 만들어줌
    void makeset(int i)
    {
        U[i].parent = i;
        U[i].depth = 0;
    }

    set_pointer find(int i)
    {
        int j;

        j = i;
        while(U[j].parent != j)
            j = U[j].parent;
        return j;
    }

    //p와 q가 가리키고 있는 두 개의 집합을 하나로 합친다
    void merge (set_pointer p, set_pointer q)
    {
        if(U[p].depth == U[q].depth)
        {
            //두 서로소 집합 트리의 깊이가 같다면
            //트리의 깊이는 증가해야 한다
            U[p].depth = U[p].depth + 1;
            U[q].parent = p;
        }
            //두 서로소 집합 트리의 깊이가 다르다면
            //깊이가 작은 트리를 자식마디로 만든다
        else if(U[p].depth < U[q].depth)
            U[p].parent = q;
        else
            U[q].parent = p;
    }

    //p와 q가 같은 집합을 가리키면 true를 넘겨준다
    bool equal (set_pointer p, set_pointer q)
    {
        if(p == q)
            return true;
        else
            return false;
    }

    //n개의 서로소 부분집합을 초기화
    //하나의 부분집합에 1에서 n 사이의 인덱스가 정확히 하나 포함됨
    void initial (int n)
    {
        for(int i = 1; i<=n; i++)
            makeset(i);
    }

    //n: vertex의 갯수, m: edge의 갯수,
    //입력으로 주어진 가중치 포함 이음선 집합 E,
    //출력으로 내보낼 최소비용 신장트리에서 이음선의 집합 F
    void kruskal(int n, int m, set_of_edges E, set_of_edges& F)
    {
        //e로 연결된 마디의 인덱스
        //i: e의 source vertex
        //j: e의 destination vertex
        int i, j;
        set_pointer p, q;
        //아직 고려하지 않은 edge들 중 weight(가중치)가 최소인 edge
        edge e;

        //E에 속한 m개의 이음선을 가중치가 작은 것부터 차례로 정렬한다
        sort(E.begin(), E.end(), compareByTime);

        //F를 공집합으로 초기화해준다
        F.clear();

        //vertex를 n개의 서로소 부분집합으로 초기화해준다
        initial(n);

        //iterator 역할 (임의로 추가)
        int iIndex = 0;

        //F에서의 이음선의 수가 (n-1)보다 작을 동안 루프가 돈다
        while(F.size() < n-1)
        {
            e.src = E[iIndex].src;
            e.dst = E[iIndex].dst;
            e.weight = E[iIndex].weight;
            iIndex++;
            i = e.src;
            j = e.dst;
            //인덱스 i가 포함된 집합의 포인터 p를 넘겨줌
            p = find(i);
            //인덱스 j가 포함된 집합의 포인터 q를 넘겨줌
            q = find(j);
            //p와 q가 같은 집합을 가리키면 true를 넘겨줌
            if(!equal(p, q))
            {
                //두 개의 집합을 가리키는 p와 q를 합병
                merge(p, q);
                //e를 F에 추가
                F.push_back(e);
            }
        }
    }

    //edge를 weight를 기준으로 정렬하기 위한 함수 (임의 추가)
    static bool compareByTime(const edge &a, const edge &b)
    {
        return a.weight < b.weight;
    }
};

int main()
{
    Kruskal k;
    set_of_edges E;
    set_of_edges F;
    E.clear();
    edge e;

    int W[n][n];

    //W 배열의 원소를 입력 받음
    for(int i=0; i<n; ++i)
    {
        cout << "Input varibles for row number " << i+1 <<": ";
        for(int j=0; j<n; ++j)
        {
            cin >> W[i][j];
        }
    }

    //입력으로 주어질 E를 W 배열에 근거해 채워줌
    for(int i=0; i<n; ++i)
    {
        for(int j=i; j<n; ++j)
        {
            //-1은 무한대를 의미
            //가중치가 0이거나 무한대가 아닌 경우
            if((W[i][j] != 0) && (W[i][j] != -1))
            {
                e.src = i+1;
                e.dst = j+1;
                e.weight = W[i][j];
                E.push_back(e);
            }
        }
    }

    //Kruskal's Algorithm으로 MST (Minimum Spanning Tree)를 구함
    k.kruskal(n, E.size(), E, F);

    cout << "Edges" << "   " << "Weight" << endl;

    //MST(Minimum Spanning Tree)에서 edge들의 집합 F를 출력해줌
    for(int i=0; i<F.size(); ++i)
    {
        cout << "(" << F[i].src << ", " <<F[i].dst << ")    " << F[i].weight <<endl;

    }

    return 0;
}

