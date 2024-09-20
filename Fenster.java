import java.awt.*;

class Fenster {

  Fenster() {
    Frame f = new Frame();
    Label l = new Label("Produktsortiment...");
    Button b = new Button("Gib mir einen Kaugummi!");
    TextField t = new TextField();

    l.setBounds(20, 80, 80, 30);
    t.setBounds(20, 100, 80, 30);
    b.setBounds(100, 100, 80, 30);

    f.add(b);
    f.add(l);
    f.add(t);

    f.setSize(1280, 720);
    f.setTitle("Kaugummi Automat.");
    f.setLayout(null);
    f.setVisible(true);
  }
}
