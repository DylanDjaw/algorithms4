#include <iostream>
#include <vector>
#include <fstream>
#include <stack>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;


void sort(int *a, int n);
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

void sort(int *a, int *aux, int lo, int hi){
    if(lo >= hi)
        return;
    int mid = lo + (hi - lo)/2;
    sort(a, aux, lo, mid);
    sort(a, aux, mid + 1, hi);
    merge(a, aux, lo, mid, hi);
}

void sort(int *a, int n){
    if(nullptr == a || 0 == n){
        cout << "wrong input" << endl;
        return;
    }
    int *aux = new int[n];
    sort(a, aux, 0, n-1);
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