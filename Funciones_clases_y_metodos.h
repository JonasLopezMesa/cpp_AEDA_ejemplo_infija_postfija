using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#define length(x) (sizeof(x)/sizeof(x[0]))

//CLASE DATO.......................................................................................................
//.................................................................................................................

class TDato{
private:
	int dato_;
public:
	TDato();
	~TDato();
	void write();
	void setcode(int c);
	int getcode();

};
TDato::TDato() : dato_(0) {}
TDato::~TDato() {}

void TDato::setcode(int c)
{
	dato_ = c;
}

int TDato::getcode()
{
	return dato_;
}
void TDato::write (void)
{
	cout << "dato en pila:  ";
	cout << dato_ << endl;
}



//CLASE ELEMENTO LISTA.............................................................................................
//.................................................................................................................

class sll_item {
private:
	sll_item* next_;
	TDato dato_;
	//int key_;
public:
	sll_item();
	sll_item(TDato dato);
	~sll_item();
	void setnext(sll_item* n);
	sll_item* getnext();
	void setDato(TDato d);
	TDato& getDato();
	
};


sll_item::sll_item() : next_ (NULL), dato_ () {}
sll_item::sll_item (TDato dato) : next_ (NULL), dato_ (dato) {}
sll_item::~sll_item()
{
	next_ = NULL;	
}

void sll_item::setnext(sll_item* n)
{
	next_ = n;	
}

sll_item* sll_item::getnext()
{
	return next_;
}

void sll_item::setDato(TDato d)
{
	dato_ = d;
}

TDato& sll_item::getDato()
{
	return dato_;
}





//CLASE LISTA......................................................................................................
//.................................................................................................................

class sll {
private:
	sll_item* inicio_;
public:
	sll();
	~sll();
	bool empty();											//si esta vacio 0 o no 1
	void insert_b(sll_item* i);								//insertar por el principio
	sll_item* remove_b();															//insertar de forma ordenada
	void imprimir();
	sll_item* first(void);

	
	
};


sll::sll(void) : inicio_(NULL) {}				//inicializar la lista
sll::~sll()										//Destructor
{
	sll_item* aux = NULL;
	while (inicio_ != NULL) {
		aux = inicio_;
		inicio_ = inicio_->getnext();
		delete aux;
	}
}

bool sll::empty()								//ver si la lista está vacía
{
	if (inicio_ == NULL) {	//esta vacío
		return true;
	}
	else {					//no está vacío
		return false;
	}
	
}

void sll::insert_b(sll_item* i)					//insertar por el principio
{
	i->setnext(inicio_);
	inicio_ = i;
}

sll_item* sll::remove_b()						//borrar por el principio
{
	//si la lista está vacía no extraemos nada
	if (inicio_ == NULL) {
		cout << "la lista está vacía" << endl;
		return NULL;
	}
	else {
		sll_item* aux = inicio_;
		inicio_ = inicio_->getnext();
		return aux;
	}
}




sll_item* sll::first(void)
{
	return inicio_;
}

void sll::imprimir()							//mostrar por pantalla
{
	int i = 1;
	sll_item* aux = inicio_;
	while (aux != NULL) {

		aux->getDato().write();
		aux = aux->getnext();
		
		i++;
	}
	
}


//CLASE PILA.......................................................................................................
//.................................................................................................................

class pila
{
private:
	sll lista_;
	
public:
	pila();
	~pila(void);
	bool empty(void);
	void push(TDato c);
	TDato pop(void);
	TDato top(void);
	void imprimir();
};

pila::pila() : lista_() {}         //constructor
pila::~pila() {}                        //destructor
bool pila::empty()
{
	return lista_.empty();
}
void pila::push(TDato c)
{
	sll_item* aux = new sll_item(c);
	lista_.insert_b(aux);
}
TDato pila::pop(void)
{
	sll_item* aux = lista_.remove_b();
	TDato c = aux->getDato();
	delete aux;
	return c;
}
TDato pila::top()
{
	return lista_.first()->getDato();
}
void pila::imprimir()
{
	lista_.imprimir();
}



//CLASE INFIJA2POSTFiJA............................................................................................
//.................................................................................................................

class infija2posfija
{
private:
	pila pila_;
	pila pila2_;
public:
	infija2posfija();
	~infija2posfija();
	char* i2p(char* r);

};

