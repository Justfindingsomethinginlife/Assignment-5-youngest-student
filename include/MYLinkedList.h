#ifndef MYLinkedList_H_
#define MYLinkedList_H_

#include <cassert>

namespace EGCI
{	
	template<typename T>
	struct ListNode
	{
		T data;

		ListNode<T>* next = nullptr;

		ListNode(T data);
	};

	template<typename T>
	struct DListNode
	{
		T data;

		DListNode<T>* next = nullptr;
		DListNode<T>* prev = nullptr;

		DListNode(T data);
	}

	template<typename T> 
	class LinkedList
	{
		private:
			ListNode<T>* head = nullptr;
		
		public:
			LinkedList(T data);
			~LinkedList();

			size_t len = 0;
			
			void insertK(T data, int k);
			void deleteK(int k);
			ListNode<T>* getNodeK(int k);
	};
	template<typename T> 
	class DoublyLinkedList
	{
		private:
			DListNode<T>* head = nullptr;
	
		public:
			DoublyLinkedList(T data);
			~DoublyLinkedList();

			size_t len = 0;
			
			void insertK(T data, int k);
			void deleteK(int k);
			DListNode<T>* getNodeK(int k);
	};

}

template<typename T>
EGCI::ListNode<T>::ListNode(T data)
{
	this->data = data;
	this->next = nullptr;
}

template<typename T>
EGCI::LinkedList<T>::LinkedList(T data)
{
	this->head = new ListNode<T>(data);
	len = 1;
}

template<typename T>
EGCI::LinkedList<T>::~LinkedList()
{
	while(head)
	{
		ListNode<T>* tmp = head;
		head=head->next;
		delete tmp;
	}
}

template<typename T> 
void EGCI::LinkedList<T>::insertK(T data, int k)
{
	ListNode<T>* tmp = this->head;
	

	if(k == 0)return;
	if(k > len)
	{
		for(int i=1;i<len;i++)tmp=tmp->next;
	}
	else for(int i=1;i<k;i++)tmp = tmp->next;
	
	len++;
	ListNode<T>* nex = new ListNode<T>(data);
	nex->next = tmp->next;
	tmp->next = nex;
}

template<typename T>
EGCI::ListNode<T>* EGCI::LinkedList<T>::getNodeK(int k)
{	
	ListNode<T>* tmp = head;
	if(k > len)
	{
		return NULL;
	}
	for(int i=0;i<k;i++)tmp = tmp->next;
	
	return tmp;
}


#endif
