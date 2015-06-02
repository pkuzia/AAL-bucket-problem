Projekt AAL plik readme.txt

Przemysław Kuzia nr indeksu: 257344 ISI

Problem:
Danych jest n ponumerowanych kolejno pojemników. W pojemnikach znajdują się klocki w k kolorach, przy czym łączenie we wszystkich pojemnikach jest nie więcej niż n klocków danego koloru. Pojemnośc i-tego pojemnika wynosi pi klocków. Należy przełożyć klocki w taki sposób, żeby w każdym pojemniku pozostał co najwyżej jeden klocjek każdego koloru. W jednym ruchu można przełożyć jeden klocek z pojemnika, w którym się znajduje, do pudełka sąsiedniego (dozwolone jest przenoszenie pomiedzy pudełkiem pierwszym i n-tym. 

Program ma wbudowany interfejs konsolowy przez który użytkownik może testowac program.

Ograniczenia testowania:
Liczba kolorów < 100

Program zawiera 3 sposoby rozwiązania zadanego problemu:

	Metoda układania klocków iterująca po pojemnikach.

	Metoda układania klocków iterująca po kolorach a następnie po pojemnikach.

	Metoda zachłanna drzewa rozwiązań.

Program składa się z plików:

Pliki .h :

Block.h
Container.h
Creator.h
NaiveSolver.h
Node.h
Tree.h

Pliki .cpp :

Block.cpp
Container.cpp
Creator.h
NaiveSolver.cpp
Node.cpp
Tree.cpp
main.cpp

Dodatkowo program zawiera plik colors.txt zawierający baze 200 kolorów.

Struktury danych:
Program korzysta z dwóch struktur danych tj. map i vector.
