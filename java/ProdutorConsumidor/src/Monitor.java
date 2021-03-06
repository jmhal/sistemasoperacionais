
public class Monitor {
	private int N;
	private int buffer[];
	private int count = 0;
	private int nextRead = 0;
	private int nextWrite = 0;

	public Monitor(int size) {
		N = size;
		buffer = new int[N];
	}

	public synchronized void insert(int val) {
		if (count == N) {
			try {
				System.out.println("Produtor em espera.");
				wait();
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
		System.out.println("Produtor: Inserindo " + val);
		buffer[nextWrite] = val;
		nextWrite = (nextWrite + 1) % N;
		count = count + 1;
		if (count == 1) {
			notify();
		}
	}

	public synchronized int remove() {
		int val;
		if (count == 0) {
			try {
				System.out.println("Consumidor em espera.");
				wait();
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		val = buffer[nextRead];
		System.out.println("Consumidor: Consumindo " + val);
		nextRead = (nextRead + 1) % N;
		count = count - 1;
		if (count == N - 1) {
			notify();
		}
		return val;
	}
}
