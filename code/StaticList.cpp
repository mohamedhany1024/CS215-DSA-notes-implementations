#include <iostream>
#include <array>
template <typename T>
class StaticList {
    private:
        T* data;
        int cap = 0;
        int size = 0;

    public:
        StaticList(int cap) {
            this->cap = cap;
            size = 0;
            data = new T[cap];
        }

        StaticList(const StaticList& other) {
            cap = other.cap;
            size = other.size;
            data = new T[cap];

            for(int i=0; i<this->length(); i++) {
                data[i] = other.at(i);
            }
        }

        StaticList& operator=(const StaticList& other) {
            if (this != &other) {
                this->cap = other.cap;
                this->size = other.size;
                delete[] this->data;
                this->data = new T[cap];
                
                for(int i=0; i<this->length(); i++) {
                    data[i] = other.at(i);
                }
            }

            return *this;
        }

        void append(T val) {
            if (size+1 <= cap) {
                data[size] = val;
                size++;
            } else {
                throw std::out_of_range("can't exceed this StaticList's Capacity: "+std::to_string(cap));
            }
        }

        void pop() {
            if (size>0) {
                size--;
            }
        }

        void insert(T val, int idx) {
            if (idx < size && idx >= 0 && size+1<=cap) {
                for(int i=size; i!=idx; i--) {
                    data[i] = data[i-1];
                }
                data[idx] = val;
                size++;
            } else {
                throw std::out_of_range("");
            }
        }

        void remove(int idx) {
             if (idx < size && idx >= 0 && size-1 >= 0){
                for(int i=idx; i<size-1; i++) {
                    data[i] = data[i+1];
                }
                size--;
            } else {
                throw std::out_of_range("");
            }
        }

        T& at(int idx) {
            if (idx < size && idx >= 0) {
                return data[idx];
            } else {
                throw std::out_of_range("");
            }
        }

        int length() { return size; }
        bool isEmpty() { return size==0; }
        void clear() { size = 0; }
        ~StaticList() {
            delete[] data;
        }
};



int main() {
    StaticList<int> li(10);

    for(int i=1; i<=4; i++) {
        li.append(i);
    }
    li.insert(55, 2);
    //li.remove(2);
    li.insert(55, 0);
    //li.remove(0);
    li.append(55);
    for(int i=0; i<li.length(); i++) {
        std::cout << li.at(i) << " ";
    }
    std::cout << '\n';

    //std::cout << li.at(1) << " " << li.at(3) << " " << li.at(0) << std::endl;
    return 0;
}