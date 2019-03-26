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

bool String::equals(const String &other) const {
   return equals(other.c_str());
}

bool String::equals(const char *other) const {
   return !(strcmp(value, other));
}

String& String::assign(const String &other) {
   assign(other.c_str());
   return *this;
}

String& String::assign(const char *other) {
   memcpy(value,other,strlen(other) + 1);
   return *this;
}

String& String::append(const String &other) {
   append(other.c_str());
   return *this;
}

String& String::append(const char *other) {
   strcat(value,other);
   return *this;
}

ostream& String::print(ostream& os) const {
   os << value;
}

istream& String::read(istream& is) const {
   is >> value;
}

/* OPERATORS */
String operator+(String lhs, const String &rhs) {
   lhs += rhs;
   return lhs;
}

String operator+(String lhs, const char *rhs) {
   lhs += rhs;
   return lhs;
}

String operator+(const char *lhs, const String &rhs) {
   String s(lhs);
   s += rhs;
   return s;
}

String& String::operator+=(const String &rhs) {
   return this->append(rhs);
}

String& String::operator+=(const char *rhs) {
   return this->append(rhs);
}

String& String::operator=(const String &rhs) {
   return this->assign(rhs);
}

String& String::operator=(const char *rhs) {
   return this->assign(rhs);
}

bool String::operator==(const String &rhs) {
   return this->equals(rhs);
}

bool String::operator==(const char *rhs) {
   return this->equals(rhs);
}

std::ostream& operator<<(std::ostream& os, const String &rhs) {
   return rhs.print(os);
}

std::istream& operator>>(std::istream& is, String &rhs) {
   return rhs.read(is);
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

