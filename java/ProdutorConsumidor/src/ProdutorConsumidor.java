
public class ProdutorConsumidor {

	public static void main(String[] args) {
		Monitor m = new Monitor(5);
		
		Thread produtor = new Thread(new Produtor(m));
		Thread consumidor = new Thread(new Consumidor(m));
		
		produtor.start();
		consumidor.start();
		
		return;
	}
}
