#Optimierung von Programmen Labor

###Requirements

Auf dem Rechner muss GCC installiert sein, auf Windows kann hier [Cygwin](https://www.cygwin.com/) verwendet werden.
Falls nicht bereits vorhanden, kann GCC auf Linux mit folgendem Befehl installiert werden.

    $ sudo apt-get install build-essential 
    
###Konfiguration
Bevor das Programm compiliert wird müssen einige Konstanten an die aktuelle Laufzeitumgebung angepasst werden.
Dafür müssen die Werte in in der Datei [Constants.h]((https://github.com/Aspern/optimierung-von-programmen-labor/blob/master/src/runtime/Constants.h))
überschrieben werden.

|Variable|Beschreibung|Default|
|---|----|----|
|`cache_line_size`|Größe einer Cache-Line in Byte. Bei den meisten x64 Architekturen ist die Cache-Line genau 64 Byte groß.|64|
|`max_cache_size`|Maximale Größe des gesamten Caches in Bytes. Falls die Hardware der Laufzeitumgebung mehr als 20 Megebyte hat, muss dieser Wert angepasst werden.|2621440|
|`quick_sort_cutt_off`|Anzahl Elemente die in einer Teilmenge des Quicksort-Algorithmus enthalten sein müssen, damit dieser ineffizient wrid. Der Wert ist je nach Architektur verschieden.|10|
|`min_array_size`|Startgröße des Arrays für die Zahlenwerte bei der Zeitmessung. Je nach Leistungsfähigkeit des Systems muss der Wert hoch oder runter geschraubt werden.|16384|
|`max_array_size`|Arraygröße, die auf dem System **nicht** mehr ausgeführt werden kann. Wenn diese Größe erreicht wird, bricht die Zeitmessung ab.|131072|

###Installieren
Das Programm zur Zeitmessung kann anschließend wie folgt installiert werden.

    $ git clone https://github.com/Aspern/optimierung-von-programmen-labor.git
    $ cd optimierung-von-programmen-labor
    $ cmake .
    $ make

Die Ausführungsdatei befindet sich nach einem erfolgreichen Build im `bin` Verzeichnis.

    $ bin>opl.exe
    
Die Ergebnisse werden in die Datei `results.txt` geschrieben.
    
###Tests

Die Tests für die Algorithmen müssen mit folgender Option gebaut werden.

    $ cmake . -DBUILD_TESTS=ON
    
Anschließend können die Tests ausgeführt werden.

    $ bin>runUnitTests.exe



