/*
		1) const char* strChar(char * s, int c);
		Suchfunktion kann ver�ndern - aufrufer kann nur lesen nicht schreiben

		2) char* strChar(const char * s, int c);
		Zeiger konstant - wert dahinter ver�nderbar, �bergabe nicht �nderbar
		(sinnvollstes)

		3) char* strChar(char const *s, int c);
		Zeichenkette die hinter zeiger steht nicht ver�nderbar -- sinnlos
*/