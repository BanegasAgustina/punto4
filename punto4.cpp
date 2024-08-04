#include <bits/stdc++.h>
using namespace std;

class CPassword {
    private:
        string contrasenia;
        int longitud;
    public:
        
        CPassword() {
            this->longitud = 8;
            generarPassword();
        }

       
        CPassword(string contrasenia) {
            this->contrasenia = contrasenia;
            this->longitud = contrasenia.size();
        }
        
        bool esFuerte() {
            int mayuscula = 0, minuscula = 0, numero = 0;
            for (char c : contrasenia) {
                if (isupper(c)) mayuscula++;
                else if (islower(c)) minuscula++;
                else if (isdigit(c)) numero++;
            }
            return mayuscula > 2 && minuscula > 1 && numero > 5;
        }

        void generarPassword() {
            contrasenia = "";
            int may = 0, min = 0, num = 0;
            srand(time(NULL));

            while (contrasenia.size() < longitud) {
                int randNum = rand() % 3;
                if (randNum == 0 && may < 3) {
                    contrasenia += 'A' + rand() % 26;
                    may++;
                } else if (randNum == 1 && min < 2) {
                    contrasenia += 'a' + rand() % 26;
                    min++;
                } else if (randNum == 2 && num < 6) {
                    contrasenia += '0' + rand() % 10;
                    num++;
                }
                
                else if (contrasenia.size() < longitud) {
                    int type = rand() % 3;
                    if (type == 0) contrasenia += 'A' + rand() % 26;
                    else if (type == 1) contrasenia += 'a' + rand() % 26;
                    else contrasenia += '0' + rand() % 10;
                }
            }
        }

        string getPassword() {
            return contrasenia;
        }

        int getLongitud() {
            return longitud;
        }

        void setLongitud(int longitud) {
            this->longitud = longitud;
            generarPassword(); 
        }
};

int main() {
  
    CPassword passwordDefecto;
    cout << "Contraseña por defecto: " << passwordDefecto.getPassword() << endl;
    cout << "Longitud: " << passwordDefecto.getLongitud() << endl;
    cout << "Es fuerte: " << (passwordDefecto.esFuerte() ? "Sí" : "No") << endl;

   
    string contrasenia;
    cout << "Ingrese contraseña: ";
    getline(cin, contrasenia);
    CPassword password(contrasenia);
    cout << "Tu contraseña es: " << password.getPassword() << endl;
    cout << "Su longitud es: " << password.getLongitud() << endl;
    cout << "Es fuerte: " << (password.esFuerte() ? "Sí" : "No") << endl;

    return 0;
}
