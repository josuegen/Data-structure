/*Función para imprimir los elementos de un arbol en pre orden, el nodo 'root' apunta a la raíz del arbol*/
/*Function to print the elements of a tree in preorder way,the node 'root' points to the root of the tree*/



/*Node is defined as  

struct node
{
    int data;
    node* left;
    node* right;
};

*/


void preOrder(node *root) {
    if(root!=NULL){ 
        printf("%i ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
    
}
