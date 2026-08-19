
#include <iostream>
using namespace std;
struct node{
    int data;
    node* next;
};
class LL{
    private:
        node* head;
    public:
        LL(){
            head=nullptr;
        }
        void print(){
            node* temp=head;
            if(head==nullptr){
                cout<<"Empty list \n";
                return;
            }
            while(temp!=nullptr){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
        }
        void search(int e){
            node* temp=head;
            int pos=1;
            if(head==nullptr){
                cout<<"Empty list \n";
                return;
            }
            while(temp!=nullptr){
                if(temp->data==e){
                    cout<<"Found at position "<<pos<<endl;
                    return;
                    
                }
                pos++;
                temp=temp->next;
            }
            cout<<"Not found \n";
        }
        void length(){
            int length=0;
            node* temp=head;
            if(head==nullptr){
                cout<<"Empty list \n";
                return;
            }
            while(temp!=nullptr){
                temp=temp->next;
                length++;
            }
            cout<<"length of the list is "<<length<<endl;
            return;
        }
        void create(){
            int n;
            node* temp=head;
            cout<<"How many elements?\n";
            cin>>n;
            for(int i=0;i<n;i++){
                node* newnode= new node;
                cout<<"Enter value of element "<<i+1<<endl;
                cin>>newnode->data;
                newnode->next=nullptr;
                
                if(head==nullptr){
                    head=newnode;
                    temp=newnode;
                }
                else{
                    temp->next=newnode;
                    temp=temp->next;
                }
            }
            
            
        }
        void insert(int e,int p){
            node* newnode=new node;
            newnode->data=e;
            node* temp=head;
            int pos=1;
            if(head==nullptr||p==1){
                cout<<"Updating head"<<endl;
                newnode->next=head;
                head=newnode;
                return;
                
            }
            while(pos<p-1 && temp!=nullptr){
                temp=temp->next;
                pos++;
            }
             if(temp==nullptr){
                cout<<"invalid\n";
                return;
            }
            
            newnode->next=temp->next;
            temp->next=newnode;
            
           
            
            
        }
        void deletenode(int p){
    node* temp = head;
    int pos = 1;

    if(head == nullptr){
        cout << "empty list.\n";
        return;
    }

   
    if(p == 1){
        node* temp2 = head;
        head = head->next;
        delete temp2;
        return;
    }

    
    while(pos < p - 1 && temp != nullptr){
        temp = temp->next;
        pos++;
    }

    
    if(temp == nullptr || temp->next == nullptr){
        cout << "invalid position\n";
        return;
    }

    
    node* temp2 = temp->next;
    temp->next = temp->next->next;
    delete temp2;
}
        void update(int p, int e){
            node* temp=head;
            int pos = 1;
            if(head==nullptr){
                cout<<"empty list\n";
                return;
            }
             if( p==1){
        cout << "updating head\n";
        head->data=e;
        
        return;
        }
        
        while(pos<p&& temp!=nullptr){
            temp=temp->next;
            pos++;
        }
        if(temp==nullptr){
            cout<<"invalid position\n"<<endl;
            return;
        }
        temp->data=e;
        }
        int findMax(){
    if(head == nullptr){
        cout << "Empty list\n";
        return -1;
    }

    node* temp = head;
    int max = head->data;

    while(temp != nullptr){
        if(temp->data > max){
            max = temp->data;
        }
        temp = temp->next;
    }

    return max;
}
        int findMin(){
    if(head == nullptr){
        cout << "Empty list\n";
        return -1;
    }

    node* temp = head;
    int min = head->data;

    while(temp != nullptr){
        if(temp->data < min){
            min = temp->data;
        }
        temp = temp->next;
    }

    return min;
}
        void delbyvalue(int e){
    if(head == nullptr){
        cout << "Empty list\n";
        return;
    }

    // If the head contains the value
    if(head->data == e){
        node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    node* temp = head;

    // Find the node before the node to delete
    while(temp->next != nullptr){
        if(temp->next->data == e){
            node* temp2 = temp->next;
            temp->next = temp->next->next;
            delete temp2;
            return;
        }
        temp = temp->next;
    }

    cout << "Element not found\n";
}
        void reverse(){
    if(head == nullptr){
        cout << "Empty list\n";
        return;
    }

    node* prev = nullptr;
    node* curr = head;
    node* ahead = nullptr;

    while(curr != nullptr){
        ahead = curr->next;
        curr->next = prev;
        prev = curr;
        curr = ahead;
    }

    head = prev;
}

        
       
        
        
        
        
            
        
};
int main()
{
    

    return 0;
}