//
// Created by mattia93b on 19/03/18.
//
#ifndef SORTEDARRAY_H
#define SORTEDARRAY_H

#include <iostream>
#include <ostream>
#include <cstddef>// ptrdiff_t
#include <iterator> // categorie degli iterator
using namespace std;

/**
@file sortedArray.h 
@brief Dichiarazione della classe SortedArray
**/

/**
@brief Array di T

Classe che rappresenta un array di tipo T e un array di puntatori a T ordinato. 
La dimensione puo' essere scelta in fase di costruzione.
**/
template <typename T>
class SortedArray {
typedef unsigned int size_type;///< Definzione del tipo corrispondente a size
private:
	int dim, indice;
	T* An;
	T** Ap;


public:
	/**
		@brief Costruttore di default (METODO FONDAMENTALE)

		Costruttore di default per istanziare un SortedArray vuoto. E' l'unico costruttore
		che puo' essere usato per create un array di SortedArray!
	**/
	SortedArray() : dim(0), indice(0), An(0), Ap(0) {

	}

	/**
		@brief Costruttore secondario

		Costruttore secondario. Permette di istanziare un SortedArray con una data dimensione.
		@param dim Dimensione del dbuffer da istanziare 
	**/
	SortedArray(size_type _dim) :dim(0), indice(0), An(0), Ap(0) {
		try{
			this->dim = _dim;
			An = new T[dim];
			Ap = new T*[dim];
			cout << "Costrutore SIZE " << dim <<"\n";
		}catch(...){
			delete[] An;
			delete[] Ap;
			dim = 0;
			indice = 0;
			An = 0;
		}
	}

	/**
		@brief Accesso ai dati in scrittura 

		Metodo setter per aggiungere un elemento all'array. 

		@pre E' necessario che indice < size
		@param indice Indice della cella dell'array da scrivere
		@param e Valore da scrivere nella cella
	**/
	void addElement(T e) {

		if(indice < this->dim){
		An[indice] = e;
		Ap[indice] = &An[indice];
		this->indice = indice + 1;
		//cout << indice << "\n";
		}else{
		cout << "out of bound" << "\n";
		}
	}

	/**
		@brief Distruttore (METODO FONDAMENTALE)

		Distruttore. Rimuove la memoria allocata da SortedArray.
	**/
	~SortedArray() {
		delete[] An;
		delete[] Ap;
		dim = 0;
		indice = 0;
		An = 0;
	}

	/**
		@brief Sorting con funtori

		@param conta numero di ricorrenze
		@param fun funzione sorting
	**/
	void sortaConFunzione(bool(*fun)(const T &a, const T &b)) {
		T* s = 0;
		for (int n1 = 0; n1<indice; n1++) {
			for (int n2 = 0; n2<indice - n1 - 1; n2++) {
				//if (*(Ap[n2])>*(Ap[n2 + 1])) {  //Vecchio criterio di paragone
				if (fun(*Ap[n2], *(Ap[n2 + 1]))) { //nuovo criterio con funtore
					s = Ap[n2];
					Ap[n2] = Ap[n2 + 1];
					Ap[n2 + 1] = s;
				}
			}
		}
	}

	/**
		@brief Restituisce quanti dati continene l'array

		Metodo getter per leggere quanti dati continene l'array. 
	**/
	int getHowMany() {
		//cout << "INDICE:" << "\n";
		//cout << indice << "\n";
		return indice;
	}

	/**
		@brief Accesso ai dati in lettura (stile C++ con operatore)

		Metodo getter per leggere il valore index-esimo dell'array non ordinato. 

		@pre E' necessario che In < dim
		@param In Indice della cella dell'array da scrivere
	**/
	T operator()(int In) {
		//cout << "Operatore ()" << "\n";
		//cout << An[In] << "\n";
		return An[In];
	}
	
