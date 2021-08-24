#include <iostream>
#include <vector>
#include <stack>
#include <string>


using namespace std;

template <typename T> class my_stack{
public:
    my_stack() : _N(0), _pHead(nullptr) {}
    ~my_stack(){
        Node *p1 = _pHead, *p2 = p1;
        for(int i = 0; (i < _N) || (nullptr != p2); ++i){
            p1 = p1->_pNext;
            delete p2;
            p2 = p1;    
        }
    }
    bool isEmpty() const { return 0 == _N; }
    int size() const { return _N; }
    T top(){
        if(nullptr == _pHead){
            cout << "no data" << endl;
            return -1;
        }
        return _pHead->_data; 
    }
    void push(T new_data){
        Node *pNewNode = new Node();
        pNewNode->_data = new_data;
        pNewNode->_pNext = _pHead;
        _pHead = pNewNode;
        ++_N; 
    }
    void pop(){
        if(nullptr == _pHead){  
            cout << "no data" << endl;
            return; 
        }
        Node *pDelNode = _pHead;
        _pHead = _pHead->_pNext;
        delete pDelNode;
        --_N;
    }
    void show(){
        Node *p = _pHead;
        for(int i = 0; (i < _N) || (nullptr != p); ++i){
            cout << p->_data << "\t";  
            p = p->_pNext;
        }
        cout << endl; 
    }
private:
    struct Node{
        T _data;
        Node *_pNext;
    };
    Node *_pHead;
    int _N;
};

int main(){
    my_stack<int> s;
    cout << s.size() << endl;
    cout << s.isEmpty() << endl;
    cout << s.top() << endl;
    s.pop();
    s.push(2);
    s.push(3);
    s.show();
    cout << s.top() << endl;
    s.pop();
    s.show();
    s.pop();
    s.pop();
    s.show();
    cout << "----" << endl;
    cout << s.size() << endl;
    cout << s.isEmpty() << endl;
    cout << s.top() << endl;
}