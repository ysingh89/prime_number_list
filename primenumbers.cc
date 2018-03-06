//Abstract: Generate prime numbers upto user input and make a double linked list

#include<iostream>
using namespace std;

class elem
{
    public:
    int data;
    elem *next;
    elem *prev;
    elem()      // Constructor to initialize variables to NULL when an object is created
    {
        data =0;
        next=prev=NULL;
    }
};

int generate_prime(int a)
{
    for(int j=2;j<=a;j++)
    {
        if(a%j==0 && a!=j)  // Check if number is divisible by any number between 1 < itself
        {
            return 0;   // If not prime
        }
    }
    
    return 1;           // If prime
}

elem *get_last(elem *head)
{
    if(!head)   //If head is NULL
    {
        return head;
    }
    while(head->next)   // If list exist then find the very last element and return that
    {
        head = head->next;
    }
    return head;
}

elem *gen_elem(int val, elem *head)
{
    elem *new_elem = new elem();
    new_elem->data = val;
    elem *last = get_last(head);
    if(!last)
        head=new_elem;
    else
    {
        new_elem->prev=last;    // Connect new elem to the end of the list
        last->next=new_elem;
    }
    
    return head;
}

elem *my_list(int usr_input)
{
   elem *head = NULL;
   for(int i=2;i<=usr_input;i++) // Loop through all the numbers
   {
       if(generate_prime(i)!=0)  // Check if it is a prime number
       {
           head = gen_elem(i,head); // if it is then add it to the list
       }
   }
   return head; // return head of the list
}

void print_list(elem *head)
{
    while(head)
    {
        cout<<head->data<<endl;
        head=head->next;
    }
}

int main()
{
    int user_input;
    cout<<"Enter the last number.\n";
    cin>> user_input;
    cout<<"Below are the prime numbers upto "<<user_input<<".\n";
    
    elem *head = my_list(user_input);
    print_list(head);
    
    return 0;
}