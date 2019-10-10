
public class No {

	int elemento;
	int fator_b;
	No dir;
	No esq;
	
	
	
	public No(int elemento) {
		this.elemento = elemento;
		this.dir = null;
		this.esq = null;
	}
	public int getElemento() {
		return elemento;
	}
	public void setElemento(int elemento) {
		this.elemento = elemento;
	}
	public int getFator_b() {
		return fator_b;
	}
	public void setFator_b(int fator_b) {
		this.fator_b = fator_b;
	}
	public No getDir() {
		return dir;
	}
	public void setDir(No dir) {
		this.dir = dir;
	}
	public No getEsq() {
		return esq;
	}
	public void setEsq(No esq) {
		this.esq = esq;
	}
}