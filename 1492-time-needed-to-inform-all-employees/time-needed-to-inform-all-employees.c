int numOfMinutes(int n, int headID, int* manager, int managerSize, int* informTime, int informTimeSize) {
    int *head = (int *)malloc(n * sizeof(int));
    int *next = (int *)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++) {
        head[i] = -1;
    }

    for(int i = 0; i < n; i++) {
        if(manager[i] != -1) {
            next[i] = head[manager[i]];
            head[manager[i]] = i;
        }
    }

    int queue[n][2];
    int front = 0, rear = 0;
    
    queue[0][0] = headID;
    queue[0][1] = 0;
    rear++;

    int time = 0;

    while(front < rear) {
        int id = queue[front][0];
        int currentTime = queue[front][1];
        front++;

        time = time > currentTime ? time : currentTime;

        int subordinate = head[id];
        while(subordinate != -1) {
            queue[rear][0] = subordinate;
            queue[rear][1] = currentTime + informTime[id];
            rear++;
            
            subordinate = next[subordinate];
        }
    }
    return time;
}