// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int len=0;
        int m;
        while (len+4<=n){
            m=read4(buf+len);
            len+=m;
            if (m<4) break;
        }
        if (m<4 || len==n) return len;
        m = n-len;
        char remain[4];
        m = min(m,read4(remain));
        for (int i=0;i<m;i++) buf[len++]=remain[i];
        return len;
        
    }
};
