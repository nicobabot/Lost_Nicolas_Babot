#ifndef _DMYLIST_H_
#define _DMYLIST_H_
typedef unsigned int uint;
template<class TYPE>
class Dlist{
public:
	class DNodo{
	public:
		TYPE data;
		DNodo *next = nullptr;
		DNodo *previous = nullptr;
	public:
		DNodo(const TYPE &data) : data(data){
		}

	};
	DNodo *first;
public:
	Dlist(){
	}
	bool empty()const{
		return first == nullptr;
	}
	unsigned int Size()const{
		unsigned int i = 0;
		DNodo  *temp = first;
		while (temp != nullptr){
			temp = temp->next;
			i++;
		}
		return i;
	}
	DNodo* end()const{
		DNodo  *temp = first;
		while (temp != nullptr){
			if (temp->next == nullptr){
				return temp;
			}
			temp = temp->next;
		}
	}

	void pushback(const TYPE &data){
		DNodo* temp = first;
		DNodo* nnode = new DNodo(data);
		if (temp == nullptr){
			first = nnode;
		}
		else{
			while (temp->next != nullptr){
				temp = temp->next;
			}
			temp->next = nnode;
			nnode->previous = temp;
		}
	}

	void pushfront(const TYPE &data){
		DNodo* temp = first;
		DNodo* nnode = new DNodo(data);
		if (temp == nullptr){
			first = nnode;
		}
		else{
			nnode->next = temp;
			temp->previous = nnode;
			first = nnode;
		}
	}

	void pop_back(){
		if (first != nullptr){
			if (first->next != nullptr){
				DNodo* temp = first;
				DNodo* temp2 = first;
				while (temp->next != nullptr){
					temp = temp->next;
				}
				while (temp2->next != temp){
					temp2 = temp2->next;
				}
				temp2->next = nullptr;
				delete temp;
			}
			else{
				DNodo* temp = first;
				first = nullptr;
				delete temp;

			}
		}
	}

	bool pop_front(){
		DNodo* temp = first;
		if (first != nullptr){
			if (first != nullptr && first->next != nullptr){
				first = first->next;
				first->previous = nullptr;
				delete temp;

			}
			else{
				DNodo* temp = first;
				first = nullptr;
				delete temp;
			}
			return true;
		}
		return false;
	}

	void erase(DNodo* othernode){
		if (Size() > 1 && othernode != first){
			if (othernode->previous == nullptr){
				first = othernode->next;
				first->previous = nullptr;
			}
			else if (othernode->next == nullptr){
				othernode->previous->next = nullptr;
			}
			else{
				othernode->previous->next = othernode->next;
				othernode->next->previous = othernode->previous;
			}
			delete othernode;
		}
		else{
			first = nullptr;
			delete othernode;
		}
	}

	void insert(DNodo* newnodo, TYPE Data){
		DNodo* nnode = new DNodo(Data);
		if (first != nullptr){
			if (newnodo->previous == nullptr){
				nnode->next = newnodo;
				newnodo->previous = nnode;
				first = nnode;
			}
			else{
				nnode->previous = newnodo->previous;
				newnodo->previous->next = nnode;
				newnodo->previous = nnode;
				nnode->next = newnodo;
			}
		}
		else{
			first = nnode;
		}
	}
	//SWAP

};
#endif