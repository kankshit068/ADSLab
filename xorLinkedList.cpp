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
{
    
    vector<int> keys = { 1, 2, 3, 4, 5 };
 
    Node* head = nullptr;
    for (int i = keys.size() - 1; i >=0; i--) {
        push(head, keys[i]);
    }
 
    traverse(head);
 
 
   return 0;
}
