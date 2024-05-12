#include <iostream>
#include <cctype>
#include <bits/stdc++.h>
#include <cmath>
#include <ostream>
#include <algorithm>
#include <cctype>
#include <chrono>
using namespace std;
using namespace chrono;
//long long cnt1=0,cnt2=0;
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// TO CREATE NODES
template <class type>
class node {
public:
    type data;
    node* next;
    node* previous;
};

// TO MAKE OPERATION ON LINKED LIST
template <class type>
class single_linked_list {
private:
    node<type>* head;

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
            node<type>* temp = head;
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
            node<type>* temp = head;
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
            node<type>* temp = head;
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
            node<type>* temp1 = NULL;
            node<type>* temp2 = head;

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
                node<type>* temp = head;
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
            node<type>* newnode = new node<type>;
            newnode->data = element;
            newnode->next = NULL;
            head = newnode;
        }
        else
        {
            node<type>* newnode = new node<type>;
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
            node<type>* newnode = new node<type>;
            newnode->data = element;
            newnode->next = NULL;
            node<type>* temp = head;
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
            if (index == linkedListSize() + 1) // Add in last index
            {
                insertAtTail(element);
            }
            else if (index == 1) // Add in first index
            {
                insertAtHead(element);
            }
            else if (index > linkedListSize() + 1 || index <= 0) // The index is invalid
            {
                cout << " SORRY BUT CAN'T INSERT IN THIS INDEX ): " << '\n';
            }
            else
            {
                node <type>* temp = head;
                node<type>* newnode = new node<type>;
                newnode->data = element;
                for (int i = 1; i < index - 1 && temp != NULL; ++i)
                {
                    temp = temp->next;
                }
                newnode->next = temp->next;
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
            node<type>* temp = head;
            head = NULL;
            delete temp;
        }
        else
        {
            node<type>* temp = head;
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
            node<type>* temp = head;
            head = NULL;
            delete temp;
        }
        else
        {
            node<type>* temp1 = NULL;
            node<type>* temp2 = head;

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
            node<type>* temp1 = NULL;
            node<type>* temp2 = head;

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
            node<type>* temp = head;
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
            node<type>* temp = head;
            for (int i = 1; i < index && temp != NULL; ++i)
            {
                temp = temp->next;
            }
            return temp->data;
        }
    }

    //
    void swap(int index1, int index2) {
        if (isEmpty()) {
            cout << " SORRY BUT THE LIST IS EMPTY ): " << '\n';
            return;
        }
        else {
            if (index1 > linkedListSize() || index1 <= 0 || index2 > linkedListSize() || index2 <= 0) {
                cout << " SORRY BUT IT'S INVALID INDEX ): " << '\n';
                return;
            }
            else if (index1 == index2) {
                cout << " SAME NODES....NOTHING TO SWAP! " << '\n';
                return;
            }
            else {
                node<type>* prev1 = NULL;
                node<type>* curr1 = head;
                node<type>* prev2 = NULL;
                node<type>* curr2 = head;

                for (int i = 1; i < index1 && curr1 != NULL; ++i) {
                    prev1 = curr1;
                    curr1 = curr1->next;
                }

                for (int i = 1; i < index2 && curr2 != NULL; ++i) {
                    prev2 = curr2;
                    curr2 = curr2->next;
                }


                if (prev1 != NULL)
                    prev1->next = curr2;
                else
                    head = curr2;

                if (prev2 != NULL)
                    prev2->next = curr1;
                else
                    head = curr1;


                node<type>* temp = curr2->next;
                curr2->next = curr1->next;
                curr1->next = temp;
            }
            return;
        }
    }
};

template <class type>
class double_linked_list {
private:
    int size = 0;
    node<type>* head = NULL;
    node<type>* tail = NULL;

public:

    // To check if list empty or not
    bool isEmpty()
    {
        return head == NULL && tail == NULL;
    }

    // To search for an element
    bool isExist(type element)
    {
        if (isEmpty())
        {
            cout << " SORRY BUT THE LIST IS EMPTY " << '\n';
            return false;
        }
        else
        {
            node<type>* temp = head;
            while (temp != NULL) {
                if (temp->data == element)return true;
                temp = temp->next;
            }
            cout << " SORRY BUT THE ELEMENT " << element << " DOESN'T EXIST " << '\n';
            return false;
        }
    }

    // To print the size of list
    int linkedListSize()
    {
        return size;
    }

    // To print the list
    void print()
    {
        if (isEmpty())
        {
            cout << " SORRY BUT THE LIST IS EMPTY ): " << '\n';
            return;
        }
        else
        {
            node <type>* temp = head;
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << "\n";
            return;
        }
    }

