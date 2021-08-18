#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <fstream>
#include <ctime>
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
    void _union(int p, int q);
    int find(int p);
    bool connected(int p, int q){   return find(p) == find (q); }
    int count(){    return _count;   }

private:
    int _count;         //分量数量
    int _n;             //点的数量
    int *_id;           //分量id（以触点为索引）
};

int UF::find(int p){
    return _id[p];
}
void UF::_union(int p, int q){
    //若p, q相连，则返回
    if(connected(p, q))
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



class WeightedQuickUnionUF{
public:
    WeightedQuickUnionUF(int n) : _count(n) {
        //将所有的节点的父节点设为节点本身
        _id = new int[n];
        for(int i = 0; i < n; ++i)  _id[i] = i;
        //将各个节点的分量大小初始化为1
        _size = new int[n];
        for(int i = 0; i < n; ++i)  _size[i] = 1;        
    }
    //返回联通分量的数量
    int count(){    return _count;  }
    //返回节点所在联通分量树的根节点
    int find(int node){
        while(_id[node] != node){
            node = _id[node];
        }
        return node;
    }
    bool connected(int p, int q){
        return find(p) == find(q);
    }
    void _union(int p, int q){
        int root_p = find(p);
        int root_q = find(q);
        if(root_p == root_q)
            return;
        if(_size[root_p] > _size[root_q]){
            _id[root_q] = root_p;
            _size[root_p] += _size[root_q];
        } else {
            _id[root_p] = root_q;
            _size[root_q] += _size[root_p];
        }
        --_count;
    }
private:
    int *_id;           //节点的父节点
    int *_size;         //各个根节点的分量大小
    int _count;         //联通分量数量
};


int main(){
    clock_t bng, end;
    double time = 0;

    ifstream input;
    int p, q;
    int n;

    //u1
    input.open("/home/jyn/workspace/algorithms4/input/mediumUF.txt", ios::in);
    //if(input.is_open()) cout << "success" << endl;
    input >> n;
    UF u1(n);
    bng = clock();
    while(input >> p){
        input >> q;
        //若不联通，则联通，若联通，则忽略
        if( ! u1.connected(p, q) )
            u1._union(p, q);            
    }
    end = clock(); 
    cout << bng << endl;
    cout << end << endl;
    time = 1000 * (end - bng) / CLOCKS_PER_SEC ;
    cout << "u1 time:" << time << "ms" << endl;


    //u2
    
    input.close();
    input.open("/home/jyn/workspace/algorithms4/input/largeUF.txt", ios::in);
    input >> n;
    WeightedQuickUnionUF u2(n);
    bng = clock();
    while(input >> p){
        input >> q;
        //若不联通，则联通，若联通，则忽略
        u2._union(p, q);            
    }
    end = clock();
    time = (double)(end - bng) / (double)CLOCKS_PER_SEC * 1000;

    cout << "u2 time:" << time << "ms" << endl;
}