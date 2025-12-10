#include <iostream>
#include "BSTFunc.cpp"
using namespace std;

int main()
{
  node* root = NULL;
  int x;
  cout << "Enter value for root node: ";
    cin >> x;
    root = insert(root, x);

    for (int i = 0; i < 8; i++) {
        cout << "Enter value to insert in tree: ";
        cin >> x;
        insert(root, x);
    }

    cout << "Enter value to search in tree: ";
    cin >> x;
    cout << (search(root, x) ? "Found" : "Not Found") << endl;

    cout << "Enter value to delete in tree: ";
    cin >> x;
    root = deletenode(root, x);

    cout << "\nPreorder Traversal: ";
    preorder(root);
    cout << "\nInorder Traversal: ";
    inorder(root);
    cout << "\nPostorder Traversal: ";
    postorder(root);
    cout << endl;

    return 0;
}
