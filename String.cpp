/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo2
 Fichier     : String.cpp
 Auteur(s)   : Gilliand Loris - Tutic Mateo
 Date        : 27.03.2019

 But         : Implémentation de la classe String

 Compilateur : MinGW-g++ 6.3.0 - Apple LLVM 9.1.0
 -----------------------------------------------------------------------------------
 */

#include "String.hpp"

#include <cstring>
#include <cstdlib>
#include <sstream>
#include <iostream>  // TODO : Déjà inclus dans String.hpp donc l'enlever d'ici non ? (TUM)

using namespace std;

/* CONSTRUCTEURS */
// Constructeur sans paramètres
String::String() {
   init("");
}

// Constructeur à partir d'une chaîne de caractère
String::String(const char* value) {
   init(value);
}

// Constructeur de copie
String::String(const String& s) {
   init(s.value);
}

// Constructeur à partir d'un caractère
String::String(char c) {
   // Convertir le caractère en chaîne de caractères
   char buffer[2];
   snprintf(buffer, 2, "%c", c); // buffer[0] = c et buffer[1] = '\0'
   init(buffer);
}

// Constructeur à partir d'un entier signé
String::String(int i) {
   // Compter le nombre de digit
   ostringstream sstream;
   sstream << i;
   init(sstream.str().c_str());
}

// Constructeur à partir d'un réel
String::String(double d) {
   ostringstream sstream;
   sstream << d;
   init(sstream.str().c_str());
}

// Constructeur à partir d'un booléen
String::String(bool b) {
   if (b) {
      init("true");
   } else {
      init("false");
   }
}

/* METHODES */
size_t String::getLength() const {
   return strlen(value);
}

const char* String::c_str() const {
   return value;
}

char& String::at(size_t index) {
   if(index >= strlen(value))
      throw out_of_range("access out of range");
   return value[index];
}

const char& String::at(size_t index) const {
   if(index >= strlen(value))
      throw out_of_range("access out of range");
   return value[index];
}

bool String::equals(const String& other) const {
   return equals(other.c_str());
}

bool String::equals(const char* other) const {
   return !(strcmp(value, other));
}

String& String::assign(const String& other) {
   assign(other.c_str());
   return *this;
}

String& String::assign(const char* other) {
   delete[] value;
   value = new char[strlen(other) + 1];
   strcpy(value, other);
   return *this;
}

String& String::append(const String& other) {
   append(other.c_str());
   return *this;
}

String& String::append(const char* other) {
   // sauve la valeur actuelle
   char* temp = new char[strlen(value) + 1];
   strcpy(temp, value);
   // supprime la zone allouee dynamiquement
   delete[] value;
   // reserve une nouvelle zone de la bonne taille
   value = new char[strlen(temp) + strlen(other) + 1];
   // copie l'ancienne chaine
   strcpy(value, temp);
   // ajoute a la fin de l'ancienne chaine l'autre chaine
   strcpy((value + strlen(temp)), other);
   // libere la zone temporaire
   delete[] temp;
   return *this;
}

/* OPERATORS */
String operator+(String lhs, const String& rhs) {
   lhs += rhs;
   return lhs;
}

String operator+(String lhs, const char* rhs) {
   lhs += rhs;
   return lhs;
}

String operator+(const char* lhs, const String& rhs) {
   String s(lhs);
   s += rhs;
   return s;
}

String& String::operator+=(const String& rhs) {
   return this->append(rhs);
}

String& String::operator+=(const char* rhs) {
   return this->append(rhs);
}

String& String::operator=(const String& rhs) {
   this->assign(rhs);
   return *this;
}

String& String::operator=(const char* rhs) {
   this->assign(rhs);
   return *this;
}

bool String::operator==(const String& rhs) {
   return this->equals(rhs);
}

bool String::operator==(const char* rhs) {
   return this->equals(rhs);
}

std::ostream& operator<<(std::ostream& os, const String& rhs) {
   os << rhs.value;
   return os;
}

std::istream& operator>>(std::istream& is, String& rhs) {
   delete[] rhs.value;
   rhs.value = new char[80];
   fgets(rhs.value, 80, stdin);
   return is;
}

/* DESTRUCTEUR */
String::~String() {
   delete[] value;
}

/* UTILS */
void String::init(const char* value) {
   if (value) {
      this->value = new char[strlen(value) + 1];
      strcpy(this->value, value);
   } else {
      this->value = new char[0];
   }
}

