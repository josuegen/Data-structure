/*Función para insertar un nodo en una lista doblemente ligada, ordenada; el nodo 'head' apunta al primer nodo en la lista, el 
entero 'data' es la información que contiene el nodo*/
/*Function to insert a node in an ordered doubly-linked list; the node 'head' points to the first node in the list, the integer
'data' is the information that the node contains*/



/*Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/


Node* SortedInsert(Node *head,int data)
{
    Node *n=(Node *)malloc(sizeof(Node));
    n->data=data;
    n->next=NULL;
    n->prev=NULL;
    Node *aux=head;
    Node *aux2;
    if(head==NULL){
        head=n;
        return n;
    }
    if(head->next==NULL){
        if(head->data>n->data){
            n->next=head;
            head->prev=n;
            head=n;
        }
        else{
            head->next=n;
            n->prev=head;
        }
        return head;
    }
    else{
        while(aux->next!=NULL){
            if(n->data>aux->data){
                aux=aux->next;
            }
            else{
                aux2=aux->prev;
                n->next=aux;
                n->prev=aux2;
                aux2->next=n;
                aux->prev=n;
            }
        }
        if(aux->next==NULL){
            if(aux->data>n->data){
                aux2=aux->prev;
                n->next=aux;
                n->prev=aux2;
                aux2->next=n;
                aux->prev=n;
            }
            else{
                aux->next=n;
                n->prev=aux;
            }
        }
        return head;
    }
    
    
}
