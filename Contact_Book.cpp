#include <iostream>
using namespace std;

struct Contact
{
    string name;
    string phoneNumber;
    Contact *left;
    Contact *right;

};
class BinarySearchTree
{
private: Contact* root;

   void insertNode(Contact *& tree, string name , string phoneNumber){
        if(tree==NULL)
        {
           tree = new Contact;
           tree -> name = name;
           tree -> phoneNumber = phoneNumber;
           tree -> left = NULL;
           tree -> right = NULL;
        }
        else if(phoneNumber<tree->phoneNumber){
           insertNode(tree->left, name, phoneNumber);
        }
        else{
           insertNode(tree->right,name,phoneNumber);
        }
   }
   void printInOrder(Contact *tree){
        if(tree == NULL){
           return;
        }
           cout << endl;

        printInOrder(tree ->left);
        cout << tree -> name << ", ";
        cout << tree -> phoneNumber << ", "<<endl;

        printInOrder(tree -> right);
        }
   int treeLength(Contact  *tree){
        if(tree == NULL)
        {
           return 0;
        }
        return 1+treeLength(tree -> left) + treeLength(tree -> right);
   }
   bool findNode(Contact *tree, string phoneNumber){
        if(tree == NULL){
           return false;
        }
        if(tree -> phoneNumber == phoneNumber){
           return true;
        }
        else if(phoneNumber < tree->phoneNumber)
        {
           return findNode(tree->left,phoneNumber);
        }
        else
        {
           return findNode(tree->right,phoneNumber);
        }
    }
    void RetrieveName(Contact *tree, string name){
        if(tree == NULL){
           return ;
        }
        if(tree -> name == name){
           cout<<endl;
           cout<<"Contact Found: "<<endl;
           cout<<endl;
           cout<< tree->name <<","<<tree -> phoneNumber <<endl;
        }
        else if(name < tree -> name)
        {
           return RetrieveName(tree -> left, name);
        }
        else
        {
           return RetrieveName(tree->right, name);
        }
    }
    void RetrievePhoneNumber(Contact *tree, string phoneNumber){
        if(tree == NULL){
            return ;
        }
        if(tree -> phoneNumber == phoneNumber)
        {   cout<<endl;
            cout<<"Contact Found: "<<endl;
            cout<<endl;
            cout << tree->name <<","<<tree -> phoneNumber <<endl;
        }
        else if(phoneNumber < tree -> phoneNumber)
        {
           return RetrievePhoneNumber(tree -> left, phoneNumber);
        }
        else
        {
           return RetrievePhoneNumber(tree -> right, phoneNumber);
        }
    }
    void deleteNode(Contact *&tree, string phoneNumber){
        if(tree == NULL){
                return;
        }
        if(tree -> phoneNumber == phoneNumber)
        {
            if(tree -> left == NULL && tree -> right == NULL)
            {
                delete tree;
                tree = NULL;
            }
            else if(tree -> left != NULL)
            {
                string maxLeftNode = findMaxNode(tree -> left);
                tree -> phoneNumber =  maxLeftNode;
                deleteNode(tree -> left,  maxLeftNode);
            }
            else
            {
                string minRightNode = findMinNode(tree -> right);
                tree -> phoneNumber=minRightNode;
                deleteNode(tree->right,minRightNode);
            }
        }
            else if(tree -> phoneNumber < phoneNumber)
            {
                deleteNode(tree -> right, phoneNumber);
            }
            else
            {
                deleteNode(tree -> left, phoneNumber);
            }
    }
    string findMinNode(Contact *tree){
            if(tree == NULL)
            {
                return "  -1  ";
            }
            else if(tree -> left == NULL)
            {
                return tree -> phoneNumber;
            }
            else
            {
                return findMinNode(tree->left);
            }
    }
    string findMaxNode(Contact *tree){
            if(tree == NULL)
            {
                    return " -1 ";
            }
            else if(tree->right==NULL)
            {
                return tree->phoneNumber;
            }
            else
            {
                return findMaxNode(tree->right);
            }
    }
    void makeEmpty(Contact  *&tree){
            if(tree == NULL)
                return;

            makeEmpty(tree -> left);
            makeEmpty(tree -> right);

            delete tree;
            tree = NULL;
       }

