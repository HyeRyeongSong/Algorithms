//
// Created by HyeRyeongSong on 2017. 11. 28..
//
#include<iostream>
#include <vector>

using namespace std;

const int n = 5;

typedef int set_pointer;

struct edge
{
    int src;
    int dst;
    int weight;
};

typedef vector<edge> set_of_edges;

struct nodetype
{
    int parent;
    int depth;
};

typedef nodetype universe[n];

class Kruskal
{
private:
    universe U;

public:

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

    void merge (set_pointer p, set_pointer q)
    {
        if(U[p].depth == U[q].depth)
        {
            U[p].depth = U[p].depth + 1;
            U[q].parent = p;
        }
        else if(U[p].depth < U[q].depth)
            U[p].parent = q;
        else
            U[q].parent = p;
    }

    bool equal (set_pointer p, set_pointer q)
    {
        if(p == q)
            return true;
        else
            return false;
    }

    void initial (int n)
    {
        for(int i = 1; i<=n; i++)
            makeset(i);
    }

    void kruskal(int n, int m, set_of_edges E, set_of_edges& F)
    {
        int i, j;
        set_pointer p, q;
        edge e;

        sort(E.begin(), E.end(), compareByTime);

        F.clear();
        initial(n);

        int iIndex = 0;

        while(F.size() < n-1)
        {
            e.src = E[iIndex].src;
            e.dst = E[iIndex].dst;
            e.weight = E[iIndex].weight;
            iIndex++;
            i = e.src;
            j = e.dst;
            p = find(i);
            q = find(j);
            if(!equal(p, q))
            {
                merge(p, q);
                F.push_back(e);
            }
        }
    }

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

    k.kruskal(n, E.size(), E, F);

    cout << "Edges" << "   " << "Weight" << endl;

    for(int i=0; i<F.size(); ++i)
    {
        cout << "(" << F[i].src << ", " <<F[i].dst << ")    " << F[i].weight <<endl;

    }

    return 0;
}

