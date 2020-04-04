#include <iostream>
#include <cstddef>

struct Node{
  int data;
  Node* next=NULL;
};

void add_head(Node** head_ref,int data){
  Node* new_node=new Node;
  new_node->data=data;
  new_node->next=NULL;
  *head_ref=new_node;
  std::cout << "Address of node-->" <<new_node->data<<"-----"<<new_node <<'\n';
}

void append(Node*head,int data){
  Node* new_node=new Node;
  while(head->next!=NULL){
    head=head->next;
  }
  head->next=new_node;
  new_node->data=data;
  new_node->next=NULL;
  std::cout << "Address of node-->" <<new_node->data<<"----"<<new_node <<'\n';
}

void append_at(Node*head,int position, int data){
  Node* new_node=new Node;
  int pos=1;
  while (pos!=position&&position!=0){
    head=head->next;
    pos+=1;
  }
  new_node->next=head->next;
  head->next=new_node;
  new_node->data=data;
  std::cout << "Address of node-->" <<new_node->data<<"-----"<<new_node <<'\n';
}

void delete_head(Node**head_ref){
  Node* temp=*head_ref;
  *head_ref=temp->next;
  //temp->next=NULL;
  delete(temp);
  std::cout << "Address of new head node-------"<<*head_ref << '\n';


}

void delete_end_node(Node*head){
  while(head->next->next!=NULL){
    head=head->next;
  }
  delete(head->next->next);
  head->next=NULL;
}

void delete_node_at(Node*head,int position){
  int pos=1;
  if (position==0){
    std::cout << "not allowed" << '\n';
  }
  else{
    Node* prev=new Node;
    while(pos!=position){
      prev=head;
      head=head->next;
      pos+=1;
    }
    prev->next=head->next;
    delete(head);
  }
}

void printlist(Node* head){
  Node* head_node=head;
  while (head_node!=NULL) {
    std::cout << head_node->data << "->";
    head_node=head_node->next;
  }
  std::cout << "NULL" << '\n';
}

int main(){
  Node* head=new Node;
  add_head(&head,76);//where ever we have to change the value of head we need to have call by reference.
  append(head,98);
  append(head,89);
  append(head,300);
  append(head,34);
  append_at(head,2,69);
  append_at(head,3,41);
  std::cout << "Address of previous head node ------"<<head<< '\n';
  delete_head(&head);
  std::cout <<"Address of current head after fuction call----------"<< head << '\n';
  delete_end_node(head);
  printlist(head);
  delete_node_at(head,3);
  printlist(head);
  return 0;

}
