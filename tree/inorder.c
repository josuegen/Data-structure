/*Función para imprimir nodos de un arbol en orden, el nodo'root' apunta  la raíz del árbol*/
/*Function to print the nodes of a tree inorder way, the node 'root' points to the root of the tree*/


/*
Node is defined as  
struct node
{
    int data;
    node* left;
    node* right;
};

*/

void inOrder(node *root) {
    if(root!=NULL){
        inOrder(root->left);
        printf("%i ",root->data);
        inOrder(root->right);
    }
}
