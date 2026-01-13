int compress(char* chars, int charsSize) {
    int write = 0;
    if(charsSize == 1)
        return 1;
    int read = 0;
    while(read < charsSize) {
        int char_count = 0;
        char ch = chars[read];
        while(read < charsSize && ch == chars[read]) {
            char_count++;
            read++;
        }
        chars[write++] = ch;
        if(char_count != 1) {
            char buffer[12];
            int len = sprintf(buffer, "%d", char_count);
            for(int j = 0; j < len; j++) {
                chars[write++] = buffer[j];
            }
        }
    }
    return write;
}