#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* next;
    Node(int val)
    {
        data = val;
        next =NULL;
    }
};
class LinkedList
{
private:
    Node* head;
public:
    LinkedList()
    {
        head = NULL;
    }


    void insert_a_node(int val)
    {
        Node* newNode = new Node(val);
        if(head == NULL)
        {
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next!= NULL)
        {
            temp= temp->next;
        }
        temp-> next= newNode;
    }

    void insert_at_beginning(int x)
    {
        Node* newnode = new Node(x);
        newnode->next = head;
        head = newnode;
    }



    void insert_at_position(int post,int x)
    {
        Node* newnode = new Node(x);
        int i = 1;
        Node* temp = head;
        if(post == 1)
        {
            newnode->next = head;
            head = newnode;
            return;
        }
        while(post-1 >i)
        {
            temp = temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next = newnode;
    }


    void delete_at_beginning()
    {
        if(head==NULL){
            return;
        }
        head = head->next;
    }

    void delete_at_end()
    {
        Node* temp = head;
        if(head == NULL)
        {
            return;
        }
        if(head->next == NULL)
        {
            head =NULL;
            return;
        }
        while(temp->next->next!= NULL)
        {
            temp = temp->next;
        }
        temp->next= NULL;
    }

    void delete_at_position(int post)
    {
        int i = 1;
        if(head == NULL)
        {
            return;
        }
        if(head->next == NULL)
        {
            head = NULL;
            return;
        }
        if(post == 1){
            head = head->next;
            return;
        }
        Node* temp = head;
        while(post-1>i)
        {
            temp = temp->next;
            ++i;
        }
        temp->next=temp->next->next;
    }

    void display()
    {
        Node* temp = head;

        if(head == NULL){
            cout << "EMPTY LIST"<<endl;
        }
        while(temp!= NULL)
        {
            cout << temp->data<<endl;
            temp = temp->next;
        }
    }
    void search(int x)
    {
        Node* temp = head;
        if(head == NULL){
            cout<<"EMPTY LIST"<<endl;
            return;
        }
        while(temp!=NULL)
        {
            if(temp->data == x)
            {
                cout << "Found"<<endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Not found"<<endl;

    }


    void count_nodes(){
    Node* temp = head;
    int i = 0;
    while(temp!=NULL){
        temp = temp->next;
        i++;
        }
    cout << "Total Nodes:"<<i<<endl;
    }


    void reverse()
{
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    while(curr!= NULL){
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }
    head = prev;
}
};
int main()
{
    LinkedList* LIST = new LinkedList();



    LIST->insert_a_node(20);
    LIST->insert_at_beginning(10);
    LIST->insert_at_position(3,30);
    LIST->insert_a_node(40);


    LIST->reverse();

    LIST->display();

}
