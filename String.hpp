/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo2
 Fichier     : String.hpp
 Auteur(s)   : Gilliand Loris - Tutic Mateo
 Date        : 27.03.2019

 But         : Header de la classe String

 Remarque(s) : Met à disposition plusieurs constructeurs (sans param, à partir
               d'une chaine, copie, à partir d'un char, à partir d'un entier,
               à partir d'un double, à partir d'un booleen).

               Met à disposition pluisieurs methodes acceptant un string ou une
               chaine en paramètre (assign, equals, append). Il existe aussi une
               méthode d'accès (at), d'extraction de la chaine (c_str) et une
               rendant la longeur de la chaine (getLength).

               Les operateurs +, +=, ==, << et >> sont surchargés. L'operateur +
               offre trois possibilités (char* + String, String + String,
               String + char*).

 Compilateur : MinGW-g++ 6.3.0 - Apple LLVM 9.1.0
 -----------------------------------------------------------------------------------
 */

#ifndef STRING_HPP
#define STRING_HPP

#include <cstdio>
#include <iostream>

/**
 * Permet d'implémenter une chaîne de caractères
 */
class String {

   friend String operator+(String lhs, const String& rhs);
   friend String operator+(String lhs, const char* rhs);
   friend String operator+(const char* lhs, const String& rhs);
   friend std::ostream& operator<<(std::ostream& os, const String& rhs);
   friend std::istream& operator>>(std::istream& is, String& rhs);

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
    String(const String& s);

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
    * @param d Le réel en question
    */
   explicit String(double d);

   /**
    * Constructeur à partir d'un booléen
    * @param b Le booléen en question
    */
   explicit String(bool b);

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
    * @return le caractere a l'index passe en parametre
    */
   char& at(size_t index);

   /**
    * Permet d'obtenir  le caractere a l'index souhaite
    * @param index index du caractere a traiter
    * @return le caractere a l'index passe en parametre
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
    * Destructeur
    */
   ~String();

   String& operator+=(const String& rhs);
   String& operator+=(const char* rhs);

   String& operator=(const String& rhs);
   String& operator=(const char* rhs);

   bool operator==(const String& rhs);
   bool operator==(const char* rhs);

private:
   char* value;      // Valeur de la chaîne de caractères

   /**
    * Permet de généraliser l'initialisation de la classe String
    * @param value Valeur de la chaîne de caractères
    */
   void init(const char* value);
};

#endif
