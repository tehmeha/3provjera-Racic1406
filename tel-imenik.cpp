#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    int brojOsoba = 0;
    int izbor;
    int MAX = 50;
    string prezimeIme[MAX];
    unsigned long long brojtelefona[MAX];
    string adresa[MAX];
    ofstream datotekaUpisivanje;
    ifstream datotekaUcitavanje;

    datotekaUcitavanje.open("imenik.txt");
    datotekaUcitavanje >> prezimeIme[brojOsoba];
    datotekaUcitavanje >> brojtelefona[brojOsoba];
    datotekaUcitavanje >> adresa[brojOsoba];
    datotekaUcitavanje.close();
    brojOsoba++;

    while(1)
    {
        cout << "Glavni izbornik" << endl;
        cout << "1. Unos nove osobe" << endl;
        cout << "2. Ispisi sve podatke" << endl;
        cout << "3. Pretraga prema telefosnkom broju" << endl;
        cout << "4. Pretraga prema prezimenu i imenu" << endl;
        cout << "5. Izmjena podataka prema telefonskom broju" << endl;
        cout << "6. Ispisi sortirano prema prezimenu i imenu" << endl;
        cout << "7. Izlaz iz programa" << endl;
        cout << "Upisite broj iz izbornika: ";
        cin >> izbor;
        if( izbor == 1 )
        {
            cout << "Unesite ime i prezime: ";
            cin.ignore();
            getline(cin, prezimeIme[brojOsoba]);
            cout << "Upisite broj telefona: ";
            cin >> brojtelefona[brojOsoba];
            cout << "Unesite adresu: ";
            cin.ignore();
            getline(cin, adresa[brojOsoba]);

            datotekaUpisivanje.open("imenik.txt", ios::app);
            datotekaUpisivanje << prezimeIme[brojOsoba] << endl;
            datotekaUpisivanje << brojtelefona[brojOsoba] << endl;
            datotekaUpisivanje << adresa[brojOsoba] << endl;
            datotekaUpisivanje.close();

            brojOsoba++;
        }
        else if( izbor == 2 )
        {
            cout << "prezime i ime" << "\t" << "broj telefona" << "\t" << "adresa" << endl;
            for( int i = 0; i < brojOsoba; i++ )
            {
                cout << prezimeIme[i] << "\t" << brojtelefona[i] << "\t" << "\t" << adresa[i] << endl;
            }
        }
        else if( izbor == 3 )
        {
            unsigned long long int brTelefona;
            cout << "Unesite broj telefona kojeg zelite pronaci: ";
            cin >> brTelefona;
            bool postoji=false;
            for(int i=0; i < brojOsoba; i++)
            {
                if(brTelefona == brojtelefona[i])
                {
                    cout << "Postoji u telefonskom imeniku" << endl;
                    postoji=true;
                    cout << prezimeIme[i] << "\t" << brojtelefona[i] << "\t" << "\t" << adresa[i] << endl;
                    break;
                }
            }
            if( postoji==false )
            {
                cout << "Nepostoji u telefonskom imeniku" << endl;
            }
        }
        else if( izbor == 4 )
        {
            string prezimeime;
            cout << "Unesite ime i prezime osobe koju zelite pronaci: ";
            cin.ignore();
            getline(cin, prezimeime);
            bool postoji=false;
            for(int i=0; i < brojOsoba; i++)
            {
                if(prezimeime == prezimeIme[i])
                {
                    cout << "Postoji u telefonskom imeniku" << endl;
                    postoji=true;
                    cout << prezimeIme[i] << "\t" << brojtelefona[i] << "\t" << "\t" << adresa[i] << endl;
                    break;
                }
                if( postoji==false )
                {
                    cout << "Nepostoji u telefonskom imeniku" << endl;
                }
            }
        }
        else if( izbor == 5 )
        {
        }
        else if( izbor == 6 )
        {
        }
        else if( izbor == 7 )
        {
            cout << "Kraj rada" << endl;
            break;
        }
        else
        {
            cout << "Unijeli ste krivi broj." << endl;
        }
        cout << endl;
    }
}
