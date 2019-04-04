# Feedback Labo2

## Factorisation : 3 méthodes

### Concat

* Réserver mémoire pour chaîne gauche + droite
* Remplir en copiant gauche et droite
* Retourner le résultat

### Append

* Réserver mémoire pour chaîne gauche + droite
* Remplir en copiant gauche et droite
* Mettre à jour gauche
* Retourner gauche

### Substr

* Réserver mémoire pour la sous-chaîne
* Remplir en copiant la partie concernée
* Retourner le résultat

**Peut être fait en une méthode d'initialisation :**

```c++
void String::initConcatCStrings(String& dest,
  const char* lhs, size_t lhsSize, const char* rhs, size_t rhsSize) {

  size_t size_ = lhsSize + rhsSize;
  char* cstring = new char[size + 1];

  if (lhs)
    memcpy(cstring, lhs, lhsSize);
  if(rhs)
    memcpy(cstring + lhsSize, rhs, rhsSize);

  cstring[size] = '\0';

  // Clean and init
  dest.memoryClean();
  dest._cstr = cstring;
  dest._size = size;
}
```
**Et pour les 3 méthodes :**

```c++
// append
initConcatCStrings(*this, _cstr, _size, other, strlen(other));

// concat
initConcatCStrings(result, _cstr, _size, other, strlen(other));

// substr
initConcatCStrings(result, _cstr + begin, end - begin, nullptr, 0);
```

Egalement utilisable pour les constructeurs, sur le principe de la méthode substr
