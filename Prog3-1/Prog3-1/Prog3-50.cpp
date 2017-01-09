/*
class Polygon {

public:

	Polygon(Punkt* ecken);
	virtual double flaeche();
protected:

	Punkt* ecken;

};

class Dreieck : public Polygon {

public:

	Dreieck(Punkt* ecken);
	double flaeche();

protected:

	double grundseite;
	double hoehe;

};

Sind die folgenden Aussagen wahr oder falsch ? Begründen Sie kurz Ihre Antwort.

a) Ein Zeiger vom Typ Dreieck* kann auch auf ein Objekt der Klasse Polygon zeigen.
-- Nein. Polymorphismus funktioniertn nur von Polygon->Dreieck

b) Das Attribut grundseite ist Objekten der Klasse Polygon zugänglich.
-- falsche richtung

c) Jedes Objekt der Klasse Dreieck hat ein Attribut ecken.
-- Korrekt. Polymorphismus

d) Die Methode Polygon.flaeche() ist rein virtuell.
-- korrekt

e) Die Methode Dreieck.flaeche() ist automatisch auch virtuell.
-- ja, muss aber überschrieben werden
*/