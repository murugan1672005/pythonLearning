//  Singly Linked list
// Insertion ,Deletion,search
#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node*next;
    Node()
    {

    }
    Node(int data)
    {
        this->data = data;
        this->next =NULL;
    }
};
class LinkedList{
public:
    Node*pos;
    // insert at end
    void append(Node**head,int data)
    {
        Node*newnode = new Node(data);
        if(*head == NULL)
        {
            *head = newnode;
            pos=newnode;
        }
        else{
            pos->next = newnode;
            pos=newnode;
        }
    }
    // insert at front
    void appendFirst(Node**head,int data)
    {
        Node*newnode = new Node(data);
        if(*head == NULL)
        {
            *head = newnode;
        }
        else{
            newnode->next = *head;
            *head = newnode;
        }
    }
    // insert at position
    void insert(Node**head,int data,int pos)
    {
        Node *newnode = new Node(data);
        Node*curr = *head;
        int cnt = 1;

        while(curr!=NULL && cnt<pos-1)
        {
            curr=curr->next;
            cnt++;
        }
        if(cnt==pos && pos==1)
        {
            newnode->next =*head;
            *head = newnode;
            return;
        }
      if(curr->next==NULL)
      {
          cout<<"Invalid position";
          return;
      }
       newnode->next = curr->next;
       curr->next = newnode;
    }
    // delete front
    void deleteFront(Node**head)
    {
        if(*head == NULL)
        {
            return;
        }
            Node*temp =*head;
            *head = (*head)->next;
            delete temp;
    }
    // delete end
    void deleteEnd(Node**head)
    {
        if(*head == NULL)
        {
            return;
        }
        Node *curr = *head;
        while(curr->next->next!=NULL)
        {
            curr = curr->next;
        }
        Node*temp = curr->next;
        curr->next = NULL;
        delete temp;
    }
    // delete Position
    void deletepos(int pos,Node**head)
    {
        if(*head == NULL)
        {
            return;
        }
        if(pos==1)
        {
        *head = (*head)->next;
        return;
        }
        Node*curr = *head;
        int cnt = 1;
        while(curr->next!=NULL && cnt<pos-1)
        {
            curr = curr->next;
            cnt++;
        }
        if(curr->next==NULL)
        {
            cout<<"Invalid position";
            return;
        }
        Node*temp = curr->next;
        if(curr->next!=NULL)
        {
            curr->next = curr->next->next;
        }
        delete temp;

    }
    // print list
    void print(Node **head)
    {
        Node*curr = *head;
        while(curr!=NULL)
        {
            cout<<curr->data<<" ";
            curr = curr->next;
        }
        cout<<"\n";
    }
    Node* reverse(Node**head)
    {
        Node*prev=NULL;
        Node*curr =*head;
        while(curr!=NULL)
        {
            Node*temp = curr->next;
            curr->next =prev;
            prev=curr;
            curr = temp;
        }
        *head =prev;
        return prev;
    }
    Node* findMiddle(Node**head)
    {
        Node*fast =*head;
        Node*slow=*head;
        while(fast!=NULL && fast->next!=NULL)
        {
            fast = fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    bool isPlaindrome(Node**head)
    {

        Node*middle = findMiddle(head);
        middle=middle->next;
        Node*newHead =reverse(&middle);
        Node*l1=*head;
        Node*l2=newHead;
        while(l2!=NULL)
        {
            if(l1->data!=l2->data)
            {
                reverse(&newHead);
                return false;
            }
            l1=l1->next;
            l2=l2->next;
        }
        reverse(&newHead);
        return true;
    }
};
int main()
{
    int n;
    cin>>n;
    int data;
    Node*head = NULL;
    LinkedList list = LinkedList();
    for(int i=0;i<n;i++)
    {
        cin>>data;
        list.append(&head,data);
    }
       list.reverse(&head);
    list.print(&head);
    if(list.isPlaindrome(&head))
    {
        cout<<"Palindrome"<<"\n";
    }
    else{
        cout<<"Not a Palindrome"<<"\n";
    }

}
