
#include <iostream>
using namespace std;
template <class type>
class node {
public:
    type data;
    node* next;
};
template <class type>
class stack
{
private:
    int size = 0;
    node<type>* head = NULL;

public:
    void push(type element)
    {
        size++;
        node<type>* temp=new node <type>;
        temp->data = element;
        if (size == 0) {
            temp->next = NULL;
            head = temp;
            return;
        }
        else
        {
            temp->next = head;
            head = temp;
            return;
        }
    }

    type pop() {
        if (isEmpty())cout << "SORRY STACK IS EMPTY ):\n";
        else {
            node<type>* temp = head;
            type result = head->data;
            head = head->next;
            delete temp;
            size--;
            return result;
        }
    }

    bool isEmpty()
    {
        return(head == NULL);
    }

    // To print the size of list
    int stackSize()
    {
           return size;

    }

    // To print the stack
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

    // To delete stack
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

    //to get top element
    type top()
    {
        return head->data;
    }


};


int main()
{
    int x = 1;
    stack <int> s;
    while (x)
    {
        cout << "Choose\n1.Push in stack\n2.Pop\n3.Size\n4.Top\n5.Is_Empty\n6.clear\n7.print\n0.To Exist\n";
        cin >> x;
        if (x==1)
        {
            int element;
            cout << "Enter element\n";
            cin >> element;
            s.push(element);
            continue;
        }
        else if (x==2) {
           cout<< s.pop()<<"\n";
        }
        else if (x == 3) {
            cout<<s.stackSize()<<"\n";
        }
        else if (x == 4) {
           cout<< s.top()<<"\n";
        }
        else if (x == 5) {
            if (s.isEmpty())
            {
                cout << "Empty\n";
            }
            else
                cout << "NOT Empty\n";
        }
        else if (x == 6) {
            s.clear();
        }
        else if (x == 7) {
            s.print();
            cout << "\n";
        }
        else if (x == 0) {
            break;
        }


    }
}