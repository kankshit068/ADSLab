#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;
 

struct Node
{
    int data;
    Node* link;
};
 

Node* XOR(Node* x, Node* y) {
    return (Node*)((uintptr_t)(x) ^ (uintptr_t)(y));
}
 

void traverse(Node* head)
{
    Node* curr = head;
    Node* prev = nullptr;
    Node *next;
 
    while (curr != nullptr)
    {
        cout << curr->data << " —> ";
        next = XOR(prev, curr->link);
 
    
        prev = curr;
        curr = next;
    }
 
    cout << "nullptr";
}
 

void push(Node* &headRef, int data)
{
    
    Node* newNode = new Node();
    newNode->data = data;
 
    
    newNode->link = XOR(headRef, nullptr);
 
   
    if (headRef)
    {
        
        headRef->link = XOR(newNode, XOR(headRef->link, nullptr));
    }
 
  
    headRef = newNode;
}
 
int main()
{   Node* head = nullptr;
    int p;
    do{
      cout<<"1.insert\n"<<"2.dispay"<<endl;
      cout<<"Enter the number\n";
      int k;
      cin>>k;
      switch(k){
          
          case 1: cout<<"enter the data\n";
          int data;
          cin>>data;
          
          push(head,data);
          break;
          
          case 2: traverse(head);
               break;
               
               
          
          
      }
      
      cout<<"Press 1 to continue and 2 for exit\n";
        cin>>p;
        
    }while(p!=2);

 
 
   return 0;
}
