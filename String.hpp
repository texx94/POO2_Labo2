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

   /**
    * Permet d'obtenir la longeur de la string
    * @return la longeur de la string
    */
   size_t getLength() const;

   /**
    * Permet d'obtenir la valeur à l'aide d'un pointeur sur char constant
    * @return un pointeur sur char
    */
   const char* c_str() const;

   /**
    * Permet d'obtenir et de modifier le caractere a l'index souhaite
    * @param index index du caractere a traiter
    * @return le caractere a l'indexe passe en parametre
    */
   char& at(size_t index);

   /**
    * Permet d'obtenir et de modifier le caractere a l'index souhaite
    * @param index index du caractere a traiter
    * @return le caractere a l'indexe passe en parametre
    */
   const char& at(size_t index) const;

   /**
    * Permet de comparer si deux Strings/chaine sont égales
    * @param other String a comparer
    * @return vrai si oui, faux sinon
    */
   bool equals(const String& other) const;

   /**
    * Permet de comparer si deux Strings/chaine sont égales
    * @param other String a comparer
    * @return vrai si oui, faux sinon
    */
   bool equals(const char* other) const;

   /**
    * Permet de modifier la valeur de la String
    * @param other String a assigner a l'objet courant
    * @return une reference sur l'objet courant
    */
   String& assign(const String& other);

   /**
    * Permet de modifier la valeur de la String
    * @param other chaine a assigner a l'objet courant
    * @return une reference sur l'objet courant
    */
   String& assign(const char* other);

   /**
    * Permet d'ajouter une string a la suite de l'objet courant
    * @param other String a appondre a l'objet courant
    * @return une reference sur l'objet courant
    */
   String& append(const String& other);

   /**
    * Permet d'ajouter une chaine a la suite de l'objet courant
    * @param other chaine a appondre a l'objet courant
    * @return une reference sur l'objet courant
    */
   String& append(const char* other);

   /**
    * Permet l'affichage dans la console
    */
   void print() const;

   /**
    * Permet la lecture de la saisie et sauve la valeur
    */
   void read();

private:
   char* value;      // Valeur de la chaîne de caractères
   size_t length;    // Longeur de la chaîne
};

#endif
