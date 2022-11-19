#include <iostream>

typedef struct node{
    int data;
    /*
    하나의 노드에서 왼쪽 자식 노드의 주소를 left_child 에 저장하고
    오른쪽 자식 노드의 주소를 right_child 변수에 저장한다.
    */
    node* left_child;
    node* right_child;    
}node;
void preorder_traversal(node* node){
    if(node){
        printf("%d ", node->data);
        preorder_traversal(node->left_child);
        preorder_traversal(node->right_child);
    }
}
void inorder_traversal(node* node){
    if(node){
        inorder_traversal(node->left_child);
        printf("%d ", node->data);
        inorder_traversal(node->right_child);
    }
}
void postorder_traversal(node* node){
    if(node){
        postorder_traversal(node->left_child);
        postorder_traversal(node->right_child);
        printf("%d ", node->data);
    }
}
int main(){
    // [1] initialise
    const int node_numbers = 15;
    node nodes[node_numbers + 1];
    
    for(int i = 1; i <= node_numbers; i++){
        nodes[i].data = i;
        /*
        아직 왼쪽, 오른쪽 자식으로 누구를 가져야하는지 모르기때문에
        nullptr을 넣어줌으로써 가르키는 메모리 주소가 없다고 한다.
        */
        nodes[i].left_child = nullptr;
        nodes[i].right_child = nullptr;
    }
    for(int i = 2; i <= node_numbers; i++){
        if(i % 2 == 0){
            nodes[i/2].left_child = &nodes[i];
        } else{
            nodes[i/2].right_child = &nodes[i];
        }
    }
    // [2] process
    printf("preorder traversal : ");
    preorder_traversal(&nodes[1]);
    printf("\n");

    printf("inorder traversal : ");
    inorder_traversal(&nodes[1]);
    printf("\n");

    printf("postorder traversal : ");
    postorder_traversal(&nodes[1]);
    printf("\n");
    return 0;
}