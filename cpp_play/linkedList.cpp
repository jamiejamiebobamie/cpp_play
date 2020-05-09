//
//  linkedList.cpp
//  cpp_play
//
//  Created by James McCrory on 5/4/20.
//  Copyright © 2020 James McCrory. All rights reserved.
//

#include<iostream>
#include"helperFunctions.cpp"

template<class T>
class LinkedListNode {
    friend int operator+(LinkedListNode<T>& nodeToAdd);
public:
    LinkedListNode();
    LinkedListNode(T newdata);
    T getData()const;
    void setData(T newdata);
    LinkedListNode<T>* getNext();
    LinkedListNode* operator++();
    void setNext(LinkedListNode<T>* newNext);
    
private:
    T data;
    LinkedListNode<T>* next;
};
template<class T>
LinkedListNode<T>::LinkedListNode():data{0}, next{nullptr} {};
template<class T>
LinkedListNode<T>::LinkedListNode(T newdata) : data{newdata}, next{nullptr} {};
template<class T>
T LinkedListNode<T>::getData()const {return data;};
template<class T>
void LinkedListNode<T>::setData(T newData) {data=newData;};
template<class T>
LinkedListNode<T>* LinkedListNode<T>::getNext(){return next;};
template<class T>
void LinkedListNode<T>::setNext(LinkedListNode<T>* newNext){ next = newNext;};
template<class T>
LinkedListNode<T>* LinkedListNode<T>::operator++(){
    return next;
};
// in progress friend function.
template<class T>
int operator+(LinkedListNode<T>& nodeToAdd){
//    auto type = decltype(nodeToAdd->getData())
//    auto anInt = decltype(3);
//    auto aChar = decltype('c');
//    auto aCharPointer = decltype("hello");
//    switch (type)
//    {
//        case typeof(0):
//        break;
//    }
    return 0;
};

