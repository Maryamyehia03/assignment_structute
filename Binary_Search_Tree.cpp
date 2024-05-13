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
    node <type> * root;
public:
    // Default constructor
    Binary_Search_Tree()
    {
        root = NULL;
    }

    // To check if the BST empty or not
    bool isEmpty()
    {
        return (root == NULL);
    }

    // Helper function to perform selection sort
    void selectionSort(node <type> *r)
    {
        node <type> *ptr1;
        node <type> *ptr2;
        type temp;

        // Check for empty tree
        if (r == NULL)
            return;

        for (ptr1 = r; ptr1->right != NULL; ptr1 = ptr1->right) {
            for (ptr2 = ptr1->right; ptr2 != NULL; ptr2 = ptr2->right) {
                // Compare node data and swap if necessary
                if (ptr1->data > ptr2->data) {
                    temp = ptr1->data;
                    ptr1->data = ptr2->data;
                    ptr2->data = temp;
                }
            }
        }
    }

    // To insert item data
    void insert (type element)
    {
        node <type> * r = root;
        node <type> * prev = NULL;
        node <type> * newnode = new node <type>;
        newnode->data = element;

        if (isEmpty())
        {
            newnode->right = newnode->left = NULL;
            root = newnode;
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

            // Update r to point to the new node
            //r = newnode;


            return;
        }
    }

    // To display the tree in preorder ----> 1-root , 2-left , 3-right
    void display(node <type> * r)
    {
        if (isEmpty())
        {
            cout << " SORRY BUT THE LIST IS EMPTY ): " << '\n';
            return;
        }
        else
        {
            cout << "name: " << r->data.getName() << ", Category: " << r->data.getCategory() << ", Price: " << r->data.getPrice() << endl;
            if (r->left != NULL)
                display(r->left);
            if (r->right != NULL)
                display(r->right);
            return;
        }
        return;
    }

    // To call display function
    void displayCall()
    {
        display(root);
        return;
    }

    // To display according to names ascending
    void displayNameAscending(node <type> * r)
    {
        if (isEmpty())
        {
            cout << " SORRY BUT THE LIST IS EMPTY ): " << '\n';
            return;
        }
        else
        {
            selectionSort(r);
            cout << "name: " << r->data.getName() << ", Category: " << r->data.getCategory() << ", Price: " << r->data.getPrice() << endl;
            if (r->left != NULL)
                displayNameAscending(r->left);
            if (r->right != NULL)
                displayNameAscending(r->right);
            return;
        }
        return;
    }

    // To call displayNameAscending function
    void displayNameAscendingCall()
    {
        displayNameAscending(root);
    }
};

int main()
{
    int mainMenu = 5, miniMenu = 100, itemPrice = 0;
    string itemName = "", itemCategory = "";

    // An instance of Binary search tree
    Binary_Search_Tree <item> BST;

    while (mainMenu != 0)
    {
        miniMenu = 100; // So I can enter the inner loop again

        cout << "PLEASE CHOOSE NON LINEAR STRUCTURE YOU WANT :"    <<'\n'
             << "1- Binary Search Trees."                          <<'\n'
             << "2- Heaps."                                        <<'\n'
             << "3- AVL Trees."                                    <<'\n'
             << "OR PRESS 0 TO END THE PROGRAM."                   <<'\n';

        cin >> mainMenu;

        switch (mainMenu)
        {
            case 1:
                while (miniMenu != 0 && miniMenu != 8)
                {
                    cout << "PLEASE ENTER # OF FUNCTION YOU WANT :"                          <<'\n'
                         << "1- Add item."                                                   <<'\n'
                         << "2- Remove item."                                                <<'\n'
                         << "3- Display the item data normally."                             <<'\n'
                         << "4- Display all the items sorted by their name ascending."       <<'\n'
                         << "5- Display all the items sorted by their name descending."      <<'\n'
                         << "6- Display all the items sorted by their prices ascending."     <<'\n'
                         << "7-  Display all the items sorted by their prices descending."   <<'\n'
                         << "8- To return to the main menu."                                 <<'\n'
                         << "OR PRESS 0 TO END THE PROGRAM."                                 <<'\n';
                    cin >> miniMenu;

                    switch (miniMenu)
                    {
                        case 1:
                        {
                            cout << "Enter the items manually." << '\n';
                            int x = 1;
                            while (x != 0)
                            {
                                cout << "Enter item name:     " <<'\n';
                                cin >> itemName;
                                cout << "Enter item category: " <<'\n';
                                cin >> itemCategory;
                                cout << "Enter item price: " <<'\n';
                                cin >> itemPrice;

                                item newItem(itemName, itemCategory, itemPrice);
                                BST.insert(newItem);

                                // Reset variables
                                itemName = "";
                                itemCategory = "";
                                itemPrice = 0;

                                cout << "IF YOU FINISH ENTER 0 ELSE ENTER 1." << '\n';
                                cin >> x;
                                if (x == 0)
                                    break;
                            }
                            continue;
                        }
                        case 2:
                            continue;
                        case 3:
                            BST.displayCall();
                            cout << '\n';
                            continue;
                        case 4:
                            BST.displayNameAscendingCall();
                            cout << '\n';
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
            case 2:
                while (miniMenu != 0 && miniMenu != 8)
                {
                    cout << "PLEASE ENTER # OF FUNCTION YOU WANT :"                          <<'\n'
                         << "1- Add item."                                                   <<'\n'
                         << "2- Remove item."                                                <<'\n'
                         << "3- Display the item data normally."                             <<'\n'
                         << "4- Display all the items sorted by their name ascending."       <<'\n'
                         << "5- Display all the items sorted by their name descending."      <<'\n'
                         << "6- Display all the items sorted by their prices ascending."     <<'\n'
                         << "7-  Display all the items sorted by their prices descending."   <<'\n'
                         << "8- To return to the main menu."                                 <<'\n'
                         << "OR PRESS 0 TO END THE PROGRAM."                                 <<'\n';
                    cin >> miniMenu;

                    switch (miniMenu)
                    {
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
                while (miniMenu != 0 && miniMenu != 8)
                {
                    cout << "PLEASE ENTER # OF FUNCTION YOU WANT :"                          <<'\n'
                         << "1- Add item."                                                   <<'\n'
                         << "2- Remove item."                                                <<'\n'
                         << "3- Display the item data normally."                             <<'\n'
                         << "4- Display all the items sorted by their name ascending."       <<'\n'
                         << "5- Display all the items sorted by their name descending."      <<'\n'
                         << "6- Display all the items sorted by their prices ascending."     <<'\n'
                         << "7-  Display all the items sorted by their prices descending."   <<'\n'
                         << "8- To return to the main menu."                                 <<'\n'
                         << "OR PRESS 0 TO END THE PROGRAM."                                 <<'\n';
                    cin >> miniMenu;

                    switch (miniMenu)
                    {
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
