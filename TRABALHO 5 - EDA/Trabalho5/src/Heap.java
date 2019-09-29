public class Heap {
	int valor;
	int peso;
	int s;
	
	Heap esq;
	Heap dir;
	
	public Heap(int valor, int peso) {
		this.valor = valor;
		this.peso = peso;
		this.s = 1;
		this.esq = null;
		this.dir = null;
	}
	
}
