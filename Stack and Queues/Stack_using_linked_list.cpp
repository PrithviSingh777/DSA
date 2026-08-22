#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(int x) {
        Node* newNode = new Node;

        newNode->data = x;
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow\n";
            return -1;
        }

        Node* temp = top;
        int x = top->data;

        top = top->next;
        delete temp;

        return x;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return -1;
        }

        return top->data;
    }

    int size() {
        int count = 0;
        Node* temp = top;

        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        return count;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }

        Node* temp = top;

        while (temp != nullptr) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    void clear() {
        while (!isEmpty()) {
            pop();
        }
    }

    ~Stack() {
        clear();
    }
};

int main() {
    Stack s;

    int choice;
    int x;

    do {
        cout << "\n--- STACK USING LINKED LIST ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Is Empty\n";
        cout << "5. Display\n";
        cout << "6. Size\n";
        cout << "7. Clear\n";
        cout << "8. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter element: ";
                cin >> x;
                s.push(x);
                break;

            case 2:
                x = s.pop();

                if (x != -1)
                    cout << "Popped element: " << x << endl;

                break;

            case 3:
                x = s.peek();

                if (x != -1)
                    cout << "Top element: " << x << endl;

                break;

            case 4:
                if (s.isEmpty())
                    cout << "Stack is empty\n";
                else
                    cout << "Stack is not empty\n";

                break;

            case 5:
                s.display();
                break;

            case 6:
                cout << "Stack size: " << s.size() << endl;
                break;

            case 7:
                s.clear();
                cout << "Stack cleared\n";
                break;

            case 8:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 8);

    return 0;
}
