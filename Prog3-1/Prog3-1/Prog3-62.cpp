#include <iostream>
using namespace std;


int maxV(int a, int b);

class BitVec {

private:

	unsigned char* vec;    // Array mit 8*bytes Bits
	unsigned short bytes;  // Größe des Arrays

public:
	BitVec(unsigned short dim);
	BitVec(const BitVec& v);
	~BitVec();
	BitVec& BitVec::operator= (const BitVec& b);
	bool operator[] (unsigned short idx);   // Wert eines einzelnen Bits
	void set(unsigned short index);   // Setzen auf 1
	bool get(unsigned short index) const;   // Auslesen des Werts
	void reset(unsigned short index); // Setzen auf 0
	void print();                     // Ausgabe aller Bits als 0/1
	friend BitVec operator| (const BitVec& a, const BitVec& b);
	friend BitVec operator& (const BitVec& a, const BitVec& b);
	friend BitVec& operator&= (BitVec& a, const BitVec& b);
	friend BitVec& operator~ (BitVec& b);
};

BitVec::BitVec(unsigned short dim) : bytes(dim/8) {
	cout << dim << endl;
	vec = new unsigned char[bytes];
	for (int i = 0; i < bytes; i++)
		vec[i] = 0;
}

BitVec::BitVec(const BitVec& v) {
	bytes = v.bytes;
	vec = new unsigned char[bytes];
	for (int i = 0; i < bytes; i++)
		vec[i] = v.vec[i];
}

BitVec::~BitVec() {
	delete vec;
}

bool BitVec::operator[] (unsigned short idx) {
	return ((0x01 << idx - (idx/8) * 8) & *(vec + idx/8)) > 0x00;
}

void BitVec::set(unsigned short index) {
	*(vec + index/8) |= (0x01 << index - (index/8)*8);
}

void BitVec::reset(unsigned short index) {
	*(vec + index/8) &= ~(0x01 << index - (index/8)*8);
}

bool BitVec::get(unsigned short index) const {
	return (((0x01 << index - (index / 8) * 8) & *(vec + index / 8)) > 0x00);
}

void BitVec::print() {
	for (int i = 0; i < bytes * 8; i++)
		cout << (((0x01 << i - (i/8)*8) & *(vec + i/8)) > 0x00) << " ";
	cout << endl;
}

BitVec operator| (const BitVec& a, const BitVec& b) {
	BitVec bv = BitVec(maxV(a.bytes*8, b.bytes*8));
	for (int i = 0; i < bv.bytes*8; i++)
		if (a.get(i) || b.get(i))
			bv.set(i);

	return bv;
}

BitVec operator& (const BitVec& a, const BitVec& b) {
	BitVec bv = BitVec(maxV(a.bytes*8, b.bytes*8));
	for (int i = 0; i < bv.bytes*8; i++)
		if (a.get(i) && b.get(i))
			bv.set(i);
		else
			bv.reset(i);

	return bv;
}

BitVec& operator&= (BitVec& a, const BitVec& b) {
	for (int i = 0; i < a.bytes*8; i++)
		if (a.get(i) && b.get(i))
			a.set(i);
		else
			a.reset(i);
	return a;
}

BitVec& operator~ (BitVec& b) {
	for (int i = 0; i < b.bytes*8; i++)
		if (b.get(i))
			b.reset(i);
		else
			b.set(i);
	return b;
}

BitVec& BitVec::operator= (const BitVec& b) {
	if (this == &b)
		return *this;

	if (bytes != b.bytes) {
		if(vec)
			delete[] vec;

		bytes = b.bytes;
		vec = new unsigned char[bytes];

	}

	for (int i = 0; i < b.bytes; ++i) 
		vec[i] = b.vec[i];

	return *this;
}

int maxV(int a, int b) {
	if (a > b)
		return a;
	else return b;
}


int main()
{
	BitVec s(16);  BitVec t(16);  BitVec u(16);
	s.set(3); s.set(10); s.set(12);
	t.set(8); t.set(10); t.set(11);

	cout << "s =      "; s.print();
	cout << "t =      "; t.print();

	u = s | t; cout << "s | t =  "; u.print();
	u = s & t; cout << "s & t =  "; u.print();
	u = ~s;    cout << "~s =     "; u.print();
	u &= t;    cout << "~s & t = "; u.print();

	system("pause");
	return 0;
}