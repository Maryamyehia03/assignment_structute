#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// Enum to use it in comparing
enum class ComparisonType {
    NAME,
    PRICE
};

// To create objects to pass to trees
class item {
private:
    string name;
    string category;
    double price;

public:
    //Default constructor
    item()
    {
        name = "";
        category = "";
        price = 0;
    }

    // constructor
    item (string name, string category, double price)
    {
        this->name = name;
        this->category = category;
        this->price = price;
    }

    // To display item's properties
    void print()
    {
        cout << "Name is : " << name << '\n' << "Category is : " << category << '\n' << "Price is : " << price << '\n';
        return;
    }

    // To return item's name
    string getName()
    {
        return name;
    }

    // To return item's category
    string getCategory()
    {
        return category;
    }

    // To return item's price
    double getPrice()
    {
        return price;
    }

    // Set how to compare
    static ComparisonType compareBy;

    // Operator for comparison
    bool operator < (const item& other)
    {
        if (compareBy == ComparisonType::NAME)
        {
            return name < other.name;
        }
        else if (compareBy == ComparisonType::PRICE)
        {
            return price < other.price;
        }
        return false;
    }

    bool operator > (const item& other)
    {
        if (compareBy == ComparisonType::NAME)
        {
            return name > other.name;
        }
        else if (compareBy == ComparisonType::PRICE)
        {
            return price > other.price;
        }
        return false;
    }
friend class AVLTree;
};

ComparisonType item::compareBy;

// TO CREATE NODES
template <class type>
class node {
public:
    type data;
    node <type> * left;
    node <type> * right;

    // Default constructor
    node()
    {
        left = right = NULL;
    }
};

// TO MAKE OPERATION ON BINARY SEARCH TREE
template <class type>
class Binary_Search_Tree {
private:
    node<type> *root;
    int MAX_SIZE;
    vector<string> nameVec;
    vector<int> priceVec;
public:
    // Default constructor
    Binary_Search_Tree() {
        root = NULL;
        MAX_SIZE = sizeCall();
        nameVec.resize(MAX_SIZE);
        priceVec.resize(MAX_SIZE);
    }

    // To check if the BST empty or not
    bool isEmpty() {
        return (root == NULL);
    }

    // To update nameVec and priceVec vectors after inserting a new item
    void updateVectors(type element)
    {
        nameVec.push_back(element.getName());
        priceVec.push_back(element.getPrice());
    }

    // To insert item data
    void insert(type element)
    {
        node<type> *r = root;
        node<type> *prev = NULL;
        node<type> *newnode = new node<type>;
        newnode->data = element;

        if (isEmpty())
        {
            newnode->right = newnode->left = NULL;
            root = newnode;
            updateVectors(element);
            return;
        }
        else
        {
            while (r != NULL)
            {
                prev = r;
                if (element > r->data)
                    r = r->right;
                else if (element < r->data)
                    r = r->left;
            }

            if (prev->data > element)
                prev->left = newnode;
            if (prev->data < element)
                prev->right = newnode;

            updateVectors(element);

            return;
        }
    }

    // To display the tree in preorder ----> 1-root , 2-left , 3-right
    void display(node<type> *r) {
        if (isEmpty()) {
            cout << " SORRY BUT THE LIST IS EMPTY ): " << '\n';
            return;
        } else {
            cout << "name: " << r->data.getName() << ", Category: " << r->data.getCategory() << ", Price: "
                 << r->data.getPrice() << endl;
            if (r->left != NULL)
                display(r->left);
            if (r->right != NULL)
                display(r->right);
            return;
        }
        return;
    }

    // To call display function
    void displayCall() {
        display(root);
        return;
    }

    // To return the size of tree
    int size(node<type> *r) {
        if (r == NULL) // Base case
            return 0;

        int counter = 1; // Start with 1 for the current node
        counter += size(r->left);
        counter += size(r->right);

        return counter;
    }

    // To call size function
    int sizeCall() {
        int SIZE = size(root);
        return SIZE;
    }

    // To search by item name and return node
    node<type> *searchByName(const string &itemName, node<type> *current) {
        if (current == NULL)
        {
            return NULL;
        }

        if (current->data.getName() == itemName)
        {
            return current;
        }

        node<type> *leftResult = searchByName(itemName, current->left);
        if (leftResult != NULL)
        {
            return leftResult; // If found in the left subtree, return the result
        }

        node<type> *rightResult = searchByName(itemName, current->right);
        if (rightResult != NULL)
        {
            return rightResult; // If found in the right subtree, return the result
        }
    }

