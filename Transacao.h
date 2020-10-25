#ifndef AEDA_TRANSACAO_H
#define AEDA_TRANSACAO_H


class Transacao {
private:
    date data;
    vector<Produto*> produtos;
    double ;
    //estatisticas(por definir)
    Cliente cliente;

public:
    Transacao();
    ~Transacao();
    unsigned int getYear() const;
    unsigned int getMonth() const;
    unsigned int getDay() const;
    void setYear(unsigned int year);
    void setMonth(unsigned int month);
    void setDay(unsigned int day);
}


#endif //AEDA_TRANSACAO_H
