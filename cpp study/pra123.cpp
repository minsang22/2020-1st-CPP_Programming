#include<iostream>
#include<string.h>

using namespace std;

class Kvector{
  int *p;
  int length;
public:
  Kvector(int size = 0, int value = 0);
  Kvector(Kvector& v);
  ~Kvector();
  void print();
  void clear();
  int size();
};

Kvector::Kvector(int size,int value):length(size){
    cout << this << " : Kvector(int) \n";

    if(length){
        p = new int[length];

        for(int i = 0; i < length; i++){
        p[i] = value;
        }
    }

    else{
        p = NULL;
    }

}

Kvector::Kvector(Kvector& v):length(v.length){
  cout << this << " : Kvector(Kvector&) \n";

  if(length){
    p = new int[length];
    memcpy(p, v.p, sizeof(int) * length);
  }

  else{
    p = NULL;
  }

}

Kvector::~Kvector(){
  cout << this << " : ~Kvector() \n";
  delete[] p;
}

void Kvector::print(){

  for(int i = 0; i < length; i++){
    cout << p[i] << " ";
  }

  cout <<length << endl;

}

void Kvector::clear(){
  delete[] p;
  p = NULL;
  length = 0;
}

int Kvector::size(){
  return length;
}

int main(){
  Kvector v1(3);
  v1.print();

  Kvector v2(2,9);
  v2.print();

  Kvector v3(v2);
  v3.print();

  v2.clear();
  v2.print();
  v3.print();

  return -1;

}