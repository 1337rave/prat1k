#include <iostream>

template <typename T>
class Queue {
private:
    static const int MAX_SIZE = 100; // Максимальний розмір черги
    T elements[MAX_SIZE];
    int front; // Передня частина черги
    int rear;  // Задня частина черги

public:
    Queue() : front(-1), rear(-1) {}

    // Перевірка черги на порожнечу
    bool IsEmpty() const {
        return front == -1 && rear == -1;
    }

    // Перевірка черги на заповнення
    bool IsFull() const {
        return (rear + 1) % MAX_SIZE == front;
    }

    // Додавання елемента в чергу
    void Enqueue(const T& value) {
        if (IsFull()) {
            std::cout << "Queue is full. Cannot enqueue." << std::endl;
            return;
        }

        if (IsEmpty()) {
            front = rear = 0;
        }
        else {
            rear = (rear + 1) % MAX_SIZE;
        }

        elements[rear] = value;
        std::cout << "Enqueued: " << value << std::endl;
    }

    // Видалення елемента з черги
    void Dequeue() {
        if (IsEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue." << std::endl;
            return;
        }

        std::cout << "Dequeued: " << elements[front] << std::endl;

        if (front == rear) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % MAX_SIZE;
        }
    }

    // Відображення всіх елементів черги на екран
    void Show() const {
        if (IsEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return;
        }

        std::cout << "Queue elements: ";
        int i = front;
        do {
            std::cout << elements[i] << " ";
            i = (i + 1) % MAX_SIZE;
        } while (i != (rear + 1) % MAX_SIZE);
        std::cout << std::endl;
    }
};

int main() {
    Queue<int> myQueue;

    myQueue.Enqueue(1);
    myQueue.Enqueue(2);
    myQueue.Enqueue(3);

    myQueue.Show();

    myQueue.Dequeue();
    myQueue.Show();

    myQueue.Enqueue(4);
    myQueue.Show();

    return 0;
}