    // To delete list
    void clear()
    {
        size = 0;
        if (isEmpty())
        {
            cout << " SORRY BUT THE LIST IS EMPTY ): " << '\n';
            return;
        }
        else
        {
            node <type>* temp1;
            node <type>* temp2 = head;
            while (temp2 != NULL)
            {
                temp1 = temp2;
                temp2 = temp2->next;
                delete temp1;
            }
            head = NULL;
            tail = NULL;
            return;
        }

    }

    // To check if an element in a specific index
    bool isItemAtEqual(type element, int index)
    {
        node<type>* temp = head;
        for (int i = 1; i <= index && temp != NULL; ++i) {
            if (element == temp->data) {
                cout << "THE ELEMENT" << element << "IS EXIST IN INDEX " << index << '\n';
                return true;
            }
            temp = temp->next;
        }
        cout << " SORRY BUT THE ELEMENT " << element << " DOESN'T EXIST IN INDEX " << index << '\n';
        return false;
    }

    // To insert an element into the head
    void insertAtHead(type element)
    {
        size++;
        node<type>* temp = new node <type>;
        temp->data = element;

        if (isEmpty()) {
            temp->next = NULL;
            temp->previous = NULL;
            head = temp;
            tail = temp;
            return;
        }
        else {
            temp->next = head;
            head->previous = temp;
            head = temp;
            return;
        }
    }

    // To insert an element into the tail
    void insertAtTail(type element)
    {
        size++;
        node<type>* temp = new node <type>;
        temp->data = element;
        temp->next = NULL;
        if (isEmpty()) {
            insertAtHead(element);
            return;
        }
        tail->next = temp;
        temp->previous = tail;
        tail = temp;
        return;
    }

    // To insert an element into the specific index
    void insertAt(type element, int index)
    {
        if (index <= size + 1 && index > 0) {
            node<type>* temp = new node <type>;
            temp = head;
            node<type>* add = new node<type>;
            add->data = element;

            if (index == 1) {
                insertAtHead(element);
                return;
            }

            else if (index == size + 1) {
                insertAtTail(element);
                return;
            }

            for (int i = 1; i < index - 1 && temp != NULL; ++i) {
                temp = temp->next;
            }

            add->previous = temp;
            add->next = temp->next;
            temp->next = add;
            add->next->previous = add;
            size++;

            return;
        }
        else {
            cout << "SORRY BUT YOU ENTER WRONG INDEX \n";
            return;
        }
    }

    // To delete the first element
    void removeAtHead()
    {
        if (isEmpty()) {
            cout << "SORRY BUT THE LIST IS EMPTY ):";
            return;
        }
        else if (head->next == NULL) {
            head = NULL;
            tail = NULL;
            size--;
            return;
        }
        else if (size == 2) {
            node<type>* temp = new node <type>;
            temp = head;
            head = head->next;
            head->previous = NULL;
            delete temp;
            size--;
            return;
        }
        else {
            node<type>* temp = new node <type>;
            temp = head;
            head = head->next;
            temp->next = NULL;
            head->previous = NULL;
            delete temp;
            size--;
            return;
        }
    }

    // To delete the last element
    void removeAtTail()
    {
        if (isEmpty()) {
            cout << "SORRY BUT THE LIST IS EMPTY ):";
            return;
        }
        else if (tail == head) {
            node<type>* temp = new node <type>;
            temp = head;
            head = NULL;
            tail = NULL;
            delete temp;
            size--;
            return;
        }
        else if (size == 2) {
            node<type>* temp = new node <type>;
            temp = tail;
            tail = tail->previous;
            tail->next = NULL;

        }
        else {
            node<type>* temp = new node <type>;
            temp = tail;
            tail = tail->previous;
            tail->next = NULL;
            temp->previous = NULL;
            delete temp;
            size--;
            return;
        }
    }

    // To delete a specific element
    void removeAt(int index)
    {
        if (index > linkedListSize() || index < 0) {
            cout << "SORRY INDEX OUT OF RANGE ): \n";
            return;
        }
        else if (index == 1) {
            removeAtHead();
            return;
        }
        else if (index == size) {
            removeAtTail();
            return;
        }
        else {
            node<type>* temp = new node<type>;
            temp = head;
            for (int i = 1; i < index && temp != NULL; i++) {
                temp = temp->next;
            }
            temp->previous->next = temp->next;
            temp->next->previous = temp->previous;
            delete temp;
            size--;
        }
    }

