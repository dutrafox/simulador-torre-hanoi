#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {     
    int disco;     
    struct elemento *seguinte;     
}ELEMENTO;

typedef struct pilha{
    ELEMENTO *inicio;
    int tamanho;      
}PILHA;  

//Protótipos de Funções
void inicializaPilha(PILHA *p);
int empilhar(PILHA *p, int i);
int desempilhar(PILHA *p);
int tamanhoPilha(PILHA *p);
int retornaTopo(PILHA *p);
void imprimir(PILHA *p);
void imprimirMenu();

int main(void){
	PILHA p1, p2, p3;
	inicializaPilha(&p1);
	inicializaPilha(&p2);
	inicializaPilha(&p3);
	
	int opcao=1;
	while(opcao != 0){
		imprimirMenu();
		printf("Informe a opção: ");
		scanf("%d", &opcao);
		if(opcao >= 0 && opcao <= 6){
			switch(opcao){
				case 0:
					return 0;
				case 1:{
					int disco=0, p=0, ok=0;
					printf("Em qual torre deseja adicionar: ");
					scanf("%d", &p);
					printf("Informe o número do disco: ");
					scanf("%d", &disco);
					if(p==1){
						ok = empilhar(&p1, disco);
					}else if(p==2){
						ok = empilhar(&p2, disco);
					}else if(p==3){
						ok = empilhar(&p3, disco);
					}else printf("Torre inválida\n");
					if(ok==0){
						printf("Empilhado com sucesso!\n"); 
					}else if(ok==-1){
						printf("Você não pode colocar um disco maior em cima de um menor!\n");
					}else{
						printf("Falha ao empilhar!\n");
					}
					break;}
				case 2:{
					int p=0, ok=0;
					printf("De qual torre deseja remover: ");
					scanf("%d", &p);
					if(p==1){
						ok = desempilhar(&p1);
					}else if(p==2){
						ok = desempilhar(&p2);
					}else if(p==3){
						ok = desempilhar(&p3);
					}else printf("Torre inválida\n");
					if(ok == 0) printf("Desempilhado com sucesso!\n"); else printf("Falha ao desempilhar!\n");
					break;}
				case 3:{
					int p = 0, tamanho = 0;
					printf("De qual torre deseja saber o tamanho: ");
					scanf("%d", &p);
					if(p==1){
						tamanho = tamanhoPilha(&p1);
						printf("O tamanho da torre %d é %d\n", p, tamanho);
					}else if(p==2){
						tamanho = tamanhoPilha(&p1);
						printf("O tamanho da torre %d é %d\n", p, tamanho);
					}else if(p==3){
						tamanho = tamanhoPilha(&p1);
						printf("O tamanho da torre %d é %d\n", p, tamanho);
					}else printf("Torre inválida\n");
					break;}
				case 4:{
					int p = 0, topo = 0;
					printf("De qual torre deseja saber o disco do topo: ");
					scanf("%d", &p);
					if(p==1){
						topo = retornaTopo(&p1);
					}else if(p==2){
						topo = retornaTopo(&p2);
					}else if(p==3){
						topo = retornaTopo(&p3);
					}else printf("Torre inválida\n");
					if(topo == -1){
						printf("Torre vazia\n");
					}else	printf("O disco do topo da torre %d é o disco %d\n", p, topo);
					break;}
				case 5:{
					int p = 0;
					printf("De qual torre deseja imprimir: ");
					scanf("%d", &p);
					if(p==1){
						imprimir(&p1);
					}else if(p==2){
						imprimir(&p2);
					}else if(p==3){
						imprimir(&p3);
					}else printf("Torre inválida");
					break;}
				case 6:{
					int pd = 0, pp = 0, ok=1;
					printf("De qual torre deseja mover: ");
					scanf("%d", &pd);
					printf("Para qual torre deseja mover: ");
					scanf("%d", &pp);
					if(pd==1){
						if(pp == 2){
							ok = moverElemento(&p1, &p2);
						}else if(pp == 3){
							ok = moverElemento(&p1, &p3);
						}else{
							printf("Movimento Inválido!\n");
						}	
					}else if(pd==2){
						if(pp == 1){
							ok = moverElemento(&p2, &p1);
						}else if(pp == 3){
							ok = moverElemento(&p2, &p3);
						}else{
							printf("Movimento Inválido!\n");
						}
					}else if(pd==3){
						if(pp == 2){
							ok = moverElemento(&p3, &p2);
						}else if(pp == 1){
							ok = moverElemento(&p3, &p1);
						}else{
							printf("Movimento Inválido!\n");
						}
					}else printf("Movimento Inválido!\n");
					if(ok==0){
						printf("Movido com sucesso!\n");
					}else if(ok==-1){
						printf("Você não pode colocar um disco maior em cima de um menor!\n");
					}else if(ok==-2){
						printf("A torre origem não pode ser vaiza!\n");
					}
					break;}
			}
		}else{
			printf("Opção Inválida\n");
		}
	}
	return 0;
}

// Função inicializaPilha
void inicializaPilha(PILHA *p){
     p->inicio = NULL;
     p->tamanho = 0;
}

// Função empilhar
int empilhar(PILHA *p, int i){
	if(p->inicio != NULL && i >= p->inicio->disco){
		return -1;
	}
	  ELEMENTO *novoElemento;     
	  if ((novoElemento = (ELEMENTO *) malloc (sizeof (ELEMENTO))) == NULL)     
	    return -2;     
	  if ((novoElemento->disco = (int *) malloc ( sizeof (int))) == NULL)     
	    return -2;     
	  novoElemento->disco = i;     
	  novoElemento->seguinte = p->inicio;     
	  p->inicio = novoElemento;     
	  p->tamanho = p->tamanho+1;
	  return 0;    
}
      
// Função desempilhar
int desempilhar(PILHA *p){     
  ELEMENTO *removeElemento;     
  if (p->tamanho == 0)     
    return -1;     
  removeElemento = p->inicio;     
  p->inicio = p->inicio->seguinte;     
  //free(removeElemento->disco);     
  //free(removeElemento);     
  p->tamanho--;     
  return 0;     
}      
                                                                                                                                                                   
//Função tamanhoPilha
int tamanhoPilha(PILHA *p){
	return p->tamanho;
}

//Função retornaTopo
int retornaTopo(PILHA *p){
	if(p->tamanho > 0){
		return p->inicio->disco;
	}
	return -1;
}
 
// Função imprimir
void imprimir(PILHA *p){     
  ELEMENTO *atual;     
  int i;     
  atual = p->inicio;     

  for(i=0;i<p->tamanho;i++){     
    printf("\t\t%d\n", atual->disco);     
    atual = atual->seguinte;     
  }     
}  

//Função moverElemento
int moverElemento(PILHA *p1, PILHA *p2){
	if(p1->inicio == NULL){
		return -2;
	}else{
		if(p2->inicio == NULL || p2->inicio->disco >= p1->inicio->disco){
			empilhar(p2, p1->inicio->disco);
			desempilhar(p1);
		}else{
			return -1;
		}
	}
	return 0;
}

//Função imprimirMenu
void imprimirMenu(){
	printf("0 - Fechar\n1 - Empilhar\n2 - Desempilhar\n3 - Tamanho da Pilha\n4 - Retorna Topo\n5 - Imprimir\n6 - Mover Elemento\n");
}
