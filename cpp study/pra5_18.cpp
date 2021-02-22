#include<iostream>
#include<ostream>
#include<cassert>
using namespace std;
// =  ==  !=  []  <<
class Kvector{
protected:
    int *m;
    int length;
public:
    Kvector(int size = 0,int value = 0); 
    Kvector(const Kvector&v );
    ~Kvector();
    void print();
    void print() const;
    void clear();
    int size();
    friend bool operator==(Kvector& v, Kvector& c);
    friend bool operator!=(Kvector& v, Kvector& c);
    friend ostream& operator<<(ostream& os, Kvector& v);
    Kvector& operator=( Kvector& v);
    int& operator[](int idx);  
};

#define N 3
class Avector : public Kvector{
    char table[N];
public:
    Avector(int size = 0, int v = 0, const char *t = "abc");
    void setTable(char argv[]){
        for(int i = 0; i<N; i++)
         table[i] = argv[i];
    }
    friend ostream& operator<<(ostream& os, Avector&v);

};
Avector::Avector(int size , int v , const char *t):Kvector(size, v)
{
    cout << this << " : Avector("<< size<<","<< v<<"," << t << ")" << endl;

    for(int i = 0; i<N; i++)
        table[i] = t[i];
    

}

ostream& operator<<(ostream& os, Avector& v){
    for(int i = 0; i < v.length; i++){
    int num = v.m[i]%3;
    os << v.table[num] << " ";
    }
    return os;
}




bool operator==(Kvector& v, Kvector& c){
    if(v.length==c.length){
        for(int i=0; i<v.length; i++){
            if(v.m[i]!=c.m[i]) return false;
        }
        return true;
    }
    else return false;
}

bool operator!=(Kvector& v, Kvector& c){
    if(v.length==c.length){
        for(int i=0; i<v.length; i++){
            if(v.m[i]!=c.m[i]) return true;
        }
        return false;
    }
    else return true;
}
Kvector& Kvector::operator=(Kvector& v){
    if(this != &v){
        delete[] m;
        length = v.length;
        m = new int[length];
        for(int i = 0; i < length; i++){
            m[i] = v.m[i];
        }
    }
    return *this;
}

ostream& operator<<(ostream& os, Kvector& v){
    for(int i=0; i<v.length; i++){
        os << v.m[i] << " ";
    }
    return os;
}

 int& Kvector::operator[](int idx){
     return m[idx];

 }
Kvector::Kvector(int size,int value):length(size){
        cout << this << " : Kvector(" << size << "," << value << ")\n";
    if(!size){m = NULL; return;}
    m = new int[size];
    for (int i = 0; i< size; i++) m[i] = value;
}
Kvector::Kvector(const Kvector&v){
    cout << this << " : Kvector(* " << &v << ")\n";
    length = v.length;
    if(!length){m = NULL; return;}
    m = new int [length];
    for(int i = 0; i<length; i++) m[i] = v.m[i];
}




Kvector::~Kvector(){
    cout << this << " : ~Kvector() \n";
    delete[] m; 
}

void Kvector::print(){
    for(int i=0; i<length; i++){
        cout << m[i] << " ";
    }
    cout << endl;
}

void Kvector::print() const {
    for(int i=0; i<length; i++){
        cout << m[i] << " ";
    }
    cout << endl;
}



void Kvector::clear(){
    delete[] m;
    m = NULL;
    length = 0; 
}

int Kvector::size(){
    return length;
}
int main(int argc, char *argv[]){
    if (argc != 2){
        cout << "usage : ./avctor pqr" << endl;
    }
    Avector v1(3); v1.print();
    Avector v2(2, 1, "xyz"); v2.print();
    Avector v3(v2); v3.print();
    cout << "v1 == v2 " <<(v1 == v2) << endl;
    cout << "v3 == v2 " << (v3 == v2) << endl;
    v3 = v2 = v1;
    cout << "v1 = " << v1 << endl;
    v1.print();
    cout << "v2 = " << v2 << endl;
    v2.print();
    cout << "v3 = " << v3 << endl;
    v3.print();
    cout << "v3 != v2 " << (v3 != v2) << endl;
    v1[2] = 2;
    v2[0] = v1[2];
    v1.setTable(argv[1]);
    cout << "v1: " << v1 << "v2: " << v2 << "v3: " << v3 << endl;
    v1.print();
    v2.print();
    v3.print();
    return 0;
}