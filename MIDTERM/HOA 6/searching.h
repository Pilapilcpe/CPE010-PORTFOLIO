#ifndef SEARCHING_H
#define SEARCHING_H

template <typename T>
bool linearSearch(T data[], int N, T item) {
    int i = 0;

    while (i < N) {
        if (item == data[i]) {
            return true;
        }
        else {
            i++;
        }
    }
    return false;
}

template <typename T>
bool linearLS(Node<T>* head, T dataFind) {
    Node<T>* current = head;

    while (current != NULL) {
        if (current->data == dataFind) {
            return true;
        }

        current = current->next;
    }

    return false;
}

template <typename T>
bool binarySearch(T arr[], int n, T item) {
    int low = 0;
    int up = n - 1;

    while (low <= up) {
        int mid = (low + up) / 2;

        if (item == arr[mid]) {
            return true;
        }

        else if (item < arr[mid]) {
            up = mid - 1;
        }

        else {
            low = mid + 1;
        }
    }
    return false;
}

template <typename T>
Node<T>* getMiddle(Node<T>* start, Node<T>* last) {
    if (start == NULL) {
        return NULL;
    }
    Node<T>* slow = start;
    Node<T>* fast = start;

    while (fast != last && fast->next != last) {
        fast = fast->next;

        if (fast != last) {
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
}

template <typename T>
bool binarySearchLL(Node<T>* head, T key) {
    Node<T>* start = head;
    Node<T>* last = NULL;


    while (start != last) {
        Node<T>* middle = getMiddle(start, last);

        if (middle == NULL) {
            return false;
        }
        if (middle->data == key) {
            return true;
        }
        else if (middle->data > key) {
            last = middle;
        }
        else {
            start = middle->next;
        }
    }

    return false;
}

#endif