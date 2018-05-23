#include "SortedArray.h"


//Test metodi int

bool ordinamento_D(const int &a, const int &b) {
	//cout << "sto usando la funzione esterna per " << a << " e " << b << endl;
	return a < b;
}

bool ordinamento_C(const int &a, const int &b) {
	//cout << "sto usando la funzione esterna per " << a << " e " << b << endl;
	return a > b;
}

bool contaTutto(const int &a, const int &b) {
	return a == b;
}

bool contaTutton(const int &a, const int &b) {
	return a != b;
}
///////////////////////////////////////////////////////////////////////////////////////////////

//Test metodi char

bool ordinamentoC_D(const char &a, const char &b) {
	//cout << "sto usando la funzione esterna per " << a << " e " << b << endl;
	return a < b;
}

bool ordinamentoC_C(const char &a, const char &b) {
	//cout << "sto usando la funzione esterna per " << a << " e " << b << endl;
	return a > b;
}

bool contaTuttoC(const char &a, const char &b) {
	return a == b;
}

bool contaTuttonC(const char &a, const char &b) {
	return a != b;
}
///////////////////////////////////////////////////////////////////////////////////////////////

//Test metodi string

bool ordinamentoS_D(const string &a, const string &b) {
	//cout << "sto usando la funzione esterna per " << a << " e " << b << endl;
	return a < b;
}

bool ordinamentoS_C(const string &a, const string &b) {
	//cout << "sto usando la funzione esterna per " << a << " e " << b << endl;
	return a > b;
}

bool contaTuttoS(const string &a, const string &b) {
	return a == b;
}

bool contaTuttonS(const string &a, const string &b) {
	return a != b;
}


///////////////////////////////////////////////////////////////////////////////////////////////

