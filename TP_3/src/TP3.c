#include <stdio.h>
#include <stdlib.h>

int main(void) {


	#ifndef __LINKEDLIST
	#define __LINKEDLIST
	struct Node
	{
	    void* pElement;
	    struct Node* pNextNode;
	}typedef Node;

	struct LinkedList
	{
	    Node* pFirstNode;
	    int size;
	}typedef LinkedList;
	#endif



	//Publicas
	LinkedList* ll_newLinkedList(void);
	int ll_len(LinkedList* self);
	Node* test_getNode(LinkedList* self, int nodeIndex);
	int test_addNode(LinkedList* self, int nodeIndex,void* pElement);
	int ll_add(LinkedList* self, void* element);
	void* ll_get(LinkedList* self, int index);
	int ll_set(LinkedList* self, int index,void* pElement);
	int ll_remove(LinkedList* self,int index);
	int ll_clear(LinkedList* self);
	int ll_deleteLinkedList(LinkedList* self);
	int ll_indexOf(LinkedList* self, void* pElement);
	int ll_isEmpty(LinkedList* self);
	int ll_push(LinkedList* self, int index, void* pElement);
	void* ll_pop(LinkedList* self,int index);
	int ll_contains(LinkedList* self, void* pElement);
	int ll_containsAll(LinkedList* self,LinkedList* this2);
	LinkedList* ll_subList(LinkedList* self,int from,int to);
	LinkedList* ll_clone(LinkedList* self);
	int ll_sort(LinkedList* self, int (*pFunc)(void* ,void*), int order);
	return EXIT_SUCCESS;
}
