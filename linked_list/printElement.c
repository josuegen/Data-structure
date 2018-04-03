// el nodo 'head' apunta a el primer elemento en la lista ligada, puedes cambiarlo por el nombre que tú tengas en este nodo
//the node 'head' points to the fisrt node in the linked list u can change it 

void Print(Node *head)
{
  Node *aux;
  aux=head;
  if(aux!=NULL){
      while(aux){
          printf("%i\n",aux->data);
          aux=aux->next;
      }
  }
}
