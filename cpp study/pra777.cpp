#include<iostream>
#include<string.h>

using namespace std;

class Kvector
{
  int *p;
  int len;
public:
  static int total_len;
  Kvector(int size = 0, int value = 0);
  Kvector(const Kvector& v);
  ~Kvector();
  void print()const;
  void clear();
  int size();
};

Kvector::Kvector(int size,int value):len(size)
{
  cout << this << " : Kvector(int) \n";
  total_len += size;
  if(len)
  {
    p = new int[len];
    for(int i = 0; i < len; i++)
    {
      p[i] = value;
    }
  }
  else
  {
    p = NULL;
  }
}

Kvector::Kvector(const Kvector& v)
{
  cout << this << " : Kvector(Kvector&) \n";
  len = v.len;
  total_len += len;

  if(len)
  {
    p = new int[len];
    memcpy(p, v.p, sizeof(int) * len);
  }
  else
  {
    p = NULL;
  }
}

Kvector::~Kvector()
{
  cout << this << " : ~Kvector() \n";
  total_len -= len;
  delete[] p;
}

void Kvector::print() const
{
  for(int i = 0; i < len; i++)
  {
    cout << p[i] << " ";
  }
  cout << endl;
}

void Kvector::clear()
{
  delete[] p;
  p = NULL;
  len = 0;
}

int Kvector::total_len = 0;

int Kvector::size()
{
  return len;
}

int main()
{
  Kvector v1(3);
  v1.print();

  const Kvector v2(2,9);
  v2.print();

  Kvector v3(v2);
  v3.print();

  cout << "total_len: " << Kvector::total_len << endl;
  v2.print();
  v3.print();
  cout << "total_len: " << Kvector::total_len << endl;
  return 0;
}