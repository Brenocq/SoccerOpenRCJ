///////////////////////////////////////////////////////////
//  Communication.cpp
//  Implementation of the Class Communication
//  Created on:      21-mar-2018 21:46:56
//  Original author: Breno Queiroz
///////////////////////////////////////////////////////////

#include "Communication.h"
#include <iostream>

//#include "List.h" // designed by Deitel

using namespace std;

Communication::Communication(){
	channel1 = new List< char >();
	channel2 = new List< char >();
}

Communication::~Communication(){

}

void Communication::write(const char byte, int channel){
	
	if (channel==1)
		channel1->insertAtBack(byte);
	else
		channel2->insertAtBack(byte);
}

char Communication::read(int channel)const{
	char returnVal = 0;

	if (channel == 1){
		channel1->removeFromFront(returnVal);
	}
	else{
		channel2->removeFromFront(returnVal);
	}
	return returnVal;
}

int Communication::available(int channel)const{
	int totalAvailable;
	if (channel == 1){
		return channel1->size();
	}
	else{
		return channel2->size();
	}
}

//---------- List(Book Deitel) ----------//

template< typename NODETYPE >
List< NODETYPE >::List()
	: firstPtr(0), lastPtr(0)
{
	// corpo vazio
} // fim do construtor List

template< typename NODETYPE >
List< NODETYPE >::~List()
{
	if (!isEmpty()) // List n�o est� vazia
	{
		cout << "Destroying nodes ...\n";

		ListNode< NODETYPE > *currentPtr = firstPtr;
		ListNode< NODETYPE > *tempPtr;

		while (currentPtr != 0) // exclui n�s restantes
		{
			tempPtr = currentPtr;
			cout << tempPtr->data << '\n';
			currentPtr = currentPtr->nextPtr;
			delete tempPtr;
		} // fim do while
	} // fim do if

	cout << "All nodes destroyed\n\n";
} // fim do destrutor List

template< typename NODETYPE >
void List< NODETYPE >::insertAtFront(const NODETYPE &value)
{
	ListNode< NODETYPE > *newPtr = getNewNode(value); // novo n�

	if (isEmpty()) // List est� vazia
		firstPtr = lastPtr = newPtr; // nova lista tem apenas um n�
	else // List n�o est� vazia
	{
		newPtr->nextPtr = firstPtr; // aponta novo n� para o primeiro n� anterior 
		firstPtr = newPtr; // aponta firstPtr para o novo n�
	} // fim de else
} // fim da fun��o insertAtFront

template< typename NODETYPE >
void List< NODETYPE >::insertAtBack(const NODETYPE &value)
{
	ListNode< NODETYPE > *newPtr = getNewNode(value); // novo n�

	if (isEmpty()) // List est� vazia
		firstPtr = lastPtr = newPtr; // nova lista tem apenas um n�
	else // List n�o est� vazia
	{
		lastPtr->nextPtr = newPtr; // atualiza o �ltimo n� anterior
		lastPtr = newPtr; // novo �ltimo n�
	} // fim de else
} // fim da fun��o insertAtBack

template< typename NODETYPE >
bool List< NODETYPE >::removeFromFront(NODETYPE &value)
{
	if (isEmpty()) // List est� vazia
		return false; // exclui malsucedido
	else
	{
		ListNode< NODETYPE > *tempPtr = firstPtr; // armazena tempPtr para excluir

		if (firstPtr == lastPtr)
			firstPtr = lastPtr = 0; // nenhum n� permanece depois da exclus�o
		else
			firstPtr = firstPtr->nextPtr; // aponta para segundo n� anterior

		value = tempPtr->data; // retorna os dados sendo removidos
		delete tempPtr; // reivindica n� frontal anterior
		return true; // exclus�o bem-sucedido
	} // fim de else
} // fim da fun��o removeFromFront

template< typename NODETYPE >
bool List< NODETYPE >::removeFromBack(NODETYPE &value)
{
	if (isEmpty()) // List est� vazia
		return false; // exclui malsucedido
	else
	{
		ListNode< NODETYPE > *tempPtr = lastPtr; // armazena tempPtr para excluir

		if (firstPtr == lastPtr) // List tem um elemento
			firstPtr = lastPtr = 0; // nenhum n� permanece depois da exclus�o
		else
		{
			ListNode< NODETYPE > *currentPtr = firstPtr;

			// localiza do segundo ao �ltimo elemento
			while (currentPtr->nextPtr != lastPtr)
				currentPtr = currentPtr->nextPtr; // move para pr�ximo n�

			lastPtr = currentPtr; // remove �ltimo n�
			currentPtr->nextPtr = 0; // esse � agora o �ltimo n�
		} // fim de else

		value = tempPtr->data; // retorna valor do �ltimo n� antigo
		delete tempPtr; // reivindica o primeiro �ltimo n�
		return true; // exclus�o bem-sucedido
	} // fim de else
} // fim da fun��o removeFromBack

template< typename NODETYPE >
bool List< NODETYPE >::isEmpty() const
{
	return firstPtr == 0;
} // fim da fun��o isEmpty

template< typename NODETYPE >
int List< NODETYPE >::size() const
{
	if (firstPtr == lastPtr)
		return 0;
	else{
		ListNode<NODETYPE> *currentPtr = firstPtr;
		int coutSize = 1;

		while (currentPtr->nextPtr != lastPtr){
			coutSize++;
			currentPtr = currentPtr->nextPtr;
		}

		return coutSize;
	}
} // fim da fun��o isEmpty

template< typename NODETYPE >
ListNode< NODETYPE > *List< NODETYPE >::getNewNode(
	const NODETYPE &value)
{
	return new ListNode< NODETYPE >(value);
} // fim da fun��o getNewNode

template< typename NODETYPE >
void List< NODETYPE >::print() const
{
	if (isEmpty()) // List est� vazia
	{
		cout << "The list is empty\n\n";
		return;
	} // fim do if

	ListNode< NODETYPE > *currentPtr = firstPtr;

	cout << "The list is: ";

	while (currentPtr != 0) // obt�m dados de elemento
	{
		cout << currentPtr->data << ' ';
		currentPtr = currentPtr->nextPtr;
	} // fim do while

	cout << "\n\n";
} // fim da fun��o print
