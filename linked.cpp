#include <iostream>
#include <string>
using namespace std;

typedef struct node
{
    int data;
    string nama;
    node* next;
}*list;

list head;

void SalahMemasukkan()
{
    system("cls");
    cout << "Anda Salah Memasukkan Input\n\n" << endl << endl;
    system("pause");
}

void KeluarProgram()
{
    system("cls");
    cout << "Anda Keluar Program \n\n";
    system("pause");
}

void InstallHead()
{
    head = NULL;
}

int CekHead()
{
    return (head == NULL) ? 1 : 0;
}

void InsertDataHead(list insert)
{
    if (CekHead() == 1)
    {
        head = insert;
        insert->next = NULL;
    }
    else
    {
        insert->next = head;
        head = insert;
    }
    cout << "Mahasiswa Baru Telah Ditambahkan Di Awal Data\n\n";
    system("pause");
    system("cls");
}

void InsertDataTail(list insert)
{
    list tail;
    tail = head;
    if (CekHead() == 1)
    {
        head = insert;
        head->next = NULL;
    }
    else
    {
        do
        {
            tail = tail->next;
        } while (tail->next != NULL);
        tail->next = insert;
        tail = tail->next;
    }
    cout << "Mahasiswa Baru Telah Ditambahkan Di Akhir Data\n\n";
    system("pause");
    system("cls");
}

void InsertDataAfterNode(int lokasinode, list masuk)
{
    list after;
    if (CekHead() == 1)
    {
        head = after;
        after->next = NULL;
    }
    else
    {
        after = head;
        do
        {
            after = after->next;
        } while (after->data != lokasinode);
        masuk->next = after->next;
        after->next = masuk;
    }
    cout << "Mahasiswa Baru Telah Ditambahkan Setelah NIM: " << lokasinode << endl << endl;
    system("pause");
    system("cls");
}

void InsertDataBeforeNode(int lokasinode, list masuk)
{
    list t, prevt;
    if (head->data == lokasinode)
    {
        InsertDataHead(masuk);
    }
    else
    {
        if (CekHead() == 1)
        {
            head = t;
            t->next = NULL;
        }
        else
        {
            t = head;
            do
            {
                prevt = t;
                t = t->next;
            } while (t->data != lokasinode);
            masuk->next = t;
            prevt->next = masuk;
        }
    }

    cout << "Mahasiswa Baru Telah Ditambahkan Sebelum NIM: " << lokasinode << endl << endl;
    system("pause");
    system("cls");
}

void DeleteDataHead()
{
    list hapus;
    int d;
    string de;
    if (CekHead() == 0)
    {
        if (head->next != NULL)
        {
            hapus = head;
            d = hapus->data;
            de = hapus->nama;
            head = head->next;
            delete hapus;
        }
        else
        {
            d = head->data;
            de = head->nama;
            head = NULL;
        }
        cout << "Mahasiswa " << d << " Terhapus\n\n";
    }
    else
    {
        cout << "Data Masih Kosong\n\n";
    }
    system("pause");
    system("cls");
}

void DeleteDataTail()
{
    list t, hapus;
    int d;
    string de;
    if (CekHead() == 0)
    {
        if (head->next != NULL)
        {
            t = head;
            while (t->next->next != NULL)
            {
                t = t->next;
            }
            hapus = t->next;
            d = hapus->data;
            de = hapus->nama;
            t->next = NULL;
            delete hapus;
        }
        else
        {
            d = head->data;
            de = head->nama;
            head = NULL;
        }
        cout << "Mahasiswa " << d << " Terhapus\n\n";
    }
    else
    {
        cout << "Data Masih Kosong\n\n";
    }
    system("pause");
    system("cls");
}

void DeleteDataNode(int lokasinode)
{
    
}

void TampilList()
{
    list t;
    t = head;
    if (CekHead() == 0)
    {
        cout << "Nama\tNIM\n\n";
        while (t != NULL)
        {
            cout << t->nama << "\t" << t->data << endl;
            t = t->next;
        }
    }
    else
    {
        cout << "Data Masih Kosong\n\n";
    }
    cout << endl;
    system("pause");
    system("cls");
}

void ClearData()
{
    list t, hapus;
    t = head;
    while (t != NULL)
    {
        hapus = t;
        t = t->next;
        delete t;
    }
    head = NULL;
    cout << "Semua Mahasiswa Terhapus \n\n";
    system("pause");
    system("cls");
}