template<class T>
class LinkedList {
public:
    LinkedList();
    LinkedList(T data);
    LinkedList(LinkedListNode<T>* newNode);
    LinkedListNode<T>* getHead();
    void addNode(T data);
    void addNode(LinkedListNode<T>* newNode);
    void removeNode(LinkedListNode<T>* node);
    void removeNodes(T data);
    LinkedListNode<T>* findOneNode(T data);
    LinkedList<LinkedListNode<T>*>* findAllNodes(T data);
    void sort(bool ascending);
    LinkedListNode<T>* operator[](int index);
    LinkedList<LinkedListNode<T>*>* operator()(int indices...);
    void printList();
private:
    LinkedListNode<T>* head;
    LinkedListNode<T>* tail;
    // NEED TO IMPLEMENT.
    int len;
};
template<class T>
LinkedList<T>::LinkedList() : head{nullptr}, tail{nullptr} {};
template<class T>
LinkedList<T>::LinkedList(T data) : head{new LinkedListNode<T>(data)}, tail{nullptr} {};
template<class T>
LinkedList<T>::LinkedList(LinkedListNode<T>* node) : head{node}, tail{nullptr} {};
template<class T>
LinkedListNode<T>*  LinkedList<T>::getHead(){
    return head;
};
template<class T>
void LinkedList<T>::addNode(T data){
    LinkedListNode<T>* newNode = new LinkedListNode<T>(data);
    if (!head)
        head = newNode;
    else if (!tail){
        tail = newNode;
        head->setNext(tail);
    }
    else{
        tail->setNext(newNode);
        tail = newNode;
    }
};
template<class T>
void LinkedList<T>::addNode(LinkedListNode<T>* newNode){
    if (!head)
        head = newNode;
    else if (!tail){
        tail = newNode;
        head->setNext(tail);
    }
    else{
        tail->setNext(newNode);
        tail = newNode;
    }
};
template<class T>
void LinkedList<T>::removeNode(LinkedListNode<T>* node){
    // check to make sure the list is not empty.
    if (head){
        // check to see that a nullptr hasn't been passed-in.
        if (node){
            // check to see if the passed-in node is the same as the head.
            if (node == head)
                // if the node is the same as the head
                // set the head to the head's next node.
                head = head->getNext();
            else{
                // if the desired node to be removed is not the head
                // we need to iterate through the whole list
                // (even if the desired node is the tail).
                
                // set an iterator node pointer and a previous node pointer
                // that points to the last iterator node
                LinkedListNode<T>* curr = head;
                LinkedListNode<T>* prev = head;
                while (curr){
                    if (curr == node && curr != tail){
                        prev->setNext(curr->getNext());
                        break;
                    } else if (curr == node && curr == tail) {
                        prev->setNext(nullptr);
                        break;
                    }
                    prev = curr;
                    // curr = curr->getNext();
                        // works too.
                    curr = curr->operator++();
                }
            }
        }
    }
};
template<class T>
void LinkedList<T>::removeNodes(T data){
    LinkedListNode<T>* node = head;
    while (node){
        if (data == node->getData()){
            removeNode(node);
        }
        node = node->getNext();
    }
};
template<class T>
LinkedListNode<T>* LinkedList<T>::findOneNode(T data){
    if (head){
        if (data == head->getData())
            return head;
    }
    if (tail) {
        if (data == tail->getData())
            return tail;
    }
    LinkedListNode<T>* node = head;
    while (node){
        if (data == node->getData())
            return node;
        else
            node = node->getNext();
    }
    return nullptr;
};
template<class T>
LinkedList<LinkedListNode<T>*>* LinkedList<T>::findAllNodes(T data){
    // i want to create a linked list with data that are references of the nodes.
    LinkedList<LinkedListNode<T>*>* listOfNodesWithDataPointers = new LinkedList<LinkedListNode<T>*>;
    // if i make a new linked list and pass in llnodes with addNode method
        // the nodes being passed in will have their next data members changed.
    LinkedListNode<T>* node = head;
    while (node){
        if (data == node->getData()){
            LinkedListNode<LinkedListNode<T>*>* newNode = new LinkedListNode<LinkedListNode<T>*>;
            newNode->setData(node);
            listOfNodesWithDataPointers->addNode(newNode);
        }
        node = node->getNext();
    }
    return listOfNodesWithDataPointers;
};
template<class T>
void LinkedList<T>::sort(bool ascending){
    // check that a nullptr wasn't passed in.
    if (head){
        // initialize a bool to false to control sorting while loop.
        bool sorted = false;
        // initialize LinkedListNode pointers.
        LinkedListNode<T> *prev, *curr, *prevPrev;
        while(!sorted){
            // breaks  the sordid "sorted" loop
            bool editedOrder = false;
            // prev == prevPrev pointing to the same node controls whether or not to update the head.
            prevPrev = head;
            prev = head;
            curr = head->getNext();
            // the condition to check whether or not we want the list in ascendign order or descending order.
            bool condition;
            while (curr){
                // update condition based on "ascending" parameter bool and the new node pointers.
                    // switches prev with curr. sort is in place.
                if (ascending)
                    condition = prev->getData() > curr->getData();
                else
                    condition = prev->getData() < curr->getData();
                if (condition){
                    // set prev.next to curr.next
                    prev->setNext(curr->getNext());
                    // set curr.next to prev
                    curr->setNext(prev);
                    // if prevPrev != prev
                    if (prevPrev != prev)
                        // set prevPrev.next to curr
                        prevPrev->setNext(curr);
                    else
                        // set the curr to the head.
                        head = curr;
                    editedOrder = true;
                }
                prevPrev = prev;
                prev = curr;
                curr = curr->getNext();
            }
            if (!editedOrder)
                sorted = true;
        }
    }
};
template<class T>
LinkedListNode<T>* LinkedList<T>::operator[](int index){
    int count = 0;
    LinkedListNode<T>* node = head;
    while (node){
        if (count == index)
            return node;
        else
            node = node->getNext();
        count++;
    }
    return nullptr;
};
/*
    Variadic, overloaded () operator member function.
    First argument is the number of indices passed to the function
    All following arguments are the indices to return from the function.
 */
