class Pcb   //Pcb adýnda class oluþturuldu
{
private:    //Diðer class'lardan eriþimi engelledi.
    int baseAdress; //integer deðiþkeniyle bir atama yaptýk.
    int limit;  //integer deðiþkeniyle bir atama yaptýk.
public: //Diðer class'lardan eriþim yapabilmesi saðlandý.
    Pcb(int, int);  //Pcb'ye iki tane integer parametre atandý.
    int getLimit();     //Ýnteger deðiþkenli bir fonksiyon oluþturuldu.
    int getBaseAddress();   //Ýnteger deðiþkenli bir fonksiyon oluþturuldu.
    ~Pcb();     //Yýkýcý fonksiyon yazýldý 
};


class Node  //Node adýnda class oluþturuldu.
{
private:    //Diðer class'lardan eriþimi engelledi.
    Node* left;     //Bir dizi oluþturma amacý ile Node'un sol kolu için alan oluþturuldu.
    Node* right;    //Bir dizi oluþturma amacý ile Node'un sað kolu için alan oluþturuldu.
    int PID;        //Benzersiz bir id numarasý integer deðiþkenine atandý. 
    const char* path;   // dizideki herhangi bir elemana ulaþmak için yol oluþturuldu. 
    const char* fileName;   //dosya adý oluþturuldu.
    Pcb* pcb; //pcb adýnda pointer oluþturuldu
public:     //Diðer class'lardan eriþim yapabilmesi saðlandý.
    Node* getLeft(); //private olarak oluþturdupumuz left pointerýný get ettik.
    Node* getRight();   //private olarak oluþturdupumuz right pointerýný get ettik.
    Pcb* getPcb();  //priavte olarak oluþturduðumuz pcb pointerýný get ettik.
    void setLeft(Node* newer);  //private olarak oluþturdupumuz left pointerýný set ettik.
    void setRight(Node* newer); //private olarak oluþturdupumuz right pointerýný set ettik.
    int getPID();   //priavte olarak oluþturduðumuz PID pointerýný get ettik.
    Node(int pid, const char* path, const char* fileName, int base, int limit); //Node'umuza gerekli olan parametrelerimizi atadýk. 
    ~Node();    //Yýkýcý fonksiyon yazýldý 

};

class List  //List adýnda class oluþturuldu.
{
public:     //Diðer class'lardan eriþim yapabilmesi saðlandý.
    Node* first;    //Node'muzun ilk elemaný için pointer atadýk.
    Node* pointer;  //Node'umuza pointer adýnda pointer atadýk.
    Node* tasma;    //Node'muzun taþabilecek olan elemaný için pointer atadýk.
    Node* tasmaPointer; //Node'muzun taþabilecek olan elemaný için tasmaPointer atadýk.
    int startAdress;    //Baþlangýç adresini tutacaðýmýz bir integer deðer atadýk.
    int pointerAdress;  //Pointer adresini tutacaðýmýz bir integer deðer atadýk.
    int endingAdress;   //Dizinin sonunu tutacak birinteger deðer atadýk.
    int limits[5];      //Dizinin size'ýný 5 olarak belirledik.
    int size;           //Size adýnda dizinin boyutunu tutacaðýmýz bir iteger deðer atadýk.
    int tasmaSize;      //Taþmanýn boyutunu tutacaðýmýz bir integer deðer atadýk. 
    enum MyEnum         //Enum oluþturduk.
    {
        ekleme, cikarma //Ekleme çýkarma iþlemlerini tuttuk.
    };

    // List classýný alma, yýkma, size'ý alma, Node'a process ekleme, process silme, yazdýrma, taþmayý yazdýrma, process'i yazdýrma ve Node'daki process'i bulma
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
