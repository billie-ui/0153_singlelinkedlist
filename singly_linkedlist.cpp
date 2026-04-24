#include <iostream>
using namespace std;

class Node
{
    public:
        int noMhs;
        Node *next;
};
class linkedlist
{
    Node *START;

    public:
        linkedlist()
        {
            START = NULL;
        }

        void addNode()
        {
            int nim;
            cout << "\nMasukkan Nomor Mahasiswa : ";
            cin >> nim;

            Node *nodeBaru = new Node;
            nodeBaru->noMhs = nim;

            if (START == NULL || nim <= START->noMhs)
            {
                if ((START != NULL) && (nim == START->noMhs))
                {
                    cout << "\nDuplikasi noMhs tidak diizinkan\n";
                    return;
                }
                nodeBaru->next = START;
                START = nodeBaru;
                return;
            }

            Node *previous = START;
            Node *current = START;
            
            while ((current != NULL) && (nim >= current->noMhs))
            {
                if (nim == current->noMhs)
                {
                    cout << "\nDuplikasi noMhs tidak diizinkan\n";
                    return;
                }
                previous = current;
                current = current->next;
            }

            nodeBaru->next = current;
            previous->next = nodeBaru;
        }

        bool listempty ()
        {
            return (START == NULL);
        }

        bool search (int nim, Node **previous, Node **current)
        {
            *previous = START;
            *current = START;

            while ((*current != NULL) && (nim != (*current)->noMhs))
            {
                *previous = *current;
                *current = (*current)->next;
            }

            return (*current != NULL);
        }

        bool delNode (int nim)
        {
            Node *current, *previous;
            if (!search(nim, &previous, &current))
            return false;

            if (current == START)
                START = START->next;
            else
                previous->next= current->next;

            delete current;
            return true;
        }
    
    void traverse ()
    {
        if (listempty())
        {
            cout << "\nList Kosong\n";
        }
        else
        {
            cout << "\nData didalam list adalah:\n";
            Node *currentNode = START;
            while (currentNode != NULL)
            {
                cout << currentNode->noMhs << endl;
                currentNode = currentNode->next;
            }
            cout << endl;
        }   
    }
};

int main()
{
    linkedlist mhs;
    int nim;
    char ch;
    do
    {
        cout << endl
             << "Menu";
        cout << endl
             << "1. Menambah Data Kedalam list" << endl;
        cout << "2. Menghapus Data dari dalam list" << endl;
        cout << "3. Menampilkan semua data didalam list" << endl;
        cout << "4. Menampilkan semua data didalam list secara terbalik" << endl;
        cout << "5. Mencari data dalam list" << endl;
        cout << "6. Keluar" << endl;
        cout << endl
             << "Masukkan pilihan (1-5) : ";
        cin >> ch;
        switch (ch)
        {
            case '1':
            {
                mhs.addNode();
            }
            break;
             case '2':
            {
                if (mhs.listempty())
                {
                    cout << endl
                         << "list Kosong" << endl;
                         break;
                }
                cout << endl
                     << "\nMasukkan no Mahasiswa yang akan dihapus : ";
                cin >> nim;
                if (mhs.delNode(nim)== false)
                    cout << endl
                         << "Data tidak ditemukan" << endl;
                else
                cout << endl
                     << "Data dengan Nomor Mahasiswa" << nim
                     << "Berhasil Dihapus" << endl;
            }
            break;
