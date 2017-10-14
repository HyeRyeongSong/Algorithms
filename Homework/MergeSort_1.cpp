#include <iostream>

using namespace std;

void MergeSort (int n, int* S);
void Merge (int h, int m, const int* U, const int* V, int* S);

int main()
{
    //배열의 크기(n)를 5에서 15까지 랜덤하게 정해줌
    srand(time(NULL));
    int n = rand() % 10 + 5;
    //n의 크기만큼 동적할당함
    int *S = new int[n];
    //배열 S에 1에서 100까지의 수를 랜덤하게 넣어줌
    for (int i = 0; i < n; ++i)
        S[i] = rand() % 100 + 1;
    //정렬되지 않은 상태의 배열 S를 출력
    cout << "--------------------\n" << "Not Arraged Array\n";
    for (int i = 0; i < n; i++)
        cout << S[i] << " ";
    cout << endl << endl;
    //MergeSort를 통한 배열 S의 정렬
    MergeSort(n, S);
    //원소가 비내림차순으로 정렬된 이후의 배열 S를 출력
    cout << "After Merge Sort\n";
    for (int i = 0; i < n; i++)
        cout << S[i] << " ";
    cout << "\n--------------------" << endl << endl;
    delete[] S;

    return 0;
}

//'양의 정수 n', '배열 S(인덱스는 1부터 n까지)'를 입력받음
void MergeSort (int n, int* S)
{
    //배열의 원소의 수가 1개 남을 때까지 계속 MergeSort 함수를 재귀 호출함
    if (n > 1)
    {
        //배열 S를 반으로 분할하여 각각 U와 V배열에 넣어준다
        const int h = n/2, m = n-h;
        int U[h], V[m];
        copy(S, S+h, U);
        copy(S + h, S+n,V);
        //분할된 배열 중 U를 대상으로 다시 합병정렬한다
        MergeSort(h, U);
        //분할된 배열 중 V를 대상으로 다시 합병정렬한다
        MergeSort(m, V);
        //정렬된 배열 두 개를 정렬상태를 유지하면서 하나로 합병한다
        Merge(h, m, U, V, S);
    }
}

//'양의 정수 h와 m', '정렬된 배열 U(인덱스는 1부터 h까지)', '정렬된 배열 V(인덱스는 1부터 m까지)'를 입력받음
void Merge (int h, int m, const int* U, const int* V, int* S)
{
    int i, j, k;
    i = j = k = 0;
    //i와 j가 각각 배열 U와 V의 마지막 원소를 가리킬 때까지 루프가 돈다
    while(i < h && j < m)
    {
        //U[i]의 값이 V[j]의 값보다 작으면 U[i]를 S[k]에 넣어주고 i값을 1 증가시킨다
        if(U[i] < V[j])
        {
            S[k] = U[i];
            i++;
        }
        //V[j]의 값이 U[i]의 값보다 작으면 V[j]를 S[k]에 넣어주고 j값을 1 증가시킨다
        else
        {
            S[k] = V[j];
            j++;
        }
        //S[k]에 원소가 배정되면 k의 값을 1 증가시킨다
        k++;
    }
    //i의 값이 h보다 크거나 같은 경우 배열 V의 값들이 아직 배열 S에 배정되지 못한 것이므로
    //이 값들을 배열 S에 마저 넣어준다
    //else의 경우 배열 U의 값들이 아직 배열 S에 배정되지 못한 것이므로 이 값들을 배열 S에 마저 넣어준다
    if(i>=h)
        copy(V+j, V+m, S+k);
    else
        copy(U+i, U+h, S+k);
}