template<class T>
LinkedList<LinkedListNode<T>*>* LinkedList<T>::operator()(int indicesCount...){
    // the first parameter passed-in is held
        // in 'indicesCount', the number of parameters to follow.
    // initializes the list to hold
        // the arguements of the variadic function.
    va_list args;
    // enables access to the arguments.
    va_start(args, indicesCount);
    // return linkedlist of linkedlistnode addresses
    LinkedList<LinkedListNode<T>*>* listOfNodesByIndex = new
    LinkedList<LinkedListNode<T>*>;
    
    // gets the next item from the list of parameters (in this case the second)
    int nextIndex = va_arg(args, int);
    for (int i = 0; i < indicesCount; i++){
        LinkedListNode<T>* node = head;
        int count = 0;
        while (node){
            if (nextIndex == count){
                LinkedListNode<LinkedListNode<T>*>* newNode = new LinkedListNode<LinkedListNode<T>*>;
                newNode->setData(node);
                listOfNodesByIndex->addNode(newNode);
            }
            node = node->getNext();
            count++;
        }
        nextIndex = va_arg(args, int);
    }
    // "ends traversal of the variadic function arguments "
    va_end(args);
    return listOfNodesByIndex;
};
template<class T>
void LinkedList<T>::printList(){
    LinkedListNode<T>* node = head;
    while (node){
        std::cout << node->getData() << std::endl;
        node = node->getNext();
    }
    std::cout << " " << std::endl;
};

//int main(){
//    LinkedListNode<int> test = LinkedListNode<int>(7);
//    LinkedList<int> myll = LinkedList<int>(&test);
//    myll.addNode(1);
//    myll.addNode(1);
//    myll.addNode(1);
//    myll.addNode(1);
//    myll.addNode(3);
//    myll.addNode(4);
//    myll.addNode(5);
//    myll.addNode(1);
//    
//    LinkedListNode<int> firstTwo = LinkedListNode<int>(2);
//    myll.addNode(&firstTwo);
//    LinkedListNode<int> secondTwo = LinkedListNode<int>(2);
//    myll.addNode(&secondTwo);
//    
//    myll.printList();
//    myll.removeNodes(1);
//    myll.printList();
//    
//    bool ascending = true;
//    myll.sort(ascending);
//    myll.printList();
//    ascending = false;
//    myll.sort(ascending);
//    myll.printList();
//    
//    std::cout << "finding nodes" << std::endl;
//
//    LinkedList<LinkedListNode<int>*>* allNodesTwo = myll.findAllNodes(2);
//    allNodesTwo->printList();
//    myll.printList();
//    helpers::print(&firstTwo);
//    helpers::print(&secondTwo);
//    
//    LinkedList<LinkedListNode<int>*>* nodesByIndex = myll(2,0,5);
//    nodesByIndex->printList();
//    helpers::print(myll[2]);
//
//    return 0;
//}

