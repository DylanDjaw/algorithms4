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

void sort(int *a, int n){
    if(nullptr == a || 0 == n){
        cout << "wrong input" << endl;
        return;
    }
    int num;
    for(int i = 1; i < n; ++i){
        num = a[i];
        int j;
        for(j = i; num < a[j-1] && j > 0; --j)
            a[j] = a[j-1];
        a[j] = num;
    }
}

int main(){
    int n;
    cin >> n;
    int a[n];
    srand((unsigned)time(NULL));
    for(int i = 0; i < n; ++i)
        a[i] = rand();
    sort(a, n);
    if(isSorted(a, n))
        show(a, n);
}