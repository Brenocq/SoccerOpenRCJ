#include "Classes/List.h" // designed by Deitel


// construtor padr�o
template< typename NODETYPE >
List< NODETYPE >::List()
	: firstPtr(0), lastPtr(0)
{
	// corpo vazio
} // fim do construtor List

// destrutor
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

// insere n� na frente da lista
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

// insere n� no fim da lista
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

// exclui n� da frente da lista
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

// exclui n� do fim da lista
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

// List est� vazia?
template< typename NODETYPE >
bool List< NODETYPE >::isEmpty() const
{
	return firstPtr == 0;
} // fim da fun��o isEmpty

// retorna ponteiro para n� recentemente alocado
template< typename NODETYPE >
ListNode< NODETYPE > *List< NODETYPE >::getNewNode(
	const NODETYPE &value)
{
	return new ListNode< NODETYPE >(value);
} // fim da fun��o getNewNode

// exibe o conte�do de List
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