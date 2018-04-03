/*Función para eliminar un nodo en la posición n, el nodo 'head' apunta al primer nodo en la lista, el entero 'position' indica 
la posición del elemento a borrar dentro de la lista*/
/*Function to delete a node in the Nth position, the node 'head' points to the first node in the list, the integer 'position' is the
position where is the node that will be deleted*/


Node* Delete(Node *head, int position)
{
    Node *aux,*aux2,*del;
    aux=head;
    if(position==0){
        head=aux->next;
    }
    else{
        for(int i=0;i<position-1;i++){
            aux=aux->next;
        }
        del=aux->next;
        aux2=del->next;
        aux->next=aux2;
        free(del);
    }
    
    return head;
    
}
