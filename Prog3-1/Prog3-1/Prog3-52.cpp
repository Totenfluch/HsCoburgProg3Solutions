/*Gegeben sei folgende Deklaration


template<typename T, int n>
class Stapel
{
public:
	Stapel();
	T pop();
	void push(T);
	bool istLeer();
private:

	int hoehe;
	T speicher[n];
};


Stapel<int, 50> S1, S2;
Stapel<bool, 30> S3;
Stapel<int, 100> S4;


Sind die folgenden Anweisungen syntaktisch korrekt oder nicht ? Begründen Sie kurz Ihre Antwort.

a) S1.push(20.0);       -- funktioniert nicht da double
b) S2.push(S1.pop()); -- funktioniert
c) S3.push(S2.istLeer()); -- funktioniert
d) S4 = S1 + S2; -- fehlt + operator
e) S4.push(S1.hoehe); -- funktioniert


*/