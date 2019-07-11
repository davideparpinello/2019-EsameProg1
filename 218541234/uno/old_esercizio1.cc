#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>

using namespace std;

int main(int argc, char * argv[]) {
    if(argc != 3) {
        cout << "Sintassi: ./a.out testo testocorretto" << endl;
        exit(0);
    }

    fstream myin, myout;

    myin.open(argv[1], ios::in);
    if(myin.fail()) {
        cout << "Errore nell'apertura del file " << argv[1] << endl;
        exit(0);
    }

    myout.open(argv[2], ios::out);

    //leggo il primo carattere e lo converto se necessario
    char c;
    myin.get(c);
    if(c >= 'a' && c <= 'z') {
        c = c - ('a' - 'A');
        myout << c;
    }

    myin.get(c);
    while(!myin.eof()) {
        if((c == '.' || c == '?' || c == '!') && !myin.eof())  {
            //ristampo il carattere
            myout << c;
            //leggo e stampo uno spazio, controllo però di non aver raggiunto fine file altrimenti stamperei piu volte l'ultimo char
            myin.get(c);
            if(!myin.eof()) {
                myout << c;
                //leggo il primo carattere della prossima parola
                myin.get(c);
                //lo converto se minuscolo
                if(c >= 'a' && c <= 'z') {
                    c = c - ('a' - 'A');
                    myout << c;
                }
                else {
                    myout << c;
                }
            }
            
        }
        else {
            myout << c;
        }
        myin.get(c);
    }

    myin.close();
    myout.close();
    
    return 0;
}