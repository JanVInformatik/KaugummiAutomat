#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream> // For converting diameter input
#include <vector>

// Kaugummi-Klasse, die den Durchmesser und die Farbe speichert
class Kau {
public:
  float durchmesser;
  sf::Color farbe;

  Kau(float d, sf::Color f) : durchmesser(d), farbe(f) {}
};

// Funktion zum Erstellen eines Kreises für den Kaugummi
sf::CircleShape createKaugummi(const Kau &kau, float x, float y) {
  sf::CircleShape circle(kau.durchmesser / 2); // Radius = Durchmesser / 2
  circle.setFillColor(kau.farbe);
  circle.setPosition(x, y); // Setze Position des Kreises
  return circle;
}

int main() {
  // Schritt 1: Kaugummis in einem std::vector speichern
  std::vector<Kau> kaugummiListe;

  // Schritt 2: Erstelle das Fenster
  sf::RenderWindow window(sf::VideoMode(800, 600), "Kaugummi-Shop");

  // Farbauswahl (simulierte Buttons)
  std::vector<std::pair<sf::Color, sf::RectangleShape>>
      colorButtons; // Fix: Added space between '> >'
  sf::Color colors[] = {sf::Color::Red, sf::Color::Green, sf::Color::Blue,
                        sf::Color::Yellow};
  std::string colorNames[] = {"Red", "Green", "Blue", "Yellow"};

  for (int i = 0; i < 4; ++i) {
    sf::RectangleShape button(sf::Vector2f(50.f, 50.f));
    button.setFillColor(colors[i]);
    button.setPosition(100.f + i * 60, 500.f);
    colorButtons.push_back(
        std::make_pair(colors[i], button)); // Fix: Use std::make_pair
  }

  // Variablen zur Eingabe
  std::string diameterInput = "";
  bool isDiameterSet = false;
  bool isColorSet = false;
  sf::Color selectedColor;

  // Statusanzeige
  sf::Font font;
  if (!font.loadFromFile("arial.ttf")) {
    std::cout << "Fehler beim Laden der Schriftart." << std::endl;
    return -1;
  }

  sf::Text instructionText("Enter Diameter (press Enter):", font, 20);
  instructionText.setPosition(10, 10);
  sf::Text diameterText("", font, 20);
  diameterText.setPosition(10, 40);
  sf::Text colorText("Click a color button:", font, 20);
  colorText.setPosition(10, 70);

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }

      // Eingabe des Durchmessers über die Tastatur
      if (!isDiameterSet) {
        if (event.type == sf::Event::TextEntered) {
          if (std::isdigit(event.text.unicode)) {
            diameterInput += event.text.unicode;
            diameterText.setString(diameterInput);
          }
        }
        if (event.type == sf::Event::KeyPressed &&
            event.key.code == sf::Keyboard::Enter && !diameterInput.empty()) {
          isDiameterSet = true;
          instructionText.setString("Diameter set. Click a color button.");
        }
      }

      // Überprüfen, ob der Benutzer auf einen Farbauswahlknopf geklickt hat
      if (event.type == sf::Event::MouseButtonPressed &&
          event.mouseButton.button == sf::Mouse::Left) {
        for (auto &pair : colorButtons) {
          if (pair.second.getGlobalBounds().contains(event.mouseButton.x,
                                                     event.mouseButton.y)) {
            selectedColor = pair.first;
            isColorSet = true;
            colorText.setString("Color set: " +
                                colorNames[&pair - &colorButtons[0]]);
          }
        }
      }
    }

    // Wenn der Benutzer sowohl Farbe als auch Durchmesser gesetzt hat, füge
    // neuen Kaugummi hinzu
    if (isColorSet && isDiameterSet) {
      std::istringstream iss(diameterInput);
      float diameter;
      iss >> diameter;

      kaugummiListe.push_back(Kau(diameter, selectedColor));

      // Zurücksetzen für die nächste Eingabe
      isDiameterSet = false;
      isColorSet = false;
      diameterInput = "";
      diameterText.setString("");
      instructionText.setString("Enter Diameter (press Enter):");
      colorText.setString("Click a color button:");
    }

    // Fenster löschen (Hintergrund schwarz)
    window.clear(sf::Color::Black);

    // Schritt 3: Alle Kaugummis zeichnen
    float x = 50; // Startposition X
    float y =
        150; // Startposition Y (etwas höher, damit Platz für Buttons bleibt)

    for (const auto &kau : kaugummiListe) {
      sf::CircleShape kaugummi = createKaugummi(kau, x, y);
      window.draw(kaugummi);

      // Verschiebe die Position für den nächsten Kaugummi
      x += kau.durchmesser + 20; // Abstand zwischen den Kreisen
      if (x > window.getSize().x - kau.durchmesser) {
        x = 50;
        y +=
            kau.durchmesser +
            20; // Gehe eine Zeile nach unten, wenn die Breite überschritten ist
      }
    }

    // Zeichne die Farbauswahl-Buttons
    for (const auto &pair : colorButtons) {
      window.draw(pair.second);
    }

    // Zeichne die Anweisungen
    window.draw(instructionText);
    window.draw(diameterText);
    window.draw(colorText);

    // Fensterinhalt anzeigen
    window.display();
  }

  return 0;
}

