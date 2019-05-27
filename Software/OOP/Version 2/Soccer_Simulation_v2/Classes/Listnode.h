// Fig. 21.3: Listnode.h
// defini��o da template de classe ListNode.
#ifndef LISTNODE_H
#define LISTNODE_H

// declara��o antecipada da classe List necess�ria para anunciar essa classe
// List existe, portanto, pode ser utilizada na declara��o friend na linha 13
template< typename NODETYPE > class List;                                   

template< typename NODETYPE> 
class ListNode 
{
   friend class List< NODETYPE >; // torna List uma amiga (friend)

public:
   ListNode( const NODETYPE & ); // construtor
   NODETYPE getData() const; // retorna dados no n�
private:
   NODETYPE data; // dados
   ListNode< NODETYPE > *nextPtr; // pr�ximo n� na lista
}; // fim da classe ListNode

// construtor
template< typename NODETYPE> 
ListNode< NODETYPE >::ListNode( const NODETYPE &info )
   : data( info ), nextPtr( 0 )
{ 
   // corpo vazio
} // fim do construtor ListNode

// retorna c�pia de dados no n�
template< typename NODETYPE >
NODETYPE ListNode< NODETYPE >::getData() const 
{ 
   return data; 
} // fim da fun��o getData

#endif


/**************************************************************************
 * (C) Copyright 1992-2005 Deitel & Associates, Inc. e                    *
 * Pearson Education, Inc. Todos os direitos reservados                   *
 *                                                                        *
 * NOTA DE ISEN��O DE RESPONSABILIDADES: Os autores e o editor deste      *
 * livro empregaram seus melhores esfor�os na prepara��o do livro. Esses  *
 * esfor�os incluem o desenvolvimento, pesquisa e teste das teorias e     *
 * programas para determinar sua efic�cia. Os autores e o editor n�o      *
 * oferecem nenhum tipo de garantia, expl�cita ou implicitamente, com     *
 * refer�ncia a esses programas ou � documenta��o contida nesses livros.  *
 * Os autores e o editor n�o ser�o respons�veis por quaisquer danos,      *
 * acidentais ou conseq�entes, relacionados com ou provenientes do        *
 * fornecimento, desempenho ou utiliza��o desses programas.               *
 **************************************************************************/
