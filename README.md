# KaugummiAutomat

1. Installationshinweise

Auf dem Rechner sollte selbstverstaendlich Java installiert sein.
Folgende Befehle sind nacheinander auszufuehren, um das Projekt zu verwenden:

`javac App.java Fenster.java Kau.java`

`java App`

2. Entscheidungen beim Design

- App.java:
  scanner - um Input in der Befehlszeile zu lesen und parsen
  ArrayList - um dynamisch die Kaugummis zu speichern
  theoretisch unendliche Schleife (bis Anweisung erreicht wird) - Programmausfuehrung
  App.main(args) (Zeile 28) - um main Methode nochmals aufzurufen

- Kau.java:
  Implementierung des Kaugummis (Konstruktor erhaelt Farbe und Durchmesser; Der leere Konstruktor hat keinen wirklichen Zweck.)
  get Methoden zur Weiterverarbeitung in der Klasse App.java und Fenster.java
  whoami Methode zur Ausgabe der Attribute der einzelnen Objekte

- Fenster.java
  AWT: einfach, schnell und mit Code Snippet gemacht ;)
  Konstruktor mit wichtigen Inhalten (fuer AWT notwendig bzw. sinnvoll)
  paint Methode, die man ueberschreiben sollte (wird aufgerufen, wenn man ein neues Fenster erstellt und zeichnet dann den Inhalt (hier ist ein Kaugummi zu zeichnen))

- KEINE Vererbung
  Bei einem solch kleinem Projekt ist das kaum sinnvoll.
  Zudem: Polymorphismus, wo sinnvoll. Nicht, wo machbar oder moeglich.
