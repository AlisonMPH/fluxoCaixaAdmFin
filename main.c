#include <stdio.h>
#include <stdlib.h>
typedef struct operacional{
  float RecVendas;
  float Salarios;
  float Fornecedores;
  float Impostos;
  float Total;
}tipo_op;
typedef struct investimento{
  float VenAtiPer;
  float RecDiv;
  float AquVei;
  float AquCom;
  float Total;
}tipo_in;
typedef struct financiamento{
  float AquEmp;
  float PagDiv;
  float AmoFin;
  float Total;
}tipo_fi;
typedef struct semana{
  float SalAnt;
  tipo_op operacional;
  tipo_in investimento;
  tipo_fi financiamento;
  float Total;
  float TotalFinal;
}tipo_semana;

tipo_semana semana[5];

void semana_menu();
void inserir(int *opcao);
void calcular();

int main(void){
  int opcao;
  int repetir = 1;
  for(int x = 0; x < 5; x++){
    semana[x].SalAnt = 0;
    semana[x].operacional.RecVendas = 0;
    semana[x].operacional.Salarios = 0;
    semana[x].operacional.Fornecedores = 0;
    semana[x].operacional.Impostos = 0;
    semana[x].operacional.Total = 0;
    semana[x].investimento.VenAtiPer = 0;
    semana[x].investimento.RecDiv = 0;
    semana[x].investimento.AquVei = 0;
    semana[x].investimento.AquCom = 0;
    semana[x].investimento.Total = 0;
    semana[x].financiamento.AquEmp = 0;
    semana[x].financiamento.PagDiv = 0;
    semana[x].financiamento.AmoFin = 0; 
    semana[x].financiamento.Total = 0; 
    semana[x].Total = 0;
    semana[x].TotalFinal = 0;
  }
  do{
    puts("Escolha uma opcao");
    puts("1- Inserir");
    puts("2- Calcular Fluxo de caixa");
    scanf("%d", &opcao);
    switch (opcao){
      case 1:
        semana_menu();
      break;
      case 2:
        calcular();
        repetir = 0;
        puts("Algoritmo finalizado");
      break;
    }
    if(repetir != 0){
      puts("Deseja realizar mais alguma operacao no menu inicial?(1-Sim/0-Nao)");
      scanf("%d", &repetir);
    }
  }while(repetir == 1);
}

