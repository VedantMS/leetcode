bool canReach(int* arr, int arrSize, int start) {
    int n = arrSize;
    int queue[n];
    int front = 0, rear = 0;
    int visited[n];

    for(int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    queue[rear] = start;
    rear++;

    visited[start] = 1;

    while(front < rear) {
        int pos = queue[front];
        front++;

        if(arr[pos] == 0) {
            return 1;
        }

        if(pos + arr[pos] < n && !visited[pos + arr[pos]]) {
            queue[rear] = pos + arr[pos];
            rear++;
            
            visited[pos + arr[pos]] = 1;
        }

        if(pos - arr[pos] >= 0 && !visited[pos - arr[pos]]) {
            queue[rear] = pos - arr[pos];
            rear++;
            
            visited[pos - arr[pos]] = 1;
        }
    }
    return 0;
}