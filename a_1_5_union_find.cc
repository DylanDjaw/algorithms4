#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <fstream>

using namespace std;

class UF{
public:
    UF(int N){
        _count = N;
        _n = N;
        _id = new int[N];
        for(int i = 0; i < N; ++i)
            _id[i] = i;
    }
    void union1(int p, int q);
    int find1(int p);
    bool connected1(int p, int q){   return find1(p) == find1 (q); }
    int count(){    return _count;   }

private:
    int _count;         //分量数量
    int _n;             //点的数量
    int *_id;           //分量id（以触点为索引）
};

int UF::find1(int p){
    return _id[p];
}
void UF::union1(int p, int q){
    //若p, q相连，则返回
    if(connected1(p, q))
        return;
    //否则将与p在同一联通分量中的点都与q相连
    int pId = _id[p];
    int qId = _id[q];
    for(int i = 0; i < _n; ++i){
        if(_id[i] == pId)
            _id[i] = qId;
    }
    --_count;
}



int main(){
    ifstream input;
    input.open("/home/jyn/workspace/algorithm4/input/tinyUF.txt", ios::in | ios::in);
    if(input.is_open()) cout << "success" << endl;
    int n;
    input >> n;
    //cout << n << endl;
    UF u(n);
    int p, q;
    while(input >> p){
        input >> q;
        //cout << p << "\t" << q << endl;
        //若不联通，则联通，若联通，则忽略
        if( ! u.connected1(p, q) )
            u.union1(p, q);            
    }
    cout << u.connected1(4,8) << endl;
    cout << u.count() << endl;
}