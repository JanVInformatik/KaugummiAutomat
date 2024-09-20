public class Kau {
  double durchmesser;
  String farbe;

  Kau(double durchmesser, String farbe) {
    this.durchmesser = durchmesser;
    this.farbe = farbe;
  }

  Kau() {
  }

  public void whoami() {
    System.out.println("Mein Durchmesser ist: " + durchmesser);
    System.out.println("Meine Farbe ist: " + farbe);
  }
}