    // To replace an element with a new one
    void replaceAt(type Element, int index)
    {
        if (index > linkedListSize() || index < 0) {
            cout << "SORRY INDEX OUT OF RANGE ):";
            return;
        }
        else {
            node<type>* temp = new node<type>;
            temp = head;
            for (int i = 1; i < index; i++) {
                temp = temp->next;
            }
            temp->data = Element;
            return;
        }
    }

    // To retrieve an element
    type retrieveAt(int index)
    {
        node<type>* temp = new node <type>; temp = head;
        if (index <= size && index > 0) {
            for (int i = 1; i < index && temp != NULL; ++i) {
                temp = temp->next;
            }
            return temp->data;
        }

        return -1;
    }

    //swap between two node
    void swap_node(int firstItemIdx, int secondItemIdx)
    {
        bool check1 = true, check2 = true;
        if (isExist(firstItemIdx) && isExist(secondItemIdx)) {
            node<type>* add1 = new node<type>;           node<type>* add2 = new node<type>;
            add1->data = firstItemIdx;                   add2->data = secondItemIdx;
            node<type>* temp1 = new node<type>;          node<type>* temp2 = new node<type>;
            temp1 = head;                                temp2 = head;
            while (temp1 != NULL) {
                if (temp1->data == firstItemIdx)break;
                temp1 = temp1->next;
            }
            while (temp2 != NULL) {
                if (temp2->data == secondItemIdx)break;
                temp2 = temp2->next;
            }

            if (temp1 == head) {
                check1 = false;
                add2->previous = NULL;
                add2->next = temp1->next;
                temp1->next->previous = add2;
                head = add2;
            }
            else if (temp1 == tail) {
                check1 = false;
                add2->next = NULL;
                add2->previous = temp1->previous;
                temp1->previous->next = add2;
                tail = add2;
            }
            else {
                add2->previous = temp1->previous;
                temp1->previous->next = add2;
                add2->next = temp1->next;
                temp1->next->previous = add2;
            }
            if (temp2 == tail) {
                check2 = false;
                add1->next = NULL;
                add1->previous = temp2->previous;
                temp2->previous->next = add1;
                tail = add1;
            }
            else if (temp2 == head) {
                check2 = false;
                add1->previous = NULL;
                add1->next = temp2->next;
                temp2->next->previous = add1;
                head = add1;
            }
            else {
                add1->previous = temp2->previous;
                temp2->previous->next = add1;
                add1->next = temp2->next;
                temp2->next->previous = add1;
            }

            delete temp1;                                                   delete temp2;
            return;
        }
        else {
            cout << "SORRY! Enter Right Element\n";
            return;
        }
    }

};

template <class type>
class single_circular_linked_list {
private:
    int size = 0;
    node<type>* head = NULL;
    node<type>* tail = NULL;

public:

    // To check if list empty or not
    bool isEmpty()
    {
        return head == NULL && tail == NULL;
    }

    // To search for an element
    bool isExist(type element)
    {
        if (isEmpty())
        {
            cout << " SORRY BUT THE LIST IS EMPTY " << '\n';
            return false;
        }
        else
        {
            node<type>* temp = new node <type>;
            temp = head;
            for (int i = 1; i <= size; ++i) {
                if (temp->data == element) { return true; }
                temp = temp->next;
            }
            cout << " SORRY BUT THE ELEMENT " << element << " DOESN'T EXIST " << '\n';
            return false;
        }
    }

    // To print the size of list
    int linkedListSize()
    {
        return size;
    }

    // To print the list
    void print()
    {
        if (isEmpty())
        {
            cout << " SORRY BUT THE LIST IS EMPTY ): " << '\n';
            return;
        }
        else
        {
            node <type>* temp = new node<type>;
            temp = head;
            for (int i = 1; i <= size; ++i)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << "\n";
            return;
        }
    }

    // To delete list
    void clear()
    {
        size = 0;
        if (isEmpty())
        {
            cout << " SORRY BUT THE LIST IS EMPTY ): " << '\n';
            return;
        }
        else
        {
            node <type>* temp1;
            node <type>* temp2 = head;
            while (temp2 != tail->next)
            {
                temp1 = temp2;
                temp2 = temp2->next;
                delete temp1;
            }
            head = NULL;
            tail = NULL;
            return;
        }

    }

    // To check if an element in a specific index
    bool isItemAtEqual(type element, int index)
    {
        node<type>* temp = head;
        for (int i = 1; i <= index && temp != tail->next; ++i) {
            if (element == temp->data) {
                cout << "THE ELEMENT" << element << "IS EXIST IN INDEX " << index << '\n';
                return true;
            }
            temp = temp->next;
        }
        cout << " SORRY BUT THE ELEMENT " << element << " DOESN'T EXIST IN INDEX " << index << '\n';
        return false;
    }

