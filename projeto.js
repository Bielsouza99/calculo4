var prompt = require('prompt');
var input = require('console-read-write');
const readline = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout
});
prompt.start();
const epsilon =  0.00001;
function cp (x1,x0){
    return Math.abs((x1-x0)/x1);
}
function newton() {
        var criterio_de_parada, x0, x;
        x0 = 3;
        var i = 1;

        function funcao(x) {
            return ((-2*Math.log(x)) - 1.4*x + 7);
        }

        function derivada(x) {
            return ((-2/x) - 1.4);
        }

        function phi(x) {
            return (x - ((funcao(x)) / derivada(x)));
        }

        do {
            x = phi(x0);
            
            console.log('x' + i + ' é igual a: ' + x);
            criterio_de_parada = cp(x,x0);
            console.log('O critério de parada é: ' + criterio_de_parada);
            i = i + 1;
            x0 = x;
        } while (criterio_de_parada > epsilon);

        console.log('A aproximação da raiz é (x' + (i-1) + ') = ' + x0);
}
function mpf(){
    var criterio_de_parada, x0,x;
        x0 = 1.5;
        var i = 1;

        function funcao(x) {
            return ((2*Math.sqrt(x)) - (1.3* Math.pow(x,2)) + 3);
        }
        function phi(x) {
            return (Math.sqrt(((2 * Math.sqrt(x)) +3 ) / (1.3)));
        }
        function derivada_phi(x) {
            return (1/ ((2.6*Math.sqrt(x))*Math.sqrt((2*Math.sqrt(x) + 3))));
        }

        do{
            x = phi(x0);
            console.log('x' + i + ' é igual a: ' + x);
            criterio_de_parada = cp(x,x0);
            console.log('O critério de parada é: ' + criterio_de_parada);
            i = i + 1;  
            x0 = x;
        }while(criterio_de_parada > epsilon);

        console.log('A aproximação da raiz é (x' + (i-1) + ') igual a: ' + x0 );
}

//function menu(){
  //var metodo;
  //readline.question(`>> `, (metodo) => {
  //  switch(metodo){
 //   case 1: 
  //    console.log('Você selecionou o método do ponto fixo');
   //   mpf();
  //    break;
  //  case 2:
    //  console.log('Você selecionou o método de newton');
     // newton();
  //    break;
  //  default:
  //    console.log('Nenhum método foi selecionado, favor selecionar algum');
 //     menu();
 //   }
    
 //   readline.close();
//  })
  
//  prompt('Bem-vindo ao projeto de Cálculo 4 em JS, escolha qual método deseja visualizar \n 1 - Método do Ponto fixo \n 2 - Método de Newton \n >> ');
  
  
  
  
//}

//menu();
newton();
mpf();
