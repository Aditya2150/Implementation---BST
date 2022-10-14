// BINARY SEARCH TREE IMPLEMENTATION IN C++
#include<bits/stdc++.h>
using namespace std;
define ix int;

// BST Class
template<class T>
class BST{
    // Node Class
    class Node{
    public:    
        T data;//data of Node
        Node* left; //left pointer
        Node* right;// right pointer

        Node() // Default Constructer
        {
            left=NULL;
            right=NULL;
        }
        Node(T x) // Parameterized Constructor
        {
            data=x;
            left=NULL;
            right=NULL;
        }
        ~Node() // Destructor
        {
            cout << "NODE DESTROYED!!!\n";
        }
    };
    // PRIVATE
    // Member Functions
    Node* insertion(Node*,T);
    Node* deletion(Node*,T);
    void preorder(Node*);
    void inorder(Node*);
    void postorder(Node*);
    Node* findMin(Node*);
    Node* findMax(Node*);
    bool isEmpty();
    // Data Members
    unordered_map<T,T>m;
    Node* head=NULL;
public:
    // PUBLIC
    BST() // Default Constructor
    {
        cout << "\n\n..............Welcome to BST Implementation..............\n\n";
    }
    ~BST() // Destructor
    {
        cout << "\n\n..............THE END!!!!..............\n\n";
    }
    // Member Functions
    void insert();
    void deleteNode();
    void Traversals();
    void Top();
};

// Wrapper Function for Insertion Opertaion..
template<typename T>
void BST<T>::insert()
{
    cout << "Insert--> ";
    T val;
    cin >> val;
    // Checks for Duplicate Element..
    if(m.find(val)==m.end())
    {
        head=insertion(head,val);
        // Insert into the Map.
        m[val]=1;
        return;
    }
    cout << "Element Already Exist in BST!!!!!\n";
}

// Insert Function to Insert Node in the BST..
template<typename T>
typename BST<T>::Node* BST<T>::insertion(Node* root,T val)
{
    if(root==NULL)
        root=new Node(val);
    else if(root->data<val)
        root->right=insertion(root->right,val);
    else
        root->left=insertion(root->left,val);
    return root;    
}

// Wrapper Function for Deletion Opertaion..
template<typename T>
void BST<T>:: deleteNode()
{
    if(!isEmpty())
    {
        cout << "Delete--> ";
        T val;
        cin >> val;
        // Checks if Node exist in BST
        if(m.find(val)==m.end())
            cout << "Node doesn't EXIST!!!\n";
        else
        {
            head=deletion(head,val);
            // Then erase it from the Map as well.
            m.erase(val);
        }    
    }    
}

// Delete Function to Delete node from the BST..
template<typename T>
typename BST<T>::Node* BST<T>::deletion(Node* root,T val)
{
    if(root->data>val) // if root->data is greater than value then goto left
    root->left=deletion(root->left,val); 
    else if(root->data<val) // if root->data is lesser than value then goto right
    root->right=deletion(root->right,val);
    else
    {
        // Case-1 (0- Child)
        if(root->left==NULL && root->right==NULL)
        {
            delete(root);
            root=NULL;
            return root;
        }
        // Case-1 (1- Child(RIGHT))
        else if (root->left==NULL) 
        {
            Node* temp=root;
            root=root->right;
            delete(temp);
            return root;
        }
        // Case-1 (1- Child(LEFT))
        else if (root->right==NULL) 
        {
            Node* temp=root;
            root=root->left;
            delete(temp);
            return root;
        }
        // Case-1 (2- Child)
        else
        {
            cout << "DELETE Node according to--> \n";
            cout << "1- INORDER PREDECESSOR\n";
            cout << "2- INORDER SUCCESSOR\n";
            int x;
            cout << "Enter--> ";
            cin >> x;
            while(x<1 || x>2)
            {
                cout << "Enter a Valid Input...\n";
                cout << "Enter--> ";
                cin >> x;
            } 
            Node* temp=NULL;
            if(x==1) // Using INORDER PREDECESSOR
            {
                temp=findMax(root->left);
                root->data=temp->data;
                root->left=deletion(root->left,temp->data);
            }
            else if(x==2) // Using INORDER SUCCESSOR
            {
                temp=findMin(root->right);
                root->data=temp->data;
                root->right=deletion(root->right,temp->data);
            }
        }
    }
    return root;
}

// Finds the Minimum from the SubTree
template<typename T>
typename BST<T>::Node* BST<T>::findMin(Node* root)
{
    while(root->left!=NULL)
    root=root->left;
    return root;   
}

// Finds the Maximum from the SubTree
template<typename T>
typename BST<T>::Node* BST<T>::findMax(Node* root)
{
    while(root->right!=NULL)
    root=root->right;
    return root;   
}

//  Traversals in the BST
template<typename T>
void BST<T>::Traversals()
{
    if(!isEmpty())
    {    
        cout << "1-PREORDER TRAVERSAL\n";
        cout << "2-INORDER TRAVERSAL\n";
        cout << "3-POSTORDER TRAVERSAL\n";
        cout << "Select Option--> ";
        int opt;
        cin >> opt;
        switch (opt)
        {
        case 1:
            cout << "\nPre-Order--> ";
            preorder(head);
            break;
        case 2:
            cout << "\nIn-Order--> ";
            inorder(head);
            break;
        case 3:
            cout << "\nPost-Order--> ";
            postorder(head);
            break;
        default:
            cout << "\nInvalid Option...";
            break;
        }
        cout << endl << endl;
    }
}

// Implements INORDER Traversal
template<typename T>
void BST<T>::inorder(Node* root)
{
    if(root==NULL)
    return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Implements POSTORDER Traversal
template<typename T>
void BST<T>::postorder(Node* root)
{
    if(root==NULL)
    return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}




// Driver Code
int main()
{
    BST<int>obj; // Object of BST Class.
    cout << "# INSTRUCTIONS--> \n";
    cout << "1- Insert\n";
    cout << "2- Delete\n";
    cout << "3- Traversals\n";
    cout << "4- Top\n";
    cout << "Any Character to EXIT!\n\n";
    int n;
    cout << "Enter--> ";
    while(cin >> n)
    {
        if(n==1)
            obj.insert(); // Calling Insert Function
        else if(n==2)
            obj.deleteNode(); // Calling Delete Function
        else if(n==3)
            obj.Traversals(); // Calling Traversal Function
        else if(n==4)
            obj.Top(); // Calling Top Function
        else
            cout << "Choose VALID OPTION!!!\n";    
        cout << "Enter--> ";
    }
    // delete(obj);
    return 0;
}

// Finds the Root/Top Node from the BST.
template<typename T>
void BST<T>::Top()
{
    cout << "Top Element--> " << head->data << endl;
}

//  Checks if the BST is Empty or NOT..
template<typename T>
bool BST<T>::isEmpty()
{
    if(head==NULL)
    {
        cout << "\nBST is Empty...\n\n";
        return true;
    }
    return false;
}
Footer