    // To insert an element into the head
    void insertAtHead(type element)
    {
        size++;
        node<type>* temp = new node <type>;
        temp->data = element;

        if (isEmpty()) {
            head = temp;
            tail = temp;
            temp->next = head;
            return;
        }
        else {
            temp->next = head;
            head = temp;
            tail->next = head;
            return;
        }
    }

    // To insert an element into the tail
    void insertAtTail(type element)
    {
        size++;
        node<type>* temp = new node <type>;
        temp->data = element;
        temp->next = NULL;
        if (isEmpty()) {
            insertAtHead(element);
            return;
        }
        else {
            tail->next = temp;
            tail = temp;
            temp->next = head;
            return;
        }
    }

    // To insert an element into the specific index
    void insertAt(type element, int index)
    {
        if (index <= size + 1 && index > 0) {
            node<type>* temp = new node <type>;
            temp = head;
            node<type>* add = new node<type>;
            add->data = element;

            if (index == 1) {
                insertAtHead(element);
                return;
            }

            else if (index == size + 1) {
                insertAtTail(element);
                return;
            }

            for (int i = 1; i < index - 1; ++i) {
                temp = temp->next;
            }
            add->next = temp->next;
            temp->next = add;
            size++;

            return;
        }
        else {
            cout << "SORRY BUT YOU ENTER WRONG INDEX \n";
            return;
        }
    }

    // To delete the first element
    void removeAtHead()
    {
        if (isEmpty()) {
            cout << "SORRY BUT THE LIST IS EMPTY ):";
            return;
        }
        else if (head == tail) {
            head = NULL;
            tail = NULL;
            size--;
            return;
        }
        else if (size == 2) {
            node<type>* temp = new node <type>;
            temp = head;
            head = tail;
            tail->next = NULL;
            delete temp;
        }
        else {
            node<type>* temp = new node <type>;
            temp = head;
            head = head->next;
            tail->next = head;
            temp->next = NULL;
            delete temp;
            size--;
            return;
        }
    }

    // To delete the last element
    void removeAtTail()
    {
        if (isEmpty()) {
            cout << "SORRY BUT THE LIST IS EMPTY ):";
            return;
        }
        else if (tail == head) {
            head = NULL;
            tail = NULL;
            size--;
            return;
        }
        else if (size == 2) {
            size--;
            node<type>* temp = new node <type>;
            temp = tail;
            tail->next = NULL;
            head->next = NULL;
            tail = head;
            delete temp;
            return;
        }
        else {
            node<type>* temp = new node <type>;
            temp = head;
            for (int i = 1; i < size - 1; ++i) {
                temp = temp->next;
            }
            tail = temp;
            temp = temp->next;
            tail->next = head;
            delete temp;
            size--;
            return;
        }
    }

    // To delete a specific element
    void removeAt(int index)
    {
        if (index > linkedListSize() || index < 0) {
            cout << "SORRY INDEX OUT OF RANGE ): \n";
            return;
        }
        else if (index == 1) {
            removeAtHead();
            return;
        }
        else if (index == size) {
            removeAtTail();
            return;
        }
        else {
            node<type>* temp = new node<type>; node<type>* temp2 = new node<type>;
            temp = head;
            for (int i = 1; i < index - 1 && temp != tail->next; i++) {
                temp = temp->next;
            }
            temp2 = temp->next;
            temp->next = temp->next->next;
            delete temp2;
            size--;
        }
    }

    // To replace an element with a new one
    void replaceAt(type Element, int index)
    {
        if (index > linkedListSize() || index < 0) {
            cout << "SORRY INDEX OUT OF RANGE ):";
            return;
        }
        else {
            node<type>* temp = new node<type>;
            temp = head;
            for (int i = 1; i < index; i++) {
                temp = temp->next;
            }
            temp->data = Element;
            return;
        }
    }

    // To retrieve an element
    type retrieveAt(int index)
    {
        node<type>* temp = new node <type>; temp = head;
        if (index <= size && index > 0) {
            for (int i = 1; i < index && temp != tail->next; ++i) {
                temp = temp->next;
            }
            return temp->data;
        }

        return -1;
    }

