#include <iostream>
#include <algorithm>

template <typename T>
class PriorityQueue {
private:
    struct QueueNode {
        T data;
        int priority;

        // Default constructor added here
        QueueNode() : data(T()), priority(0) {}

        QueueNode(const T& value, int p) : data(value), priority(p) {}

        bool operator<(const QueueNode& other) const {
            return priority < other.priority;
        }
    };

    static const int MAX_SIZE = 100;
    QueueNode elements[MAX_SIZE];
    int size;

public:
    PriorityQueue() : size(0) {}

    bool IsEmpty() const {
        return size == 0;
    }

    bool IsFull() const {
        return size == MAX_SIZE;
    }

    void InsertWithPriority(const T& value, int priority) {
        if (IsFull()) {
            std::cout << "Priority queue is full. Cannot insert element." << std::endl;
            return;
        }

        elements[size++] = QueueNode(value, priority);
        std::cout << "Inserted: " << value << " with priority " << priority << std::endl;
    }

    void PullHighestPriorityElement() {
        if (!IsEmpty()) {
            auto maxElementIt = std::max_element(elements, elements + size);
            std::swap(*maxElementIt, elements[size - 1]);
            size--;
            std::cout << "Pulled: " << maxElementIt->data << " with priority " << maxElementIt->priority << std::endl;
        }
        else {
            std::cout << "Priority queue is empty. Cannot pull element." << std::endl;
        }
    }

    void Peek() const {
        if (!IsEmpty()) {
            auto maxElementIt = std::max_element(elements, elements + size);
            std::cout << "Peeked: " << maxElementIt->data << " with priority " << maxElementIt->priority << std::endl;
        }
        else {
            std::cout << "Priority queue is empty. Cannot peek." << std::endl;
        }
    }

    void Show() const {
        if (!IsEmpty()) {
            std::cout << "Priority queue elements:" << std::endl;
            for (int i = 0; i < size; ++i) {
                std::cout << elements[i].data << " (Priority: " << elements[i].priority << ")" << std::endl;
            }
        }
        else {
            std::cout << "Priority queue is empty." << std::endl;
        }
    }
};

int main() {
    PriorityQueue<int> myPriorityQueue;

    myPriorityQueue.InsertWithPriority(1, 3);
    myPriorityQueue.InsertWithPriority(2, 1);
    myPriorityQueue.InsertWithPriority(3, 2);

    myPriorityQueue.Show();

    myPriorityQueue.PullHighestPriorityElement();
    myPriorityQueue.Show();

    myPriorityQueue.Peek();

    return 0;
}
