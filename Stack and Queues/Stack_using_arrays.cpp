#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;
    int capacity;
    int top = -1;

public:
    Stack(int n) {
        capacity = n;
        arr = new int[capacity];
    }

    ~Stack() {
        delete[] arr;
    }

    int isempty() {
        if (top == -1) {
            return 1;
        }
        return 0;
    }

    int isfull() {
        if (top == capacity - 1) {
            return 1;
        }
        return 0;
    }

    void push(int x) {
        if (!isfull()) {
            top++;
            arr[top] = x;
            return;
        }

        cout << "Stack overflow\n";
    }

    int pop() {
        if (!isempty()) {
            int e = arr[top];
            top--;
            return e;
        }

        cout << "Stack underflow\n";
        return -1;
    }

    int peek() {
        if (!isempty()) {
            return arr[top];
        }

        cout << "Stack is empty\n";
        return -1;
    }

    int size() {
        return top + 1;
    }

    void display() {
        if (isempty()) {
            cout << "Empty stack\n";
            return;
        }

        for (int i = top; i >= 0; i--) {
            cout << arr[i] << endl;
        }
    }

    void clear() {
        top = -1;
    }
};
int main() {
    int n;
    cout << "Enter stack size: ";
    cin >> n;

    Stack s(n);

    int choice, x;

    do {
        cout << "\n--- STACK MENU ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Is Empty\n";
        cout << "5. Is Full\n";
        cout << "6. Size\n";
        cout << "7. Display\n";
        cout << "8. Clear\n";
        cout << "9. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter element: ";
                cin >> x;
                s.push(x);
                break;

            case 2:
                cout << "Popped element: " << s.pop() << endl;
                break;

            case 3:
                cout << "Top element: " << s.peek() << endl;
                break;

            case 4:
                if (s.isempty())
                    cout << "Stack is empty\n";
                else
                    cout << "Stack is not empty\n";
                break;

            case 5:
                if (s.isfull())
                    cout << "Stack is full\n";
                else
                    cout << "Stack is not full\n";
                break;

            case 6:
                cout << "Stack size: " << s.size() << endl;
                break;

            case 7:
                s.display();
                break;

            case 8:
                s.clear();
                cout << "Stack cleared\n";
                break;

            case 9:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 9);

    return 0;
}
