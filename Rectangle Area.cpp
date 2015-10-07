class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int a1=(D-B)*(C-A);
        int a2=(H-F)*(G-E);
        int overlap=tool(A,B,C,D,E,F,G,H);

        
        return a1+a2-overlap;
    }
    
    int tool(int A, int B, int C, int D, int E, int F, int G, int H) {
        int h1=min(D,H);
        int h2=max(B,F);
        int h=h1-h2;
        
        int w1=min(C,G);
        int w2=max(E,A);
        int w=w1-w2;
        
        if(h1<h2||w1<=w2) return 0;
        return w*h;
        
    }
};
