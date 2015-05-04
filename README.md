fensterchen
===========
In diesem Projekt werden einfache Klassen implementiert (noch ohne Vererbung). Es lassen sich in einem Fenster einfache Geometrische Formen zeichen. Kreise und Rechtecke als Konturen mit unterschiedlichen Farben. Ebenso sind bereits Punkte und Linien möglich. 
Kreise bieten des weiteren die Möglichkeit gefüllt zu sein. 

Nach dem Kompilieren dieses Projekts stehen im entsprechenden Build Ordner zwei ausführbare Dateien zur Verfügung. Entscheidend ist die 
`./build/Release/Debug/example`, welche das Fensterchen startet. Die Tests werden direkt bei der Erstellung mittels make ausgeführt.

**Projekt in Xcode importieren** und ggf im Terminal bauen:
```
mkdir xcode
cd xcode
cmake -G "Xcode" ..

xcodebuild -list
xcodebuild
```
es wäre auch normal das Kompilieren mittel `cmake ..` und anschließendem `make` möglich.

#Überladung
Unter gleichem Bezeichner lassen sich unterschiedliche Methoden aufrufen, diese werden unterscheidbar durch ihre Signaturen überladen. So ist es z.B. möglich Getter und Setter Methoden unter gleichem Namen anzubieten (siehe Glossar, Beispiel). Ebenso bietet C++ die Möglichkeit Operatoren zu überladen. Häufige Verwendung bei Vergleichsoperatoren oder dem Streamoperator. 

#Includeguardes 
```
#ifndef BUW_POINT2D_HPP 
#define BUW_POINT2D_HPP
// Point2d class declaration 
#endif // BUW_POINT2D_HPP
```
Gehören zu den Präprozessoranweisungen. Sie dienen der bedingten Kompilierung und sind Textersetzungswerkzeuge. Oben beschriebene verhindern die Mehrfachinkludierung der Headerdatei. Würde die Header Datei in einer anderen eingebunden werden, dann wäre der Bezeichner bereits definiert und die entsprechenden Textstellen müssen nicht erneut eingefügt werden. Würden sie eingefügt werden, würde der Kompiler Fehler ausgeben, da eine Mehrfache Deklaration des gleichen Bezeichners und gleicher Signatur nicht möglich ist.

#Glossar
- **Klasse**n	stellen einen entscheidenden Bestandteil der Objektorientierten Programmierung dar. Sie sind in C++ die zentrale Strukturen, welche zusammengehörige Daten mit ihren zugehörigen Funktionen vereint. Sie können von anderen Klassen abgeleitet werden.
- ** Objekt **	Instanz einer Klasse
- **Instanziierung **	stellt die Erzeugung eines konkreten Objekts einer Klasse dar. Hierzu wird der *Standardkonstruktor* der Klasse aufgerufen.
- **Instanz **	ist ein konkretes Exemplar mit konkreter Ausprägung. Auf diesem kann gearbeitet werden (Memberfunktionen aufrufen) bis es durch den Destruktor wieder zerstört wird (Lebenszeit).
- **Statische Objekterzeugung ** Zur Kompilierzeit erzeugtes Objekt.
- **Dynamische Objekterzeugung **	Zur Laufzeit erzeugtes Objekt (mittels z.B. `new`).
- **Methode **	Unterprogramme (Funktionen) welche das Verhalten von Objekten implementieren und auf diese als Teil der Klasse aufgerufen werden.
- **Getter **	Methode zum Auslesen eines Wertes. `int radius() const;`
- **Setter **	Methode zum Setzen eines Wertes. `void radius(int value);`
- **Kapselung **	*information hiding* verbigt Daten und Informationen vor dem Zugriff von außen, es werden nur definierte Schnittstellen zum Zugriff auf diese angeboten (Black-Box). Somit können sich interne Strukturen ändern, ohne dass sich der Zugriff auf das Objekt verändert.
- **public **	stellt die öffentliche Schnittstelle eines Objektes dar.
- **private **	hier sind die nicht von außen ausführbaren Methoden, sowie die Daten des Objektes abgelegt. Es ist nicht von außen einseh- und veränderbar. Es müssen öffentliche Methoden aufgerufen werden.
- **C++ Präprozessor **	Vor der Übersetzung des Quelltextes übernimmt der Präprozessor einige Verarbeitungen. Es werden die Präprozessor Diriktiven verarbeitet. `#include #define #ifdef #pragma ...` Somit werden im Header z.B. Dateiinhalte eingefügt. Der Präprozessor versteht nur seine eigenen Diriktiven und kein C-Code. (Textersetzerwerkzeug) Das Ergebnis wird an den Compiler übergeben, wobei in heutigen Compilern die Anweisungen mit berücksichtig werden.
- **Konstruktor **	Objekte werden in einem definierten Anfangszustand gebracht und Ressourcen reserviert.
- **Standardkonstruktor **	wenn kein Default Konstruktor explizit angegeben wurde wird automatisch ein Konstuktor zum erstellen des Objektes angeboten.
- **Default-Konstruktor **	== Standardkonstruktor? Er dient der Initialen Belegung der Membervariablen, möglichst mit für das Objekt sinnvollen Standard Werten, mittels der Initialisierungsliste.
- **Destruktor **	Wird aufgerufen, wenn das Objekt zerstört wird (immer wenn der Gültigkeitsbereich des Objektes endet). Es können noch letzte Aktionen mit dem Objekt ausgeführt werden, Ressourcen freigeben.
- **Membervariablen **	stellen die internen Daten eines Objektes dar. Können über ihren Namen zugegriffen werden, es sei denn sie sind als Public deklariert.
- **Klassendeklaration **	führt einen Bezeichner als Klasse ein. z.B. mittels Forwarddeklaration `class Name;` 
- **Initialisierungsliste / Memberinitialisiererliste class**, bietet Konstruktoren die Möglichkeite direkt mit einem Wert zu initialsieren. Ohne Initialisierungsliste, müsste die Membervarbiable angelegt werden, intern mit einem initialen Wert automatisch belegt werden und dann der neue Wert über den Skope des Konstruktors neu zugewiesen werden. Mittels Initialisierungsliste lässt sich direkt ein Wert initial zuweisen.
- **struct **	ist eine einfache Datenstruktur ähnlich einer Klasse. Standartmäßig ist das Interface Public. Eignet sich für Datentransferobjekte.
- **Datentransferobjekt ** (DTO)	bündelt mehrere einfache Datenstrukturen und Typen zu einem Objekt, welches leicht über einen einzigen Programmaufruf übertragen werden kann.
- **Statische Typisierung **	Datentyp einer Variable wird bereits zur Kompilierung festgelegt. Templates in C++ versuchen hier eine Möglichkeit zu bieten, *etwas dynamischer* zu werden.
- **Dynamische Typisierung **, der Datentyp ist erst zur Laufzeit bekannt und kann sich während dieser beliebig ändern. z.B. in Python haben die Werte ihre Typen, nicht die Variable.
- **Framework**, stellt eine gewisse Funktionalität bereit, über wohl definierte Schnittstellen. Der Programmierer kann dieses nutzen, ohne genau wissen zu müssen, wie die Implementierung erfolgt, es sind somit nur die Schnittstellen bekannt.
