#include <iostream>

// Forward declaration of the List class template
template<typename T, typename Allocator>
class List;

// Definition of the Link class
template<typename T>
class Link {
    // Grant List access to Link's internals
    template<typename U, typename A>
    friend class List;
    
private:
    T val;
    Link* succ;
    Link* prev;
};

// Definition of the List class template
template<typename T, typename Allocator>
class List {
public:
    // Constructor
    List() {
        head = nullptr; // Initialize head to nullptr
        tail = nullptr; // Initialize tail to nullptr
        // Initialize other members and perform list operations
    }
    
    // Add an element to the list
    void push_back(const T& value) {
        Link<T>* newLink = new Link<T>();
        newLink->val = value;
        newLink->prev = tail;
        newLink->succ = nullptr; // Initialize newLink's succ to nullptr
        
        if (tail != nullptr) {
            tail->succ = newLink; // Update the previous tail's succ
        }
        
        tail = newLink; // Update tail to the newLink
        if (head == nullptr) {
            head = newLink; // If this is the first element, update head
        }
    }

    // Display elements in the list
    void display() {
        Link<T>* current = head;
        while (current != nullptr) {
            std::cout << current->val << " ";
            current = current->succ;
        }
        std::cout << std::endl;
    }
    
    // ... Other List methods ...

private:
    Link<T>* head; // Use the Link type
    Link<T>* tail; // Keep track of the tail for efficient push_back
    
    // ... Other private members ...
};

int main() {
    // Create an instance of List with the std::allocator<int> type
    List<int, std::allocator<int>> myList;

    // Add elements to myList
    myList.push_back(42);
    myList.push_back(123);
    myList.push_back(567);

    // Display elements in myList
    myList.display();

    return 0;
}
/*Linked List Data Structure: The code defines a singly linked list data structure with the following components:

Link class: Represents individual elements (nodes) in the linked list. Each Link contains a value (val) of type T, and pointers to the next (succ) and previous (prev) elements in the list.
List class: Represents the linked list itself. It contains a head pointer pointing to the first element and a tail pointer pointing to the last element in the list.
Constructor: The List constructor initializes the linked list by setting both head and tail pointers to nullptr, indicating an empty list.

push_back Method: The push_back method adds a new element to the end of the linked list. It creates a new Link, assigns the provided value to it, and updates the prev and succ pointers to maintain the list's structure.

display Method: The display method is used to print the elements of the linked list to the console. It traverses the list from head to tail, printing each element's value separated by spaces.

main Function: In the main function:

An instance of List<int, std::allocator<int>> named myList is created.
Three elements (42, 123, and 567) are added to myList using the push_back method.
Finally, the display method is called to print the elements of myList to the console.
  */
