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
    int price;

public:

    // Default constructor
    item()
    {
        name = "";
        category = "";
        price = 0;
    }

    // constructor
    item (string name, string category, int price)
    {
        this->name = name;
        this->category = category;
        this->price = price;
    }

    // To display item's properties
    void print()
    {
        cout << "Name is     : " << name << '\n' << "Category is : " << category << '\n' << "Price is    : " << price << '\n';
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
    int getPrice()
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

    int main() {
        int mainMenu = 5, miniMenu = 100, itemPrice = 0;
        string itemName = "", itemCategory = "";

        // An instance of Binary search tree
        Binary_Search_Tree<item> BST;

        while (mainMenu != 0) {
            miniMenu = 100; // So I can enter the inner loop again

            cout << "PLEASE CHOOSE NON LINEAR STRUCTURE YOU WANT :" << '\n'
                 << "1- Binary Search Trees."                       << '\n'
                 << "2- Heaps."                                     << '\n'
                 << "3- AVL Trees."                                 << '\n'
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

                                    item newItem(itemName, itemCategory, itemPrice);
                                    BST.insert(newItem);

                                    cout << "If you're done, enter 0 Enter anything else." << '\n';
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
                             << "2- Remove item." << '\n'
                             << "3- Display the item data normally." << '\n'
                             << "4- Display all the items sorted by their name ascending." << '\n'
                             << "5- Display all the items sorted by their name descending." << '\n'
                             << "6- Display all the items sorted by their prices ascending." << '\n'
                             << "7-  Display all the items sorted by their prices descending." << '\n'
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
                case 3:
                    while (miniMenu != 0 && miniMenu != 8) {
                        cout << "PLEASE ENTER # OF FUNCTION YOU WANT :" << '\n'
                             << "1- Add item." << '\n'
                             << "2- Remove item." << '\n'
                             << "3- Display the item data normally." << '\n'
                             << "4- Display all the items sorted by their name ascending." << '\n'
                             << "5- Display all the items sorted by their name descending." << '\n'
                             << "6- Display all the items sorted by their prices ascending." << '\n'
                             << "7-  Display all the items sorted by their prices descending." << '\n'
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