/*Función para imprimir los nodos de un arbol en post orden, el nodo 'root' apunta a la raíz del nodo*/
/*Function to print the nodes of a tree in postorder way, the node 'root' points to the roor of the tree*/
/* 
Node is defined as  
struct node
{
    int data;
    node* left;
    node* right;
};
*/

void postOrder(node *root) {
    if(root!=NULL)
    {
     postOrder(root->left);
     postOrder(root->right);
     printf("%i ",root->data);
    }
    
}