int main()
{
    list n;
    list t;
    InstallHead();
    do
    {
        cout << "Program Pengelompokakan Data Mahasiswa \n\n";
        system("pause");
        system("cls");
        unsigned short int pilihan;
        cout << "Apakah anda ingin melanjutkan ?\n\n1. Iya \n2. Tidak \n\nPilihan: ";
        cin >> pilihan;
        if (pilihan == 1)
        {
            system("cls");
            int nim, batas, lokasi;
            string name;
            cout << "Masukkan Total Mahasiswa: ";
            cin >> batas;
            system("cls");
            for (int x = 1; x <= batas; x++)
            {
                if (x == 1)
                {
                    system("cls");
                    cout << "Mahasiswa Ke-" << x << endl << endl;
                    cout << "Masukkan Nama: ";
                    cin >> name;
                    cout << "\nMasukkan NIM: ";
                    cin >> nim;
                    n = new node;
                    n->data = nim;
                    n->nama = name;
                    t = n;
                    head = n;
                }
                else if (x == batas)
                {
                    system("cls");
                    cout << "Mahasiswa Ke-" << x << endl << endl;
                    cout << "Masukkan Nama: ";
                    cin >> name;
                    cout << "\nMasukkan NIM: ";
                    cin >> nim;
                    n = new node;
                    n->data = nim;
                    n->nama = name;
                    t->next = n;
                    n->next = NULL;
                    t = head;
                }
                else
                {
                    system("cls");
                    cout << "Mahasiswa Ke-" << x << endl << endl;
                    cout << "Masukkan Nama: ";
                    cin >> name;
                    cout << "\nMasukkan NIM: ";
                    cin >> nim;
                    n = new node;
                    n->data = nim;
                    n->nama = name;
                    t->next = n;
                    t = t->next;
                }
            }
            do
            {
                system("cls");
                cout << "1. Lihat Mahasiswa\n2. Pengoperasian Mahasiswa \n3. Keluar Program \n\nPilihan: ";
                cin >> pilihan;
                if (pilihan == 1)
                {
                    system("cls");
                    TampilList();
                }
                else if (pilihan == 2)
                {
                    system("cls");
                    cout << "Pengoperasian Mahasiswa \n\n";
                    cout << "1. Tambah Mahasiswa Di Awal Data\n";
                    cout << "2. Tambah Mahasiswa Di Akhir Data\n";
                    cout << "3. Tambah Mahasiswa Setelah NIM Mahasiswa Yang Ada Di Data\n";
                    cout << "4. Tambah Mahasiswa Sebelum NIM Mahasiswa Yang Ada Di Data\n";
                    cout << "5. Hapus Mahasiswa Di Awal Data\n";
                    cout << "6. Hapus Mahasiswa Di Akhir Data\n\nPilihan:";
                    //cout << "7. Hapus Mahasiswa Sesuai NIM Mahasiswa Yang Ada Di Data\n";
                    //cout << "8. Hapus Semua Mahasiswa\n\nPilihan: ";
                    cin >> pilihan;
                    if (pilihan == 1)
                    {
                        system("cls");
                        cout << "Masukkan Nama Mahasiswa: ";
                        cin >> name;
                        cout << "\nMasukkan NIM Mahasiswa: ";
                        cin >> nim;
                        n = new node;
                        n->data = nim;
                        n->nama = name;
                        InsertDataHead(n);
                    }
                    else if (pilihan == 2)
                    {
                        system("cls");
                        cout << "Masukkan Nama Mahasiswa: ";
                        cin >> name;
                        cout << "\nMasukkan NIM Mahasiswa: ";
                        cin >> nim;
                        n = new node;
                        n->data = nim;
                        n->nama = name;
                        InsertDataTail(n);
                    }
                    else if (pilihan == 3)
                    {
                        system("cls");
                        cout << "Masukkan Nama Mahasiswa: ";
                        cin >> name;
                        cout << "\nMasukkan NIM Mahasiswa: ";
                        cin >> nim;
                        cout << "\n\nMasukkan Data Setelah NIM: ";
                        cin >> lokasi;
                        n = new node;
                        n->data = nim;
                        n->nama = name;
                        InsertDataAfterNode(lokasi, n);
                    }
                    else if (pilihan == 4)
                    {
                        system("cls");
                        cout << "Masukkan Nama Mahasiswa: ";
                        cin >> name;
                        cout << "\nMasukkan NIM Mahasiswa: ";
                        cin >> nim;
                        cout << "\n\nMasukkan Data Sebelum NIM: ";
                        cin >> lokasi;
                        n = new node;
                        n->data = nim;
                        n->nama = name;
                        InsertDataBeforeNode(lokasi, n);
                    }
                    else if (pilihan == 5)
                    {
                        system("cls");
                        DeleteDataHead();
                    }
                    else if (pilihan == 6)
                    {
                        system("cls");
                        DeleteDataTail();
                    }
                    /*else if (pilihan == 7)
                    {
                        system("cls");
                        cout << "Masukkan NIM Mahasiswa Yang Akan Dihapus: ";
                        cin >> nim;
                        DeleteDataNode(nim);
                    }
                    else if (pilihan == 8)
                    {
                        system("cls");
                        void ClearData();
                    }*/
                    else
                    {
                        system("cls");
                        SalahMemasukkan();
                        return 0;
                    }
                }
                else if (pilihan == 3)
                {
                    system("cls");
                    KeluarProgram();
                    return 0;
                }

                else
                {
                    system("cls");
                    SalahMemasukkan();
                    return 0;
                }

            } while (true);
        }
        else if (pilihan == 2)
        {
            system("cls");
            KeluarProgram();
            return 0;
        }
        else
        {
            system("cls");
            SalahMemasukkan();
            return 0;
        }
    } while (true);
}
