//
//  main.cpp
//  algorithms
//
//  Created by Gulchiroy on 22/09/2019.
//  Copyright © 2019 Gulchiroy. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstdlib>


using namespace std;

struct node
{
    int data;
    node *next;
};
typedef node* nodeptr;
nodeptr head  = NULL;
void insert_head( int num)
{
    nodeptr temp = new node;
    temp->data=num;
    temp->next= NULL;
    
    if(head==NULL)
        head=temp;
    else
        temp->next=head;
        head=temp;
    
}
void display()
{
    nodeptr curr= new node;
    curr = head;
    if(curr==NULL)
        cout<<"The list is Empty"<<endl;
  
        while(curr!=NULL)
        {
            cout<<curr->data<<endl;
            curr=curr->next;
        }
    
           
}
void deletenum(int num)
{
    nodeptr curr = head;
    nodeptr prev=head;
    if(curr->data==num&&curr==head)//deleting the head
       {
           head=curr->next;
           delete curr;
           cout<<"head is deleted"<<endl;
           
       }
    
    else{
        
    while(curr->next!=NULL&&curr->data!=num)//iterator
    {
        prev=curr;
        curr=curr->next;
    }
    if(curr->data!=num)//if the last node next is null and there is not element left to check
    {
            cout<<"there is no such a number to delete"<<endl;
        
       }
    
     else  if (curr->data==num&&curr->next!=nullptr)//deleting the middle node
    {
        prev->next=curr->next;
        delete curr;
        cout<<"middle node is deleted"<<endl;
    }
        
    else if(curr->data==num&&curr->next==NULL)//code for deleting the last node
    {
            delete curr;
            prev->next=NULL;
        cout<<"the last node id deleted"<<endl;
    }
   
   
    
       
    }
     display();
    }
    
int search(int target)
{
    nodeptr here = head;
    
    if(here==NULL)
    {
        return NULL;
    }
    else
    {
    while(here->data!=target&&here->next!=NULL)
        here=here->next;
        if(here->data==target)
            return here->data;
        else
            return NULL;
    }
    
}
void insert(int num)//inserting the number in the middle;
{
    nodeptr prev = new node;
    nodeptr curr = head;
    nodeptr temp = new node;
   
    
    if(curr==NULL)
    {
        cout<<"List is Empty"<<endl;
    }
    
        while(curr->next!=NULL&&curr->data>num)
        {
            prev=curr;
           curr=curr->next;
        }
    temp->data= num;
       if(curr->data<num)
       {
           
           prev->next=temp;
            temp->next=curr;
        }
        
    
}
int main(int argc, const char * argv[])
    {
    
    insert_head(1);
    insert_head(3);
    insert_head(5);
    insert_head(7);
    insert(2);
    insert(4);
    insert(6);
    deletenum(7);//deleting the head
    deletenum(1);//delete the last element in the list
    deletenum(4);//delete the middle element in the list
    deletenum(10);// not found element
       
    
    
    
    
    
    
    
   
    
  
    return 0;
}


