#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TO CREATE NODES
template <class type>
class node {
public:
    type data;
    node *next;
};

// TO MAKE OPERATION ON LINKED LIST
template <class type>
class single_linked_list {
private:
    node<type> *head;

public:
    // Constructor
    single_linked_list()
    {
        head = NULL;
    }

    // To check if list empty or not
    bool isEmpty()
    {
        return (head == NULL);
    }

    // To search for an element
    bool isExist(type element)
    {
        if (isEmpty())
        {
            cout << " SORRY BUT THE LIST IS EMPTY ): " << '\n';
            return false;
        }
        else
        {
            node<type> *temp = head;
            bool found = false;
            while (temp != NULL)
            {
                if (temp->data == element)
                {
                    found = true;
                }
                temp = temp->next;
            }
            return found;
        }
    }

    // To print the size of list
    int linkedListSize()
    {
        int size = 0;
        if (isEmpty())
        {
            return size;
        }
        else
        {
            node<type> *temp = head;
            while (temp != NULL)
            {
                size += 1;
                temp = temp->next;
            }
            return size;
        }
    }

    // To print the list
    void print()
    {
        if (isEmpty())
        {
            cout << " SORRY BUT THE LIST IS EMPTY ): " << '\n';
        }
        else
        {
            node<type> *temp = head;
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
        return;
    }

    // To delete list
    void clear()
    {
        if (isEmpty())
        {
            cout << " THE LIST ALREADY EMPTY ! " << '\n';
            return;
        }
        else
        {
            node<type> *temp1 = NULL;
            node<type> *temp2 = head;

            while (temp2 != NULL)
            {
                temp1 = temp2;
                temp2 = temp2->next;
                delete temp1;
            }
            head = NULL;
            return;
        }
    }

    // To check if an element in a specific index
    bool isItemAtEqual(type element, int index)
    {
        if (!isEmpty())
        {
            if (index > linkedListSize() || index <= 0)
            {
                cout << " THE INDEX IS INVALID ): " << '\n';
                return false;
            }
            else
            {
                bool equal = false;
                node<type> *temp = head;
                for (int i = 1; i < index && temp != NULL; ++i)
                {
                    temp = temp->next;
                }

                if (temp->data == element)
                    equal = true;

                return equal;
            }
        }
        else
        {
            cout << " SORRY BUT THE LIST IS EMPTY ): " << '\n';
            return false;
        }
    }

    // To insert an element into the head
    void insertAtHead(type element)
    {
        if (isEmpty())
        {
            node<type> *newnode = new node<type>;
            newnode->data = element;
            newnode->next = NULL;
            head = newnode;
        }
        else
        {
            node<type> *newnode = new node<type>;
            newnode->data = element;
            newnode->next = head;
            head = newnode;
        }
        return;
    }

    // To insert an element into the tail
    void insertAtTail(type element)
    {
        if (isEmpty())
        {
            insertAtHead(element);
            cout << " SORRY BUT THE LIST IS EMPTY ): " << '\n'
                 << " THE ELEMENT ADDED IN THE HEAD. " << '\n';
        }
        else
        {
            node<type> *newnode = new node<type>;
            newnode->data = element;
            newnode->next = NULL;
            node<type> *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
        return;
    }

    // To insert an element into the specific index
    void insertAt(type element, int index)
    {
        if (isEmpty())
        {
            insertAtHead(element);
            cout << " SORRY BUT THE LIST IS EMPTY ): " << '\n'
                 << " THE ELEMENT ADDED IN THE HEAD. " << '\n';
        }
        else
        {
            if (index == linkedListSize()+1) // Add in last index
            {
                insertAtTail(element);
            }
            else if (index == 1) // Add in first index
            {
                insertAtHead(element);
            }
            else if (index > linkedListSize()+1 || index <= 0) // The index is invalid
            {
                cout << " SORRY BUT CAN'T INSERT IN THIS INDEX ): " << '\n';
            }
            else
            {
                node <type> *temp = head;
                node<type> *newnode = new node<type>;
                newnode ->data = element;
                for (int i = 1; i < index-1 && temp != NULL; ++i)
                {
                    temp = temp->next;
                }
                newnode -> next = temp->next;
                temp->next = newnode;
            }
        }
        return;
    }

    // To delete the first element
    void removeAtHead()
    {
        if (isEmpty())
        {
            cout << "YOU CAN'T REMOVE...THE LIST IS EMPTY!" << '\n';
        }
        else if (linkedListSize() == 1)
        {
            node<type> *temp = head;
            head = NULL;
            delete temp;
        }
        else
        {
            node<type> *temp = head;
            head = head->next;
            delete temp;
        }
        return;
    }

    // To delete the last element
    void removeAtTail()
    {
        if (isEmpty())
        {
            cout << "YOU CAN'T REMOVE...THE LIST IS EMPTY!" << '\n';
        }
        else if (linkedListSize() == 1)
        {
            node<type> *temp = head;
            head = NULL;
            delete temp;
        }
        else
        {
            node<type> *temp1 = NULL;
            node<type> *temp2 = head;

            while (temp2->next != NULL)
            {
                temp1 = temp2;
                temp2 = temp2->next;
            }

            temp1->next = NULL;
            delete temp2;
        }
        return;
    }

    // To delete a specific element
    void removeAt(int index)
    {
        if (isEmpty())
        {
            cout << "YOU CAN'T REMOVE...THE LIST IS EMPTY!" << '\n';
        }
        else if (index > linkedListSize() || index <= 0)
        {
            cout << " SORRY BUT IT'S INVALID INDEX ): " << '\n';
        }
        else if (index == 1) // delete first element
        {
            removeAtHead();
        }
        else if (index == linkedListSize()) // delete last element
        {
            removeAtTail();
        }
        else
        {
            node<type> *temp1 = NULL;
            node<type> *temp2 = head;

            for (int i = 1; i < index; ++i)
            {
                temp1 = temp2;
                temp2 = temp2->next;
            }

            temp1->next = temp2->next;
            delete temp2;
        }
        return;
    }

    // To replace an element with a new one
    void replaceAt(type element, int index)
    {
        if (isEmpty())
        {
            cout << " SORRY BUT THE LIST IS EMPTY ): " << '\n';
        }
        else if (index > linkedListSize() || index <= 0)
        {
            cout << " SORRY BUT IT'S INVALID INDEX ): " << '\n';
        }
        else
        {
            node<type> *temp = head;
            for (int i = 1; i < index && temp != NULL; ++i)
            {
                temp = temp->next;
            }
            temp->data = element;
        }
        return;
    }

    // To retrieve an element
    type retrieveAt(int index)
    {
        if (isEmpty())
        {
            cout << " SORRY BUT THE LIST IS EMPTY ): " << '\n';
            return false;
        }
        else if (index > linkedListSize() || index <= 0)
        {
            cout << " SORRY BUT IT'S INVALID INDEX ): " << '\n';
            return false;
        }
        else
        {
            node<type> *temp = head;
            for (int i = 1; i < index && temp != NULL; ++i)
            {
                temp = temp->next;
            }
            return temp->data;
        }
    }

    //
    void swap(int firstItemIdx, int secondItemIdx)
    {
    }
};

int main()
{

    int x = 20, index = 0;
    int element;

    single_linked_list<int> myList;

    while (x)
    {
        cout << "PLEASE ENTER # OF FUNCTION YOU WANT :" << '\n'
             << "1 - Insert at head." << '\n'
             << "2 - Insert at tail." << '\n'
             << "3 - Insert at specific index." << '\n'
             << "4 - Remove from head." << '\n'
             << "5 - Remove from tail." << '\n'
             << "6 - Remove from specific index." << '\n'
             << "7 - Swap." << '\n'
             << "8 - Is exist." << '\n'
             << "9 - Is empty." << '\n'
             << "10 - Get size." << '\n'
             << "11 - Clear the list." << '\n'
             << "12 - Display list." << '\n'
             << "13 - Replace." << '\n'
             << "14 - retrieve." << '\n'
             << "15 - Is equal." << '\n'
             << "OR PRESS 0 TO EXIT." << '\n';

        cin >> x;

        switch (x)
        {
            case 1:
                cout << "Please enter an element : " << '\n';
                cin >> element;
                myList.insertAtHead(element);
                continue;
            case 2:
                cout << "Please enter an element : " << '\n';
                cin >> element;
                myList.insertAtTail(element);
                continue;
            case 3:
                cout << "Please enter an element end index : " << '\n';
                cin >> element >> index;
                myList.insertAt(element, index);
                continue;
            case 4:
                myList.removeAtHead();
                continue;
            case 5:
                myList.removeAtTail();
                continue;
            case 6:
                cout << "Please enter an index : " << '\n';
                cin >> index;
                myList.removeAt(index);
                continue;
                //case 7:
                //    break;
            case 8:
                cout << "Please enter an element : " << '\n';
                cin >> element;
                cout << myList.isExist(element) << '\n';
                continue;
            case 9:
                cout << myList.isEmpty() << '\n';
                continue;
            case 10:
                cout << myList.linkedListSize() << '\n';
                continue;
            case 11:
                myList.clear();
                continue;
            case 12:
                myList.print();
                cout << '\n';
                continue;
            case 13:
                cout << "Please enter an element and index : " << '\n';
                cin >> element >> index;
                myList.replaceAt(element, index);
                continue;
            case 14:
                cout << "Please enter an index : " << '\n';
                cin >> index;
                cout << myList.retrieveAt(index) << '\n';
                continue;
            case 15:
                cout << "Please enter an element and index : " << '\n';
                cin >> element >> index;
                cout << myList.isItemAtEqual(element, index) << '\n';
                continue;
            case 0:
                cout << "Exiting program..." << '\n';
                return 0;
            default:
                cout << " INVALID CHOICE ): " << '\n';
                continue;
        }
    }

    return 0;
}
