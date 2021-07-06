class Pcb
{
private:
    int baseAdress;
    int limit;
public:
    Pcb(int, int);
    int getLimit();
    int getBaseAddress();
    ~Pcb();
};


class Node
{
private:
    Node* left;
    Node* right;
    int PID;
    const char* path;
    const char* fileName;
    Pcb* pcb;
public:
    Node* getLeft();
    Node* getRight();
    Pcb* getPcb();
    void setLeft(Node* newer);
    void setRight(Node* newer);
    int getPID();
    Node(int pid, const char* path, const char* fileName, int base, int limit);
    ~Node();

};

class List
{
public:
    Node* first;
    Node* pointer;
    Node* tasma;
    Node* tasmaPointer;
    int startAdress;
    int pointerAdress;
    int endingAdress;
    int limits[5];
    int size;
    int tasmaSize;
    enum MyEnum
    {
        ekleme, cikarma
    };

public:
    List();
    ~List();
    int getSize();
    void CreateProcess(Node*);
    void DestroyProcess(int);
    void print(int);
    void printTasma();
    void printProcess();

    Node* findProcess(int);
};
