#include <iostream>

using namespace std;

void MergeSort (int low, int high);
void Merge (int low, int mid, int high);

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
    //MergeSort를 통한 배열 S의 정렬
    MergeSort(0, n-1);
    //원소가 비내림차순으로 정렬된 이후의 배열 S를 출력
    cout << "After Merge Sort\n";
    for (int i = 0; i < n; i++)
        cout << S[i] << " ";
    cout << "\n--------------------" << endl << endl;
    delete[] S;

    return 0;
}

//배열 S의 처음 index와 마지막 index를 입력받는다
void MergeSort (int low, int high)
{
    int mid;

    //배열의 원소의 수가 1개 남을 때까지 계속 MergeSort 함수를 재귀 호출함
    if(low < high)
    {
        mid = (low + high) / 2;
        //분할된 배열 중 앞부분을 대상으로 다시 합병정렬한다
        MergeSort(low, mid);
        //분할된 배열 중 뒷부분을 대상으로 다시 합병정렬한다
        MergeSort(mid + 1, high);
        //정렬된 배열 두 개를 정렬상태를 유지한면서 하나로 합병한다
        Merge(low, mid, high);
    }
}

//배열 S의 처음, 중간, 마지막 index를 입력받는다
void Merge (int low, int mid, int high)
{
    int i, j, k;
    //합병에 필요한 지역배열 U를 선언한다
    int U[n];
    i = low; j = mid + 1; k = low;
    //i와 j가 각각 배열 S의 첫 번째 부분배열(인덱스 low부터 high까지)과
    //배열 S의 두 번째 부분배열(인덱스 'mid+1'부터 high까지)의
    //마지막 원소를 가리킬 때까지 루프가 돈다
    while(i <= mid && j <= high)
    {
        //S[i]의 값이 S[j]의 값보다 작으면 S[i]를 U[k]에 넣어준다
        if(S[i] < S[j])
        {
            U[k] = S[i];
            i++;
        }
        //S[j]의 값이 S[i]의 값보다 작으면 S[j]를 U[k]에 넣어준다
        else
        {
            U[k] = S[j];
            j++;
        }
        //S[k]에 원소가 배정되면 k의 값을 1 증가시킨다
        k++;
    }
    //i의 값이 mid보다 큰 경우 배열 S의 첫 번째 부분 배열의 값들이 아직 배열 U에 배정되지 못한 것이므로
    //이 값들을 배열 U에 마저 넣어준다
    //else의 경우 배열 S의 두 번째 부분 배열의 값들이 아직 배열 U에 배정되지 못한 것이므로
    //이 값들을 배열 U에 마저 넣어준다
    if(i > mid)
        copy(S+j, S+(high+1), U+k);
    else
        copy(S+i, S+(mid+1), U+k);
    //임시로 만든 지역 배열 U의 정렬된 값들을 S에 복사해준다
    copy(U+low, U+(high+1), S+low);
}
