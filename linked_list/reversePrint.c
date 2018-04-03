/*Función para imprimir en reversa los elementos de la lista, el nodo 'head' apunta al primer nodo de la lista*/
/*Function to print in reverse the nodes in the list, the node 'head' points to the first node in the list*/



void ReversePrint(Node *head)
{
    if(head!=NULL)
    {
        ReversePrint(head->next);
        printf("%i\n",head->data);
    }
}