	/**
		@brief Accesso ai dati in lettura (stile C++ con operatore)

		Metodo getter per leggere il valore index-esimo dell'array ordinato. 

		@pre E' necessario che In < dim
		@param In Indice della cella dell'array da scrivere
	**/
	T operator[](int In) {
		//cout << "Operatore []" << "\n";
		//cout << *Ap[In] << "\n";
		return *Ap[In];
	}


///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
//							ITERATORI								 //
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class const_iterator;
class unsorted_const_iterator;

//UNSORTED CONST ITERATOR
class unsorted_const_iterator {
public:
	typedef std::forward_iterator_tag iterator_category;
	typedef T                         value_type;
	typedef ptrdiff_t                 difference_type;
	typedef const T*                  pointer;
	typedef const T&                  reference;

	unsorted_const_iterator() : ptr(0) {}
	unsorted_const_iterator(const unsorted_const_iterator &other) : ptr(other.ptr) {}
	unsorted_const_iterator& operator=(const unsorted_const_iterator &other) {
		ptr = other.ptr;
		return *this;
	}
	~unsorted_const_iterator() {}
	reference operator*() const { return *ptr; }
	pointer operator->() const { return ptr; }
	unsorted_const_iterator operator++(int) { unsorted_const_iterator tmp(ptr); ++ptr; return tmp; }
	unsorted_const_iterator& operator++() { ++ptr; return *this; }
	bool operator==(const unsorted_const_iterator &other) const { return other.ptr == ptr; }
	bool operator!=(const unsorted_const_iterator &other) const { return other.ptr != ptr; }
private:
	const T *ptr;
	friend class SortedArray;
	unsorted_const_iterator(const T*p) : ptr(p) {}
};

unsorted_const_iterator ubegin() const { return unsorted_const_iterator(An); }
unsorted_const_iterator uend() const { return unsorted_const_iterator(An + indice); }

//CONST ITERATOR
class const_iterator {
public:
	typedef std::forward_iterator_tag iterator_category;
	typedef T                        value_type;
	typedef ptrdiff_t                 difference_type;
	typedef const T*                 pointer;
	typedef const T&                  reference;

	const_iterator() : ptr(0) {}
	const_iterator(const const_iterator &other) : ptr(other.ptr) {}
	const_iterator& operator=(const const_iterator &other) {
		ptr = other.ptr;
		return *this;
	}
	~const_iterator() {}
	reference operator*() const { return **ptr; }
	pointer operator->() const { return ptr; }
	const_iterator operator++(int) { const_iterator tmp(ptr); ++ptr; return tmp; }
	const_iterator& operator++() { ++ptr; return *this; }
	bool operator==(const const_iterator &other) const { return other.ptr == ptr; }
	bool operator!=(const const_iterator &other) const { return other.ptr != ptr; }
private:
	T **ptr;
	friend class SortedArray;
	const_iterator(T**p) : ptr(p) {}
};

const_iterator begin() const { return const_iterator(Ap); }
const_iterator end() const { return const_iterator(Ap + indice); }



};

/**
	@brief Operatore di confronto

	dato un generico sortedarray SA che contiene dati di tipo T, 
	un valore target di tipo T, e un predicato binario P, 
	stampa a schermo il numero di valori contenuti in SA uguali 
	a target secondo il criterio definito da P.
	
	@param conta numero di ricorrenze
	@param foo funzione predicato binario
	@param arr SortedArray
	@param target valore con cui effettuare il confronto
	@return il numero di volte che il predicato è verificato
**/
template<typename Type>
int find_count(const SortedArray<Type>& arr, const Type target, bool(*foo)(const Type &a, const Type &b)) {
	int conta = 0;
	for (typename SortedArray<Type>::const_iterator it = arr.begin(); it != arr.end(); it++){
		if (foo(*(it), target)) { //nuovo criterio con funtore
			conta = conta + 1;
		}
	}
	cout << "funzione find_count:" << endl;
	cout << conta << "\n";
	return conta;
}

#endif //SORTEDARRAY_H
