#include <iostream>
#include <iterator>

using namespace std;

template<class T>
class Predicate
{
public:
	virtual bool operator () (T x) = 0;
};

template <class T>
class Positive : public Predicate<T>
{
public:
	virtual bool operator () (T x)
	{
		return x > 0;
	}
};

template <class T>
class Negative : public Predicate<T>
{
public:
	virtual bool operator () (T x)
	{
		return x < 0;
	}
};

template <class T>
class Even : public Predicate<T>
{
public:
	virtual bool operator () (T x)
	{
		return x % 2 == 0;
	}
};

template <class T>
class Odd : public Predicate<T>
{
public:
	virtual bool operator () (T x)
	{
		return x % 2 != 0;
	}
};

template <class T>
T Min_Element(T* begin, T* end)
{
	T min = *begin;
	for (T* from = begin + 1; from < end; from++)
	{
		if (*from < min)
		{
			min = *from;
		}
	}
	return min;
}

template <class T>
T Min_Element_If(T* begin, T* end, Predicate<T>& p)
{
	T min = *begin;
	for (T* from = begin + 1; from < end; from++)
	{
		if (p(*from))
		{
			if (*from < min)
			{
				min = *from;
			}
		}
	}
	return min;
}

int main()
{
	int a[10] = { 3, -2, 0, 4, -5, -2, 3, 8, -2, -5 };

	cout << "a = { ";
	for (int i = 0; i < 10; i++)
		cout << a[i] << ' ';
	cout << "}" << endl;

	cout << "Min element: " << Min_Element(&a[0], &a[10]) << endl;

	Predicate<int>* neg = new Negative<int>();
	cout << "Min negative element: " << Min_Element_If(&a[0], &a[10], *neg) << endl;

	Predicate<int>* pos = new Positive<int>();
	cout << "Min positive element: " << Min_Element_If(&a[0], &a[10], *pos) << endl;

	Predicate<int>* odd = new Odd<int>();
	cout << "Min odd element: " << Min_Element_If(&a[0], &a[10], *odd) << endl;

	Predicate<int>* even = new Even<int>();
	cout << "Min even element: " << Min_Element_If(&a[0], &a[10], *even) << endl;

}