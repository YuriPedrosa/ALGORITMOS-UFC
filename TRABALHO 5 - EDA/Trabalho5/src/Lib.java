public class Lib {
	
	static void trocaFilhos (Heap a) {
		Heap temp = a.esq;
		a.esq = a.dir;
		a.dir = temp;
	}
	
	static Heap uniao(Heap h1, Heap h2) {
		if (h1 == null) return h2; 

	    if (h2 == null) return h1;
	    
	    if(densidadeObjeto(h1) > densidadeObjeto(h2) || (densidadeObjeto(h1) == densidadeObjeto(h2) && h1.peso < h2.peso))
	    	return uniaoHeaps(h1, h2);
	    else
	    	return uniaoHeaps(h2, h1);
		
	}
	
	static int densidadeObjeto(Heap h) {
		return (h.valor/h.peso);
	}
	
	static Heap remover(Heap h) {
		if(h == null)
			System.out.println("Não há elementos");
		
		else {
			Heap aux = h;
			h = uniao(h.esq, h.dir);
			aux.dir = null;
			aux.esq = null;
		}
		
		return h;
	}
	
	
	static Heap preencherMochila(Mochila m, Heap h) {
		Heap novo;
		
		if(m.pesoAtual == 0 && h.peso > m.pesoMax) {
			System.out.println("Peso máximo da mochila é menor que o peso do primeiro elemento");
			return h;
		}
		
		while( (m.pesoAtual+h.peso) <= m.pesoMax) {
			novo = remover(h);
			m.pesoAtual += h.peso; 
			m.elementos = uniao(m.elementos, h);
			h = novo;
		}
		
		return h;
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
			System.out.print(h.valor + ":" + h.peso); 
			imprime(h.esq); 
			imprime(h.dir); 
		}
		System.out.print(">");
	}
}
