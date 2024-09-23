#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

// Kaugummi-Klasse, die den Durchmesser und die Farbe speichert
class Kau {
public:
  float durchmesser;
  sf::Color farbe;

  Kau(float d, sf::Color f) : durchmesser(d), farbe(f) {}
};

// Funktion zum Erstellen eines Kreises für den Kaugummi
sf::CircleShape createKaugummi(float durchmesser, sf::Color farbe, float x,
                               float y) {
  sf::CircleShape circle(durchmesser / 2); // Radius = Durchmesser / 2
  circle.setFillColor(farbe);
  circle.setPosition(x, y); // Setze Position des Kreises
  return circle;
}

int main() {
  // Erstelle ein Fenster
  sf::RenderWindow window(sf::VideoMode(800, 600), "Kaugummi-Shop");

  // Liste zum Speichern von Kaugummis
  std::vector<Kau> kaugummiListe;

  // Initialisiere Kaugummis
  kaugummiListe.push_back(Kau(50.f, sf::Color::Red));
  kaugummiListe.push_back(Kau(100.f, sf::Color::Blue));
  kaugummiListe.push_back(Kau(70.f, sf::Color::Yellow));
  kaugummiListe.push_back(Kau(90.f, sf::Color::Green));

  bool buttonPressed = false;                 // Zustand des Buttons
  Kau letzterKaugummi = kaugummiListe.back(); // Speichere den letzten Kaugummi

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }

      // Überprüfen, ob die linke Maustaste gedrückt wurde
      if (event.type == sf::Event::MouseButtonPressed &&
          event.mouseButton.button == sf::Mouse::Left) {
        // Simuliere einen Button-Klick im Bereich (700, 500) bis (780, 580)
        if (event.mouseButton.x >= 700 && event.mouseButton.x <= 780 &&
            event.mouseButton.y >= 500 && event.mouseButton.y <= 580) {
          // Füge einen neuen Kaugummi hinzu
          kaugummiListe.push_back(letzterKaugummi);
          buttonPressed = true;
        }
      }
    }

    // Fenster löschen (Hintergrund schwarz)
    window.clear(sf::Color::Black);

    // Position zum Zeichnen der Kreise
    float x = 50;
    float y = 50;

    // Zeichne alle Kaugummis
    for (const auto &kau : kaugummiListe) {
      sf::CircleShape kaugummi =
          createKaugummi(kau.durchmesser, kau.farbe, x, y);
      window.draw(kaugummi);

      // Verschiebe die Position für den nächsten Kaugummi
      x += kau.durchmesser + 20;
      if (x > window.getSize().x - kau.durchmesser) {
        x = 50;
        y += kau.durchmesser + 20;
      }
    }

    // Simulierter Button (ein Rechteck)
    sf::RectangleShape button(sf::Vector2f(80.f, 80.f));
    button.setFillColor(buttonPressed
                            ? sf::Color::Green
                            : sf::Color::White); // Farbe wechselt bei Klick
    button.setPosition(700.f, 500.f);
    window.draw(button);

    // Fensterinhalt anzeigen
    window.display();
  }

  return 0;
}
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

// Kaugummi-Klasse, die den Durchmesser und die Farbe speichert
class Kau {
public:
  float durchmesser;
  sf::Color farbe;

  Kau(float d, sf::Color f) : durchmesser(d), farbe(f) {}
};

// Funktion zum Erstellen eines Kreises für den Kaugummi
sf::CircleShape createKaugummi(float durchmesser, sf::Color farbe, float x,
                               float y) {
  sf::CircleShape circle(durchmesser / 2); // Radius = Durchmesser / 2
  circle.setFillColor(farbe);
  circle.setPosition(x, y); // Setze Position des Kreises
  return circle;
}

int main() {
  // Erstelle ein Fenster
  sf::RenderWindow window(sf::VideoMode(800, 600), "Kaugummi-Shop");

  // Liste zum Speichern von Kaugummis
  std::vector<Kau> kaugummiListe;

  // Initialisiere Kaugummis
  kaugummiListe.push_back(Kau(50.f, sf::Color::Red));
  kaugummiListe.push_back(Kau(100.f, sf::Color::Blue));
  kaugummiListe.push_back(Kau(70.f, sf::Color::Yellow));
  kaugummiListe.push_back(Kau(90.f, sf::Color::Green));

  bool buttonPressed = false;                 // Zustand des Buttons
  Kau letzterKaugummi = kaugummiListe.back(); // Speichere den letzten Kaugummi

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }

      // Überprüfen, ob die linke Maustaste gedrückt wurde
      if (event.type == sf::Event::MouseButtonPressed &&
          event.mouseButton.button == sf::Mouse::Left) {
        // Simuliere einen Button-Klick im Bereich (700, 500) bis (780, 580)
        if (event.mouseButton.x >= 700 && event.mouseButton.x <= 780 &&
            event.mouseButton.y >= 500 && event.mouseButton.y <= 580) {
          // Füge einen neuen Kaugummi hinzu
          kaugummiListe.push_back(letzterKaugummi);
          buttonPressed = true;
        }
      }
    }

    // Fenster löschen (Hintergrund schwarz)
    window.clear(sf::Color::Black);

    // Position zum Zeichnen der Kreise
    float x = 50;
    float y = 50;

    // Zeichne alle Kaugummis
    for (const auto &kau : kaugummiListe) {
      sf::CircleShape kaugummi =
          createKaugummi(kau.durchmesser, kau.farbe, x, y);
      window.draw(kaugummi);

      // Verschiebe die Position für den nächsten Kaugummi
      x += kau.durchmesser + 20;
      if (x > window.getSize().x - kau.durchmesser) {
        x = 50;
        y += kau.durchmesser + 20;
      }
    }

    // Simulierter Button (ein Rechteck)
    sf::RectangleShape button(sf::Vector2f(80.f, 80.f));
    button.setFillColor(buttonPressed
                            ? sf::Color::Green
                            : sf::Color::White); // Farbe wechselt bei Klick
    button.setPosition(700.f, 500.f);
    window.draw(button);

    // Fensterinhalt anzeigen
    window.display();
  }

  return 0;
}
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

