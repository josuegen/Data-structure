/*Función para insertar nodo al final de la lista simplemente ligada, el nodo 'head' apunta al primer elemento de la lista, el entero 'data'
  es la información del nodo*/
/*Function to insert a node at the tail of the linked list, the node 'head' points to the fisrt node, the integer 'data' is the content
of the node*/
  


Node* insertTail(Node *head,int data)
{
    Node *n;
    n=(Node *)malloc(sizeof(Node));
    n->data=data;
    n->next=NULL;
    Node *aux;
    aux=head;
    if(aux==NULL){
        head=n;
    }
    else{
        while(aux->next!=NULL){
            aux=aux->next;
        }
        aux->next=n;
    }
    return head;
}