    //swap between two node
    void swap_node(int index1, int index2) {
        if (isEmpty()) {
            cout << "SORRY BUT THE LIST IS EMPTY :(" << '\n';
            return;
        }
        else {
            if (index1 <= 0 || index2 <= 0 || index1 > linkedListSize() || index2 > linkedListSize()) {
                cout << "SORRY BUT IT'S AN INVALID INDEX :(" << '\n';
                return;
            }
            else if (index1 == index2) {
                cout << "SAME NODES....NOTHING TO SWAP!" << '\n';
                return;
            }
            else {
                node<type>* prev1 = NULL;
                node<type>* curr1 = head;
                node<type>* prev2 = NULL;
                node<type>* curr2 = head;
                int count1 = 1, count2 = 1;

                // Traverse the list to find the nodes at index1 and index2
                do {
                    prev1 = curr1;
                    curr1 = curr1->next;
                    count1++;
                } while (curr1 != head && count1 < index1);

                do {
                    prev2 = curr2;
                    curr2 = curr2->next;
                    count2++;
                } while (curr2 != head && count2 < index2);

                // Check if either index is out of bounds
                if (curr1 == head || curr2 == head) {
                    cout << "SORRY BUT IT'S AN INVALID INDEX :(" << '\n';
                    return;
                }

                // If index1 is not the head, update the previous node's next pointer
                if (curr1 != head)
                    prev1->next = curr2;
                else // index1 is the head, update head to point to curr2
                    head = curr2;

                // If index2 is not the head, update the previous node's next pointer
                if (curr2 != head)
                    prev2->next = curr1;
                else // index2 is the head, update head to point to curr1
                    head = curr1;

                // Swap the next pointers of the nodes
                node<type>* temp = curr2->next;
                curr2->next = curr1->next;
                curr1->next = temp;

                // Update tail if necessary
                if (curr1->next == head) // If curr1 becomes the new tail
                    tail = curr1;
                else if (curr2->next == head) // If curr2 becomes the new tail
                    tail = curr2;
            }
            return;
        }
    }


};

// TO MAKE OPERATION ON LINKED LIST
template <class type>
class circular_double_linked_list {
private:
    int size = 0;
    node<type>* head = NULL;
    node<type>* tail = NULL;

public:

    // To check if list empty or not
    bool isEmpty()
    {
        return head == NULL && tail == NULL;
    }

    // To search for an element
    bool isExist(type element)
    {
        if (isEmpty())
        {
            cout << " SORRY BUT THE LIST IS EMPTY " << '\n';
            return false;
        }
        else
        {
            node<type>* temp = head;
            for (int i = 1; i <= size; i++) {
                if (temp->data == element)return true;
                temp = temp->next;
            }
            cout << "SORRY BUT THE ELEMENT " << element << " DOESN'T EXIST " << '\n';
            return false;
        }
    }

    // To print the size of list
    int linkedListSize()
    {
        return size;
    }