/*
from class
class LinkedList(object):

    def __init__(self, iterable=None):
        """Initialize this linked list and append the given items, if any."""
        self.head = None  # First node of the sequence
        self.tail = None  # Last node of the sequence
        self.size = 0  # Number of nodes
        # Append the given items
        if iterable is not None:
            for item in iterable:
                self.append(item)

    def __str__(self):
        """Return a formatted string representation of this linked list."""
        items = ['({!r})'.format(item) for item in self.items()]
        return '[{}]'.format(' -> '.join(items))

    def __repr__(self):
        """Return a string representation of this linked list."""
        return 'LinkedList({!r})'.format(self.items())

    def items(self):
        """Return a list of all items in this linked list.
        Best and worst case running time: Theta(n) for n items in the list
        because we always need to loop through all n nodes."""
        # Create an empty list of results
        result = []  # Constant time to create a new list
        # Start at the head node
        node = self.head  # Constant time to assign a variable reference
        # Loop until the node is None, which is one node too far past the tail
        while node is not None:  # Always n iterations because no early exit
            # Append this node's data to the results list
            result.append(node.data)  # Constant time to append to a list
            # Skip to the next node
            node = node.next  # Constant time to reassign a variable
        # Now result contains the data from all nodes
        return result  # Constant time to return a list

    def is_empty(self):
        """Return True if this linked list is empty, or False."""
        return self.head is None

    def length(self):
        """Return the length of this linked list by traversing its nodes.
        Best and worst case running time: ??? under what conditions? [TODO]"""
        # Node counter initialized to zero
        node_count = 0
        # Start at the head node
        node = self.head
        # Loop until the node is None, which is one node too far past the tail
        while node is not None:
            # Count one for this node
            node_count += 1
            # Skip to the next node
            node = node.next
        # Now node_count contains the number of nodes
        return node_count

    def get_at_index(self, index):
        """Return the item at the given index in this linked list, or
        raise ValueError if the given index is out of range of the list size.
        Best case running time: O(1) Index is the head or tail of the LL.
        Worst case running time: O(n)"""
        # Check if the given index is out of range and if so raise an error
        if not (0 <= index < self.size):
            raise ValueError('List index out of range: {}'.format(index))

        if index == self.size - 1:
            return self.tail.data

        node = self.head
        count = 0
        while node:
            if count == index:
                return node.data
            else:
                count+=1
                node = node.next
        else:
            raise ValueError("List index is out of range: {}".format(index))

    def insert_at_index(self, index, item):
        """Insert the given item at the given index in this linked list, or
        raise ValueError if the given index is out of range of the list size.
        Best case running time: O(1)
        Worst case running time: O(n)
        '# TODO: Find the node before the given index and insert item after it.'
        
        I found the item at the given index and and pushed that item forward while
        inserting the new node.
        """

        if not (0 <= index <= self.size):
            raise ValueError('List index out of range: {}'.format(index))

        #check to see if the list is empty, if so self.append() will take over...
        if self.is_empty():
            self.append(item)
            return True

        #check to see if the index is one greater than the index at the tail,
        #if so, self.append() will take over...
        if index == self.size:
            self.append(item)
            return

        #otherwise iterate through list.
        count = 0
        node = previous = self.head
        while node:
        #if we've counted to the correct index.
        #create a new node, ipdate the size, set the next node of the new node
        #to the current item at the index and set the current item at the index's
        #last pointer to the new node just created, effectively bumping the node
        #that was at the index down the list by one. next we have to take into
        #account the special cases...
            if index == count:
                new_node = Node(item)
                self.size +=1
                new_node.next = node
                node.last = new_node
        #if the node at the correct index is not the head, set the new_node's last
        #attribute to the node set to 'previous'.
                if node != self.head:
                    #previous.next = new_node
                    new_node.last = previous
        #else the node at the given index is the head and has been supplanted,
        #pushed forward/downstream. the new node is now the head.
                else:
                    self.head = new_node
                return True
        #we haven't found the correct index, so keep moving down the list, by updating
        #the count the previous node and the current node being iterated over.
            else:
                count += 1
                previous = node
                node = node.next
        #No need for an 'else' statement to close the while loop as the above assert
        #statement precludes the user from inputting an index that would cause the function
        #to iterate beyond the bounds of the linkedlist.

    def append(self, item):
        """Insert the given item at the tail of this linked list.
        Best and worst case running time: BEST:O(1) WORST:O(1)"""
        # Create a new node to hold the given item
        new_node = Node(item)
        # Check if this linked list is empty
        if self.is_empty():
            # Assign head to new node
            self.head = self.tail = new_node
        else:
            # Otherwise insert new node after tail
            self.tail.next = new_node
            new_node.last = self.tail
        # Update tail to new node regardless
        self.tail = new_node
        self.size+=1

    def prepend(self, item):
        """Insert the given item at the head of this linked list.
        Best and worst case running time: BEST:O(1) WORST:O(1)"""
        # Create a new node to hold the given item
        new_node = Node(item)
        # Check if this linked list is empty
        if self.is_empty():
            # Assign tail to new node
            self.tail = new_node
        else:
            # Otherwise insert new node before head
            new_node.next = self.head
            self.head.last = new_node
        # Update head to new node regardless
        self.head = new_node
        self.size+=1

    def find(self, quality):
        """Return an item from this linked list satisfying the given quality.
        Best case running time: Omega(1) if item is near the head of the list.
        Worst case running time: O(n) if item is near the tail of the list or
        not present and we need to loop through all n nodes in the list."""
        # Start at the head node
        node = self.head  # Constant time to assign a variable reference
        # Loop until the node is None, which is one node too far past the tail
        while node is not None:  # Up to n iterations if we don't exit early
            # Check if this node's data satisfies the given quality function

            # EXAMPLE: quality()==lambda key_value: key_value[0] == key

            if quality(node.data):  # Constant time to call quality function
                # We found data satisfying the quality function, so exit early
                return node.data  # Constant time to return data
            # Skip to the next node
            node = node.next  # Constant time to reassign a variable
        # We never found data satisfying quality, but have to return something
        return None  # Constant time to return None

    def replace(self, old_item, new_item):
        """Replace the given old_item in this linked list with given new_item
        using the same node, or raise ValueError if old_item is not found.
        Best case running time: O(1),
        old_item == self.head.data or the old_item == self.tail.data
        Worst case running time: O(n-1) old_item == node at index (n-1)"""
        # TODO: Find the node containing the given old_item and replace its
        # data with new_item, without creating a new node object
        if self.head:

            if self.head.data == old_item:
                self.head.data = new_item
                return True
            #if there's a head there's a tail:
            if self.tail.data == old_item:
                self.tail.data = new_item
                return True

            node = self.head
            while node:
                if node.data == old_item:
                    node.data = new_item
                    return True
                node = node.next
            else:
                raise ValueError("{} is not in the list.".format(old_item))


    def delete(self, item):
        """Delete the given item from this linked list, or raise ValueError.
        Best case running time: O(1), item is at the head.
        Worst case running time: O(n), item is at the tail"""
        # Start at the head node
        node = self.head
        # Keep track of the node before the one containing the given item
        previous = None
        # Create a flag to track if we have found the given item
        found = False
        # Loop until we have found the given item or the node is None
        while not found and node is not None:
            # Check if the node's data matches the given item
            if node.data == item:
                # We found data matching the given item, so update found flag
                found = True
            else:
                # Skip to the next node
                previous = node
                node = node.next
        # Check if we found the given item or we never did and reached the tail
        if found:
            # Check if we found a node in the middle of this linked list
            if node is not self.head and node is not self.tail:
                # Update the previous node to skip around the found node
                previous.next = node.next
                node.next.last = previous
                # Unlink the found node from its next node
                node.next = None
            # Check if we found a node at the head
            if node is self.head:
                # Update head to the next node
                self.head = node.next
                # Unlink the found node from the next node
                node.next = None
            # Check if we found a node at the tail
            if node is self.tail:
                # Check if there is a node before the found node
                if previous is not None:
                    # Unlink the previous node from the found node
                    previous.next = None
                # Update tail to the previous node regardless
                self.tail = previous
            self.size -= 1
        else:
            # Otherwise raise an error to tell the user that delete has failed
            raise ValueError('Item not found: {}'.format(item))


def test_linked_list():
    ll = LinkedList()
    print(ll)

    print('Appending items:')
    ll.append('A')
    print(ll)
    ll.append('B')
    print(ll)
    ll.append('C')
    print(ll)
    print('head: {}'.format(ll.head))
    print('tail: {}'.format(ll.tail))
    print('size: {}'.format(ll.size))
    print('length: {}'.format(ll.length()))

    print('Getting items by index:')
    for index in range(ll.size):
        item = ll.get_at_index(index)
        print('get_at_index({}): {!r}'.format(index, item))

    print('Deleting items:')
    ll.delete('B')
    print(ll)
    ll.delete('C')
    print(ll)
    ll.delete('A')
    print(ll)
    print('head: {}'.format(ll.head))
    print('tail: {}'.format(ll.tail))
    print('size: {}'.format(ll.size))
    print('length: {}'.format(ll.length()))


if __name__ == '__main__':
    test_linked_list()

*/
