#include <iostream>

using namespace std;

void QuickSort (int low, int high);
void Partition(int low, int high, int& pivotpoint);

//값이 변하는 변수만 파라미터로 사용하는 관례에 따라서 n과 S가
//MergeSort 프로시저의 파라미터가 될 수 없기 때문에
//배열 S와 S의 원소 개수인 n을 전역으로 정의한다
int *S = NULL;
int n = 0;

int main()
{
    //배열의 크기(n)를 5에서 15까지 랜덤하게 정해줌
    srand(time(NULL));
    n = rand() % 10 + 5;
    //n의 크기만큼 동적할당함
    S = new int[n];
    //배열 S에 1에서 100까지의 수를 랜덤하게 넣어줌
    for (int i = 0; i < n; i++)
        S[i] = rand() % 100 + 1;
    //정렬되지 않은 상태의 배열 S를 출력
    cout << "--------------------\n" << "Not Arraged Array\n";
    for (int i = 0; i < n; i++)
        cout << S[i] << " ";
    cout << endl << endl;
    //QuickSort를 통한 배열 S의 정렬
    QuickSort(0, n-1);
    //원소가 비내림차순으로 정렬된 이후의 배열 S를 출력
    cout << "After Quick Sort\n";
    for (int i = 0; i < n; i++)
        cout << S[i] << " ";
    cout << "\n--------------------" << endl << endl;
    delete[] S;

    return 0;
}

//배열 S의 처음 index와 마지막 index를 입력받는다
void QuickSort (int low, int high)
{
    //pivotpoint: Partition이 끝났을 때 위치가 고정된 하나의 pivotitem
    int pivotpoint;

    //배열의 원소의 수가 1개 남을 때까지 계속 QuickSort 함수를 재귀 호출함
    if(high > low)
    {
        //기준원소(pivotitem)의 위치를 pivotpoint로 고정해준 후
        //이를 기준으로 pivotitem보다 작은 원소는 모두 왼쪽으로,
        //pivotitem보다 큰 원소는 모두 오른쪽으로 가도록
        //배열 S를 분할한다
        Partition(low, high, pivotpoint);
        //pivotitem 기준 왼쪽 원소들을 대상으로 QuickSort를 재귀호출한다
        QuickSort(low, pivotpoint-1);
        //pivotitem 기준 오른쪽 원소들을 대상으로 QuickSort를 재귀호출한다
        QuickSort(pivotpoint+1, high);
    }
}

//QuickSort에서 쓸 수 있도록 배열 S를 분할
void Partition(int low, int high, int& pivotpoint)
{
    int i, j;
    int pivotitem;

    //기준원소(pivotitem)를 배열 S의 첫 원소로 설정한다
    pivotitem = S[low];
    j=low;
    //기준원소(pivotitem)보다 작은 원소는 모두 왼쪽으로,
    //기준원소(pivotitem)보다 큰 원소는 모두 오른쪽으로 가도록
    //배열 S를 분할한다
    for(i=low+1; i<=high; i++)
    {
        if (S[i] < pivotitem)
        {
            j++;
            swap(S[i], S[j]);
        }
    }
    //pivoitpoint: Partiton이 끝났을 때 위치가 j로 고정된 하나의 pivotitem
    pivotpoint = j;
    //기준원소(pivotitem = S[low])의 값과
    //Partitioning이 끝난 후 정해진 S[pivotpoint]의 값을 바꿔준다
    swap(S[low], S[pivotpoint]);
}