    // To call searchByName function
    node<type> *searchByNameCall(const string &itemName)
    {
        return searchByName(itemName, root);
    }

    // To display items according to names ascending
    void displayAscendingByName()
    {
        sort(nameVec.begin(), nameVec.end());


        for (const string &name: nameVec)
        {
            node<type> *foundNode = searchByNameCall(name);
            if (foundNode != NULL)
            {
                cout << "Name: " << foundNode->data.getName() << ", Category: " << foundNode->data.getCategory()
                     << ", Price: " << foundNode->data.getPrice() << '\n';
            }
        }
    }

    // To display items according to names descending
    void displayDescendingByName()
    {
        sort(nameVec.begin(), nameVec.end(), greater<string>());


        for (const string &name: nameVec)
        {
            node<type> *foundNode = searchByNameCall(name);
            if (foundNode != NULL)
            {
                cout << "Name: " << foundNode->data.getName() << ", Category: " << foundNode->data.getCategory()
                     << ", Price: " << foundNode->data.getPrice() << '\n';
            }
        }
    }

    // To search by item price and return node
    node<type> *searchByPrice(const int &itemPrice, node<type> *current)
    {
        if (current == NULL)
        {
            return NULL;
        }

        if (current->data.getPrice() == itemPrice)
        {
            return current;
        }

        node<type> *leftResult = searchByPrice(itemPrice, current->left);
        if (leftResult != NULL)
        {
            return leftResult; // If found in the left subtree, return the result
        }

        node<type> *rightResult = searchByPrice(itemPrice, current->right);
        if (rightResult != NULL)
        {
            return rightResult; // If found in the right subtree, return the result
        }
    }

    // To call searchByPrice function
    node<type> *searchByPriceCall(const int &itemPrice)
    {
        return searchByPrice(itemPrice, root);
    }

    // To display items according to prices ascending
    void displayAscendingByPrice()
    {
        sort(priceVec.begin(), priceVec.end());


        for (const int &price: priceVec)
        {
            node<type> *foundNode = searchByPriceCall(price);
            if (foundNode != NULL)
            {
                cout << "Name: " << foundNode->data.getName() << ", Category: " << foundNode->data.getCategory()
                     << ", Price: " << foundNode->data.getPrice() << '\n';
            }
        }
    }

    // To display items according to prices descending
    void displayDescendingByPrice()
    {

        sort(priceVec.begin(), priceVec.end(), greater<int>());

        for (const int &price: priceVec)
        {
            node<type> *foundNode = searchByPriceCall(price);
            if (foundNode != NULL)
            {
                cout << "Name: " << foundNode->data.getName() << ", Category: " << foundNode->data.getCategory()
                     << ", Price: " << foundNode->data.getPrice() << '\n';
            }
        }
    }

    // To delete item
    void remove(node <type> * &r , type element)
    {
        if(r == NULL)
        {
            cout << "SORRY BUT THE LIST IS EMPTY ): " << '\n';
            return;
        }

        // Search for the node to delete
        if(element < r->data)
        {
            remove(r->left , element);
        }
        else if(element > r->data)
        {
            remove(r->right , element);
        }
        else // Found the node to delete
        {
            // Update nameVec and priceVec vectors before removing the node
            auto nameIter = find(nameVec.begin(), nameVec.end(), element.getName());
            auto priceIter = find(priceVec.begin(), priceVec.end(), element.getPrice());

            if (nameIter != nameVec.end())
            {
                nameVec.erase(nameIter);
            }
            if (priceIter != priceVec.end())
            {
                priceVec.erase(priceIter);
            }

            // Case 1: Node is a leaf (no children)
            if(r->left == NULL && r->right == NULL)
            {
                delete r;
                r = NULL;
            }
                // Case 2: Node has only one child
            else if(r->left == NULL)
            {
                node<type> *temp = r;
                r = r->right;
                delete temp;
            }
            else if(r->right == NULL)
            {
                node<type> *temp = r;
                r = r->left;
                delete temp;
            }
            else // Case 3: Node has two children
            {

                node<type> *successor = r->right;
                while(successor->left != NULL)
                {
                    successor = successor->left;
                }

                r->data = successor->data;

                // Recursively remove the successor node from the right subtree
                remove(r->right, successor->data);
            }
        }
    }