// Kaugummi-Klasse, die den Durchmesser und die Farbe speichert
class Kau {
public:
  float durchmesser;
  sf::Color farbe;

  Kau(float d, sf::Color f) : durchmesser(d), farbe(f) {}
};

// Funktion zum Erstellen eines Kreises für den Kaugummi
sf::CircleShape createKaugummi(float durchmesser, sf::Color farbe, float x,
                               float y) {
  sf::CircleShape circle(durchmesser / 2); // Radius = Durchmesser / 2
  circle.setFillColor(farbe);
  circle.setPosition(x, y); // Setze Position des Kreises
  return circle;
}

int main() {
  // Erstelle ein Fenster
  sf::RenderWindow window(sf::VideoMode(800, 600), "Kaugummi-Shop");

  // Liste zum Speichern von Kaugummis
  std::vector<Kau> kaugummiListe;

  // Initialisiere Kaugummis
  kaugummiListe.push_back(Kau(50.f, sf::Color::Red));
  kaugummiListe.push_back(Kau(100.f, sf::Color::Blue));
  kaugummiListe.push_back(Kau(70.f, sf::Color::Yellow));
  kaugummiListe.push_back(Kau(90.f, sf::Color::Green));

  bool buttonPressed = false;                 // Zustand des Buttons
  Kau letzterKaugummi = kaugummiListe.back(); // Speichere den letzten Kaugummi

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }

      // Überprüfen, ob die linke Maustaste gedrückt wurde
      if (event.type == sf::Event::MouseButtonPressed &&
          event.mouseButton.button == sf::Mouse::Left) {
        // Simuliere einen Button-Klick im Bereich (700, 500) bis (780, 580)
        if (event.mouseButton.x >= 700 && event.mouseButton.x <= 780 &&
            event.mouseButton.y >= 500 && event.mouseButton.y <= 580) {
          // Füge einen neuen Kaugummi hinzu
          kaugummiListe.push_back(letzterKaugummi);
          buttonPressed = true;
        }
      }
    }

    // Fenster löschen (Hintergrund schwarz)
    window.clear(sf::Color::Black);

    // Position zum Zeichnen der Kreise
    float x = 50;
    float y = 50;

    // Zeichne alle Kaugummis
    for (const auto &kau : kaugummiListe) {
      sf::CircleShape kaugummi =
          createKaugummi(kau.durchmesser, kau.farbe, x, y);
      window.draw(kaugummi);

      // Verschiebe die Position für den nächsten Kaugummi
      x += kau.durchmesser + 20;
      if (x > window.getSize().x - kau.durchmesser) {
        x = 50;
        y += kau.durchmesser + 20;
      }
    }

    // Simulierter Button (ein Rechteck)
    sf::RectangleShape button(sf::Vector2f(80.f, 80.f));
    button.setFillColor(buttonPressed
                            ? sf::Color::Green
                            : sf::Color::White); // Farbe wechselt bei Klick
    button.setPosition(700.f, 500.f);
    window.draw(button);

    // Fensterinhalt anzeigen
    window.display();
  }

  return 0;
}
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

// Kaugummi-Klasse, die den Durchmesser und die Farbe speichert
class Kau {
public:
  float durchmesser;
  sf::Color farbe;

  Kau(float d, sf::Color f) : durchmesser(d), farbe(f) {}
};

// Funktion zum Erstellen eines Kreises für den Kaugummi
sf::CircleShape createKaugummi(float durchmesser, sf::Color farbe, float x,
                               float y) {
  sf::CircleShape circle(durchmesser / 2); // Radius = Durchmesser / 2
  circle.setFillColor(farbe);
  circle.setPosition(x, y); // Setze Position des Kreises
  return circle;
}

