#include<iostream>
#include<ostream>
#include<cassert>

using namespace std;

class Kvector{
    int *m;
    int len;
public:
    Kvector(int size = 0,int value = 0); 
    Kvector(const Kvector&v );
    ~Kvector();
    void print() ;
    void clear();
    int size();
    friend bool operator==(Kvector& v, Kvector& c);
    friend bool operator!=(Kvector& v, Kvector& c);
    friend ostream& operator<<(ostream& os, Kvector& v);
    Kvector& operator=( Kvector& v);
    int& operator[](int idx);
    
};

bool operator==(Kvector& v, Kvector& c){
    if(v.len==c.len){
        for(int i=0; i<v.len; i++){
            if(v.m[i]!=c.m[i]) return false;
        }
        return true;
    }
    else return false;
}

bool operator!=(Kvector& v, Kvector& c){
    if(v.len==c.len){
        for(int i=0; i<v.len; i++){
            if(v.m[i]!=c.m[i]) return true;
        }
        return false;
    }
    else return true;
}
Kvector& Kvector::operator=(Kvector& v){
    if(this != &v){
        delete[] m;
        len = v.len;
        m = new int[len];
        for(int i = 0; i < len; i++){
            m[i] = v.m[i];
        }
    }
    return *this;
}

ostream& operator<<(ostream& os, Kvector& v){
    for(int i=0; i<v.len; i++){
        os << v.m[i] << " ";
    }
    return os;
}

 int& Kvector::operator[](int idx){
     assert(0<=idx && idx < size());
     return m[idx];

 }
Kvector::Kvector(int size,int value){
    this -> len = size;
    cout << this << " : Kvector(int) \n";
    if(len){
        m = new int[len];
        for(int i=0; i<len; i++) m[i] = value;
    }
    else{
    m = NULL; 
    }
}
Kvector::Kvector(const Kvector&v){
    this ->len = v.len;
    m = new int[len];
    for(int i = 0; i < len; i++){
        m[i] = v.m[i];
    }
    cout << this << " : Kvector(Kvector&) \n";
}
    


Kvector::~Kvector(){
    cout << this << " : ~Kvector() \n";
    delete[] m; 
}

void Kvector::print(){
    for(int i=0; i<len; i++){
        cout << m[i] << " ";
    }
    cout << endl;
}




void Kvector::clear(){
    delete[] m;
    m = NULL;
    len = 0; 
}

int Kvector::size(){
    return len;
}
int main(){
    Kvector v1(3); v1.print();
    Kvector v2(2,9); v2.print(); 
    Kvector v3(v2); v3.print(); 
    cout << (v1 == v2) << endl;
    cout << (v3 == v2) << endl;
    v3 = v2 = v1;
    cout << v1 << endl;
    cout << v2 << endl;
    cout << v3 << endl;
    cout << (v3 != v2) << endl;
    v1[2] = 2;
    v2[0] = v1[2];
    cout << "v1: "<< v1 <<"v2: "<< v2 <<"v3: "<< v3 << endl;
    return 0;
}