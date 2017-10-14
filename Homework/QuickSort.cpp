#include <iostream>

using namespace std;

void QuickSort (int low, int high);
void Partition(int low, int high, int& pivotpoint);

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
    QuickSort(0, n-1);
    cout << "After Quick Sort\n";
    for (int i = 0; i < n; i++)
        cout << S[i] << " ";
    cout << "\n--------------------" << endl << endl;
    delete[] S;

    return 0;
}

void QuickSort (int low, int high)
{
    int pivotpoint;

    if(high > low)
    {
        Partition(low, high, pivotpoint);
        QuickSort(low, pivotpoint-1);
        QuickSort(pivotpoint+1, high);
    }
}

void Partition(int low, int high, int& pivotpoint)
{
    int i, j;
    int pivotitem;

    pivotitem = S[low];
    j=low;
    for(i=low+1; i<=high; i++)
        if(S[i] < pivotitem)
        {
            j++;
            swap(S[i], S[j]);
        }
    pivotpoint = j;
    swap(S[low], S[pivotpoint]);
}