int main() {
  // Erstelle ein Fenster
  sf::RenderWindow window(sf::VideoMode(800, 600), "Kaugummi-Shop");

  // Liste zum Speichern von Kaugummis
  std::vector<Kau> kaugummiListe;

  // Initialisiere Kaugummis
  kaugummiListe.push_back(Kau(50.f, sf::Color::Red));
  kaugummiListe.push_back(Kau(100.f, sf::Color::Blue));
  kaugummiListe.push_back(Kau(70.f, sf::Color::Yellow));
  kaugummiListe.push_back(Kau(90.f, sf::Color::Green));

  bool buttonPressed = false;                 // Zustand des Buttons
  Kau letzterKaugummi = kaugummiListe.back(); // Speichere den letzten Kaugummi

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }

      // Überprüfen, ob die linke Maustaste gedrückt wurde
      if (event.type == sf::Event::MouseButtonPressed &&
          event.mouseButton.button == sf::Mouse::Left) {
        // Simuliere einen Button-Klick im Bereich (700, 500) bis (780, 580)
        if (event.mouseButton.x >= 700 && event.mouseButton.x <= 780 &&
            event.mouseButton.y >= 500 && event.mouseButton.y <= 580) {
          // Füge einen neuen Kaugummi hinzu
          kaugummiListe.push_back(letzterKaugummi);
          buttonPressed = true;
        }
      }
    }

    // Fenster löschen (Hintergrund schwarz)
    window.clear(sf::Color::Black);

    // Position zum Zeichnen der Kreise
    float x = 50;
    float y = 50;

    // Zeichne alle Kaugummis
    for (const auto &kau : kaugummiListe) {
      sf::CircleShape kaugummi =
          createKaugummi(kau.durchmesser, kau.farbe, x, y);
      window.draw(kaugummi);

      // Verschiebe die Position für den nächsten Kaugummi
      x += kau.durchmesser + 20;
      if (x > window.getSize().x - kau.durchmesser) {
        x = 50;
        y += kau.durchmesser + 20;
      }
    }

    // Simulierter Button (ein Rechteck)
    sf::RectangleShape button(sf::Vector2f(80.f, 80.f));
    button.setFillColor(buttonPressed
                            ? sf::Color::Green
                            : sf::Color::White); // Farbe wechselt bei Klick
    button.setPosition(700.f, 500.f);
    window.draw(button);

    // Fensterinhalt anzeigen
    window.display();
  }

  return 0;
}
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

// Kaugummi-Klasse, die den Durchmesser und die Farbe speichert
class Kau {
public:
  float durchmesser;
  sf::Color farbe;

  Kau(float d, sf::Color f) : durchmesser(d), farbe(f) {}
};

// Funktion zum Erstellen eines Kreises für den Kaugummi
sf::CircleShape createKaugummi(float durchmesser, sf::Color farbe, float x,
                               float y) {
  sf::CircleShape circle(durchmesser / 2); // Radius = Durchmesser / 2
  circle.setFillColor(farbe);
  circle.setPosition(x, y); // Setze Position des Kreises
  return circle;
}

int main() {
  // Erstelle ein Fenster
  sf::RenderWindow window(sf::VideoMode(800, 600), "Kaugummi-Shop");

  // Liste zum Speichern von Kaugummis
  std::vector<Kau> kaugummiListe;

  // Initialisiere Kaugummis
  kaugummiListe.push_back(Kau(50.f, sf::Color::Red));
  kaugummiListe.push_back(Kau(100.f, sf::Color::Blue));
  kaugummiListe.push_back(Kau(70.f, sf::Color::Yellow));
  kaugummiListe.push_back(Kau(90.f, sf::Color::Green));

  bool buttonPressed = false;                 // Zustand des Buttons
  Kau letzterKaugummi = kaugummiListe.back(); // Speichere den letzten Kaugummi

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }

      // Überprüfen, ob die linke Maustaste gedrückt wurde
      if (event.type == sf::Event::MouseButtonPressed &&
          event.mouseButton.button == sf::Mouse::Left) {
        // Simuliere einen Button-Klick im Bereich (700, 500) bis (780, 580)
        if (event.mouseButton.x >= 700 && event.mouseButton.x <= 780 &&
            event.mouseButton.y >= 500 && event.mouseButton.y <= 580) {
          // Füge einen neuen Kaugummi hinzu
          kaugummiListe.push_back(letzterKaugummi);
          buttonPressed = true;
        }
      }
    }

    // Fenster löschen (Hintergrund schwarz)
    window.clear(sf::Color::Black);

    // Position zum Zeichnen der Kreise
    float x = 50;
    float y = 50;

    // Zeichne alle Kaugummis
    for (const auto &kau : kaugummiListe) {
      sf::CircleShape kaugummi =
          createKaugummi(kau.durchmesser, kau.farbe, x, y);
      window.draw(kaugummi);

      // Verschiebe die Position für den nächsten Kaugummi
      x += kau.durchmesser + 20;
      if (x > window.getSize().x - kau.durchmesser) {
        x = 50;
        y += kau.durchmesser + 20;
      }
    }

    // Simulierter Button (ein Rechteck)
    sf::RectangleShape button(sf::Vector2f(80.f, 80.f));
    button.setFillColor(buttonPressed
                            ? sf::Color::Green
                            : sf::Color::White); // Farbe wechselt bei Klick
    button.setPosition(700.f, 500.f);
    window.draw(button);

    // Fensterinhalt anzeigen
    window.display();
  }

  return 0;
}
