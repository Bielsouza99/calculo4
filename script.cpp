#include <iostream>
#include <cmath>
/*
    Data de entrega: 21/05/19
    epsilon = 0.00001

*/
using namespace std;

float funcao1(float x)
{
    // Escreva a função para aplicar no metódo do ponto fixo
    return ((2 * sqrt(x)) - (1.3 * pow(x, 2)) + 3);
}

float funcao2(float x)
{
    // Escreva a função para aplicar no metódo de Newton
    return (((-2) * log(x)) - (1.4 * x) + 7);
}

float derivada_phi1(float x)
{
    
    return ((((1/sqrt(x))*(1.3*x))-((2*sqrt(x))*1.3))/(1.69*x));
}

float derivada_f2(float x)
{
    return ((-2 / x) - 1.4);
}

float phi1(float x)
{
    //Função phi do método do ponto fixo em relação a funcao1
    return (sqrt(((2*sqrt(x))+3)/(1.3)));
}

float phi2(float x)
{
    //Função phi do metódo de Newton em relação a funcao2
    return (x - ((funcao2(x)) / derivada_f2(x)));
}

float cp(float x1, float x0)
{
    // Critério de parada recebe como parâmetro o maior e o menor valor, respectivamente
    return (fabs(x1 - x0) / x1);
}

//float fsecante(float x0, float x1){
// return (((x0*f(x1)) - (x1*f(x0)))/(f(x1)-f(x0)));
//}
/*
int bissec() {
 float s, r, epsilon, cp, xBarra;
 int garantia;

 cout << "Digite o epsilon: \n";
 cin >> epsilon;

 cout << "Digite o 'r' e o 's' apenas separados por espaço \n";
 cin >> r, s;

 garantia = ((funcao(r) * funcao(s)) > 0 ? 0 : 1);

 while (garantia == 0)
 {
     cout << "Esse intervalo é inválido, pois não atende que o '(f(r)*f(s))<0', por favor digite outro: \n";
     cin >> r;
     cin >> s;
     garantia = ((funcao(r) * funcao(s)) > 0 ? 0 : 1);
 }

 if (funcao(r) == 0 || funcao(s) == 0)
 {
     cout << "Esse é o valor da expressão: " << endl;
     return 0;
 }

 while (cp > epsilon)
 {
    cp = abs(s - r);
    cout << "o critério de parada vale: " << cp << endl;
     xBarra = (r + s) / 2;
     if (funcao(xBarra) == 0)
     {
        cout << "Raiz encontrada, vale: " << xBarra << endl;
        return 0;
     }

     if ((funcao(r) * funcao(xBarra) < 0))
     {
        s = xBarra;
     }
    else
    {
        r = xBarra;
    }
  }

 cout << "O intervalo e a solução aproximada são: " << r << "," << s << "," << (r + s) / 2 << endl;
 return 0;


    float s, r, epsilon, cp, xBarra;
    int garantia;

    cout << "Digite o epsilon: \n";
    cin >> epsilon;

    cout << "Digite o 'r' e o 's' apenas separados por espaço \n";
    cin >> r;
    cin >> s;

    garantia = ((funcao(r) * funcao(s)) > 0 ? 0 : 1);

    while (garantia == 0)
    {
        cout << "Esse intervalo é inválido, pois não atende que o '(f(r)*f(s))<0', por favor digite outro: \n";
        cin >> r;
        cin >> s;
        garantia = ((funcao(r) * funcao(s)) > 0 ? 0 : 1);
    }

    if (funcao(r) == 0 || funcao(s) == 0)
    {
        cout << "Esse é o valor da expressão: " << endl;
        return 0;
    }


    do
    {
        float min = fmin(s,r);
        float max = fmax(s,r);
        cp = (abs(max - min))/max;
        cout << "o critério de parada vale: " << cp << endl;
        xBarra = (r + s) / 2;
        cout << "O valor de f(xBarra) é: " << funcao(xBarra) << endl;
        if (funcao(xBarra) == 0)
        {
            cout << "Raiz encontrada, vale: " << xBarra << endl;
            return 0;
        }

        if ((funcao(r) * funcao(xBarra) < 0))
        {
            s = xBarra;
        }
        else
        {
            r = xBarra;
        }
    } while (cp > epsilon);
    
    // while (cp > epsilon)
    // {
        
    // }

    cout << "O intervalo e a solução aproximada são: " << "[" << r << "," << s << "]" << ";" << (r + s) / 2 << endl;
    return 0;
    
} */

int mpf()
{
    float criterio_parada, r = 1.5, s = 2.5, epsilon = 0.00001, x0, x;
    int cond_convergencia;
    
    cout << "Entre com o x0 da sua função:" << endl;
    cout << ">> ";
    cin >> x0;


    int i = 0;
    do
    {
        x = phi1(x0);
        // cout << x << endl;
        criterio_parada = cp(x, x0);
        cout << criterio_parada << endl;
        i = i + 1;
        x0 = x;
    } while (criterio_parada > epsilon);

    cout << "Esse software fez: " << i << " iterações" << endl;
    cout << "A aproximação da raiz é: " << x0 << endl;
    return 0;
}

int newton()
{

    // implementar do while
    float criterio_parada, epsilon = 0.00001, r = 3, s = 4, x0, x;
    cout << "Digite o seu x0: " << endl;
    cout << ">> ";
    cin >> x0;

    //cout << (x0 - (((x0*x0*x0)+(x0 * x0)+2))) << endl;

    //cout << f(x0) << endl;
    //cout << derivada_f(x0) << endl;
    //cout << (f(x0)/derivada_f(x0)) << endl;
    // do
    // {
    //     float cp = (x-x0);
    //     x = phi(x0);
    //     x0 = x;
    //     cout << "O valor de x é: " << x << endl;
    // } while (erro > epsilon);
    int i = 0;
    do
    {
        x = phi2(x0);
        criterio_parada = cp(x, x0);
        x0 = x;
        i = i + 1;
    } while (criterio_parada > epsilon);

    cout << "Esse programa fez " << i << " iterações" << endl;
    cout << "O valor de x é: " << x << endl;
    return 0;
}

/*
int secantes() {
    float x0,x1; // precisa de dois valores para valores iniciais
    cout << fsecante(0.8356,0.7894) << endl;
    cout << cp(0.7935,0.7894) << endl;
}
*/
int main()
{
    //newton();
    //bissec();

    int metodo;
    cout << "Selecione o metódo:" << endl;
    cout << "1 - Newton" << endl;
    cout << "2 - Bissecção" << endl;
    cout << "3 - Secantes" << endl;
    cout << "4 - Ponto fixo" << endl;
    cout << ">> ";

    cin >> metodo;
    switch (metodo)
    {
    case 1:
        cout << "Você selecionou o método de newton" << endl;
        newton();
        break;
    case 2:
        cout << "Você selecionou o metódo da bissecção, porém ele não está ativo haha" << endl;
        //bissec();
        break;
    case 3:
        cout << "Você selecionou o metódo das secantes, porém ele não está ativo haha" << endl;
        // secantes();
        break;
    case 4:
        cout << "Você selecionou o metódo do ponto fixo" << endl;
        mpf();
        break;
    default:
        break;
    }
}