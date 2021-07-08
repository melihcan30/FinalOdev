class Pcb   //Pcb ad�nda class olu�turuldu
{
private:    //Di�er class'lardan eri�imi engelledi.
    int baseAdress; //integer de�i�keniyle bir atama yapt�k.
    int limit;  //integer de�i�keniyle bir atama yapt�k.
public: //Di�er class'lardan eri�im yapabilmesi sa�land�.
    Pcb(int, int);  //Pcb'ye iki tane integer parametre atand�.
    int getLimit();     //�nteger de�i�kenli bir fonksiyon olu�turuldu.
    int getBaseAddress();   //�nteger de�i�kenli bir fonksiyon olu�turuldu.
    ~Pcb();     //Y�k�c� fonksiyon yaz�ld� 
};


class Node  //Node ad�nda class olu�turuldu.
{
private:    //Di�er class'lardan eri�imi engelledi.
    Node* left;     //Bir dizi olu�turma amac� ile Node'un sol kolu i�in alan olu�turuldu.
    Node* right;    //Bir dizi olu�turma amac� ile Node'un sa� kolu i�in alan olu�turuldu.
    int PID;        //Benzersiz bir id numaras� integer de�i�kenine atand�. 
    const char* path;   // dizideki herhangi bir elemana ula�mak i�in yol olu�turuldu. 
    const char* fileName;   //dosya ad� olu�turuldu.
    Pcb* pcb; //pcb ad�nda pointer olu�turuldu
public:     //Di�er class'lardan eri�im yapabilmesi sa�land�.
    Node* getLeft(); //private olarak olu�turdupumuz left pointer�n� get ettik.
    Node* getRight();   //private olarak olu�turdupumuz right pointer�n� get ettik.
    Pcb* getPcb();  //priavte olarak olu�turdu�umuz pcb pointer�n� get ettik.
    void setLeft(Node* newer);  //private olarak olu�turdupumuz left pointer�n� set ettik.
    void setRight(Node* newer); //private olarak olu�turdupumuz right pointer�n� set ettik.
    int getPID();   //priavte olarak olu�turdu�umuz PID pointer�n� get ettik.
    Node(int pid, const char* path, const char* fileName, int base, int limit); //Node'umuza gerekli olan parametrelerimizi atad�k. 
    ~Node();    //Y�k�c� fonksiyon yaz�ld� 

};

class List  //List ad�nda class olu�turuldu.
{
public:     //Di�er class'lardan eri�im yapabilmesi sa�land�.
    Node* first;    //Node'muzun ilk eleman� i�in pointer atad�k.
    Node* pointer;  //Node'umuza pointer ad�nda pointer atad�k.
    Node* tasma;    //Node'muzun ta�abilecek olan eleman� i�in pointer atad�k.
    Node* tasmaPointer; //Node'muzun ta�abilecek olan eleman� i�in tasmaPointer atad�k.
    int startAdress;    //Ba�lang�� adresini tutaca��m�z bir integer de�er atad�k.
    int pointerAdress;  //Pointer adresini tutaca��m�z bir integer de�er atad�k.
    int endingAdress;   //Dizinin sonunu tutacak birinteger de�er atad�k.
    int limits[5];      //Dizinin size'�n� 5 olarak belirledik.
    int size;           //Size ad�nda dizinin boyutunu tutaca��m�z bir iteger de�er atad�k.
    int tasmaSize;      //Ta�man�n boyutunu tutaca��m�z bir integer de�er atad�k. 
    enum MyEnum         //Enum olu�turduk.
    {
        ekleme, cikarma //Ekleme ��karma i�lemlerini tuttuk.
    };

    // List class�n� alma, y�kma, size'� alma, Node'a process ekleme, process silme, yazd�rma, ta�may� yazd�rma, process'i yazd�rma ve Node'daki process'i bulma
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
