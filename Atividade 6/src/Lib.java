
public class Lib {
	
	static No inserir(No a, int elemento) {
		if(a==null)
			a = new No(elemento);
		else {
			if(buscar(a, elemento))
				return a;
			
			if(a.elemento > elemento) {
				a.esq = inserir(a.esq, elemento);
			}else {
				a.dir = inserir(a.dir, elemento);
			}
			a = balanceamento(a);			
		}
		return a;
	}
	
	static boolean buscar(No a,int valor) {
		if(a != null) {
			if(a.elemento < valor) {
				return buscar(a.dir, valor);
			}else if(a.elemento > valor) {
				return buscar(a.esq, valor);
			}else {
				return true;
			}
		}
		return false;
	}

	static No balanceamento(No a) {
		int fator = calcula_FB(a);
		if ( fator > 1)
			return balanceio_esquerda(a);
		else if (fator < -1 )
			return balanceio_direita(a);
		return a;
	}
	
	private static No balanceio_direita(No a) {
		 int fator = calcula_FB(a.dir);
		 if ( fator< 0 )
		 {
		   return rotacao_simples_esquerda(a);
		 }
		 else if (fator > 0 )
		 {
		   a.dir = rotacao_simples_direita(a.dir);
		   a = rotacao_simples_esquerda(a); 
		  return a;
		 }
		 else
			 return a;
	}

	private static No rotacao_simples_direita(No a) {
		No aux;
		aux = a.esq;
		a.esq = aux.dir;
		aux.dir = a;
		a = aux;
		return a;
	}

	private static No rotacao_simples_esquerda(No a) {
		No aux;
		aux = a.dir;
		a.dir = aux.esq;
		aux.esq = a;
		a = aux;
		return a;
	}

	private static No balanceio_esquerda(No a) {
		int fator = calcula_FB(a.esq);
		  if (fator > 0){
		    return rotacao_simples_direita(a);
		  }
		  else if (fator < 0)
		  {
		    a.esq = rotacao_simples_esquerda(a.esq);
		    a = rotacao_simples_direita(a); 
			return a;	
		  }
		  else
		  	return a;
	}

	private static int calcula_FB(No a) {
		return (altura_AVL(a.esq) - altura_AVL(a.dir));
	}

	private static int altura_AVL(No a) {
		int alt_esq, alt_dir;
	    if (a == null)
	        return 0;
	    else{
	        alt_esq = altura_AVL(a.esq);
	        alt_dir = altura_AVL(a.dir);
	        if (alt_esq > alt_dir)
	            return (1 + alt_esq);
	        else
	            return (1 + alt_dir);
	    }
	}

	static void imprime(No a){
	    if (a == null){
			return;
		}
	    System.out.println(a.elemento);
	 
	    if(a.esq != null)
	        System.out.println("(E:" + a.esq.elemento + ")");
	    if(a.dir != null)
	        System.out.println("(D:" + a.dir.elemento + ")");
	    System.out.println();
	 
	    imprime(a.esq);
	    imprime(a.dir);
	}
	
	static void inOrdem(No a) {
		if (a != null) {
	        inOrdem(a.esq);
	        System.out.println(a.elemento);
	        inOrdem(a.dir);
	    }
	}

}
