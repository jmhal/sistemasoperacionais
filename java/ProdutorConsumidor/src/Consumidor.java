
public class Consumidor implements Runnable {

	private Monitor monitor;
	public Consumidor(Monitor mon) {
		monitor = mon;
	}
	public void run() {
		int item;
		for (int i = 0; i < 10; i++) {
			item = monitor.remove();
			consume_item(item);
		}
	}
	private void consume_item(int item) {
		// Poderia fazer qualquer coisa com o valor...
		return;
	}
}
