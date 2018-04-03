/*Función para eliminar nodos con información duplicada, el nodo 'head' apunta al primer nodo en la lista*/
/*Function to delete the nodes with duplicate data, the node 'head' points to the first node in the list*/

/*Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/

Node* RemoveDuplicates(Node *head)
{
    Node *aux;
    Node *supr;
    aux=head;
    if(head==NULL && head->next==NULL){
        return NULL;
    }
    else{
        while(aux->next!=NULL){
            if(aux->data==aux->next->data){
                supr=aux->next;
                aux->next=supr->next;
                free(supr);
            }
            else{
                aux=aux->next;
            }
        }
        return head;
    }
