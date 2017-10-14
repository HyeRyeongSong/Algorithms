#include <iostream>

using namespace std;

void MergeSort (int low, int high);
void Merge (int low, int mid, int high);

int *S = NULL;
int n = 0;

int main()
{
    srand(time(NULL));
    n = rand() % 10 + 5;
    S = new int[n];
    for (int i = 0; i < n; i++)
        S[i] = rand() % 100 + 1;
    cout << "--------------------\n" << "Not Arraged Array\n";
    for (int i = 0; i < n; i++)
        cout << S[i] << " ";
    cout << endl << endl;
    MergeSort(0, n-1);
    cout << "After Merge Sort\n";
    for (int i = 0; i < n; i++)
        cout << S[i] << " ";
    cout << "\n--------------------" << endl << endl;
    delete[] S;

    return 0;
}

void MergeSort (int low, int high)
{
    int mid;

    if(low < high)
    {
        mid = (low + high) / 2;
        MergeSort(low, mid);
        MergeSort(mid + 1, high);
        Merge(low, mid, high);
    }
}
void Merge (int low, int mid, int high)
{
    int i, j, k;
    int U[n];
    i = low; j = mid + 1; k = low;
    while(i <= mid && j <= high)
    {
        if(S[i] < S[j])
        {
            U[k] = S[i];
            i++;
        }
        else
        {
            U[k] = S[j];
            j++;
        }
        k++;
    }
    if(i > mid)
        copy(S+j, S+(high+1), U+k);
    else
        copy(S+i, S+(mid+1), U+k);
    copy(U+low, U+(high+1), S+low);
}
