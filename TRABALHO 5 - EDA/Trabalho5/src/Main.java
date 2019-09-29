import java.util.Scanner;

public class Main extends Lib{

	public static void main(String[] args) {
		Heap h = null, novo;
		Scanner scn = new Scanner(System.in);
		int a = scn.nextInt();
		novo = new Heap(a, 2);
		h = uniao(h, novo);

		imprime(h);
		scn.close();
	}

}
