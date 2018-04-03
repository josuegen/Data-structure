/*Función para insertar un nodo en la posición n, el nodo 'head' apunta al primer elemento de la lista, el entero 'data' es la información 
que contiene el nodo, el entero 'position' es la posición en la que se insertará el nodo */
/*Function to insert a node at the Nth position, the node 'head' points to the first element in the linked list, the integer 'data' is the 
information that contains the node and the integer 'position' is the position that the node will be inserted in*/

Node* InsertNth(Node *head, int data, int position)
{
    Node *n,*aux;
    n=(Node *)malloc(sizeof(Node));
    n->data=data;
    n->next=NULL;
    aux=head;
    if(position==0){
        n->next=head;
        head=n;
    }
    else{
        for(int i=0;i<position-1;i++){
            aux=aux->next;
        }
        n->next=aux->next;
        aux->next=n;
    }
    return head;
}
