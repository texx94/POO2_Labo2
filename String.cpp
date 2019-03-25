#include "String.hpp"
#include <cstring>
#include <cstdlib>
#include <sstream>

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


/* UTILS */
void String::init(const char* value) {
   if (value) {
      this->length = strlen(value);
      this->value = new char[this->length + 1];
      strcpy(this->value, value);
   } else {
      this->length = 0;
      this->value = new char[0];
   }
}

/* DESTRUCTEUR */
String::~String() {
   
}
