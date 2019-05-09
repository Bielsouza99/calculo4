function insert(numero) {
    document.entrada.textview.value = document.entrada.textview.value+numero;
}

function igual() {
    var exp = document.entrada.textview.value;
    if (exp) {
        document.entrada.textview.value = eval(exp);
    }
    
}

function limpar () {
    document.entrada.textview.value = "";
}

function limpar1 () {
    var exp = document.entrada.textview.value;
    document.entrada.textview.value = exp.substring(0,exp.length-1);
}

function cosseno () {
    var exp = document.entrada.textview.value;
    angRad = (exp*Math.PI)/180;
    console.log(angRad);
    if(angRad){
        document.entrada.textview.value = Math.cos(angRad);
    }
    
}

function seno () {
    var exp = document.entrada.textview.value;
    ang = (exp*Math.PI)/180;
    if(ang) {
        document.entrada.textview.value = Math.sin(ang);
    }
    
}
