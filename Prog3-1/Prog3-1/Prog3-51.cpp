class B
{
public:

	B(float _x) { d = _x; }
	float d;
};


class A : public B
{
public:

	A(int _k) { i = _k; }
	int i;
};


int main()
{

	A a(3);
	return 0;
}

// Nich typkonformer Konstruktor