    // To call remove function
    void removeCall(type element)
    {
        remove(root , element);
    }
};

template<typename t>
class heap_max{
    vector<item>heapmax;
    int n = 0;
public:

    void add(item data)
    {
        n++;
        heapmax.push_back(data);
    }

    void print(){
        for (int i = 0; i < heapmax.size(); ++i) {
            cout<<heapmax[i].getName()<<" "<<heapmax[i].getCategory()<<" "<<heapmax[i].getPrice()<<"\n";
        }
    }

    void MAX_HEAPIFY_name(){
        for (int i = (heapmax.size()/2)-1; i >=0 ; i--) {
            if (((i*2)+2)<heapmax.size()){
                if ((heapmax[(i*2)+1].getName()>heapmax[(i*2)+2].getName())){
                    if ((heapmax[(i*2)+1].getName()>heapmax[i].getName()))
                    {swap(heapmax[(i*2)+1],heapmax[i]); i=(heapmax.size()/2);}
                }
                else {
                    if ((heapmax[(i*2)+2].getName()>heapmax[i].getName())){
                        swap(heapmax[(i*2)+2],heapmax[i]); i=(heapmax.size()/2);
                    }
                }
            }
            else if (((i*2)+1)<heapmax.size())
            {
                if (heapmax[(i*2)+1].getName()>heapmax[i].getName())
                {swap(heapmax[(i*2)+1],heapmax[i]);i=(heapmax.size()/2); }
            }
        }
    }

    void MAX_HEAPIFY_PRICE(){
        for (int i = (heapmax.size()/2)-1; i >=0 ; i--) {
            if (((i*2)+2)<heapmax.size()){
                if ((heapmax[(i*2)+1].getPrice()>heapmax[(i*2)+2].getPrice())){
                    if ((heapmax[(i*2)+1].getPrice()>heapmax[i].getPrice()))
                    {swap(heapmax[(i*2)+1],heapmax[i]); i=(heapmax.size()/2);}
                }
                else {
                    if ((heapmax[(i*2)+2].getPrice()>heapmax[i].getPrice())){
                        swap(heapmax[(i*2)+2],heapmax[i]); i=(heapmax.size()/2);
                    }
                }
            }
            else if (((i*2)+1)<heapmax.size())
            {
                if (heapmax[(i*2)+1].getPrice()>heapmax[i].getPrice())
                {swap(heapmax[(i*2)+1],heapmax[i]);i=(heapmax.size()/2); }
            }
        }
    }

    void extract()
    {
        swap(heapmax[0],heapmax[heapmax.size()-1]);
        heapmax.pop_back();
    }

    void sort_namemaxheap_acs(){
        deque<item>sort_data;
        for (int i = 0; i < n; ++i) {
            MAX_HEAPIFY_name();
            sort_data.push_front(heapmax[0]);
            extract();
        }
        for (int i = 0; i < sort_data.size(); ++i) {
            heapmax.push_back(sort_data[i]);
//            cout<<sort_data[i]<<" ";
        }
        print();
    }

    void sort_namemaxheap_decs(){
        deque<item>sort_data;
        for (int i = 0; i < n; ++i) {
            MAX_HEAPIFY_name();
            sort_data.push_back(heapmax[0]);
            extract();
        }
        for (int i = 0; i < sort_data.size(); ++i) {
            heapmax.push_back(sort_data[i]);
//            cout<<sort_data[i]<<" ";
        }
        print();
    }

    void sort_pricemaxheap_acs(){
        deque<item>sort_data;
        for (int i = 0; i < n; ++i) {
            MAX_HEAPIFY_PRICE();
            sort_data.push_front(heapmax[0]);
            extract();
        }
        for (int i = 0; i < sort_data.size(); ++i) {
            heapmax.push_back(sort_data[i]);
        }
        print();
    }

    void sort_pricemaxheap_decs(){
        deque<item>sort_data;
        for (int i = 0; i < n; ++i) {
            MAX_HEAPIFY_PRICE();
            sort_data.push_back(heapmax[0]);
            extract();
        }
        for (int i = 0; i < sort_data.size(); ++i) {
            heapmax.push_back(sort_data[i]);
        }
        print();
    }

    void delete_back(){
        if (heapmax.size()==0){
            cout<<"Sorry! Heap is Empty\n";
            return;}
        n--;
        heapmax.pop_back();
    }

