#include <iostream>
#include <vector>
#include <fstream>
#include <stack>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

//相较普通的自顶向下的归并排序改进了三处
void sort(int *a, int n);
void sort(int *a, int *aux, int lo, int hi);
void merge(int *a, int *aux, int lo, int mid, int hi);
//排序a数组中[lo,hi]的项
void insertSort(int *a, int lo, int hi);
void exch(int &p, int &q){ int temp = p; p = q; q = temp; }
void show(int *a, int n){
    for(int i = 0; i < n; ++i)
        cout << a[i] << endl;
}
bool isSorted(int *a, int n){
    for(int i = 1; i < n; ++i)
        if(a[i - 1] > a[i])
            return 0;
    return 1;            
}

void sort(int *a, int n){
    if(nullptr == a || 0 == n){
        cout << "wrong input" << endl;
        return;
    }
    int *aux = new int[n];
    sort(a, aux, 0, n-1);
}

void sort(int *a, int *aux, int lo, int hi){
    if(lo >= hi)
        return;
    int mid = lo + (hi - lo)/2;
    //第一处改动，对小规模数组使用插入排序
    if(hi-lo < 10)
        insertSort(a, lo, hi);
    else {
        sort(a, aux, lo, mid);
        sort(a, aux, mid + 1, hi);
        //第二处，当数组已经有序时，跳过归并函数
        if(a[mid] > a[mid+1])
            merge(a, aux, lo, mid, hi);
    }
    
}

void merge(int *a, int *aux, int lo, int mid, int hi){
    for(int i = lo; i <= hi; ++i)
        aux[i] = a[i];
    int f1 = lo, f2 = mid + 1;
    for(int i = lo; i <= hi; ++i){
        if(f1 > mid){
            a[i] = aux[f2];
            ++f2;
        } else if(f2 > hi){
            a[i] = aux[f1];
            ++f1;
        } else if(aux[f1] > aux[f2]){
            a[i] = aux[f2];
            ++f2;
        } else {
            a[i] = aux[f1];
            ++f1;
        }
    }
}

void insertSort(int *a, int lo, int hi){
    if(nullptr == a || hi-lo < 0){
        cout << "wrong input in insert sorting" << endl;
        return;
    }
    int num, j;
    for(int i = lo+1; i <= hi; ++i){
        num = a[i];
        for(j = i; num < a[j-1] && j > lo; --j)
            a[j] = a[j-1];
        a[j] = num;
    }
}

void test(int *a, int n){
    int *a1 = new int[n];
    for(int i = 0; i < n; ++i)
        a1[i] = a[i];
    sort(a, n);
    if(!isSorted(a, n)){
        cout << "array:";
        for(int i = 0; i < n; ++i)
            cout << a1[i] << " ";
        cout << "is not sorted" << endl;
    }
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < 100; ++i){
        srand((unsigned)time(NULL));
        for(int i = 0; i < n; ++i)
            a[i] = rand();
        sort(a, n);
        if(!isSorted(a, n))
            cout << "array is not sorted" << endl;
    }
    
    int aa[6][5] = { 
                        {0,0,0,0,0},
                        {5,4,3,2,1},
                        {1,1,1,1,0},
                        {-1,1,1,1,0},
                        {0,1,1,1,1}
                   };
    for(int i = 0; i < 6; ++i)
        test(a + i*5, 5);
}