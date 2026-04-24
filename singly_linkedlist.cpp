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
