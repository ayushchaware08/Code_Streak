void MyQueue ::push(int x) {
    if(rear == 100005) {
        return;
    }
        
        arr[rear] = x;
        rear++;
}

// Function to pop an element from queue and return that element.
int MyQueue ::pop() {
     if(front >= rear) {
            return -1;
        }
        
        int x = arr[front];
        front++;
        return x;
}
