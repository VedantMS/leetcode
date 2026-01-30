int minMutation(char* startGene, char* endGene, char** bank, int bankSize) {
    bool endInBank = false;
    for (int i = 0; i < bankSize; i++) {
        if (strcmp(bank[i], endGene) == 0) {
            endInBank = true;
            break;
        }
    }
    
    if (!endInBank) {
        return -1;
    }
    
    char queue[12][9]; 
    bool visited[10] = {false};
    int front = 0, rear = 0;

    strcpy(queue[rear++], startGene);

    char *choices = "ACGT";
    int count = 0;

    while (front < rear) {
        int levelSize = rear - front;

        for (int i = 0; i < levelSize; i++) {
            char current[9];
            strcpy(current, queue[front++]);

            if (strcmp(current, endGene) == 0) {
                return count;
            }

            for (int j = 0; j < 8; j++) {
                char original = current[j];

                for (int k = 0; k < 4; k++) {
                    current[j] = choices[k];

                    for (int b = 0; b < bankSize; b++) {
                        if (!visited[b] && strcmp(current, bank[b]) == 0) {
                            visited[b] = true; 
                            strcpy(queue[rear++], bank[b]);
                        }
                    }
                }
                current[j] = original;
            }
        }
        count++;
    }

    return -1;
}
