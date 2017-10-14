#include <iostream>

using namespace std;

void MergeSort (int n, int* S);
void Merge (int h, int m, const int* U, const int* V, int* S);

int main()
{
    srand(time(NULL));
    int n = rand() % 10 + 5;
    int *S = new int[n];
    for (int i = 0; i < n; ++i)
        S[i] = rand() % 100 + 1;
    cout << "--------------------\n" << "Not Arraged Array\n";
    for (int i = 0; i < n; i++)
        cout << S[i] << " ";
    cout << endl << endl;
    MergeSort(n, S);
    cout << "After Merge Sort\n";
    for (int i = 0; i < n; i++)
        cout << S[i] << " ";
    cout << "\n--------------------" << endl << endl;
    delete[] S;

    return 0;
}

void MergeSort (int n, int* S)
{
    if (n > 1)
    {
        const int h = n/2, m = n-h;
        int U[h], V[m];
        copy(S, S+h, U);
        copy(S + h, S+n,V);
        MergeSort(h, U);
        MergeSort(m, V);
        Merge(h, m, U, V, S);
    }
}
void Merge (int h, int m, const int* U, const int* V, int* S)
{
    int i, j, k;
    i = j = k = 0;
    while(i < h && j < m)
    {
        if(U[i] < V[j])
        {
            S[k] = U[i];
            i++;
        }
        else
        {
            S[k] = V[j];
            j++;
        }
        k++;
    }
    if(i>=h)
        copy(V+j, V+m, S+k);
    else
        copy(U+i, U+h, S+k);
}
