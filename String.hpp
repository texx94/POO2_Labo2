#ifndef STRING_HPP
#define STRING_HPP

#include <stdio.h>

/**
 * Permet d'implémenter une chaîne de caractères
 */
class String {
public:
   /**
    * Constructeur sans paramètres
    */
   explicit String();

   /**
    * Constructeur à partir d'une chaîne de caractères
    * @param value Valeur de la chaîne de caractères
    */
   explicit String(const char* value);

   /**
    * Constructeur de copie
    * @param s Instance de la classe String sur laquelle on fait la copie
    */
   explicit String(const String& s);

   /**
    * Constructeur à partir d'un caractère
    * @param c Le caractère en question
    */
   explicit String(char c);

   /**
    * Constructeur à partir d'un entier
    * @param i L'entier en question
    */
   explicit String(int i);

   /**
    * Constructeur à partir d'un réel
    * @param d Le rééel en question
    */
   explicit String(double d);

   /**
    * Constructeur à partir d'un booléen
    * @param b Le booléen en question
    */
   explicit String(bool b);

   /**
    * Destructeur
    */
   ~String();
private:
   char* value;   // Valeur de la chaîne de caractères
};

#endif
