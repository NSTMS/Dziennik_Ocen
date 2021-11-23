#include <iostream>
#include <vector>
#include <fstream>
#include <utility>
#include <map>
#include<algorithm>
#include <iomanip>

using namespace std;

int main()
{

    vector<string> nazwa_klasy;
    vector <string>uczniowie; //Nazwiska uczniow
    vector<pair<string, string>> Uczen; // Imie, Nazwisko
    map<string,pair<string,string>> Klasa; // Nazwisko <imie,klasa>
    //map<pair<string,string>,vector<float>> Oceny; // <Nazwisko,Klasa>,ocena

    string Imie,Nazwisko,nazwa;
    char odp,odp_klasa;
    do
    {
        cout<<endl<<"---------------------------"<<endl;
        cout<<"Tworzenie klasy"<<endl;
        cout<<"Podaj nazwe klasy: ";
        cin>>nazwa;

        nazwa_klasy.push_back(nazwa);
        do
        {
            cout<<"Podaj imie i nazwisko ucznia klasy "<<nazwa<<": ";
            cin>>Imie>>Nazwisko;

            uczniowie.push_back(Nazwisko);
            Uczen.push_back(make_pair(Imie,Nazwisko));
            Klasa[Nazwisko] = make_pair(Imie,nazwa);

            cout<<"Chesz dodac kolejnego ucznia?(T/N):";
            cin>>odp;
        }
        while(odp=='T' || odp=='t');

        cout<<"Chesz dodac kolejna klase?(T/N):";
        cin>>odp_klasa;
    }
    while(odp_klasa=='T' || odp_klasa=='t');


    //Sortowanie wszytskich vectorow
    sort(uczniowie.begin(), uczniowie.end());
    sort(Uczen.begin(), Uczen.end());


/*
    //  Wypisanie vectora Uczniowie
    cout<<"---------------------------"<<endl;
    cout<<"Uczniowie: "<<endl;
    for(int i=0; i<uczniowie.size(); i++)
    {
        cout<<i+1<<". "<<uczniowie[i]<<endl;
    }


    //  Wypisanie vectora Uczen
    cout<<"---------------------------"<<endl;
    cout<<"Uczen: "<<endl;
    for(int i=0; i<Uczen.size(); i++)
    {
        cout<<i+1<<". "<<Uczen[i].first<<" "<<Uczen[i].second<<endl;
    }
*/
    //Wypisanie mapy Klasa
    int i;
    for(int j=0; j<nazwa_klasy.size(); j++)
    {
        cout<<"---------------------------"<<endl;
        cout<<"Klasa "<<nazwa_klasy[j]<<endl;
        for(i = 0; i<Klasa.size(); i++)
        {
            if(Klasa[uczniowie[i]].second == nazwa_klasy[j])
            {
                cout<<i+1<<". "<<uczniowie[i]<<" "<<Klasa[uczniowie[i]].first<<" "<<Klasa[uczniowie[i]].second<<endl;
            }
        }
        i=0;
    }
    cout<<"---------------------------"<<endl;
    cout<<"Oceny"<<endl;

    map<string,vector<float>> Oceny; // Oceny : Nazwisko Ocena
    string nazwisko_ucznia,klasa_ucznia;
    char odp_ocena,odp_koniec;
    float ocena;


    do
    {
err1:
        cout<<"Podaj nazwisko ucznia: ";
        cin>>nazwisko_ucznia;

        for(int i=0; i<uczniowie.size(); i++)
        {
            if(nazwisko_ucznia == uczniowie[i])
            {
                cout<<"Podales prawidlowe nazwisko!"<<endl;
                break;
            }

            else if(i==uczniowie.size() && nazwisko_ucznia != uczniowie[uczniowie.size()])
            {
                goto err1;
            }
        }

        cout<<"Podaj klase ucznia "<<nazwisko_ucznia<<": ";
        cin>>klasa_ucznia;

        do
        {
err2:
            cout<<"Podaj ocene dla ucznia "<<nazwisko_ucznia<<": ";
            cin>>ocena;
            if(ocena <1 || ocena>6)
            {
                cout<<"Podales nieprawidlowa ocene!"<<endl;
                goto err2;
            }else Oceny[nazwisko_ucznia].push_back(ocena);
            cout<<"Chesz dodac kolejna ocene?(T/N):";
            cin>>odp_ocena;
        }
        while(odp_ocena=='T' || odp_ocena=='t');

        cout<<"Chesz zakonczyc wpisywanie ocen?(T/N):";
        cin>>odp_koniec;
    }
    while(odp_koniec=='N' || odp_koniec=='n' );

    cout<<"---------------------------"<<endl;
    cout<<"Wypisanie ocen"<<endl;

    do{
    err3:
    cout<<endl<<"Podaj nazwisko ucznia: ";
    cin>>nazwisko_ucznia;

        for(int i=0; i<Oceny.size(); i++)
        {
            if(nazwisko_ucznia == uczniowie[i])
            {
                cout<<"Podales prawidlowe nazwisko!"<<endl;
                break;
            }

            else if(i==uczniowie.size() && nazwisko_ucznia != uczniowie[i])
            {
                goto err3;
            }
        }

    cout<<"Oceny dla ucznia: "<<nazwisko_ucznia<<": ";
    for(int i=0;i<Oceny.size();i++)
    {
        cout<<Oceny[nazwisko_ucznia][i]<<",";
    }

    cout<<endl;
    cout<<"Chcesz wypisac oceny dla kolejnego ucznia?(T/N):";
    cin>>odp_ocena;
}while(odp_ocena=='T' || odp_ocena=='t' );




    cout<<"---------------------------"<<endl;
    cout<<"Srednia ocen"<<endl;
err4:
    cout<<"Podaj nazwisko ucznia: ";
    cin>>nazwisko_ucznia;

        for(int i=0; i<uczniowie.size(); i++)
        {
            if(nazwisko_ucznia == uczniowie[i])
            {
                cout<<"Podales prawidlowe nazwisko!"<<endl;
                break;
            }

            else if(i==uczniowie.size() && nazwisko_ucznia != uczniowie[uczniowie.size()])
            {
                cout<<"Podales bledne nazwisko ucznia!"<<endl;
                break;
                goto err1;
            }
        }


    int ile;

        for(int i =-0;i<Oceny[nazwisko_ucznia].size();i++)
        {
            if(Oceny[nazwisko_ucznia][i] !=0)
            {
                       ile++;
            }
        }
        if(ile == 0)
        {
            cout<<"Podaj inne nazwisko ucznia! Ten nie ma zadnych ocen!"<<endl;
            goto err4;
        }


    float suma;
    for(int i =0;i<Oceny.size();i++)
    {
        suma += Oceny[nazwisko_ucznia][i];
    }
    cout<<"Srednia ocen dla "<<nazwisko_ucznia<<" wynosi: "<<setprecision(3)<<suma/Oceny[nazwisko_ucznia].size()<<endl;


    return 0;
}
