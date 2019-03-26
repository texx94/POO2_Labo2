#include "String.hpp"

#include <iostream>

using namespace std;

int main() {

   cout << boolalpha;   // afin d'afficher true/false en console

   cout << "Tests des constructeurs basiques :" << endl;
   String s1;              // test le constructeur sans paramètre.
   const String s2("hello");     // test le constructeur depuis une chaine de caractères
   String s3 = s2;         // test le constructeur de copie

   cin >> s1;              // test la saisie au clavier
   cout << s1 << endl << s2 << endl << s3 << endl << endl;    // test l'affichage en console

   cout << "Tests des constructeurs specifiques :" << endl;
   cout << String('c') << endl << String(123) << endl
        << String(1.23) << endl << String(true) << endl;

   cout << "Tests des methodes et operateurs :" << endl
        << "Longeur de la chaine s2 \"hello\" : " << s2.getLength() << endl << endl;

   // test les methodes at en lecture
   cout << "Acces a un caractere d'un string et d'un string constant : "
        << s3.at(0) << s2.at(4) << endl << endl;

   // test la methode at en ecriture
   cout << "Acces et modification d'un caractere d'un string : ";
   s3.at(4) = 'i';
   cout << s3 << endl << endl;

   String s4("POO");
   String s5 = s4;
   String s6;

   // test les operateurs == et les methodes equals
   cout << "Test l'egalite de deux strings : " << endl
        << "s4 == s5 : " << (s4 == s5) << endl
        << "s4 == s6 : " << (s4 == s6) << endl << endl;

   // test les operateurs = et les methodes assign
   cout << "Test de l'assignation d'une valeur a un string : " << endl
        << "s6 = s2 : " << (s6 = s2) << endl << endl;

   // test les operateurs +, += et les methodes append
   cout << "Test de l'ajout d'une chaine a un string : " << endl;
   String s7 = " " + s5;   // test l'op + avec (const char*, const String&)
   String s8 = s6 + s7;
   cout << "s8 = s6 + s7 : " << s7 << endl
        << "s8 + \"!\" : " << (s8 + "!") << endl
        << "s8 : " << s8 << endl << endl ;

   // test les cas limites
   try {
      cout << "Test l'acces a un caractere hors chaine : " << endl;
      s8.at(9) = 'a';
   } catch (exception &e) {
      cout << e.what() << endl;
   }

   return 0;
}