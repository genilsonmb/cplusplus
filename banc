#include <iostream>
#include <string>
using namespace std;

static int tempo=0;

class Cliente{
	string nome;
	int tempoChegada;//minutos redondos
	int duracaoServico;//minutos redondos
protected:
	Cliente(string,int,int);

public:
	Cliente();
	~Cliente();
	string getNome();
	int gettempoChegada();
	int getduracaoServico();
};

Cliente::Cliente(string nome, int tempoChegada,int duracaoServico):
	nome(nome),tempoChegada(tempoChegada),duracaoServico(duracaoServico){}
Cliente::~Cliente(){}
Cliente::Cliente(){}
string Cliente::getNome(){
	return nome;
}
int Cliente::gettempoChegada(){
	return tempoChegada;
}
int Cliente::getduracaoServico(){
	return duracaoServico;
}

class ClienteComum:public Cliente{
	int tempoEsperaMax;
public:
	ClienteComum(string,int,int,int);
	~ClienteComum();
	int gettempoEsperaMax();
};

ClienteComum::ClienteComum(string nome, int tempoChegada,int duracaoServico,int tempoEsperaMax):
	Cliente(nome,tempoChegada,duracaoServico),tempoEsperaMax(tempoEsperaMax){}
ClienteComum::~ClienteComum(){}
int ClienteComum::gettempoEsperaMax(){
	return tempoEsperaMax;
}

class ClientePreferencial:public Cliente{
	int tempoEsperaMax;
	public:
		ClientePreferencial(string,int,int);
		~ClientePreferencial();
};
ClientePreferencial::ClientePreferencial(string nome, int tempoChegada, int duracaoServico):
	Cliente(nome,tempoChegada,duracaoServico),tempoEsperaMax(0){}
ClientePreferencial::~ClientePreferencial(){}

class Banco{
	int capacidadeMax;
	int nclientes;

public:
	Cliente **clientes;
	Banco(int);
	~Banco();
	bool adicionarCliente(ClienteComum &cl);
	bool adicionarCliente(ClientePreferencial &cl);
	bool simular();
	bool ordenar();
};
Banco::Banco(int capacidadeMax):capacidadeMax(capacidadeMax),nclientes(0){
	clientes = new Cliente*[capacidadeMax];
	}
Banco::~Banco(){}
bool Banco::adicionarCliente(ClientePreferencial &cl){
		if (nclientes == capacidadeMax){
			cout << "Capacidade maxima do banco alcancada.\n";
			
			return false;}
		else {
		clientes[nclientes] = &cl;
		nclientes++;
		ordenar();
		return true;
		}
	}
bool Banco::adicionarCliente(ClienteComum &cl){
		if (nclientes == capacidadeMax){
			cout << "Capacidade maxima do banco alcancada.\n";
			return false;}
		else {
		clientes[nclientes] = &cl;
		nclientes++;
		ordenar();
		return true;
		}

}
bool Banco::ordenar(){
	Cliente aux;
	for (int i = 0 ; i < nclientes-1 ; i++){
		for (int j = 0 ; j < nclientes-1 ; j++ ) {
		if ( clientes[j]->gettempoChegada() > clientes[j+1]->gettempoChegada() ){
			aux = *(clientes[j+1]);
			*(clientes[j+1]) = *(clientes[j]);
			*(clientes[j]) = aux;
			}	
		}
	}	
return false;
}

int main()
{
	Cliente A;
	
	ClienteComum cc1("Joao",1,3,5);
	ClienteComum cc2("Mario",10,3,5);
	ClienteComum cc3("Estegonatel",30,3,5);
	ClienteComum cc4("Julia",20,50,5);
	Banco b(5);
	ClientePreferencial cp1("Roberto",5,2);
	b.adicionarCliente(cc1);
	b.adicionarCliente(cc2);
	b.adicionarCliente(cc3);
	b.adicionarCliente(cc4);
	b.adicionarCliente(cp1);
	A = cc1;
	cout << b.clientes[0]->getNome() << endl;
	cout << b.clientes[1]->getNome() << endl;
	cout << b.clientes[2]->getNome() << endl;
	cout << b.clientes[3]->getNome() << endl;		
	cout << b.clientes[4]->getNome() << endl;	
	return 0;
}

