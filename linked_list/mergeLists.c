/*Función para unir 2 listas ordenadas, el nodo 'headA' apunta al primer nodo de la primer lista, el nodo 'headB' apunta al primer nodo de
la segunda lista*/
/*Function to merge 2 ordered linked lists, the node 'headA' points to the first node in the fisrt linked list, the node 'headB' points
to the first node in the second list*/


Node* MergeLists(Node *headA, Node* headB)
{
    Node *ret;
    if(headA==NULL && headB==NULL){
        return ret;
    }
    if((headA!=NULL)&&(headB==NULL))
    return headA;
    if((headA == NULL)&&(headB!=NULL))
    return headB;
    if(headA->data < headB->data)
    headA->next = MergeLists(headA->next, headB);
    else if(headA->data > headB->data)
    {
        Node* temp = headB;
        headB = headB->next;
        temp->next = headA;
        headA = temp;
        headA->next = MergeLists(headA->next, headB);
    }
    ret= headA;
    return ret;
  
   
}