//Test valori Interi
void testInt(){
	//array di interi
	SortedArray<int>a1(7);
	a1.addElement(5);
	a1.addElement(6);
	a1.addElement(10);
	a1.addElement(2);
	a1.addElement(5);
	a1.addElement(6);
	a1.addElement(10);
	a1.sortaConFunzione(&ordinamento_D);
	a1.sortaConFunzione(&ordinamento_C);
	find_count<int>(a1, 10, &contaTutto);
	find_count<int>(a1, 10, &contaTutton);
	cout << "operatore ():"<< endl<<a1(2) << endl;
	cout << "operatore []:"<< endl<<a1[1]<< endl;
	cout << "Numero dati contenuti:"<< endl<<a1.getHowMany()<< endl;	
	//a1(2);
	//a1[1];

	//iteratori array int
	for (SortedArray<int>::unsorted_const_iterator it = a1.ubegin(); it != a1.uend(); it++) {
		cout << "valore dell'unsorted_const_iterator An = " << *(it) << endl;
	}

	for (SortedArray<int>::const_iterator it = a1.begin(); it != a1.end(); it++) {
		cout << "valore dell'const_iterator Ap = " << *(it) << endl;
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////

//Test valori Char
void testChar(){
	//array di char
	SortedArray<char>a2(7);
	a2.addElement('c');
	a2.addElement('d');
	a2.addElement('v');
	a2.addElement('n');
	a2.sortaConFunzione(&ordinamentoC_D);
	a2.sortaConFunzione(&ordinamentoC_C);
	find_count<char>(a2, 'c', &contaTuttoC);
	find_count<char>(a2, 'c', &contaTuttonC);
	cout << "operatore ():"<< endl<<a2(2) << endl;
	cout << "operatore []:"<< endl<<a2[1]<< endl;
	cout << "Numero dati contenuti:"<< endl<<a2.getHowMany()<< endl;
	//a2(2);
	//a2[1];

	//iteratori array char
	for (SortedArray<char>::unsorted_const_iterator it = a2.ubegin(); it != a2.uend(); it++) {
		cout << "valore dell'unsorted_const_iterator An = " << *(it) << endl;
	}

	for (SortedArray<char>::const_iterator it = a2.begin(); it != a2.end(); it++) {
		cout << "valore dell'const_iterator Ap = " << *(it) << endl;
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////

//Test valori String
void testString(){
	//array di string
	SortedArray<string>a3(7);
	a3.addElement("ciao");
	a3.addElement("bye");
	a3.addElement("mamma");
	a3.addElement("papa");
	a3.sortaConFunzione(&ordinamentoS_D);
	a3.sortaConFunzione(&ordinamentoS_C);
	find_count<string>(a3, "ciao", &contaTuttoS);
	find_count<string>(a3, "ciao", &contaTuttonS);
	cout << "operatore ():"<< endl<<a3(2) << endl;
	cout << "operatore []:"<< endl<<a3[1]<< endl;
	cout << "Numero dati contenuti:"<< endl<<a3.getHowMany()<< endl;
	//a3(2);
	//a3[1];

	//iteratori array string
	for (SortedArray<string>::unsorted_const_iterator it = a3.ubegin(); it != a3.uend(); it++) {
		cout << "valore dell'unsorted_const_iterator An = " << *(it) << endl;
	}

	for (SortedArray<string>::const_iterator it = a3.begin(); it != a3.end(); it++) {
		cout << "valore dell'const_iterator Ap = " << *(it) << endl;
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////

//class Persona
class persona{

public:
	string nome;
	int anni;
	char genere;

	persona():nome(""),anni(0),genere(0){
	}

	persona(string nome,int anni,char genere){
		this->nome=nome;
		this->anni=anni;
		this->genere=genere;
	}
	
	~persona() {
		nome = "";
		anni = 0;
		genere= 0;
	}
		
};

///////////////////////////////////////////////////////////////////////////////////////////////

//Test metodi persona
//class persona;

bool ordinamentoP_D(const persona &a, const persona &b) {
	//cout << "sto usando la funzione esterna per " << a << " e " << b << endl;
	return a.anni < b.anni;
}

bool ordinamentoP_C(const persona &a, const persona &b) {
	//cout << "sto usando la funzione esterna per " << a << " e " << b << endl;
	return a.anni > b.anni;
}

bool contaTuttoP(const persona &a, const persona &b) {
	if (a.nome == b.nome && a.anni == b.anni && a.genere == b.genere){
		return true;
	}else{
		return false;
	}
}

bool contaTuttonP(const persona &a, const persona &b) {
		if (a.nome != b.nome || a.anni != b.anni || a.genere != b.genere){
		return true;
	}else{
		return false;
	}
}

std::ostream &operator<<(std::ostream &os, const persona &p){
  std::cout<<"("<<p.nome<<","<<p.anni<<","<<p.genere<<")";
  return os;
}

//Test valori Persona
void testPersona(){
	//array di Persona
	SortedArray<persona>a4(7);
	a4.addElement(persona("antonio", 20, 'M'));
	a4.addElement(persona("amilcare", 24, 'M'));
	a4.addElement(persona("giulia", 24, 'F'));
	a4.addElement(persona("sara", 25, 'F'));
	a4.sortaConFunzione(&ordinamentoP_D);
	a4.sortaConFunzione(&ordinamentoP_C);
	find_count<persona>(a4, persona("giulia", 24, 'F'), &contaTuttoP);
	find_count<persona>(a4, persona("sara",25,'F'), &contaTuttonP);
	cout << "operatore (): "<<a4(2)<< endl;
	cout << "operatore []:"<<a4[1]<< endl;
	//cout << "operatore ():"<< endl<<"Nome: "<<a4(2).nome << endl<<"Eta': "<<a4(2).anni<< endl<<"Genere: "<<a4(2).genere<< endl;
	//cout << "operatore []:"<< endl<<"Nome: "<<a4[1].nome << endl<<"Eta': "<<a4[1].anni<< endl<<"Genere: "<<a4[1].genere<< endl;
	cout << "Numero dati contenuti:"<< endl<<a4.getHowMany()<< endl;
	//a3(2);
	//a3[1];

	//iteratori array Persona
	for (SortedArray<persona>::unsorted_const_iterator it = a4.ubegin(); it != a4.uend(); it++) {
		cout << "valore dell'unsorted_const_iterator An = " << *(it) << endl;
	}

	for (SortedArray<persona>::const_iterator it = a4.begin(); it != a4.end(); it++) {
		cout << "valore dell'const_iterator Ap = " << *(it) << endl;
	}
}


//main 
int main() {

	testInt();
	testChar();	
	testString();
	testPersona();

}




