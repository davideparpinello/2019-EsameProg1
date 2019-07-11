#include <iostream>
#include <iomanip>

using namespace std;

void stampaarray(const int V[],int n);
void leggiarray(int V[],int & n);
void intersezione(const int A[], int dima,
  const int B[], int dimb,
  int C[], int & dimc) ;
  void intersezione_ric(const int A[], int dima,
    const int B[], int dimb,
    int C[], int & dimc, int indice_a, int indice_b);

    int main () {
      int MAXDIM = 100;
      int A[MAXDIM] = {1,3,4,5,7,9,10,11,14,19,21,24};
      int dima = 12;
      int B[MAXDIM] = {0,1,2,4,5,6,8,11,12,13,15,19,22,23,24,27};
      int dimb = 16;
      int C[MAXDIM];
      int dimc;
      intersezione(A,dima,B,dimb,C,dimc);
      stampaarray(C,dimc);
      leggiarray(A,dima);
      leggiarray(B,dimb);
      intersezione(A,dima,B,dimb,C,dimc);
      stampaarray(C,dimc);
    }

    void stampaarray(const int V[],int n) {
      for(int i = 0; i < n; i++) {
        cout << V[i] << " ";
      }
      cout << endl;
    }

    void leggiarray(int V[],int & n) {
      int num;
      n = 0;
      do {
        cout << "Inserisci il " << n + 1 << "° elemento del vettore (< 1 per terminare): ";
        cin >> num;
        if(num > 0) {
          V[n++] = num;
        }
      }while (num > 0);
    }

    // Inserire le definizioni di intersezione, stampaarray e
    // leggiarray qui sotto.
    void intersezione(const int A[], int dima,
      const int B[], int dimb,
      int C[], int & dimc) {
        dimc = 0;
        intersezione_ric(A, dima, B, dimb, C, dimc, 0, 0);
      }

      void intersezione_ric(const int A[], int dima,
        const int B[], int dimb,
        int C[], int & dimc, int indice_a, int indice_b) {
          //controllo di non essere arrivato a fine vettori
          if(indice_a < dima && indice_b < dimb) {
            if(A[indice_a] == B[indice_b]) {
              C[dimc++] = A[indice_a];
              intersezione_ric(A, dima, B, dimb, C, dimc, indice_a + 1, indice_b + 1);
            }
            else if(A[indice_a] < B[indice_b]) {
              intersezione_ric(A, dima, B, dimb, C, dimc, indice_a + 1, indice_b);
            }
            else if(A[indice_a] > B[indice_b]) {
              intersezione_ric(A, dima, B, dimb, C, dimc, indice_a, indice_b + 1);
            }
          }

        }