    void size(){
        cout<<heapmax.size()<<"\n";
    }
};
class AVLNode {
public:
    item data;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(item data) : data(data), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
private:
    AVLNode* root;

    int height(AVLNode* node) {
        if (node == nullptr) return 0;
        return node->height;
    }

    int balanceFactor(AVLNode* node) {
        if (node == nullptr) return 0;
        return height(node->left) - height(node->right);
    }

    AVLNode* rightRotate(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    AVLNode* leftRotate(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    AVLNode* insert(AVLNode* node, item data) {
        if (node == nullptr) return new AVLNode(data);

        if (data < node->data)
            node->left = insert(node->left, data);
        else
            node->right = insert(node->right, data);

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = balanceFactor(node);

        if (balance > 1 && data < node->left->data)
            return rightRotate(node);

        if (balance < -1 && data > node->right->data)
            return leftRotate(node);

        if (balance > 1 && data > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && data < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void inorder(AVLNode* node) {
        if (node != nullptr) {
            inorder(node->left);
            node->data.print();
            inorder(node->right);
        }
    }

    void reverseInorder(AVLNode* node) {
        if (node != nullptr) {
            reverseInorder(node->right);
            node->data.print();
            reverseInorder(node->left);
        }
    }

    void inorderPrice(AVLNode* node) {
        if (node != nullptr) {
            inorderPrice(node->left);
            node->data.print();
            inorderPrice(node->right);
        }
    }

    void reverseInorderPrice(AVLNode* node) {
        if (node != nullptr) {
            reverseInorderPrice(node->right);
            node->data.print();
            reverseInorderPrice(node->left);
        }
    }

public:
    AVLTree() : root(nullptr) {}

    void insert(item data) {
        root = insert(root, data);
    }

    void display() {
        if (root == nullptr) {
            cout << "Tree is empty!" << endl;
            return;
        }
        cout << "Items in the supermarket:" << endl;
        inorder(root);
    }

    void displayAscending() {
        if (root == nullptr) {
            cout << "Tree is empty!" << endl;
            return;
        }
        cout << "Items in the supermarket (sorted by name, ascending):" << endl;
        inorder(root);
    }

    void displayDescending() {
        if (root == nullptr) {
            cout << "Tree is empty!" << endl;
            return;
        }
        cout << "Items in the supermarket (sorted by name, descending):" << endl;
        reverseInorder(root);
    }

    void displayAscendingByPrice() {
        if (root == nullptr) {
            cout << "Tree is empty!" << endl;
            return;
        }
        cout << "Items in the supermarket (sorted by price, ascending):" << endl;
        inorderPrice(root);
    }

    void displayDescendingByPrice() {
        if (root == nullptr) {
            cout << "Tree is empty!" << endl;
            return;
        }
        cout << "Items in the supermarket (sorted by price, descending):" << endl;
        reverseInorderPrice(root);
    }

    void remove(item data) {
        root = remove(root, data);
    }

    AVLNode* remove(AVLNode* node, item data) {
        if (node == nullptr) return node;

        if (data < node->data)
            node->left = remove(node->left, data);
        else if (data > node->data)
            node->right = remove(node->right, data);
        else {
            if (node->left == nullptr || node->right == nullptr) {
                AVLNode* temp = node->left ? node->left : node->right;
                if (temp == nullptr) {
                    temp = node;
                    node = nullptr;
                } else
                    *node = *temp;
                delete temp;
            } else {
                AVLNode* temp = minValueNode(node->right);
                node->data = temp->data;
                node->right = remove(node->right, temp->data);
            }
        }

        if (node == nullptr) return node;

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = balanceFactor(node);

        if (balance > 1 && balanceFactor(node->left) >= 0)
            return rightRotate(node);

        if (balance > 1 && balanceFactor(node->left) < 0) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && balanceFactor(node->right) <= 0)
            return leftRotate(node);

        if (balance < -1 && balanceFactor(node->right) > 0) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    AVLNode* minValueNode(AVLNode* node) {
        AVLNode* current = node;
        while (current->left != nullptr)
            current = current->left;
        return current;
    }
};


int main() {

    int mainMenu = 5, miniMenu = 100, itemPrice = 0;
    string itemName = "", itemCategory = "";

    // An instance of Binary search tree
    Binary_Search_Tree<item> BST;
    heap_max<item>heap_max;
    AVLTree supermarket;

    while (mainMenu != 0) {
        miniMenu = 100; // So I can enter the inner loop again

        cout << "PLEASE CHOOSE NON LINEAR STRUCTURE YOU WANT :" << '\n'
             << "1- Binary Search Trees."                       << '\n'
             << "2- Max Heap."                                  << '\n'
             << "3- Min Heaps."                                 << '\n'
             << "4- AVL Trees."                                 << '\n'
             << "OR PRESS 0 TO END THE PROGRAM."                << '\n';

        cin >> mainMenu;

        switch (mainMenu) {
            case 1:
                while (miniMenu != 0 && miniMenu != 8) {
                    cout << "PLEASE ENTER # OF FUNCTION YOU WANT :"                         << '\n'
                         << "1- Add item."                                                  << '\n'
                         << "2- Remove item."                                               << '\n'
                         << "3- Display the item data normally."                            << '\n'
                         << "4- Display all the items sorted by their name ascending."      << '\n'
                         << "5- Display all the items sorted by their name descending."     << '\n'
                         << "6- Display all the items sorted by their prices ascending."    << '\n'
                         << "7- Display all the items sorted by their prices descending."   << '\n'
                         << "8- To return to the main menu."                                << '\n'
                         << "OR PRESS 0 TO END THE PROGRAM."                                << '\n';
                    cin >> miniMenu;

                    switch (miniMenu) {
                        case 1: {
                            cout << "Enter the items manually." << '\n';
                            int x = 1;
                            while (x != 0) {
                                cout << "Enter item name:     " << '\n';
                                cin >> itemName;
                                cout << "Enter item category: " << '\n';
                                cin >> itemCategory;
                                cout << "Enter item price: " << '\n';
                                cin >> itemPrice;
                                item mnew=item();

                                item newItem(itemName, itemCategory, itemPrice);
                                BST.insert(newItem);

                                cout << "If you are finished, enter 0, and if you are not finished, enter anything else." << '\n';
                                cin >> x;
                                if (x == 0)
                                    break;
                            }
                            continue;
                        }
                        case 2:
                            cout << "Please enter item name :" << '\n';
                            cin >> itemName;
                            {
                                node<item>* foundNode = BST.searchByNameCall(itemName);
                                if (foundNode != nullptr)
                                {
                                    BST.removeCall(foundNode->data);
                                    cout << "Item successfully removed." << '\n';
                                }
                                else
                                {
                                    cout << "Item not found in the tree." << '\n';
                                }
                            }
                            continue;
                        case 3:
                            BST.displayCall();
                            cout << '\n';
                            continue;
                        case 4:
                            BST.displayAscendingByName();
                            cout << '\n';
                            continue;
                        case 5:
                            BST.displayDescendingByName();
                            cout << '\n';
                            continue;
                        case 6:
                            BST.displayAscendingByPrice();
                            cout << '\n';
                            continue;
                        case 7:
                            BST.displayDescendingByPrice();
                            cout << '\n';
                            continue;
                        case 8:
                            cout << "Returning to main menu..." << '\n';
                            break;
                        case 0:
                            cout << "Exiting program..." << '\n';
                            return 0;
                        default:
                            cout << " INVALID CHOICE ): " << '\n';
                            continue;
                    }
                }
                continue;
            case 2:
                while (miniMenu != 0 && miniMenu != 8) {
                    cout << "PLEASE ENTER # OF FUNCTION YOU WANT :" << '\n'
                         << "1- Add item." << '\n'
                         << "2- Remove item from back." << '\n'
                         << "3- Display the item data normally." << '\n'
                         << "4- Display all the items sorted by their name ascending." << '\n'
                         << "5- Display all the items sorted by their name descending." << '\n'
                         << "6- Display all the items sorted by their prices ascending." << '\n'
                         << "7- Display all the items sorted by their prices descending." << '\n'
                         << "8- To return to the main menu." << '\n'
                         << "OR PRESS 0 TO END THE PROGRAM." << '\n';
                    cin >> miniMenu;

                    switch (miniMenu) {
                        case 1:
                            cout << "Enter item name:     " << '\n';
                            cin >> itemName;
                            cout << "Enter item category: " << '\n';
                            cin >> itemCategory;
                            cout << "Enter item price: " << '\n';
                            cin >> itemPrice;

                              heap_max.add(item(itemName,itemCategory,itemPrice));
                            continue;
                        case 2:
                            heap_max.delete_back();
                            continue;
                        case 3:
                            heap_max.print();
                            continue;
                        case 4:
                            heap_max.sort_namemaxheap_acs();
                            continue;
                        case 5:
                            heap_max.sort_namemaxheap_decs();
                            continue;
                        case 6:
                            heap_max.sort_pricemaxheap_acs();
                            continue;
                        case 7:
                            heap_max.sort_pricemaxheap_decs();
                            continue;
                        case 8:
                            cout << "Returning to main menu..." << '\n';
                            break;
                        case 0:
                            cout << "Exiting program..." << '\n';
                            return 0;
                        default:
                            cout << " INVALID CHOICE ): " << '\n';
                            continue;
                    }
                }
                continue;
            case 3:
                while (miniMenu != 0 && miniMenu != 8) {
                    cout << "PLEASE ENTER # OF FUNCTION YOU WANT :" << '\n'
                         << "1- Add item." << '\n'
                         << "2- Remove item." << '\n'
                         << "3- Display the item data normally." << '\n'
                         << "4- Display all the items sorted by their name ascending." << '\n'
                         << "5- Display all the items sorted by their name descending." << '\n'
                         << "6- Display all the items sorted by their prices ascending." << '\n'
                         << "7- Display all the items sorted by their prices descending." << '\n'
                         << "8- To return to the main menu." << '\n'
                         << "OR PRESS 0 TO END THE PROGRAM." << '\n';
                    cin >> miniMenu;

                    switch (miniMenu) {
                        case 1:
                            continue;
                        case 2:
                            continue;
                        case 3:
                            continue;
                        case 4:
                            continue;
                        case 5:
                            continue;
                        case 6:
                            continue;
                        case 7:
                            continue;
                        case 8:
                            cout << "Returning to main menu..." << '\n';
                            break;
                        case 0:
                            cout << "Exiting program..." << '\n';
                            return 0;
                        default:
                            cout << " INVALID CHOICE ): " << '\n';
                            continue;
                    }
                }
                continue;
            case 4:
                while (miniMenu != 0 && miniMenu != 8) {
                    cout << "PLEASE ENTER # OF FUNCTION YOU WANT :" << '\n'
                         << "1- Add item." << '\n'
                         << "2- Remove item." << '\n'
                         << "3- Display the item data normally." << '\n'
                         << "4- Display all the items sorted by their name ascending." << '\n'
                         << "5- Display all the items sorted by their name descending." << '\n'
                         << "6- Display all the items sorted by their prices ascending." << '\n'
                         << "7- Display all the items sorted by their prices descending." << '\n'
                         << "8- To return to the main menu." << '\n'
                         << "OR PRESS 0 TO END THE PROGRAM." << '\n';
                    cin >> miniMenu;
                    item newItem("", "", 0);

                    switch (miniMenu) {
                        case 1:
                            {
                string name, category;
                int price;
                cout << "Enter item name: ";
                cin >> name;
                cout << "Enter item category: ";
                cin >> category;
                cout << "Enter item price: ";
                cin >> price;
                newItem = item(name, category, price);
                supermarket.insert(newItem);
                cout << "Item added successfully!" << endl;
                break;
            }
                        case 2:
                            {
                string name, category;
                int price;
                cout << "Enter item name: ";
                cin >> name;
                cout << "Enter item category: ";
                cin >> category;
                cout << "Enter item price: ";
                cin >> price;
                newItem = item(name, category, price);
                supermarket.remove(newItem);
                cout << "Item removed successfully!" << endl;
                break;
            }
                        case 3:
                            supermarket.display();
                            break;
                        case 4:
                            supermarket.displayAscending();
                            break;
                        case 5:
                            supermarket.displayDescending();
                            break;
                        case 6:
                            supermarket.displayAscendingByPrice();
                            break;
                        case 7:
                            supermarket.displayDescendingByPrice();
                            break;
                        case 8:
                            cout << "Returning to main menu..." << '\n';
                            break;
                        case 0:
                            cout << "Exiting program..." << '\n';
                            return 0;
                        default:
                            cout << " INVALID CHOICE ): " << '\n';
                            continue;
                    }
                }
                continue;
            case 0:
                cout << " Exiting program... " << '\n';
                return 0;
            default:
                cout << " INVALID CHOICE ): " << '\n';
                continue;
        }
    }

    return 0;
}
