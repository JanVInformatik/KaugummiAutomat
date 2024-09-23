#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Kau {
public:
  float durchmesser;
  sf::Color farbe;

  Kau(float d, sf::Color f) : durchmesser(d), farbe(f) {}
};

sf::CircleShape createKaugummi(const Kau &kau, float x, float y) {
  sf::CircleShape circle(kau.durchmesser / 2); // Radius = Durchmesser / 2
  circle.setFillColor(kau.farbe);
  circle.setPosition(x, y); // Setze Position des Kreises
  return circle;
}

int main() {
  std::vector<Kau> kaugummiListe;

  kaugummiListe.push_back(Kau(50.f, sf::Color::Red));
  kaugummiListe.push_back(Kau(100.f, sf::Color::Blue));
  kaugummiListe.push_back(Kau(70.f, sf::Color::Yellow));
  kaugummiListe.push_back(Kau(90.f, sf::Color::Green));

  sf::RenderWindow window(sf::VideoMode(800, 600), "Kaugummi-Shop");

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    window.clear(sf::Color::Black);

    float x = 50; // Startposition X
    float y = 50; // Startposition Y

    for (const auto &kau : kaugummiListe) {
      sf::CircleShape kaugummi = createKaugummi(kau, x, y);
      window.draw(kaugummi);

      x += kau.durchmesser + 20; // Abstand zwischen den Kreisen
      if (x > window.getSize().x - kau.durchmesser) {
        x = 50;
        y +=
            kau.durchmesser +
            20; // Gehe eine Zeile nach unten, wenn die Breite überschritten ist
      }
    }
    window.display();
  }
  return 0;
}