void semana_menu(){
  int opcao;
  int repetir;
  do{
    system("clear");
    puts("Informe a semana: ");
    puts("1 - Primeira Semana");
    puts("2 - Segunda Semana");
    puts("3 - Terceira Semana");
    puts("4 - Quarta Semana");
    scanf("%d", &opcao);
    inserir(&opcao);
    puts("deseja inserir mais itens em outra semana?(1-Sim/0-Nao)");
    scanf("%d", &repetir);
  }while(repetir == 1);
}
void inserir(int *sem){
  int opcao;
  int SegOpcao;
  float valor;
  int repetir;
  *sem = *sem - 1;
  do{
    system("clear");
    puts("Deseja inserir:");
    if((*sem) == 0){
      puts("0-Saldo anterior");
    }
    puts("1-Fluxo de caixa operacional");
    puts("2-Fluxo de caixa de investimento");
    puts("3-Fluxo de caixa de financiamento");
    scanf("%d", &opcao);
    system("clear");
    switch (opcao){
      case 0:
        puts("(+) informe o valor");
        scanf("%f", &valor);
        semana[*sem].SalAnt = valor;
      break;
      case 1:
        puts("qual o tipo do item:");
        puts("(+) 1-Recebimento de vendas");
        puts("(-) 2-Salarios");
        puts("(-) 3-Fornecedores");
        puts("(-) 4-Impostos");
        scanf("%d", &SegOpcao);
        system("clear");
        puts("Informe o valor:");
        scanf("%f", &valor);
        switch (SegOpcao){
          case 1:
            semana[*sem].operacional.RecVendas = valor;
          break;
          case 2:
            semana[*sem].operacional.Salarios = valor;
          break;
          case 3:
            semana[*sem].operacional.Fornecedores = valor;
          break;
          case 4:
            semana[*sem].operacional.Impostos = valor;
          break;
        }
      break;
      case 2:
        puts("qual o tipo do item:");
        puts("(+) 1-Venda de ativos permanentes");
        puts("(+) 2-Recebimento de dividendos");
        puts("(-) 3-Aquisicao de veiculos");
        puts("(-) 4-Aquisicao de computadores");
        scanf("%d", &SegOpcao);
        system("clear");
        puts("Informe o valor:");
        scanf("%f", &valor);
        switch(SegOpcao){
          case 1:
            semana[*sem].investimento.VenAtiPer = valor;
          break;
          case 2:
            semana[*sem].investimento.RecDiv = valor;
          break;
          case 3:
            semana[*sem].investimento.AquVei = valor;
          break;
          case 4:
            semana[*sem].investimento.AquCom = valor;
          break;
        }
      break;
      case 3:
        puts("qual o tipo do item:");
        puts("(+) 1-Aquisicao de emprestimos");
        puts("(-) 2-Pagamento de dividendos");
        puts("(-) 3-Amortizacao de financiamentos");
        scanf("%d", &SegOpcao);
        system("clear");
        puts("Informe o valor:");
        scanf("%f", &valor);
        switch (SegOpcao){
          case 1:
            semana[*sem].financiamento.AquEmp = valor;
          break;
          case 2:
            semana[*sem].financiamento.PagDiv = valor;
          break;
          case 3:
            semana[*sem].financiamento.AmoFin = valor;
          break;
        }
      break;
    }
    puts("deseja inserir mais itens nessa semana?(1-Sim/0-Nao)");
    scanf("%d", &repetir);
  }while(repetir == 1);
}
void calcular(){
  char texto[22][33]={
   "|SALDO ANTERIOR                |",
   "|Recebimento de vendas         |", 
   "|Salarios                      |", 
   "|Fornecedores                  |", 
   "|Impostos                      |", 
   "|SALDO FLUXO OPERACIONAL       |", 
   "|Vendas de ativos permanentes  |", 
   "|Recebimento de dividendos     |", 
   "|Aquisicao de veiculo          |", 
   "|Aquisicao de computadores     |", 
   "|SALDO FLUXO INVESTIMENTO      |", 
   "|Aquisicao de emprestimos      |", 
   "|Pagamento dividendos          |", 
   "|Amortizacao de Financiamento  |", 
   "|SALDO FLUXO FINANCIAMENTO     |", 
   "|Saldo inicial do periodo      |", 
   "|Saldo do periodo              |", 
   "|Resultado final do periodo    |"};

  printf("|");
  for(int x = 0; x < 30; x++){
    printf(" ");
  }
  printf("|");
  for(int x = 1; x < 5; x++){
    printf(" Semana %d |", x);
  }
  printf("TOTAL     |\n");
  
  for(int x = 0; x < 4; x++){
    semana[x].operacional.Total += semana[x].operacional.RecVendas;
    semana[4].operacional.RecVendas += semana[x].operacional.RecVendas;
    semana[x].operacional.Total += semana[x].operacional.Salarios;
    semana[4].operacional.Salarios += semana[x].operacional.Salarios;
    semana[x].operacional.Total += semana[x].operacional.Fornecedores;
    semana[4].operacional.Fornecedores += semana[x].operacional.Fornecedores;
    semana[x].operacional.Total += semana[x].operacional.Impostos;
    semana[4].operacional.Impostos += semana[x].operacional.Impostos;
    semana[x].investimento.Total += semana[x].investimento.VenAtiPer;
    semana[4].investimento.VenAtiPer += semana[x].investimento.VenAtiPer;
    semana[x].investimento.Total += semana[x].investimento.RecDiv;
    semana[4].investimento.RecDiv += semana[x].investimento.RecDiv;
    semana[x].investimento.Total += semana[x].investimento.AquVei;
    semana[4].investimento.AquVei += semana[x].investimento.AquVei;
    semana[x].investimento.Total += semana[x].investimento.AquCom;
    semana[4].investimento.AquCom += semana[x].investimento.AquCom;
    semana[x].financiamento.Total += semana[x].financiamento.AquEmp;
    semana[4].financiamento.AquEmp += semana[x].financiamento.AquEmp;
    semana[x].financiamento.Total += semana[x].financiamento.PagDiv;
    semana[4].financiamento.PagDiv += semana[x].financiamento.PagDiv;
    semana[x].financiamento.Total += semana[x].financiamento.AmoFin;
    semana[4].financiamento.AmoFin += semana[x].financiamento.AmoFin;
    semana[4].operacional.Total += semana[x].operacional.Total;
    semana[4].investimento.Total += semana[x].investimento.Total;
    semana[4].financiamento.Total += semana[x].financiamento.Total;
    semana[x].Total = semana[x].operacional.Total + semana[x].investimento.Total + semana[x].financiamento.Total;
    semana[4].Total += semana[x].operacional.Total + semana[x].investimento.Total + semana[x].financiamento.Total;
    semana[x].TotalFinal = semana[x].SalAnt + semana[x].Total;
    if(x < 3){
      semana[x+1].SalAnt = semana[x].TotalFinal;
    }
  }
  semana[4].TotalFinal += semana[0].SalAnt + semana[4].Total;
  semana[4].SalAnt = semana[0].SalAnt;

  for(int x = 0; x < 22; x++){
    if(x == 1 || x == 6 || x == 11 || x == 15 ){
      switch (x){
        case 1:
          puts("|                              FLUXO DE CAIXA OPERACIONAL                             |");
        break;
        case 6:
          puts("|                            FLUXO DE CAIXA DE INVESTIMENTO                           |");
        break;
        case 11:
          puts("|                           FLUXO DE CAIXA DE FINANCIAMENTO                           |");
        break;
        case 15:
          puts("|                                      RESULTADOS                                     |");
        break;
      }
    }
    printf("%s", texto[x]);
    for(int y = 0; y < 5; y++){
      switch (x){
        case 0:
          printf("%10.2f|", semana[y].SalAnt);
        break;  
        case 1:
          printf("%10.2f|", semana[y].operacional.RecVendas);
        break;
        case 2:
          printf("%10.2f|", semana[y].operacional.Salarios);
        break;
        case 3:
          printf("%10.2f|", semana[y].operacional.Fornecedores);
        break;
        case 4:
          printf("%10.2f|", semana[y].operacional.Impostos);
        break;
        case 5:
          printf("%10.2f|", semana[y].operacional.Total);
        break;
        case 6:
          printf("%10.2f|", semana[y].investimento.VenAtiPer);
        break;
        case 7:
          printf("%10.2f|", semana[y].investimento.RecDiv);
        break;
        case 8:
          printf("%10.2f|", semana[y].investimento.AquVei);
        break;
        case 9:
          printf("%10.2f|", semana[y].investimento.AquCom);
        break;
        case 10:
          printf("%10.2f|", semana[y].investimento.Total);
        break;
        case 11:
          printf("%10.2f|", semana[y].financiamento.AquEmp);
        break;
        case 12:
          printf("%10.2f|", semana[y].financiamento.PagDiv);
        break;
        case 13:
          printf("%10.2f|", semana[y].financiamento.AmoFin);
        break;
        case 14:
          printf("%10.2f|", semana[y].financiamento.Total);
        break;
        case 15:
          printf("%10.2f|", semana[y].SalAnt);
        break;
        case 16:
          printf("%10.2f|", semana[y].Total);
        break;
        case 17:
          printf("%10.2f|", semana[y].TotalFinal);
        break;
      }
    }
    printf("\n");
  }
}