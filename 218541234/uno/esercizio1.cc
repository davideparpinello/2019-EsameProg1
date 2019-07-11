#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>

using namespace std;

const int MAXDIM = 30 + 1;

int main(int argc, char * argv[]) {
  if(argc != 3) {
    cout << "Sintassi: ./a.out f-input f-outputcorretto" << endl;
    exit(0);
  }

  fstream myin, myout;

  myin.open(argv[1], ios::in);
  if(myin.fail()) {
    cout << "Errore nell'apertura del file " << argv[1] << endl;
    exit(0);
  }

  myout.open(argv[2], ios::out);

  //leggo la prima parola e la converto se necessario
  char parola[MAXDIM];
  myin >> parola;
  if(parola[0] >= 'a' && parola[0] <= 'z') {
    parola[0] = parola[0] - ('a' - 'A');
  }
  myout << parola << " ";

  //controllo se l'ultima lettera è uno dei simboli di fine frase, in caso
  //positivo mi segno che dovrò controllare la prima lettera della prossima parola
  bool maiusc = false;
  int lun = strlen(parola);
  char last = parola[lun - 1];
  if(last == '.' || last == '?' || last == '!') {
    maiusc = true;
  }

  //ciclo fino a fine file
  while(myin >> parola) {
    lun = strlen(parola);
    last = parola[lun - 1];
    //se mi ero segnato di controllare l'iniziale e in caso aggiorno
    if(maiusc && parola[0] >= 'a' && parola[0] <= 'z') {
      parola[0] = parola[0] - ('a' - 'A');
    }
    myout << parola << " ";
    maiusc = false;
    //controllo se l'ultima lettera è uno dei simboli di fine frase, in caso
    //positivo mi segno che dovrò controllare la prima lettera della prossima parola
    if(last == '.' || last == '?' || last == '!') {
      maiusc = true;
    }
  }

  myin.close();
  myout.close();

  return 0;
}
