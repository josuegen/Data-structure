/*Función para cambiar el orden de los apuntadores para que de esta manera el primer elemento se el nuevo último y el último elemento s
sea el nuevo primero*/
/*Function to change the next pointers of the nodes so that their order is reversed.*/


Node* Reverse(Node *head)
{
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node *restante=Reverse(head->next);
    head->next->next=head;
    head->next=NULL;
    return restante;
    
    
}
