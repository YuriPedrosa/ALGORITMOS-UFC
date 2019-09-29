import java.util.Scanner;

public class Main extends Lib{
	static Heap h = null;
	static Mochila m = null;
	
	public static void main(String[] args) {
		menu();
	}
	
	static void menu() {
		Heap novo;
		int op, peso, valor;
		Scanner scn = new Scanner(System.in);
		do {
			novo = null;
			System.out.println("\t\t MENU");
			System.out.println("1 - Indexar novo elemento ao conjunto\n"
					+ "2 - Resgatar elementos relevantes\n"
					+ "3 - Exibir conjunto de dados\n"
					+ "4 - Exibir elementos resgatados\n"
					+ "0 - Sair\n"
					+ "Escolha uma das opções: ");
			op = scn.nextInt();
			
			switch (op) {
			
			case 1:
				System.out.println("Valor do Objeto");
				valor = scn.nextInt();
				System.out.println("Peso do Objeto");
				peso = scn.nextInt();
				novo = new Heap(valor, peso);
				h = uniao(h, novo);
				break;
				
			case 2:
				System.out.println("Peso máximo da mochila: ");
				peso = scn.nextInt();
				m = new Mochila(peso);
				h = preencherMochila(m,h);
				break;
			
			case 3:
				System.out.println("Conjunto de dados \t\tOBS: Ao fim da exibição digitar um char para voltar ao menu");
				imprime(h);
				scn.next();
				break;
				
			case 4:
				System.out.println("Elementos resgatados \t\tOBS: Ao fim da exibição digitar um char para voltar ao menu");
				imprime(m.elementos);
				scn.next();
				break;
				
			case 0:
				System.out.println("Saindo...");
				break;
				
			default:
				break;
			}
		
		}while(op != 0);
		
		scn.close();
		
	}

}
