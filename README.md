fensterchen
===========

Framework for exercise 02.

Add your classes to the `framework/` directory and extend `source/tests.cpp`
with your test cases.

#Glossar
- **Klasse**n	stellen einen entscheidenden Bestandteil der Objektorientierten Programmierung dar. Sie sind in C++ die zentrale Datenstruktur, welche zusammengehörige Daten mit ihren zugehörigen Funktionen vereint.
- ** Objekt **	Instanz einer Klasse
- **Instanziierung **	stellt die Erzeugung eines konkreten Objekts einer Klasse dar. Hierzu wird der *Standardkonstruktor* der Klasse aufgerufen.
- **Instanz **	ist ein konkretes Exemplar mit konkreter Ausprägung. Auf diesem kann gearbeitet werden (Memberfunktionen aufrufen) bis es durch den Destruktor wieder zerstört wird (Lebenszeit).
- **Statische Objekterzeugung ** Zur Kompilierzeit erzeugtes Objekt.
- **Dynamische Objekterzeugung **	Zur Laufzeit erzeugtes Objekt (mittels z.B. `new).
- **Methode **	Unterprogramme (Funktionen) welche das Verhalten von Objekten implementieren.
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
- **Klassendeklaration **	Erfolgt in der Header-Datei. Es werden die in einer Klasse enthaltenen Elemente (Membervariablen und -Funktionen) festgelegt.
- **Initialisierungsliste / Memberinitialisiererliste class **	
- **struct **	ist eine Datenstruktur ähnlich einer Klasse, nur sehr viel einfacher. Sie bietet keine Privaten Memberfunktionen, sowie private Membervariablen. Eignet sich für einfache Datenstrukturen.
- **Datentransferobjekt ** (DTO)	bündelt mehrere einfache Datenstrukturen und Typen zu einem Objekt, welches leicht über einen einzigen Programmaufruf übertragen werden kann.
- **Statische Typisierung **	Datentyp einer Variable wird bereits zur Kompilierung festgelegt. Templates in C++ versuchen hier eine Möglichkeit zu bieten, *etwas dynamischer* zu werden.
- **Dynamische Typisierung **, der Datentyp ist erst zur Laufzeit bekannt und kann sich während dieser beliebig ändern. z.B. in Python.
- **Framework**, stellt eine gewisse Funktionalität bereit, über wohl definierte Schnittstellen. Der Programmierer kann dieses nutzen, ohne genau wissen zu müssen, wie die Implementierung erfolgt, es sind somit nur die Schnittstellen bekannt.
