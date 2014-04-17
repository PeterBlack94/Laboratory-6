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

Specyfikatory, które opcjonalnie mo¿emy umieœciæ przed nazw¹ klasy bazowej, wp³ywaj¹ na proces dziedziczenia, 
a dok³adniej na prawa dostêpu, na jakich klasa pochodna otrzymuje sk³adowe klasy bazowej.
Specyfikatory dziedziczenia s¹ identyczne z tymi wystêpuj¹cymi wewn¹trz bloku klasy.
O ile jednak tamte pojawiaj¹ siê w prawie ka¿dej sytuacji i klasie, o tyle tutaj specyfikator "public" ma niemal ca³kowity monopol,
a u¿ycie pozosta³ych dwóch nale¿y do niezmiernie rzadkich wyj¹tków.
W 99.9% przypadków nie ma najmniejszej potrzeby zmiany praw dostêpu do sk³adowych odziedziczonych po klasie bazowej.
Je¿eli wiêc któreœ z nich zosta³y tam zadeklarowane jako "protected", a inne jako "public", to prawie zawsze ¿yczymy sobie,
aby w klasie pochodnej zachowa³y te same prawa. Zastosowanie dziedziczenia "public" czyni zadoœæ tym ¿¹daniom,
dlatego w³aœnie jest ono tak czêsto stosowane. Dziedziczenie "protected" czyni wszystkie sk³adowe klasy bazowej chronionymi
w klasie pochodnej, zaœ "private" sprowadza je do dostêpu prywatnego.

Konstruktor klasy pochodnej wywo³uje konstruktor klasy bazowej, co powoduje zwiêkszenie wartoœci licznika
(licznik jest wspólny dla klasy bazowej oraz klas pochodnych).

Niemo¿liwe jest dokonianie przypisania za pomoc¹ operatora "=" bez jego przeci¹¿ania. Próbê takiego przypisania kompilator
traktuje jako b³¹d.

KOMENTARZE DO LAB 5

W przypadku destruktorów klas bazowych u¿ycie atrybutu "virtual" jest prawie zawsze konieczne.
Nieobecnoœæ wirtualnego destruktora w klasie bazowej mo¿e bowiem prowadziæ do tzw. wycieków pamiêci,
czyli bezpowrotnej utraty zaalokowanej pamiêci operacyjnej. Je¿eli wiêc destruktor nie bêdzie oznaczony jako "virtual",
to kompilator potraktuje go jako zwyczajn¹ metodê i zastosuje wobec niej technikê wczesnego wi¹zania. 
Doprowadzi to do wywo³ania wy³¹cznie destruktora klasy bazowej oraz wycieków pamiêci. 
Po zasstosowaniu atrybutu "virtual" operator "delete" bêdzie usuwa³ obiekt, na który faktycznie wskazuje podany mu wskaŸnik.

KOMENTARZE DO LAB 6
Stworzenie jakiegokolwiek obiektu z klas pochodnych nie bêdzie mo¿liwe, jeœli nie zostanie dla nich zdefiniowana metoda czysto wirtualna,
której prototyp znajduje siê w klasie bazowej. Stworzenie obiektu klasy abstrakcyjnej (posiadaj¹cej metodê czysto wirtualn¹) 
nigdy nie jest mo¿liwe.
Klasa abstrakcyjna, jako interfejs, nie zawiera zaimplementowanych metod. Jej zastosowanie zapewnia ujednolicenie kody, 
oraz poprawia jego czytelnoœæ. Klasa abstakcyjne u³atwia równie¿ korzystanie z metod klas (nie musimy pamiêtaæ nazwy ka¿dej metody).
Interfejs jest gwarantem funkcjonalnoœci, gwarancj¹ tego, ¿e klasa implementuj¹ca go bêdzie posiada³a okreœlone metody. 
Dlatego te¿ tylko publiczne deklaracje mog¹ wyst¹piæ w interfejsie. 
Pozosta³e nas w tym momencie nie interesuj¹, poniewa¿ s¹ zwi¹zane z implementacj¹.
*/