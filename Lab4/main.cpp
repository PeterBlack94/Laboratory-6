// Lab4.cpp : Defines the entry point for the console application.
//
//SETTERY I GETTERY
#include "stdafx.h"
#include "Human.h"
#include "Student.h"
#include "Student2.h"
#include "Tutor.h"
#include <cstdlib>

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Creating object student1" << endl;
	Student student1;
	cout << Student::count() << " objects created." << endl;
	cin >> student1;
	cout << student1;

	cout << "Creating object student2" << endl;
	Student2 student2;
	cout << Student2::count() << " objects created." << endl;

	cout<<"Creating object tutor1..."<<endl;
	Tutor tutor1;
	cout << Tutor::count() << " objects created." << endl;

	system("PAUSE");
}

/* 
KOMENTARZE DO LAB 4

Specyfikatory, kt�re opcjonalnie mo�emy umie�ci� przed nazw� klasy bazowej, wp�ywaj� na proces dziedziczenia, 
a dok�adniej na prawa dost�pu, na jakich klasa pochodna otrzymuje sk�adowe klasy bazowej.
Specyfikatory dziedziczenia s� identyczne z tymi wyst�puj�cymi wewn�trz bloku klasy.
O ile jednak tamte pojawiaj� si� w prawie ka�dej sytuacji i klasie, o tyle tutaj specyfikator "public" ma niemal ca�kowity monopol,
a u�ycie pozosta�ych dw�ch nale�y do niezmiernie rzadkich wyj�tk�w.
W 99.9% przypadk�w nie ma najmniejszej potrzeby zmiany praw dost�pu do sk�adowych odziedziczonych po klasie bazowej.
Je�eli wi�c kt�re� z nich zosta�y tam zadeklarowane jako "protected", a inne jako "public", to prawie zawsze �yczymy sobie,
aby w klasie pochodnej zachowa�y te same prawa. Zastosowanie dziedziczenia "public" czyni zado�� tym ��daniom,
dlatego w�a�nie jest ono tak cz�sto stosowane. Dziedziczenie "protected" czyni wszystkie sk�adowe klasy bazowej chronionymi
w klasie pochodnej, za� "private" sprowadza je do dost�pu prywatnego.

Konstruktor klasy pochodnej wywo�uje konstruktor klasy bazowej, co powoduje zwi�kszenie warto�ci licznika
(licznik jest wsp�lny dla klasy bazowej oraz klas pochodnych).

Niemo�liwe jest dokonianie przypisania za pomoc� operatora "=" bez jego przeci��ania. Pr�b� takiego przypisania kompilator
traktuje jako b��d.

KOMENTARZE DO LAB 5

W przypadku destruktor�w klas bazowych u�ycie atrybutu "virtual" jest prawie zawsze konieczne.
Nieobecno�� wirtualnego destruktora w klasie bazowej mo�e bowiem prowadzi� do tzw. wyciek�w pami�ci,
czyli bezpowrotnej utraty zaalokowanej pami�ci operacyjnej. Je�eli wi�c destruktor nie b�dzie oznaczony jako "virtual",
to kompilator potraktuje go jako zwyczajn� metod� i zastosuje wobec niej technik� wczesnego wi�zania. 
Doprowadzi to do wywo�ania wy��cznie destruktora klasy bazowej oraz wyciek�w pami�ci. 
Po zasstosowaniu atrybutu "virtual" operator "delete" b�dzie usuwa� obiekt, na kt�ry faktycznie wskazuje podany mu wska�nik.

KOMENTARZE DO LAB 6
Stworzenie jakiegokolwiek obiektu z klas pochodnych nie b�dzie mo�liwe, je�li nie zostanie dla nich zdefiniowana metoda czysto wirtualna,
kt�rej prototyp znajduje si� w klasie bazowej. Stworzenie obiektu klasy abstrakcyjnej (posiadaj�cej metod� czysto wirtualn�) 
nigdy nie jest mo�liwe.
Klasa abstrakcyjna, jako interfejs, nie zawiera zaimplementowanych metod. Jej zastosowanie zapewnia ujednolicenie kody, 
oraz poprawia jego czytelno��. Klasa abstakcyjne u�atwia r�wnie� korzystanie z metod klas (nie musimy pami�ta� nazwy ka�dej metody).
Interfejs jest gwarantem funkcjonalno�ci, gwarancj� tego, �e klasa implementuj�ca go b�dzie posiada�a okre�lone metody. 
Dlatego te� tylko publiczne deklaracje mog� wyst�pi� w interfejsie. 
Pozosta�e nas w tym momencie nie interesuj�, poniewa� s� zwi�zane z implementacj�.
*/