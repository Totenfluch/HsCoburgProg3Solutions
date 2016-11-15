/*
		1) const char* strChar(char * s, int c);
		Suchfunktion kann verändern - aufrufer kann nur lesen nicht schreiben

		2) char* strChar(const char * s, int c);
		Zeiger konstant - wert dahinter veränderbar, übergabe nicht änderbar
		(sinnvollstes)

		3) char* strChar(char const *s, int c);
		Zeichenkette die hinter zeiger steht nicht veränderbar -- sinnlos
*/