    int getHeight(Contact *tree){
            if(tree == NULL){
                return 0;
            }
            int lsh = 1+getHeight(tree->left);
            int rsh = 1+getHeight(tree->right);

            if(lsh > rsh){
                return lsh;
            }else{
                return rsh;
            }
        }
    int countNodes(Contact *tree){
            if(tree==NULL)
                return 0;
            return 1+countNodes(tree->left)+countNodes(tree->right);
        }
    public:
        BinarySearchTree(){
            root = NULL;
        }
        void insertNode(string name , string phoneNumber){
            insertNode(root, name, phoneNumber);
        }

        void printInOrder(){
            printInOrder(root);
        }
        int treeLength(){
            treeLength(root);
        }

        void RetrieveName(string name){
            return RetrieveName(root,name);
        }
        void RetrievePhoneNumber(string phoneNumber){
            return RetrievePhoneNumber(root,phoneNumber);
        }
        bool findNode(string phoneNumber){
            return findNode(root,phoneNumber);
        }
        void deleteNode(string phoneNumber){
            deleteNode(root,phoneNumber);
        }
        string findMinNode(){
            findMinNode(root);
        }
        string findMaxNode(){
            findMaxNode(root);
        }
        bool isBalanced();

        void makeEmpty(){
            makeEmpty(root);
        }
        int getHeight(){
            getHeight(root);
        }
        bool isEmpty(){
            if(root == NULL)
            {
                return true;
            }else
            {
                return false;
            }
        }
        int countNodes()
        {
            return countNodes(root);
        }

        void Mainmenu(){
        char C;
        string o;
        string a,b,d,c,e,f,g;

        cout<<endl;
        cout<< "----Menu----"<<endl;
        cout<< " 1) View all contacts "<<endl;
        cout<< " 2) Add new contact "<<endl;
        cout<< " 3) Search a contact by name "<<endl;
        cout<< " 4) Search a contact by phone number "<<endl;
        cout<< " 5) Delete a contact "<<endl;
        cout<< " 6) Delete all contacts "<<endl;
        cout<< " 7) Exit program "<<endl;
        cout<<"---------------";
        cout<<endl;
        cout<< "Select an option (1-7):  ";
        cin >> C;

    switch(C){
        case '1':
                if(root==NULL){
                cout << "-------------" << endl;
                cout << endl;
                cout << " * View Contacts * " << endl;
                cout << " Contact Book is Empty. " << endl;
                Mainmenu();
                }
                printInOrder();

                Mainmenu();
                break;

         case '2':
                cout << " *** Add new contact *** " << endl;
                cout << endl;
                cout << " Enter name: ";
                cin.ignore();
                getline(cin,a);
                cout << " Enter phone number: ";
                getline(cin,b);
                insertNode(a,b);
                cout << endl << "Contact added successfully.";
                Mainmenu();
                break;

        case '3':
                cout << endl;
                cout << " Enter name: ";
                cin.ignore();
                getline(cin,d);
                RetrieveName(d);
                Mainmenu();
                break;

        case '4':
                cout << endl;
                cout << " Enter phone number: ";
                cin.ignore();
                getline(cin,c);
                RetrievePhoneNumber(c);
                Mainmenu();
                break;

        case '5':
                cout << endl;
                cout <<  " Enter phone number: ";
                cin.ignore();
                getline(cin,e);
                findNode(e);
                cout << " ****Delete this contact*** " <<endl;
                cout << " Enter y for yes, n for no:  ";
                cout << endl;
                cin >> f;
                if(f == "y")
                {
                deleteNode(e);
                cout<< "***Contact deleted successfully**" <<endl;
                }
                else
                {
                cout << "***Contacts are not deleted***" << endl;
                }
                Mainmenu();
                break;

         case '6':
                cout << endl;
                cout << " ***Delete All Contacts**" <<endl;
                cout << " Enter y for yes, n for no:  ";
                cout<<endl;
                cin>> g;
                if(g =="y")
                {
                cout<<endl;
                makeEmpty();
                cout<< "All contacts deleted."<<endl;
                Mainmenu();
                }
                else{
                Mainmenu();
                return ;
                }
                break;

         case '7':
                cout << endl;
                cout << " Are you sure? "<<endl;
                cout << " Enter y for yes, n for no:  ";
                cout << endl;
                cin >> o;
                if(o == "y")
                {
                    cout << "*Thank you for using Contact Book*" << endl;
                    exit(0);
                }
                else
                {
                Mainmenu();
                return ;
                }
                break;
                }
        }
};

int main(){
    BinarySearchTree bst;
    cout << "*************************"<< endl;
    cout << "****** CONTACT BOOK *****"<< endl;
    cout << "*************************"<< endl;
    cout<< endl;
    bst.Mainmenu();
}


