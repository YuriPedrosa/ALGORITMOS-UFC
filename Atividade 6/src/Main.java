import java.util.Scanner;

public class Main extends Lib{

	public static void main(String[] args) {
		int op = 1, valor;
		
		No arvore = null;
		
		do {
			op = menu();
			Scanner s = new Scanner(System.in);
			switch (op) {
			case 1:
				System.out.println("Informe um elemento:");
				valor = s.nextInt();
				arvore = inserir(arvore, valor);
				break;
			case 2:
				inOrdem(arvore);
				s.next();
				break;

			default:
				System.out.println("Opção Incorreta");
			}
		}while(op != 0);
	}

	private static int menu() {
		System.out.println("TRABALHO 6");
		System.out.println("1 - INSERIR ELEMENTO");
		System.out.println("2 - IMPRIMIR ARVORE");
		System.out.println("INFORME SUA OPÇÃO: \n");
		Scanner scn = new Scanner(System.in);
		int op = scn.nextInt();
		return op;
	}
}


