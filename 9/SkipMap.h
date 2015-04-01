/*
 * SkipMap.h
 *
 *  Created on: Mar 22, 2015
 *      Author: MackO
 */

#ifndef SKIPMAP_H_
#define SKIPMAP_H_

#include <iostream>
#include <time.h>
using namespace std;

template <class type>
struct node{
	node<type>* prev;
	node<type>* next;
	node<type>* up;
	node<type>* down;
	type info;
	int key;
	bool boundry;
};

template <class type>
class SkipMap{
public:
	SkipMap(int newMaxHeight);
	~SkipMap();
	void insert(int newKey,type newInfo);
	void printAll();
	void remove(int searchkKey);
	type search(int searchKey);
	void deleteAll();
	bool isEmpty();

private:
	node<type>* searchForPtr(int searchKey);
	int ranNum();
	node<type>* getBottom(node<type>* startFrom);
	void  makeBoundries();

	node<type>* blankNode();


	node<type>* head;
	node<type>* tail;
	int   maxHeight;

};

template<class type>
bool SkipMap<type>::isEmpty(){
	return head == NULL;
}

template<class type>
void SkipMap<type>::deleteAll(){
	node<type>* searchPtr = head;
	bool forward = false;
	while(!isEmpty()){
		if(searchPtr->boundry){
			forward = (forward+1)%2;
			head = head->down;
			if(head != NULL)
				delete head->up;
		}

		if(!isEmpty()){
			if(!forward){
				head = head->prev;
				delete head->next;
			}
			else{
				head = head->next;
				delete head->prev;
			}
		}
	}
}

template<class type>
void SkipMap<type>::remove(int searchKey){
	 node<type>* searchedFor = searchForPtr(searchKey);
	 while(searchedFor->down != NULL){
		 searchedFor->next->prev = searchedFor->prev;
		 searchedFor->prev->next = searchedFor->next;
		 searchedFor = searchedFor->down;
		 delete searchedFor->up;
	 }
	 searchedFor->next->prev = searchedFor->prev;
	 searchedFor->prev->next = searchedFor->next;
	 delete searchedFor;
}

template<class type>
node<type>* SkipMap<type>::searchForPtr(int searchKey){
	node<type>* searchPtr = head;
	bool found = false;
	bool forward = false;
	while(!found){
		if(searchPtr->boundry){
			forward = (forward+1)%2;
			searchPtr = searchPtr->down;
		}
		else if(searchKey == searchPtr->key){
			found = true;
		}

		if(!found){
			if(!forward){
				searchPtr = searchPtr->prev;
			}
			else{
				searchPtr = searchPtr->next;
			}
		}
	}
	return searchPtr;
}

template<class type>
type SkipMap<type>::search(int searchKey){
	node<type>* searchPtr = head;
	bool found = false;
	bool forward = false;
	while(!found){
		if(searchPtr->boundry){
			forward = (forward+1)%2;
			searchPtr = searchPtr->down;
		}
		else if(searchKey == searchPtr->key){
			found = true;
		}

		if(!found){
			if(!forward){
				searchPtr = searchPtr->prev;
			}
			else{
				searchPtr = searchPtr->next;
			}
		}
	}
	return searchPtr->info;
}

template<class type>
void SkipMap<type>::printAll(){
	node<type>* temp = getBottom(head)->next;
	node<type>* temp2 = getBottom(tail);
	int count = 0;
	while(temp != temp2){
		cout << temp->info << "  " << temp->key << endl;
		while(temp->up != NULL){
			count ++;
			temp = temp->up;
		}
		temp = getBottom(temp);
		temp = temp->next;
		count = 0;
	}
}
template<class type>
SkipMap<type>::SkipMap(int newMaxHeight){
	maxHeight = newMaxHeight;
	makeBoundries();
	srand(time(NULL));
}

template<class type>
SkipMap<type>::~SkipMap(){
	deleteAll();
}

template<class type>
void SkipMap<type>::insert(int newKey,type newInfo){
	node<type>* temp = blankNode();
	node<type>* temp2;
	temp->key = newKey;
	temp->info = newInfo;
	int height = ranNum();
	node<type>* searchPtr = getBottom(head)->next;
	bool found = false;
	while(!found){
		if(newKey < searchPtr->key || searchPtr->boundry){
			found = true;

		}
		else if(newKey == searchPtr->key){
			node<type>* searchedFor = searchPtr;
			searchPtr = searchPtr->next;
			 while(searchedFor->up != NULL){
				 searchedFor->next->prev = searchedFor->prev;
				 searchedFor->prev->next = searchedFor->next;
				 searchedFor = searchedFor->up;
				 delete searchedFor->down;
			 }
			 searchedFor->next->prev = searchedFor->prev;
			 searchedFor->prev->next = searchedFor->next;
			 delete searchedFor;
		}
		else{
			searchPtr = searchPtr->next;
		}
	}

	temp->next = searchPtr;
	temp->prev = searchPtr->prev;
	searchPtr->prev->next = temp;
	searchPtr->prev = temp;

	for(int i = 1;i<height;i++){
		while(searchPtr->up == NULL){
			searchPtr = searchPtr->next;
		}
		searchPtr = searchPtr->up;
		temp2 = blankNode();
		temp2->key = newKey;
		temp2->info = newInfo;
		temp2->down = temp;
		temp2->next = searchPtr;
		temp2->prev = searchPtr->prev;
		searchPtr->prev->next = temp2;
		searchPtr->prev = temp2;
		temp->up = temp2;
		temp = temp2;
	}
}

template<class type>
node<type>* SkipMap<type>::getBottom(node<type>* startFrom){
	while(startFrom->down != NULL){
		startFrom = startFrom->down;
	}
	return startFrom;
}

template<class type>
int SkipMap<type>::ranNum(){
	return (rand() % maxHeight) + 1;
}

template<class type>
void SkipMap<type>::makeBoundries(){
	node<type>* temp;
	node<type>* temp2;
	head = blankNode();
	tail = blankNode();
	head->boundry = true;
	tail->boundry = true;
	head->next = tail;
	tail->prev = head;

	for(int i = 0;i<=maxHeight;i++){
		temp = blankNode();
		temp2 = blankNode();
		temp->boundry = true;
		temp2->boundry = true;
		temp->down = head;
		temp2->down = tail;
		temp->next = temp2;
		temp2->prev = temp;
		head->up = temp;
		tail->up = temp2;
		head = temp;
		tail = temp2;
	}
}

template<class type>
node<type>* SkipMap<type>::blankNode(){
	node<type>* temp = new node<type>;
	temp->key =0;
	temp->info=type();
	temp->next = NULL;
	temp->prev = NULL;
	temp->up = NULL;
	temp->down = NULL;
	temp->boundry = false;
	return temp;
}

#endif /* SKIPMAP_H_ */