    // To print the list
    void print()
    {
        if (isEmpty())
        {
            cout << " SORRY BUT THE LIST IS EMPTY ): " << '\n';
            return;
        }
        else
        {
            node <type>* temp = head;
            for (int i = 1; i <= size; ++i) {

                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << "\n";
            return;
        }
    }

    // To delete list
    void clear()
    {
        if (isEmpty())
        {
            cout << " SORRY BUT THE LIST IS EMPTY ): " << '\n';
            return;
        }
        else
        {
            node <type>* temp1;
            node <type>* temp2 = head;
            for (int i = 1; i <= size; ++i) {
                temp1 = temp2;
                temp2 = temp2->next;
                delete temp1;
            }
            head = NULL;
            tail = NULL;
            size = 0;
            return;
        }

    }

    // To check if an element in a specific index
    bool isItemAtEqual(type element, int index)
    {
        if (isEmpty()) {
            cout << " SORRY BUT THE LIST IS EMPTY ): " << '\n';
            return false;
        }
        else {
            node <type>* temp1 = head;
            for (int i = 1; i < index; ++i) {
                temp1 = temp1->next;
            }
            if (temp1->data == element) { cout << "Equal\n"; return true; }
            cout << "SORRY BUT THE ELEMENT " << element << " NOT EQUAL IN INDEX " << index << '\n';
            return false;
        }
    }

    // To insert an element into the head
    void insertAtHead(type element)
    {
        size++;
        node<type>* temp = new node <type>;
        temp->data = element;
        if (head == NULL) {
            head = temp;
            tail = temp;
        }
        else {
            temp->next = head;
            head->previous = temp;
            temp->previous = tail;
            tail->next = temp;
            head = temp;
        }
    }

    // To insert an element into the tail
    void insertAtTail(type element)
    {
        size++;
        node<type>* temp = new node <type>;
        temp->data = element;
        if (isEmpty()) {
            insertAtHead(element);
            return;
        }
        else {
            tail->next = temp;
            temp->next = head;
            temp->previous = tail;
            tail->next = temp;
            tail = temp;
        }
    }

    // To insert an element into the specific index
    void insertAt(type element, int index)
    {
        if (index == 1)insertAtHead(element);
        else if (index == size + 1)insertAtTail(element);
        else if (index < 0 || index > size + 1)cout << "SORRY OUT OF RANGE ):\n";
        else {
            node<type>* temp = new node<type>;
            temp->data = element;
            node<type>* ptr = head;
            for (int i = 1; i < index - 1; i++)
                ptr = ptr->next;
            temp->next = ptr->next;
            ptr->next->previous = temp;
            temp->previous = ptr;
            ptr->next = temp;
            size++;
            return;
        }
    }

    // To delete the first element
    void removeAtHead()
    {
        if (isEmpty()) {
            cout << "SORRY BUT THE LIST IS EMPTY ):";
        }
        else if (head == tail) {
            head = NULL;
            tail = NULL;
            size--;
            return;
        }
        else {
            node<type>* temp = head;
            head = head->next;
            tail->next = head;
            head->previous = tail;
            temp->next = NULL;
            temp->previous = NULL;
            delete temp;
            size--;
            return;
        }
    }

    // To delete the last element
    void removeAtTail()
    {
        if (isEmpty()) {
            cout << "SORRY BUT THE LIST IS EMPTY ):";
        }
        else if (tail == head) {
            head = NULL;
            tail = NULL;
            size--;
            return;
        }
        else {
            node<type>* temp = tail;
            tail = tail->previous;
            tail->next = head;
            head->previous = tail;
            temp->next = NULL;
            temp->previous = NULL;
            delete temp;
            size--;
            return;
        }
    }

    // To delete a specific element
    void removeAt(int index)
    {
        if (index > linkedListSize() || index < 0) {
            cout << "SORRY INDEX OUT OF RANGE ): \n";
        }
        else if (index == 1) {
            removeAtHead();
            return;
        }
        else if (index == size) {
            removeAtTail();
            return;
        }
        else {
            node<type>* temp = head;
            node<type>* prev = new node<type>;
            prev = NULL;
            for (int i = 1; i < index && temp->next != head; i++) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = temp->next;
            temp->next->previous = prev;
            temp->previous = NULL;
            temp->next = NULL;
            delete temp;
            size--;
            return;
        }
    }

    // To replace an element with a new one
    void replaceAt(type Element, int index)
    {
        if (index > linkedListSize() || index < 0) {
            cout << "SORRY INDEX OUT OF RANGE ):";
            return;
        }
        else {
            node<type>* temp = head;
            for (int i = 1; i < index; i++) {
                temp = temp->next;
            }
            temp->data = Element;
            return;
        }
    }

    // To retrieve an element
    type retrieveAt(int index)
    {
        if (index < 0 || index > size) { return -1; }
        else {
            node<type>* temp = head;
            for (int i = 1; i < index && temp->next != head; ++i) {
                temp = temp->next;
            }
            return temp->data;
        }
    }

    //swap between two node
    void swap_node(int firstItemIdx, int secondItemIdx)
    {
        if (isExist(firstItemIdx) && isExist(secondItemIdx)) {
            node<type>* add1 = new node<type>;           node<type>* add2 = new node<type>;
            add1->data = firstItemIdx;                   add2->data = secondItemIdx;
            node<type>* temp1 = new node<type>;          node<type>* temp2 = new node<type>;
            temp1 = head;                                temp2 = head;
            for (int i = 1; i <= size; ++i) {
                if (temp1->data == firstItemIdx)break;
                temp1 = temp1->next;
            }
            for (int i = 1; i <= size; ++i) {
                if (temp2->data == secondItemIdx)break;
                temp2 = temp2->next;
            }

            add2->previous = temp1->previous;
            temp1->previous->next = add2;
            add2->next = temp1->next;
            temp1->next->previous = add2;

            add1->previous = temp2->previous;
            temp2->previous->next = add1;
            add1->next = temp2->next;
            temp2->next->previous = add1;

            if (temp1 == head) {
                head = add2;
            }
            else if (temp1 == tail) {
                tail = add2;
            }

            if (temp2 == tail) {

                tail = add1;
            }
            else if (temp2 == head) {

                head = add1;
            }

            delete temp1;                                                   delete temp2;
            return;
        }
        else {
            return;
        }
    }


};


int main() {

    int x = 20, index = 0;
    int element;

    single_linked_list<double> single_list;
    double_linked_list<double> double_List;
    single_circular_linked_list<double> circular_list;
    circular_double_linked_list<double> circular_double_list;

    cout << "Choose type linked list:\n1.Single linked list.\n2.Double linked list.\n3.Single Circular linked list.\n4.Double Circular linked list.\n ";
    cin >> x;
    if (x == 1) {
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
                    single_list.insertAtHead(element);
                    continue;
                case 2:
                    cout << "Please enter an element : " << '\n';
                    cin >> element;
                    single_list.insertAtTail(element);
                    continue;
                case 3:
                    cout << "Please enter an element end index : " << '\n';
                    cin >> element >> index;
                    single_list.insertAt(element, index);
                    continue;
                case 4:
                    single_list.removeAtHead();
                    continue;
                case 5:
                    single_list.removeAtTail();
                    continue;
                case 6:
                    cout << "Please enter an index : " << '\n';
                    cin >> index;
                    single_list.removeAt(index);
                    continue;
                case 7:int ind1, ind2;
                    cout << "Enter first element and second element\n";
                    cin >> ind1 >> ind2;
                    single_list.swap(ind1, ind2);
                    break;
                case 8:
                    cout << "Please enter an element : " << '\n';
                    cin >> element;
                    cout << single_list.isExist(element) << '\n';
                    continue;
                case 9:
                    cout << single_list.isEmpty() << '\n';
                    continue;
                case 10:
                    cout << single_list.linkedListSize() << '\n';
                    continue;
                case 11:
                    single_list.clear();
                    continue;
                case 12:
                    single_list.print();
                    cout << '\n';
                    continue;
                case 13:
                    cout << "Please enter an element and index : " << '\n';
                    cin >> element >> index;
                    single_list.replaceAt(element, index);
                    continue;
                case 14:
                    cout << "Please enter an index : " << '\n';
                    cin >> index;
                    cout << single_list.retrieveAt(index) << '\n';
                    continue;
                case 15:
                    cout << "Please enter an element and index : " << '\n';
                    cin >> element >> index;
                    cout << single_list.isItemAtEqual(element, index) << '\n';
                    continue;
                case 0:
                    cout << "Exiting program..." << '\n';
                    return 0;
                default:
                    cout << " INVALID CHOICE ): " << '\n';
                    continue;
            }
        }

    }

    else if (x == 2) {
        while (x) {
            cout << "PLEASE Choose :" << '\n'
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
                 << "0 - TO EXIT." << '\n';

            cin >> x;
            switch (x) {
                case 1:
                    cout << "Please enter an element : " << '\n';
                    cin >> element;
                    double_List.insertAtHead(element);
                    continue;
                case 2:
                    cout << "Please enter an element : " << '\n';
                    cin >> element;
                    double_List.insertAtTail(element);
                    continue;
                case 3:
                    cout << "Please enter an element and index : " << '\n';
                    cin >> element >> index;
                    double_List.insertAt(element, index);
                    continue;
                case 4:
                    double_List.removeAtHead();
                    continue;
                case 5:
                    double_List.removeAtTail();
                    continue;
                case 6:
                    cout << "Please enter an index : " << '\n';
                    cin >> index;
                    double_List.removeAt(index);
                    continue;
                case 7:
                    double e1, e2;
                    cout << "Enter element 1 and element 2 :\n";
                    cin >> e1 >> e2;
                    double_List.swap_node(e1, e2);
                    continue;
                case 8:
                    cout << "Please enter an element : " << '\n';
                    cin >> element;
                    if (double_List.isExist(element))cout << "Exist\n";
                    else cout << "NOT Exist\n";
                    continue;
                case 9:
                    if (double_List.isEmpty())cout << "Empty \n";
                    else cout << "NOT Empty \n";
                    continue;
                case 10:
                    cout << double_List.linkedListSize() << "\n";
                    continue;
                case 11:
                    double_List.clear();
                    continue;
                case 12:
                    double_List.print();
                    continue;
                case 13:
                    cout << "Please enter an element and index : " << '\n';
                    cin >> element >> index;
                    double_List.replaceAt(element, index);
                    continue;
                case 14:
                    cout << "Please enter an index : " << '\n';
                    cin >> index;
                    if (double_List.retrieveAt(index) == -1) {
                        cout << "SORRY ENTER RIGHT INDEX \n ";
                        continue;
                    }
                    else cout << double_List.retrieveAt(index) << '\n';
                    continue;
                case 15:
                    cout << "Please enter an element and index : " << '\n';
                    cin >> element >> index;
                    double_List.isItemAtEqual(element, index);
                    continue;
                case 0:
                    cout << "Exiting program..." << '\n';
                    break;
                default:
                    cout << " INVALID CHOICE ): " << '\n';
                    continue;

            }
        }
    }

    else if (x == 3) {
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
                    circular_list.insertAtHead(element);
                    continue;
                case 2:
                    cout << "Please enter an element : " << '\n';
                    cin >> element;
                    circular_list.insertAtTail(element);
                    continue;
                case 3:
                    cout << "Please enter an element end index : " << '\n';
                    cin >> element >> index;
                    circular_list.insertAt(element, index);
                    continue;
                case 4:
                    circular_list.removeAtHead();
                    continue;
                case 5:
                    circular_list.removeAtTail();
                    continue;
                case 6:
                    cout << "Please enter an index : " << '\n';
                    cin >> index;
                    circular_list.removeAt(index);
                    continue;
                case 7:
                    double indx1, indx2;
                    cout << "Enter First Index and Second Index :\n";
                    cin >> indx1 >> indx2;
                    circular_list.swap_node(indx1, indx2);
                    continue;
                case 8:
                    cout << "Please enter an element : " << '\n';
                    cin >> element;
                    if (circular_list.isExist(element))cout << "EXIST\n";
                    continue;
                case 9:
                    cout << circular_list.isEmpty() << '\n';
                    continue;
                case 10:
                    cout << circular_list.linkedListSize() << '\n';
                    continue;
                case 11:
                    circular_list.clear();
                    continue;
                case 12:
                    circular_list.print();
                    cout << '\n';
                    continue;
                case 13:
                    cout << "Please enter an element and index : " << '\n';
                    cin >> element >> index;
                    circular_list.replaceAt(element, index);
                    continue;
                case 14:
                    cout << "Please enter an index : " << '\n';
                    cin >> index;
                    cout << circular_list.retrieveAt(index) << '\n';
                    continue;
                case 15:
                    cout << "Please enter an element and index : " << '\n';
                    cin >> element >> index;
                    cout << circular_list.isItemAtEqual(element, index) << '\n';
                    continue;
                case 0:
                    cout << "Exiting program..." << '\n';
                    return 0;
                default:
                    cout << " INVALID CHOICE ): " << '\n';
                    continue;
            }
        }
    }

    else if (x == 4) {
        while (x)
        {
            cout << "PLEASE Choose :" << '\n'
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
                 << "0 - TO EXIT." << '\n';

            cin >> x;
            switch (x)
            {
                case 1:
                    cout << "Please enter an element : " << '\n';
                    cin >> element;
                    circular_double_list.insertAtHead(element);
                    continue;
                case 2:
                    cout << "Please enter an element : " << '\n';
                    cin >> element;
                    circular_double_list.insertAtTail(element);
                    continue;
                case 3:
                    cout << "Please enter an element and index : " << '\n';
                    cin >> element >> index;
                    circular_double_list.insertAt(element, index);
                    continue;
                case 4:
                    circular_double_list.removeAtHead();
                    continue;
                case 5:
                    circular_double_list.removeAtTail();
                    continue;
                case 6:
                    cout << "Please enter an index : " << '\n';
                    cin >> index;
                    circular_double_list.removeAt(index);
                    continue;
                case 7:
                    double e1, e2;
                    cout << "Enter element 1 and element 2 :\n";
                    cin >> e1 >> e2;
                    circular_double_list.swap_node(e1, e2);
                    continue;
                case 8:
                    cout << "Please enter an element : " << '\n';
                    cin >> element;
                    if (circular_double_list.isExist(element))cout << "Exist\n";
                    continue;
                case 9:
                    if (circular_double_list.isEmpty())cout << "Empty \n";
                    else cout << "NOT Empty \n";
                    continue;
                case 10:
                    cout << circular_double_list.linkedListSize() << "\n";
                    continue;
                case 11:
                    circular_double_list.clear();
                    continue;
                case 12:
                    circular_double_list.print();
                    continue;
                case 13:
                    cout << "Please enter an element and index : " << '\n';
                    cin >> element >> index;
                    circular_double_list.replaceAt(element, index);
                    continue;
                case 14:
                    cout << "Please enter an index : " << '\n';
                    cin >> index;
                    if (circular_double_list.retrieveAt(index) == -1) {
                        cout << "SORRY ENTER RIGHT INDEX \n ";
                        continue;
                    }
                    else cout << circular_double_list.retrieveAt(index) << '\n';
                    continue;
                case 15:
                    cout << "Please enter an element and index : " << '\n';
                    cin >> element >> index;
                    circular_double_list.isItemAtEqual(element, index);
                    continue;
                case 0:
                    cout << "Exiting program..." << '\n';
                    break;
                default:
                    cout << " INVALID CHOICE ): " << '\n';
                    continue;

            }

        }
    }

    else {
        cout << "SORRY BUT YOU ENTER WRONG NUMBER\n";
        return 0;
    }

    return 0;
}