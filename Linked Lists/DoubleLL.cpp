
#include <iostream>
using namespace std;
struct node{
    int data;
    node* next, *prev;
};
class LL{
    private:
        node* head;
        node* tail;
    public:
        LL(){
            head=nullptr;
            tail=nullptr;
        }
        void create() {
    int n, e;

    cout << "Enter number of nodes: ";
    cin >> n;

    for(int i = 0; i < n; i++) {

        cout << "Enter data for node " << i + 1 << ": ";
        cin >> e;

        node* newnode = new node;
        newnode->data = e;
        newnode->next = nullptr;
        newnode->prev = tail;

        if(head == nullptr) {
            head = tail = newnode;
        }
        else {
            tail->next = newnode;
            tail = newnode;
        }
    }
}
        void reverse() {
    node* temp = tail;
    node* ahead;

    while(temp != nullptr) {
        ahead = temp->next;

        temp->next = temp->prev;
        temp->prev = ahead;

        temp = ahead;
    }

    node* t = head;
    head = tail;
    tail = t;
}
        void insert(int pos, int value) {
    node* newnode = new node;
    newnode->data = value;

    // Insert at beginning
    if(pos == 1) {
        newnode->prev = nullptr;
        newnode->next = head;

        if(head != nullptr)
            head->prev = newnode;
        else
            tail = newnode;

        head = newnode;
        return;
    }

    node* temp = head;

    // Reach node before required position
    for(int i = 1; i < pos - 1; i++) {
        if(temp == nullptr) {
            cout << "Invalid position";
            delete newnode;
            return;
        }
        temp = temp->next;
    }

    if(temp == nullptr) {
        cout << "Invalid position";
        delete newnode;
        return;
    }

    // Insert after temp
    newnode->next = temp->next;
    newnode->prev = temp;

    if(temp->next != nullptr)
        temp->next->prev = newnode;
    else
        tail = newnode;

    temp->next = newnode;
}   
        // functions similar to single LL
        void search(int value) {
    node* temp = head;

    while(temp != nullptr) {
        if(temp->data == value) {
            cout << "Element found";
            return;
        }
        temp = temp->next;
    }

    cout << "Element not found";
}
        void updateByValue(int oldValue, int newValue) {
    node* temp = head;

    while(temp != nullptr) {
        if(temp->data == oldValue) {
            temp->data = newValue;
            return;
        }
        temp = temp->next;
    }

    cout << "Element not found";
}
        void updateByPosition(int pos, int newValue) {
    node* temp = head;

    for(int i = 1; i < pos; i++) {
        if(temp == nullptr) {
            cout << "Invalid position";
            return;
        }
        temp = temp->next;
    }

    if(temp == nullptr) {
        cout << "Invalid position";
        return;
    }

    temp->data = newValue;
}
        void reverseDisplay() {
    node* temp = tail;

    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
}
        void display() {
    node* temp = head;

    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
        
       
                
         
};


    int main() {
    LL list;
    int choice;
    int value, newValue, pos;
    node* temp;

    do {
        cout << "\n\n--- DOUBLY LINKED LIST MENU ---\n";
        cout << "1. Create List\n";
        cout << "2. Search by Value\n";
        cout << "3. Update by Value\n";
        cout << "4. Update by Position\n";
        cout << "5. Reverse List\n";
        cout << "6. Reverse Display\n";
        cout << "7. Insert After a Node\n";
        cout << "8. Display\n";
        cout << "9. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {

            case 1:
                list.create();
                break;

            case 2:
                cout << "Enter value to search: ";
                cin >> value;
                list.search(value);
                break;

            case 3:
                cout << "Enter old value: ";
                cin >> value;
                cout << "Enter new value: ";
                cin >> newValue;
                list.updateByValue(value, newValue);
                break;

            case 4:
                cout << "Enter position: ";
                cin >> pos;
                cout << "Enter new value: ";
                cin >> newValue;
                list.updateByPosition(pos, newValue);
                break;

            case 5:
                list.reverse();
                cout << "List reversed.";
                break;

            case 6:
                cout << "Reverse list: ";
                list.reverseDisplay();
                break;
            case 7:
    cout << "Enter position: ";
    cin >> pos;

    cout << "Enter value: ";
    cin >> value;

    list.insert(pos, value);
    break;
            case 8:
    cout << "List: ";
    list.display();
    break;


            case 9:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid choice.";
        }

    } while(choice != 9);

    return 0;
}
    

 