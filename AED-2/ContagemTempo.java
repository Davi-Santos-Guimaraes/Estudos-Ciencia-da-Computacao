import java.util.Random;//Blibioteca para usar o Random
import java.util.Arrays;//Blibioteca para os arrays
public class ContagemTempo {

    static void InsertionSort(int[] vetor, int ini, int fim) {
        //Insertion sort
        for (int i = ini + 1; i <= fim; i++) {
            int aux = vetor[i];
            int j = i - 1;
            while (j >= ini && vetor[j] > aux) {
                vetor[j + 1] = vetor[j];
                j--;
            }
            vetor[j + 1] = aux;
        }
    }

    static void mergeAll(int[] arr, int numThreads, int parte) {
        int tamanho = parte;
        while (tamanho < arr.length) {
            for (int i = 0; i < arr.length; i += tamanho * 2) {
                int esq = i;
                int mid = Math.min(i + tamanho - 1, arr.length - 1);
                int dir = Math.min(i + tamanho * 2 - 1, arr.length - 1);
                if (mid < dir) merge(arr, esq, mid, dir);
            }
            tamanho *= 2;
        }
    }

    static void merge(int[] arr, int esq, int mid, int dir) {
        int[] L = Arrays.copyOfRange(arr, esq, mid + 1);
        int[] R = Arrays.copyOfRange(arr, mid + 1, dir + 1);

        int i = 0, j = 0, k = esq;
        while (i < L.length && j < R.length) {
            arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
        }
        while (i < L.length) arr[k++] = L[i++];
        while (j < R.length) arr[k++] = R[j++];
    }


    public static void main(String[] args) throws InterruptedException {
        //Numero de testes
        int[] tamanhos = {100_000, 500_000, 1_000_000};
        //Número de threads
        int numThread = 3;
        //seed para não permitir comparações aleatorias
        Random rand = new Random(42);
        //Percorrendo o vetor
        for (int tamanho : tamanhos) {
            int[] vetor = new int[tamanho];
            //Preencher com valores aleátorios(de 0 ao infinito e além)
            for (int i = 0; i < tamanho; i++) {
                vetor[i] = rand.nextInt(Integer.MAX_VALUE);
            }
            int[] vetorP = Arrays.copyOf(vetor, vetor.length);
            int[] vetorS = Arrays.copyOf(vetor, vetor.length);

//---------------------------------------------------------------------------------------//
            //Medição de tempo sequêncial
            long inicio = System.nanoTime();//Captura os nanosegundos antes da ordenação
            InsertionSort(vetorS, 0, vetorS.length - 1);//Ordena
            long fim = System.nanoTime();//Pega o tempo pós ordenação
            //Pega a diferença e converte para segundos
            double segundos = (fim - inicio) / 1_000_000_000.0;
            double segundosS = (fim - inicio) / 1_000_000_000.0;
            //saida de dadds
            System.out.printf("Sequencial | Tamanho: %,d | Tempo: %.4f segundos%n", tamanho, segundos);
//---------------------------------------------------------------------------------------//
            //Medição tempo com paralelização
            int parte = tamanho / numThread;//Reparto o vetor
            Thread[] threads = new Thread[numThread];
            long inicioP = System.nanoTime();//Captura os nanosegundos antes da ordenação
            for (int i = 0; i < numThread; i++) {
                final int ini = i * parte;//Onde ela começa
                final int fi;//Até onde ela vai
                if (i == numThread - 1) {//Caso não seja divido igualmente a ultima thread pega quem sobrou
                    fi = tamanho - 1;//Pegando quem sobrou
                } else {
                    fi = ini + parte - 1;//Até onde vai ?
                }
                threads[i] = new Thread(() -> InsertionSort(vetorP, ini, fi));//Chamando o Insertion
                threads[i].start();//Ativa a thread e agora ele vai executar idependente do fluxo do progama
            }
            for (int i = 0; i < threads.length; i++) {
                threads[i].join();//Tô pedindo para esperar as threads terminarem de trabalhar
            }
            mergeAll(vetorP,numThread,parte);
            //Fim da ordenação
            long fimP = System.nanoTime();
            //Pegando a diferença e convertendo para segundos
            double segundosP = (fimP - inicioP) / 1_000_000_000.0;
            System.out.printf("Paralelo   | Tamanho: %,d | Tempo: %.4f segundos%n", tamanho, segundosP);

            double speedup = segundosS / segundosP;
            System.out.printf("Speedup: %.2fx%n%n", speedup);
        }
    }
}



