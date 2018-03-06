//Abstract: Generate prime numbers upto user input and make a list

#include<iostream>
using namespace std;

class elem
{
    public:
    int data;
    elem *next;
    elem *prev;
    elem()
    {
        data =0;
        next=prev=NULL;
    }
};

int generate_prime(int a)
{
    for(int j=2;j<=a;j++)
    {
        if(a%j==0 && a!=j)
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
    while(head->next)   // If list exist then find the very last element of it and return that
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
        new_elem->prev=last;
        last->next=new_elem;
    }
    
    return head;
}




elem *my_list(int usr_input)
{
   elem *head = NULL;
   
   for(int i=2;i<=usr_input;i++)
   {
       if(generate_prime(i)!=0)
       {
           head = gen_elem(i,head);
       }
   }
   return head;
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
    // generate_prime(user_input);
    
    
    
    return 0;
}