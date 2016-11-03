#include <stdio.h>
#include <stdlib.h>
   
#ifdef WIN32 
  #define limpa_tela system("cls") 
  #define espera sleep(1) 
#else 
  #define limpa_tela system("/usr/bin/clear") 
  #define espera sleep(1) 
#endif
  
   
main(){
  //declaração de variáveis
  int nPos=0, nAux=0, i, nTrocas = 0;
   
  //Quantidade de casas do vetor
  while((nPos<=0)||(nPos>100)){
    printf("\nQuantos numeros tera o vetor? ");
    scanf("%d",&nPos);
  }
   
  //criando o vetor
  int nVetor[nPos], nOrig[nPos], nOpc=-1;
  int op;
  
  //estrutura de decisão para preenchimento do vetor
  printf("\nDeseja preencher o vetor manualmente? (1/0) ");
  scanf("%d",&op);

  
  if(op == 1) {
	  //preenchendo os dados do vetor
	  for(nAux = 0 ; nAux <= nPos-1 ; nAux++){
	    printf("\nInsira o numero %d: ",nAux+1);
	    scanf("%d",&nVetor[nAux]);
	    nOrig[nAux] = nVetor[nAux];
	  }
   }
   
  else{
	  //preenchendo o vetor com valores aleatorios
	  for(i = 0 ; i <= nPos-1 ; i++){
	  	nVetor[i] = rand() % 100;
	  	nOrig[i] = nVetor[i];
	  }
  }
   
  //Limpando a tela e pegando a opção
  limpa_tela;
  while((nOpc<=0) || (nOpc>=3)){
    printf("\n > Menu:");
    printf("\n  1. Shell Sort");
    printf("\n  2. Insertion Sort");
    printf("\n > Resposta: ");
    scanf("%d",&nOpc);
  }
  printf("\nOrdenando:\n");
   
  //Se for Shell Sort
  if(nOpc == 1){
    int nGap, nValAux, nProx, nAtual;
                
    //Definindo o gap
    while(nGap < (nPos-1)) {
      nGap = 3*nGap+1;
    }
    //Enquanto tiver o Gap
    while ( nGap > 1) {
      nGap /= 3;
      //Percorrendo as posições
      for(nAtual = nGap; nAtual < nPos; nAtual++) {
        //imprimindo os valores
        for(nAux=0;nAux<=nPos-1;nAux++){
          printf(" [%d] -",nVetor[nAux]);
          espera;
        }
              
        //definindo valor das próximas posições
        nValAux = nVetor[nAtual];
        nProx = nAtual - nGap;
          
        //Enquanto tiver próximo valor e ele seja menor que a próxima casa, faz inversão
        while (nProx >= 0 && nValAux < nVetor[nProx]) {
          nVetor[nProx + nGap] = nVetor[nProx];
          ++nTrocas;
          nProx -= nGap;
        }
        nVetor[nProx + nGap] = nValAux;
        printf("\n");
      }
    }
  }

	if(nOpc == 2){
		int i, j, atual;

			for (i = 1; i < nPos; i++){
				atual = nVetor[i];
				j = i - 1;

				while ((j >= 0) && (atual < nVetor[j])){
					nVetor[j + 1] = nVetor[j];
		            j = j - 1;
		            ++nTrocas;
				}
		    
				nVetor[j + 1] = atual;
			}
	}

   
   
  //Resultado - Vetor Original
  printf("\n > Original: ");
  for(nAux=0;nAux<=nPos-1;nAux++){
    printf("- [%d] -",nOrig[nAux]);
  }
   
  //Resultado - Vetor Ordenado
  printf("\n > Ordenada: ");
  for(nAux=0;nAux<=nPos-1;nAux++){
    printf("- [%d] -",nVetor[nAux]);
    espera;
  }
   printf("\n > Quantidade de trocas -  %d",nTrocas); 
   
  //limpando os dados e esperando o usuario apertar -Enter-
  getchar();
  printf("\n\nPressione -Enter- para finalizar!\n\n");
  getchar();
  limpa_tela;
}
