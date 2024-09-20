import java.util.Scanner;

public class App {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    System.out.println("Welchen Farbe soll der Kaugummi haben?");
    String farbe = scanner.nextLine();

    System.out.println("Wie groß soll der Kaugummi sein?");
    double durchmesser = scanner.nextDouble();

    Kau kau = new Kau(durchmesser, farbe);
    kau.whoami();
  }
}
