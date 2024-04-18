// FILA JS - Atividade 2

class Pessoa {
    constructor(nome, cpf){
        this.nome = nome;
        this.cpf = cpf;
        this.dataHoraEntrada = new Date();
        this.dataHoraSaida = null;
    }

    calculaTempoFila(){
        const tempoFila = (this.dataHoraSaida || new Date()) - this.dataHoraEntrada;
        return Math.floor(tempoFila / (1000 * 60));
    }
}
class SistemaAtendimento{
    constructor() {
        this.filaAtendimento = [];
    }

    adicionaPessoa(nome, cpf){
        const pessoa = new Pessoa(nome, cpf);
        this.filaAtendimento.push(pessoa);
        console.log(`{pessoa.nome} entrou na fila.`);      
    }

    atendePessoa(){
        if (this.filaAtendimento.length === 0){
            console.log("Não há pessoas na fila no momento ");
        } else {
            const pessoaAtendida = this.filaAtendimento.shift();
            pessoaAtendida.dataHoraSaida = new Date();
            console.log(`{pessoaAtendida.nome} foi atendida.`);
            console.log(`Hora de entrada: {pessoaAtendida.dataHoraEntrada}`);
            console.log(`Hora de saída: {pessoaAtendida.dataHoraSaida}`);
            console.log(`Tempo de fila: {pessoaAtendida.calcularTempoFila()} minutos`);
        }
    }

    mostraFila(){
        console.log("Fila de Atendimento:");
        this.filaAtendimento.forEach((pessoa, index) =>{
            console.log(`{index + 1}. {pessoa.nome} - CPF: {pessoa.cpf}`);
        });
    }

    buscaPorCPF(cpf){
        const pessoaEncontrada = this.filaAtendimento.find(pessoa => pessoa.cpf === cpf);
        if (pessoaEncontrada){
            console.log(`Pessoa encontrada: {pessoaEncontrada.nome}`);
        } else {
            console.log("Pessoa não encontrada ");
        }
    }
}
