/**
Die folgenden Definitionen seien gegeben:

int i;
unsigned int ui;
char cFeld[20];
int iFeld[20];
template<typename T> T f(T* t, int i) { /* .../ }
template<typename T> T f(T s, T t) { /* .../ }
char f(char* s, int i) { /* ... / }
double f(double x, double y) { /* ... / }
Welche Funktionen bzw.Varianten werden bei den folgenden Aufrufen ausgeführt, sofern der Aufruf kein Fehler ist ? Begründen Sie kurz Ihre Antwort.

f(cFeld, 20), -- char f(char* s, int i)
f(iFeld, 20), -- template<typename T> T f(T* t, int i)
f(iFeld[0], i), -- template<typename T> T f(T s, T t) 
f(i, ui), -- template<typename T> T f(T s, T t) 
f(iFeld, ui), -- template<typename T> T f(T* t, int i)
f(&i, i)  -- template<typename T> T f(T* t, int i)

**/