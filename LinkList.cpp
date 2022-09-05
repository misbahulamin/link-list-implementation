#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int value)
    {
        val = value;
        next = NULL;
    }
};

int countLength(Node *&head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

void displayLinkList(Node *&head)
{
    Node *temp = head;
    if (head == NULL)
    {
        cout << endl
             << "There are no value in the link list" << endl;
    }
    while (temp != NULL)
    {
        cout << temp->val;
        if (temp->next != NULL)
        {
            cout << "->";
        }
        temp = temp->next;
    }
    cout << endl;
}

void insertAtHead(Node *&head, int value)
{
    Node *newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void insertAtTail(Node *&head, int value)
{
    Node *newNode = new Node(value);
    Node *temp = head;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertAtSpecificPosition(Node *&head, int position, int value)
{
    Node *newNode = new Node(value);
    Node *temp = head;
    int i = 1;
    cout << position << endl
         << countLength(head) << endl;
    if (position > countLength(head) + 1)
    {
        cout << "Sorry!! Your position is out of bound." << endl;
    }
    else if (position > 1)
    {
        while (i < position - 1)
        {
            temp = temp->next;
            i++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        // temp = temp->next;
    }
    else if (temp->next == NULL)
    {
        insertAtTail(head, value);
    }
    else
    {
        insertAtHead(head, value);
    }
}

int searchValueUniqueList(Node *&head, int searchKey)
{
    Node *temp = head;
    int count = 1;
    if (temp == NULL)
    {
        return -1;
    }
    while (temp->val != searchKey)
    {
        if (temp->next == NULL)
        {
            return -1;
        }
        temp = temp->next;
        count++;
    }
    return count;
}

void searchValueDuplicationList(Node *&head, int searchKey)
{
    Node *temp = head;
    int count = 1, k = 1;
    int size = countLength(head);
    int position[size + 1];
    int flag = 0;
    while (temp != NULL)
    {
        if (temp->val == searchKey)
        {
            position[k] = count;
            k++;
            flag = 1;
        }
        temp = temp->next;
        count++;
    }

    if (flag == 0)
    {
        cout << "sorry!! No result found" << endl;
    }
    else
    {
        position[0] = k;
        for (int i = 1; i < position[0]; i++)
        {
            cout << position[i];
            if (i < position[0] - 1)
                cout << " ";
        }
        cout << endl;
    }
}

void insertionAtAfterSpecificValue(Node *&head, int whichValue, int value)
{
    Node *newNode = new Node(value);
    Node *temp = head;
    int find = searchValueUniqueList(head, whichValue);
    if (find != -1)
    {
        insertAtSpecificPosition(head, find + 1, value);
    }
    else
    {
        cout << "sorry!! There have no vlaue at the position" << endl;
    }
}

void deletionAtHead(Node *&head)
{
    Node *temp = head;
    temp = temp->next;
    delete head;
    head = temp;
}

void deletionAtTail(Node *&head)
{
    Node *temp = head;
    Node *delNode;
    if (temp != NULL && temp->next != NULL)
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delNode = temp->next;
        temp->next = NULL;
        delete delNode;
    }
    else
    {
        if (temp == NULL)
        {
            cout << "Sorry!! There are no value" << endl;
        }
        else
        {
            deletionAtHead(head);
        }
    }
}

void deletionAtSpecificPosition(Node *&head, int position)
{
    Node *temp = head;
    if (position > countLength(head))
    {
        cout << "Sorry!! Your position is out of bound" << endl;
    }
}

int getMidValue(Node *&head)
{
    if (head == NULL)
    {
        return -1;
    }
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->val;
}

void makeCycle(Node* &head, int posi)
{
    Node* temp=head;
    Node* startNode;
    int count=1;
    while(temp->next!=NULL)
    {
        count++;
        if(count==posi)
        {
            startNode=temp->next;
        }
        temp=temp->next;
    }
    temp->next=startNode;
}

bool detectCycle(Node* &head)
{
    Node* slow=head;
    Node* fast=head;
    while(fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow->next==fast->next) //fast->next->next==slow
        {
            return true;
        }
    }
    return false;
}

void removeCycle(Node* &head)
{
    Node* slow=head;
    Node* fast=head;
    do{
        slow=slow->next;
        fast=fast->next->next;
    }while(slow!=fast);
    fast=head;
    while(fast->next!=slow->next)
    {
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=NULL;
}

int main()
{
    Node *head = NULL;
    int choice, value, position, whichValue;
    cout << "1. Counting the Size" << endl
         << "2. Display List" << endl
         << "3. Insertion at Head" << endl
         << "4. Insertion at Tail" << endl
         << "5. Insertion at Specific Postion" << endl
         << "6. Search a value(Unique List)" << endl
         << "7. Search a value (Duplication enabled List)" << endl
         << "8. Search a value by return method(Duplication enabled List)" << endl
         << "9. Insertion after a specific value (Unique List)" << endl
         << "10. Deletion at head" << endl
         << "11. Deletion at tail" << endl
         << "12. Deletion at Specific Position" << endl
         << "13. Find the mid value" << endl
         << "14. Make a cycle" << endl
         << "15. Detect a cycle" << endl
         << "16. Remove a cycle" << endl
         << "0. Exit" << endl;
    cout << endl
         << "Enter Your Choice: ";
    cin >> choice;
    while (choice != 0)
    {
        switch (choice)
        {
        case 1:
            // int a=countLength(head);
            // cout<<"Length: "<<a<<endl;
            break;
        case 2:
            cout << "Link List: ";
            displayLinkList(head);
            break;
        case 3:
            cout << "Enter Value at Head: ";
            cin >> value;
            insertAtHead(head, value);
            break;
        case 4:
            cout << "Enter Value at Tail: ";
            cin >> value;
            insertAtTail(head, value);
            break;
        case 5:
            cout << "Enter the postion: ";
            cin >> position;
            cout << "Enter your desire value: ";
            cin >> value;
            insertAtSpecificPosition(head, position, value);
            break;
        case 6:
            cout << "Enter your desire value: ";
            cin >> value;
            position = searchValueUniqueList(head, value);
            if (position != -1)
            {
                cout << "Your search value position is: " << position << endl;
            }
            else
            {
                cout << "sorry!! There have no vlaue at the position" << endl;
            }
            break;

        case 7:
            cout << "Enter your desire value: ";
            cin >> value;
            searchValueDuplicationList(head, value);
            break;
        case 8:
            // cout << "Enter the postion: ";
            // cin >> position;
            // cout << "Enter your desire value: ";
            // cin >> value;
            // insertAtSpecificPosition(head, position, value);
            break;
        case 9:
            cout << "Enter the vlue which after you will add your desire value: ";
            cin >> whichValue;
            cout << "Enter your desire value: ";
            cin >> value;
            insertionAtAfterSpecificValue(head, whichValue, value);
            break;
        case 10:
            deletionAtHead(head);
            break;
        case 11:
            deletionAtTail(head);
            break;
        case 12:
            cout << "Enter the postion: ";
            cin >> position;
            cout << "Enter your desire value: ";
            cin >> value;
            insertAtSpecificPosition(head, position, value);
            break;
        case 13:
            int midValue;
            midValue = getMidValue(head);
            if (midValue == -1)
            {
                cout << "The link list is emty." << endl;
            }
            else
            { 
                cout << "Mid value is: " << midValue << endl;
            }
            break;
        case 14:
            cout<<"Enter the position where you want to creat a cycle: "<<endl;
            cin>>position;
            makeCycle(head, position);
            break;
        case 15:
            bool bol;
            bol=detectCycle(head);
            if(bol==true)
            {
                cout<<"Yes! In this link list have cycle."<<endl;
            }
            else
            {
                cout<<"Sorry! There are no cycle in the link lsit."<<endl;
            }
            break;
        case 16:
            bol=detectCycle(head);
            if(bol==true)
            {
                removeCycle(head);
            }
            else
            {
                cout<<"Sorry! There are no cycle in the link lsit."<<endl;
            }
            break;
        default:
            break;
        }
        cout << "Enter Your Choice: ";
        cin >> choice;
    }
    cout << endl
         << endl;

    int size = countLength(head);
    cout << "The size of link list: " << size << endl;

    return 0;
}