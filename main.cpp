#include<iostream>
#include<conio.h>
#include<fstream>

using namespace std;

//   Creating a NODE
struct node
{
   string data;  // data
   node *next,*back; //  link to next node and previous node
};

class list
{
   node *root,*end;
   public:
      void create(); 
      void insert(); 
      void del();    
      void show();  
};
// Creating a new node
void list::create()
{
   node *nxt_node,*pre_node;
   string value;
   int no,i;
   root=nxt_node=NULL;
   cout<<"\n                       CREATING A NEW LIBRARY.........\n\nHow many books : ";
   cin>>no;
   for(i=1;i<=no;i++)
   {
      cout<<"Enter the book name: ";
      cin>>value;
      nxt_node=new node;
      nxt_node->data=value;
      nxt_node->next=NULL;
      nxt_node->back=NULL;
      if(root==NULL)
	 root=nxt_node;
      else
      {
	 pre_node->next=nxt_node;
	 nxt_node->back=pre_node;
      }
      pre_node=nxt_node;
   }
   end=nxt_node;
   cout<<"\nThe Book list is created!";
   show();
}

// Displaying LIST
void list::show()
{
   node *ptr;
   ptr=root;
   cout<<"\n\nThe List is (from oldest to latest)\n";
   ofstream newfile;
   ofstream file("custom.txt");
   newfile.open ("book list.txt");
   cout<<"first book -> ";
   newfile<<"                                          LIBRARY RECORD\n\n";
   newfile<<"first book -> ";
   while(ptr!=NULL)
   {
      newfile<< ptr->data << " -> ";
      file<<ptr->data<<" ";
      cout<< ptr->data << " -> ";
      ptr = ptr->next;
   }
   cout<<"last book";
   newfile<<"last book";
   newfile<<"\n";
   ptr=end;
   cout<<"\n\nThe List is (from latest to oldest)\n";
   cout<<"last book <- ";
   newfile<<"last book <- ";
   while(ptr!=NULL)
   {
      newfile<< ptr->data <<" <- ";
      cout << ptr->data <<" <- ";
      ptr= ptr-> back;
   }
   cout<<"first book";
   newfile<<"first book";
   newfile.close();
   file.close();
   getch();
}

// Insert node at any position
void list::insert()
{
   string position;
   string dat;
   node *ptr_b,*ptr_f,*ptr;
   cout<<"Enter the DATA after which the new book is to be inserted.\n";
   cout<<"[ If the data is not found the new book will be inserted at first ]\n\t->:  ";
   cin>>position;
   cout<<"Enter the data to insert: ";
   cin>>dat;
   ptr=new node;
   ptr->data=dat;
   ptr_b=root;
   while(ptr_b->next!=NULL && ptr_b->data!=position)
   {
      ptr_b=ptr_b->next;
   }
   if(ptr_b->next==NULL && ptr_b->data!=position)
   //Insertion at first
   {
      root->back=ptr;
      ptr->next=root;
      ptr->back=NULL;
      root=ptr;
   }
   else if(ptr_b->next==NULL && ptr_b->data==position)
   //insertion at the end of list
   {
      ptr_b->next=ptr;
      ptr->next=NULL;
      ptr->back=ptr_b;
      end=ptr;
   }
   else
   //Insertion between two nodes
   {
      ptr_f=ptr_b->next;
      ptr->next=ptr_b->next;
      ptr->back=ptr_b;
      ptr_b->next=ptr;
      ptr_f->back=ptr;
   }
   cout<< "\nNew node is inserted!!";
   getch();
}  //End of insertion

//Delete node from any position
void list::del()
{
   string position,dat;
   node *ptr_b,*ptr_f,*ptr;
   cout<<"Enter the book to be removed: ";
   cin>>position;
   ptr=root;
   while(ptr->next != NULL && ptr->data != position)
   {
      ptr=ptr->next;
   }
   if(ptr->next==NULL && ptr->data!=position)
   //Data not found
   {
      cout<<"\nBook does not exist in the library!!";
      getch();
      return;
   }
   else if(ptr->next==NULL && ptr->data==position)
   //Deletion from the end of list
   {
      ptr_b=ptr->back;
      dat=ptr->data;
      ptr_b->next=NULL;
      end=ptr_b;
   }
   else
   //Deletion between two nodes or first node
   {
      dat=ptr->data;
      if(root==ptr)  // delete first node
      {
	  root=ptr->next;
	  ptr_f=root;
	  ptr_f->back=NULL;
      }
      else // Deletion between two nodes
      {
	 dat = ptr->data;
	 ptr_b = ptr->back;
	 ptr_b->next = ptr->next;
	 ptr_f = ptr_b->next;
	 ptr_f->back = ptr_b;
       }
   }
   delete ptr;
   cout<<"\nThe book is removed!!\nname of removed book= " << dat;
   getch();
}  //End of deletion


// Main function
int main()
{
   list l;
   l.create(); // to create a new node
   int choice;
   while(1)
   {
      cout<<"\n-----------------------------------------------------------";
      cout<<"\n\t\tDOUBLY LINKED LIST\n\n";
      cout<<"1:Insert new book\n2:Remove a book\n3:Display current List\n4:Exit";
      cout<<"\nEnter your choice(1-4): ";
      cin>>choice;
      switch(choice)
      {
       case 1:  // Insertion
	  l.insert();
	  break;
       case 2:   // Deletion
	  l.del();
	  break;
       case 3:  // Display
	  l.show();
	  break;
       case 4:  // Exit
	  exit(0);
	  break;
       default:
	  cout<<"Please enter correct choice(1-4)!!";
	  getch();
	  break;
       }
   }
   return 0;
}
