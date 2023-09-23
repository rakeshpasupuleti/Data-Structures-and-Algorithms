#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
};

struct Node *head=NULL;

void print_linked_list(Node* &head) {

    if(head==NULL) {
        cout<<"The list is Empty"<<endl;
    }
    else{

        struct Node *temp=head;
        cout<<"The linked list is : "<<endl;
        while(temp!=NULL) {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
}
void insert_at_begining(Node* &head, int data) {

    struct Node *node =new struct Node;
    node->data=data;
    node->next=head;
    head=node;
    
}

void insert_at_end(Node* &head, int data) {

    struct Node *node =new struct Node;
    struct Node *temp=head;
    node->data=data;
    node->next=NULL;
    if(head==NULL) {
        head=node;
    }
    else {
        while(temp->next!=NULL) temp=temp->next;
        temp->next=node;
    }

        
        
}

void insert_at_position(Node* &head,int data, int pos) {
    struct Node *temp=head;
    struct Node *node=new Node;
    int count=1;
    node->data=data;
    while(count<pos and temp!=NULL) {
        temp=temp->next;
        ++count;
    } 
    if(count==pos) {
        node->next=temp->next;
        temp->next=node;
    }
    else {
        cout<<"The list has no position "<<pos<<endl;
    }
}

void delete_at_begining(Node* &head) {
    if(head==NULL)  cout<<"The List is Empty"<<endl;
    else {
        Node* temp = head;
        head = head->next; 
        delete temp;       
    }
}

void delete_at_end(Node* &head) {
    if(head==NULL)  cout<<"The List is Empty"<<endl;
    else if (head->next == NULL) {
        // Linked list has only one node, delete it
        delete head;
        head = NULL; // Set head to NULL after deletion
        return;
    }
    else {
        Node *temp=head;
        while(temp->next->next!=NULL) temp=temp->next;
        
        delete temp->next;
        temp->next=NULL;
    }

}

void search_element(Node* &head,int key) {
    Node *temp=head;
    int found=0;
    while(temp!=NULL){
        if(temp->data==key) {
            cout<<"The element :"<<key<<" is found in the linked list"<<endl;
            found=1;
            break;
        }
        temp=temp->next;
    }
    if(!found)
        cout<<"The element :"<<key<<" is not found in the linked list"<<endl;
}

void reverse_linked_list(Node* &head) {
    if(head ==NULL or head->next==NULL) return ;
        
        Node* prev=NULL;
        Node* current=head;
        Node* next=NULL;
        
        while(current !=NULL) {
            next=current->next;
            current->next=prev;
            
            prev=current;
            current=next;
        }
        
        
        head=prev;
        
}

void rotate_linked_list(Node*& head,int k) {

        Node *current=head;
        Node *kthnode=NULL;
       int index=1;
       
       while(index<k) {
           current=current->next;
           ++index;
       }
       
       if(current==NULL) return ;
       
       kthnode=current;
       
       while(current->next!=NULL) current=current->next;
       
       current->next=head;
       head=kthnode->next;
       kthnode->next=NULL;   
}

void reverse_in_groups(Node *& head,int k) {
    if(head==NULL or k==1) return ;
       Node *dummy=new Node;
       dummy->data=0;
       dummy->next=head;
       
       Node *prev=dummy;
       Node *current=dummy;
       Node *next=dummy;
       
       int count=0,loop_variable;
       
       while(current!=NULL) {
           current=current->next;
           ++count;
       }
       
      while(next!=NULL) {
          
          current=prev->next;
          next=current->next;
          
          loop_variable= count > k ? k : count-1;
          
          for(int i=1; i<loop_variable;++i) {
              
              current->next=next->next;
              next->next=prev->next;
              prev->next = next;
              next = current->next;
          }
          
          prev=current;
          count-=k;
      }
      
      head = dummy->next;

}


int main() {

    
    
    print_linked_list(head);
    
    insert_at_begining(head,10);
    insert_at_end(head,20);
    insert_at_end(head,30);
    insert_at_end(head,40);
    print_linked_list(head);
    reverse_linked_list(head);
    print_linked_list(head);

    reverse_in_groups(head,2);
    print_linked_list(head);
    
    
    return 0;
}
