#include <iostream>

using namespace std;

class Pai{
	public:
	//tentar com "virtual void m1()" para verificar diferença
		virtual void m1(){
			cout << "PaiM1\n";
		}
		void m2() {
			m1();
			cout << "PaiM2\n";
			
		}
	
};

class Filho:public Pai{
public:
	void m1(){
		cout << "FilhoM1\n";
	}
	
	
};



int main()
{
	Pai p;
	p.m2();
	Filho f;
	f.m2();
	Filho f2;
	
	Pai *p1 = &f2;
	p1->m2();
	 
	Pai &p2 = f2;
	p2.m2();
	
	Pai p3 = f2;
	p3.m2();
	
	
	return 0;
}
