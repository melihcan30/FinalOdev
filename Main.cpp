#include "m3.h"
#include "iostream"

using namespace std;

Pcb::Pcb(int inputBase, int inputLimit)
{
    this->baseAdress = inputBase;
    this->limit = inputLimit;
}

//limit dondurulur
int Pcb::getLimit()
{
    return this->limit;
}


//base dondurur
int Pcb::getBaseAddress()
{
    return this->baseAdress;
}

Pcb::~Pcb()
{

}

Node::Node(int inputPid, const char* inputPath, const char* inputFileName, int base, int limit)
{
    this->left = nullptr;
    this->right = nullptr;
    this->PID = inputPid;
    this->path = inputPath;
    this->fileName = inputFileName;
    this->pcb = new Pcb(base, limit);

}

//pcb dondurur
Pcb* Node::getPcb()
{
    return this->pcb;
}

//sol nodu dondurur
Node* Node::getLeft()
{
    return this->left;
}

//sag nodu dondurur
Node* Node::getRight()
{
    return this->right;
}

//sol noda deger yazar
void Node::setLeft(Node* adress)
{
    this->left = adress;
}

//sag noda deger yazdýrýr 
void Node::setRight(Node* adress)
{
    this->right = adress;
}

//pid degerini dondurur
int Node::getPID()
{
    return this->PID;
}

Node::~Node()
{
    this->left = nullptr;
    this->right = nullptr;
    delete this->pcb;

}

//constructor
List::List()
{
    this->size = 0;
    this->tasmaSize = 0;
    this->startAdress = 10000;
    this->endingAdress = 100000;
    this->pointerAdress = this->startAdress;
    this->limits[0] = 10000;
    this->limits[1] = 15000;
    this->limits[2] = 20000;
    this->limits[3] = 25000;
    this->limits[4] = 30000;
    this->first = nullptr;
    this->pointer = nullptr;
    this->tasma = nullptr;
    this->tasmaPointer = nullptr;

}


//liste boyutunu dondurur
int List::getSize()
{
    return size;
}

//process ekleme
void List::CreateProcess(Node* addedNode)
{

    if ((this->pointerAdress + addedNode->getPcb()->getLimit()) <= this->endingAdress)
    {
        this->size++;
        if (this->first == nullptr)
        {
            this->first = addedNode;
            this->pointer = addedNode;
            // cout << this->first->getPID()<<"\n";
            // cout << addedNode->getPID() << "       " << addedNode->getPcb()->getBaseAddress() << "             " << addedNode->getPcb()->getLimit() << "            " << endl << endl;
        }
        else
        {
            this->pointer->setRight(addedNode);
            addedNode->setLeft(this->pointer);
            this->pointer = addedNode;
            // cout << this->first->getPID() << "\n";
            // cout << addedNode->getPID() << "       " << addedNode->getPcb()->getBaseAddress() << "             " << addedNode->getPcb()->getLimit() << "            " << endl << endl;
        }

        this->pointerAdress = this->pointerAdress + addedNode->getPcb()->getLimit();
    }
    else
    {
        this->tasmaSize++;
        if (this->tasma == nullptr)
        {
            this->tasma = addedNode;
            this->tasmaPointer = addedNode;
        }
        else
        {
            this->tasmaPointer->setRight(addedNode);
            addedNode->setLeft(this->tasmaPointer);
            this->tasmaPointer = this->tasmaPointer->getRight();
        }
    }


}


//process silme
void List::DestroyProcess(int deletedPid)
{
    Node* temp = this->first;
    while (temp->getPID() != deletedPid)
    {
        temp = temp->getRight();
        if (temp == nullptr) break;


    }
    if (temp != nullptr)
    {
        if (temp->getRight() != nullptr) temp->getRight()->setLeft(temp->getLeft());
        if (temp->getLeft() != nullptr) temp->getLeft()->setRight(temp->getRight());
        if (temp == this->first) this->first = temp->getRight();
        if (temp == this->pointer && this->pointer->getRight() != nullptr) this->pointer = temp->getRight();
        else this->pointer = temp->getLeft();
        this->pointerAdress -= temp->getPcb()->getLimit();
        delete temp;
        this->size--;
    }
}

// sýnýrý asan prosesler yazdýrýlýyor.
void List::printTasma()
{

    for (int i = 0; i < tasmaSize; i++)
    {
        Node* temp = this->tasma;
        cout << "Bu process icin yer yok => " << temp->getPcb()->getBaseAddress() << endl << endl;
        tasma = tasma->getRight();
        delete temp;
    }
    this->tasmaSize = 0;
}

//calisan prosesler yazdýrýlýyor.
void List::printProcess()
{
    this->pointer = this->first;
    for (int i = 0; i < size; i++)
    {

        cout << this->pointer->getPID() << "       " << this->pointer->getPcb()->getBaseAddress() << "             " << this->pointer->getPcb()->getLimit() << "            " << endl << endl;

        if (this->pointer->getRight() != nullptr) this->pointer = this->pointer->getRight();

    }
}

//bütün elemanlar yazdýrýlýyor
void List::print(int durum)
{
    if (durum == this->ekleme)
    {
        cout << "OLUSTURULAN PROCESSLER" << endl;
        cout << "___________________________________________" << endl << endl;

        this->printTasma();

        cout << "PID     Base Adress       Limit Register   " << endl;
        cout << "-------------------------------------------" << endl << endl;

        this->printProcess();
    }
    else if (durum == this->cikarma)
    {
        cout << "SILINME ISLEMINDEN SONRA KALAN PROCESSLER" << endl;
        cout << "___________________________________________" << endl << endl;

        this->printTasma();

        cout << "PID     Base Adress       Limit Register   " << endl;
        cout << "-------------------------------------------" << endl << endl;

        this->printProcess();
    }


}

//liste yok edilirken çaðrýlýyor.
List::~List()
{

    for (int i = 0; i < this->getSize(); i++)
    {
        Node* temp = this->pointer;

        if (this->pointer->getLeft() != nullptr) this->pointer = this->pointer->getLeft();

        delete temp;

    }
    this->first = nullptr;
    this->pointer = nullptr;

}


int main(int argc, char* argv[])
{
    int ekle = 0, cikar = 1;
    List* list = new List();



    //cout<<list->pointer->getPID()<<"\n";
    //cout << list->pointer->getLeft()->getPID();

    //int size = list->getSize();

    list->CreateProcess(new Node(1, "evde", "file1", 10000, list->limits[2]));
    list->CreateProcess(new Node(2, "iste", "file2", 20000, list->limits[1]));
    list->CreateProcess(new Node(3, "evde", "file1", 30000, list->limits[3]));
    list->CreateProcess(new Node(4, "iste", "file2", 40000, list->limits[4]));
    list->CreateProcess(new Node(5, "evde", "file1", 50000, list->limits[0]));
    list->CreateProcess(new Node(6, "iste", "file2", 60000, list->limits[1]));
    list->print(ekle);
    list->DestroyProcess(1);
    list->DestroyProcess(6);
    list->print(cikar);
    list->CreateProcess(new Node(11, "iste", "file2", 11000, list->limits[4]));
    list->CreateProcess(new Node(12, "evde", "file1", 12000, list->limits[0]));
    list->CreateProcess(new Node(13, "iste", "file2", 13000, list->limits[1]));
    list->print(ekle);
    //cout << selected->getPID() << "       " << selected->getPcb()->getBaseAddress() << "             " << selected->getPcb()->getLimit() << "            " << endl << endl;
    delete list;
}