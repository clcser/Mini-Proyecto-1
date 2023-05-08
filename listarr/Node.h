#ifndef NODE_H
#define NODE_H

class Node {
    public:
        long long capacity, buffer;
        Node *parent;

        Node(long long buf, Node *p);
        ~Node(void);
        void orphan(void);
};

#endif
