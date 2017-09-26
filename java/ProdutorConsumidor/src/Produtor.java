import java.util.Random;

public class Produtor implements Runnable {

	private Monitor monitor;
	public Produtor(Monitor mon) {
		monitor = mon;
	}
	public void run() {
		int item;
		for (int i = 0; i < 10; i++) {
			item = produce_item();
			monitor.insert(item);
		}
	}
	private int produce_item() {
		Random r = new Random();
		int item = r.nextInt(100);
		return item;
	}

}
