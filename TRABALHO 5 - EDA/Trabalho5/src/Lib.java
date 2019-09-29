
public class Lib {
	
	static void trocaFilhos (Heap a) {
		Heap temp = a.esq;
		a.esq = a.dir;
		a.dir = temp;
	}
	
	static Heap uniao(Heap h1, Heap h2) {
		if (h1 == null) return h2; 

	    if (h2 == null) return h1;
	    
	    if(h1.valor > h2.valor)
	    	return uniaoHeaps(h1, h2);
	    else
	    	return uniaoHeaps(h2, h1);
		
	}
	
	static Heap uniaoHeaps(Heap h1, Heap h2) {
		if(h1.esq == null)
			h1.esq = h2;
		else {
			h1.dir = uniao(h1.dir, h2);
			if(h1.esq.s < h1.dir.s)
				trocaFilhos(h1);
			h1.s = h1.dir.s +1;
		}
		return h1;
	}
	
	static void imprime(Heap h) {
		System.out.print("<");
		if (h != null){
			System.out.print(h.valor); 
			imprime(h.esq); 
			imprime(h.dir); 
		}
		System.out.print(">");
	}
}
