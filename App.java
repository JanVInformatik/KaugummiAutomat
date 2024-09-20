import java.util.Scanner;
import java.util.ArrayList;

public class App {
  public static void main(String[] args) {

    Scanner scanner = new Scanner(System.in);
    ArrayList<Kau> kaugummis = new ArrayList<>();

    while (true) {
      System.out.println("Willkommen zu unserem Kaugummi-Generator!");
      System.out.println("Welche Farbe soll der Kaugummi haben?");
      String farbe = scanner.nextLine();

      System.out.println("Wie groß soll der Kaugummi sein?");
      double durchmesser = scanner.nextDouble();

      scanner.nextLine();

      Kau kau = new Kau(durchmesser, farbe);
      kaugummis.add(kau);
      kau.whoami();

      System.out.println("Wollen Sie weitere Kaugummis hinzufuegen? (j/n)");
      String antwort = scanner.nextLine();

      if (antwort.equalsIgnoreCase("j")) {
        App.main(args);
      } else {
        System.out.println("Auf Wiedersehen!");
        scanner.close();
        break;
      }
      break;
    }
    Fenster test = new Fenster(kaugummis);

  }
}