infija2posfija::infija2posfija() : pila_() {}
infija2posfija::~infija2posfija() {}
char* infija2posfija::i2p(char* str3)
{
	char operators[] = "+-x/^(";			//operadores
	int in_stack[] = {1,1,2,2,3,0};			//prioridad de entrada
	int out_stack[] = {1,1,2,2,4,5};		//prioridad de salida
	
	
    
	int unc, ter;
	int i = 0;
	TDato entrada;
	TDato salida;

	
	char c;
	char op;
	char exit[] = "                              ";
	char parentesis = ')';
	
	for (i = 0; i < 14; i++) {
		pila_.imprimir();
		//cout << "iteracion número: " << i << endl;
		unc = 0;
		ter = 0;
		c = str3[i];
		if ((c>='0') && (c<= '9')){
			//cout << "el caracter es el número: " << c << endl;
			exit[i] = c;
			//cout << "el caracter es el número: " << exit[i] << endl;


		}else if (c==' '){
			//seguir leyendo ya que se trata de un caracter en blanco
			//cout << "el caracter es un espacio" << endl;
		}else{
			//cout << "el caracter es el signo: " << c << endl;
			int mn = 0;
			int rr = 0;
			op = str3[i];



			while (mn < 7 && rr == 0) {
				
				if (op == operators[mn]) {
					if (pila_.empty() == true) {
						//cout << "la pila esta vacía" << endl;
						//cout << "introduzco el signo " << c << " en la pila" << endl;
						entrada.setcode(mn);
						pila_.push(entrada);
						rr = 1;
						unc = 1;
						
	
					}
					if (pila_.empty() == false && unc == 0) {
						//cout << "la pila no esta vacía" << endl;
						
						if (mn == 5) {
							entrada.setcode(mn);
							pila_.push(entrada);
							ter = 1;
							rr = 1;
						}
						if (out_stack[mn] > in_stack[pila_.top().getcode()] && ter == 0) {
							cout << "valor de entrada: " << out_stack[mn] << endl;
							cout << "valor de la pila: " << in_stack[pila_.top().getcode()] << endl;
							entrada.setcode(mn);
							pila_.push(entrada);
							ter = 1;
							rr = 1;


						}
						if (in_stack[mn] <= out_stack[pila_.top().getcode()] && ter == 0) {
							cout << "valor de entrada: " << in_stack[mn] << endl;
							cout << "valor de la pila: " << out_stack[pila_.top().getcode()] << endl;
							//cout << "si la prioridad es menor o igual que la del signo de la cima saco el signo: " << operators[pila_.top().getcode()] << " de la cima" << endl;
							exit[i] = operators[pila_.pop().getcode()];
							mn--;


						}
					}
				}
				mn++;
			}
			
			if (op == parentesis) {
				//cout << "es parentesis derecho" << endl;
				int h = 0;
				int w = 0;
				int x = 0;
				while (h == 0) {
					while (w == 0) {
						
						
						exit[i] = operators[pila_.pop().getcode()];

						//cout << exit[i] << endl;
						if (pila_.top().getcode() == 5) {
							//cout << "paréntesis izquierdo" << endl;
							pila_.pop();
							//cout << "1" << endl;
							w = 1;
							x = 1;
						
						}
						//cout << "2" << endl;
						if (pila_.empty() == false) {
							
						
						if (pila_.top().getcode() != 5 && x == 0) {
							//cout << "no es parentesis izquierdo" << endl;
							if (pila_.empty() == false) {
								w = 0;
							}
							else {
								w = 1;
							}

						}
						}
							
					}
					h = 1;
				}
			}
			
		}

		
	}
	if (pila_.empty() == false) {
		//cout << "la pila aun no esta vacia" << endl;
		while (pila_.empty() == false) {
			//cout << exit[i] << endl;
			//cout << operators[pila_.top().getcode()] << endl;
			exit[i] = operators[pila_.pop().getcode()];
			
			//cout << exit[i] << endl;
			
			i++;
		}
	}
	
	cout << endl;
	cout << "notacion infija:   ";
	int tt = 0;
	while (tt < 14) {
		cout << str3[tt];
		tt++;
	}
	cout << endl;
	cout << "notacion postfija: ";
	tt = 0;
	while (tt < 31) {
		cout << exit[tt];
		tt++;
	}
	cout << endl;
	cout << endl;

	

	return 0; 

}













