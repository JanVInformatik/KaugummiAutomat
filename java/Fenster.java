import java.awt.*;
import java.util.ArrayList;

class Fenster extends Frame {
  private ArrayList<Kau> kaugummiListe;

  Fenster(ArrayList<Kau> kaugummiListe) {
    this.kaugummiListe = kaugummiListe;
    setTitle("Kaugummi-Generator.");
    setSize(1280, 720);
    setVisible(true);
  }

  public void paint(Graphics g) {
    int x = 50;
    int y = 100;

    for (Kau k : kaugummiListe) {
      g.setColor(getColorFromString(k.getFarbe()));
      int radius = (int) k.getDurchmesser();
      g.fillOval(x, y, radius, radius);

      x += radius + 20;
      if (x > getWidth() - radius) {
        x = 50;
        y += radius + 20;
      }
    }
  }

  public Color getColorFromString(String farbe) {
    switch (farbe.toLowerCase()) {
      case "rot":
        return Color.RED;
      case "grün":
        return Color.GREEN;
      case "blau":
        return Color.BLUE;
      case "gelb":
        return Color.YELLOW;
      default:
        return Color.GRAY;
    }
  }
}
