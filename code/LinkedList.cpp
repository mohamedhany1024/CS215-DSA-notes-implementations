#include <iostream>
#include <array>

template <typename T>
struct Node {
    T value;
    Node<T>* next;
    Node<T>* prev;
};

template <typename T>
class LinkedListADT {
    protected:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    int size = 0;
    public:
    virtual void push_back(T val) = 0;
    virtual void push_front(T val) = 0;
    virtual void pop_back() = 0;
    virtual void pop_front() = 0;
    virtual void clear() = 0;


    int find(T val) {
        Node<T>* current = head;
        bool found = false;
        int i = 0;
        if (!this->isEmpty()) {
            while (current->value != val && current->next!=nullptr) {
                current = current->next;
                i++;
            }
            if (current->value == val) { found = true; }
        }

        return (found) ? i : -1;
    }

    T at(int idx) {
        int i=0;
        if(!isEmpty() && idx < this->size && idx>=0) {
            Node<T>* current = head;
            while (i!=idx && current->next != nullptr)
            {
                current = current->next;
                i++;
            }
            return current->value;
        } else {
            throw "list is empty or index out of range";
        }
        
    }

    bool isEmpty() { return head == nullptr; }

    virtual ~LinkedListADT() {}
};

template <typename T>
class LinkedList : public LinkedListADT<T> {
    public:
        LinkedList() : LinkedListADT<T>() {

        }

        virtual void push_front(T val) override {
            Node<T>* newNode = new Node<T>;
            newNode->value = val;
            newNode->next = nullptr;
            if (!this->isEmpty()) {
                newNode->next = this->head;
                this->head = newNode;

            } else {
                this->head = newNode;
                this->tail = newNode;
            }
            this->size++;
        }

        virtual void push_back(T val) override {
            Node<T>* newNode = new Node<T>;
            newNode->value = val;
            newNode->next = nullptr;
            if (!this->isEmpty()) {
                this->tail->next = newNode;
                this->tail = newNode;
            } else {
                this->head = newNode;
                this->tail = newNode;
            }
            this->size++;
        }

        virtual void pop_back() override {
            Node<T>* current = this->head;
            if (this->size>1) {
                while (current->next != this->tail)
                {
                    current = current->next;
                }
                current->next = nullptr;
                delete this->tail;
                this->tail = current;
                this->size--;
            } else if (this->size == 1) {
                delete this->head;
                this->head = nullptr;
                this->tail = nullptr;
                this->size--;
            }

            
        }

        virtual void pop_front() override {
            
            if (this->size>1) {
                Node<T>* temp = this->head->next;
                delete this->head;
                this->head = temp;
                this->size--;
            } else if (this->size == 1) {
                delete this->head;
                this->head = nullptr;
                this->tail = nullptr;
                this->size--;
            }
            
            
        }

        virtual void clear() override {
            Node<T>* temp, *current;
            if (!this->isEmpty()) {
                current = this->head;

                while(current!=this->tail) {
                    temp = current->next;
                    delete current;
                    current = temp;
                }
                delete this->tail;
                this->head = nullptr;
                this->tail = nullptr;

                this->size = 0;
            }
        }

        virtual ~LinkedList() {
            this->clear();
        }
};

int main() {
    

    //std::cout << li.at(1) << " " << li.at(3) << " " << li.at(0) << std::endl;
    return 0;
}