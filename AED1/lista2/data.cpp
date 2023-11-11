#include "data.hpp"
#include <stdlib.h>
#include <iostream>
#include <unistd.h>

struct data{
    int dia, mes, ano;
};

Data * criaData (int dia, int mes, int ano){
    Data * dt = NULL;
    dt = (Data *) malloc(1 * sizeof(Data));
    dt->dia = dia;
    dt->mes = mes;
    dt->ano = ano;
    return dt;
}

Data * copiaData (Data * d){
    Data * copia = NULL;
    copia = criaData(d->dia, d->mes, d->ano);
    return copia;
}

void liberaData (Data * d){
    free(d);
}

Data * somaDiasData (Data * d, int dias){
    d->dia += dias;

    while(1){
        if(d->mes >= 0 && d->mes <= 7){
            if(d->mes == 2){
                if(d->dia > 28){
                    d->dia -= 28;
                    d->mes++;
                } else{
                    break;
                }
            } else if(d->mes % 2 == 0){
                if(d->dia > 30){
                    d->dia -= 30;
                    d->mes++;
                } else{
                    break;
                }
            } else{
                if(d->dia > 31){
                    d->dia -= 31;
                    d->mes++;
                } else{
                    break;
                }
            }
        } else if(d->mes >= 8 && d->mes <= 12){
            if(d->mes % 2 == 0){
                if(d->dia > 31){
                    d->dia -= 31;
                    d->mes++;
                } else{
                    break;
                }
            } else{
                if(d->dia > 30){
                    d->dia -= 30;
                    d->mes++;
                } else{
                    break;
                }
            }
        } else if(d->mes > 12){
            d->mes -= 12;
            d->ano++;
        }
    }

    return d;
}

void mostraData(Data * d){
    std::cout << d->dia << "/" << d->mes << "/" << d->ano << "\n";
}

Data * subtrairDiasData(Data * d, int dias){
    d->dia -= dias;

    while(1){
        if(d->mes >= 1 && d->mes <= 7){
            if(d->mes == 3){
                if(d->dia < 1){
                    d->dia += 28;
                    d->mes--;
                } else{
                    break;
                }
            } else if(d->mes == 1){
                if(d->dia < 1){
                    d->dia += 31;
                    d->mes--;
                } else{
                    break;
                }
            } else if(d->mes % 2 == 0){
                if(d->dia < 1){
                    d->dia += 31;
                    d->mes--;
                } else{
                    break;
                }
            } else{
                if(d->dia < 1){
                    d->dia += 30;
                    d->mes--;
                } else{
                    break;
                }
            }
        } else if(d->mes >= 8 && d->mes <= 12){
            if(d->mes == 8){
                if(d->dia < 1){
                    d->dia += 31;
                    d->mes--;
                } else{
                    break;
                }
            } else if(d->mes % 2 == 0){
                if(d->dia < 1){
                    d->dia += 30;
                    d->mes--;
                } else{
                    break;
                }
            } else{
                if(d->dia < 1){
                    d->dia += 31;
                    d->mes--;
                } else{
                    break;
                }
            }
        } else if(d->mes < 1){
            d->mes += 12;
            d->ano--;
        }
    }

    return d;
}

void atribuirData (Data * d, int dia, int mes, int ano){
    d->dia = dia;
    d->mes = mes;
    d->ano = ano;
}

int obtemDiaData (Data * d){
    return d->dia;
}

int obtemMesData (Data * d){
    return d->mes;
}

int obtemAnoData (Data * d){
    return d->ano;
}

int bissextoData (Data * d){
    if(d->ano % 4 == 0 && d->ano % 100 == 0 && d->ano % 400 == 0) return TRUE;
    return FALSE;
}

int comparaData (Data * d1, Data * d2){
    if(d1->ano > d2->ano){
        return MAIOR;
    } else if(d1->ano < d2->ano){
        return MENOR;
    } else{
        if(d1->mes > d2->mes){
            return MAIOR;
        } else if(d1->mes < d2->mes){
            return MENOR;
        } else{
            if(d1->dia > d2->dia){
                return MAIOR;
            } else if(d1->dia < d2->dia){
                return MENOR;
            } else{
                return IGUAL;
            }
        }
    }
}

int numeroDiasDatas (Data * d1, Data * d2){
    Data * d1_copy = NULL;
    Data * d2_copy = NULL;
    int k = 0;

    d1_copy = copiaData(d1);
    d2_copy = copiaData(d2);

    if(comparaData(d1_copy, d2_copy) == MAIOR){
        //k = (d1_copy->dia - d2_copy->dia) + (28 * (d1_copy->mes - d2_copy->mes)) + (365 * (d1_copy->ano - d2_copy->ano));

        while(comparaData(d1_copy, d2_copy) != IGUAL){
            somaDiasData(d2_copy, 1);
            k++;
        }

    } else if(comparaData(d1_copy, d2_copy) == MENOR){
        //k = (d2_copy->dia - d1_copy->dia) + (28 * (d2_copy->mes - d1_copy->mes)) + (365 * (d2_copy->ano - d1_copy->ano));

        while(comparaData(d1_copy, d2_copy) != IGUAL){
            somaDiasData(d1_copy, 1);
            k++;
        }

    } else if(comparaData(d1_copy, d2_copy) == IGUAL){
        return 0;
    }

    return k;
}

int numeroMesesDatas (Data * d1, Data * d2){
    int num_meses = 0;
    if(comparaData(d1, d2) == MAIOR){

        num_meses = (d1->mes - d2->mes) + (12 * (d1->ano - d2->ano));

    } else if(comparaData(d1, d2) == MENOR){

        num_meses = (d2->mes - d1->mes) + (12 * (d2->ano - d1->ano));

    }

    return num_meses;
}

int numeroAnosDatas (Data * d1, Data * d2){

    if(comparaData(d1, d2) == MAIOR){
        return d1->ano - d2->ano;
    } else if(comparaData(d1, d2) == MENOR){
        return d2->ano - d1->ano;
    } 

    return 0;

}

char * imprimeData (Data * d, char * formato){
    char inicial;
    int i = 0;

    while(formato[i] != '\0'){

        if(i == 0) inicial = formato[i];
        i++;

    }

    if(i == 8){
        if(inicial == 'd'){
            formato[0] = (d->dia / 10) + '0';
            formato[1] = (d->dia % 10) + '0';
            formato[2] = '/';
            formato[3] = (d->mes / 10) + '0';
            formato[4] = (d->mes % 10) + '0';
            formato[5] = '/';
            formato[6] = (d->ano / 1000) + '0';
            formato[7] = ((d->ano / 100) % 10) + '0';
            formato[8] = ((d->ano / 10) % 100) + '0';
            formato[9] = (d->ano % 10) + '0';
        } else if(inicial == 'a'){
            formato[0] = (d->ano / 1000) + '0';
            formato[1] = ((d->ano / 100) % 10) + '0';
            formato[2] = ((d->ano / 10) % 100) + '0';
            formato[3] = (d->ano % 10) + '0';
            formato[4] = '/';
            formato[5] = (d->mes / 10) + '0';
            formato[6] = (d->mes % 10) + '0';
            formato[7] = '/';
            formato[8] = (d->dia / 10) + '0';
            formato[9] = (d->dia % 10) + '0';
        }
    } else if(i == 4){
        if(inicial == 'd'){
            formato[0] = (d->dia / 10) + '0';
            formato[1] = (d->dia % 10) + '0';
            formato[2] = '/';
            formato[3] = (d->mes / 10) + '0';
            formato[4] = (d->mes % 10) + '0';
        } else if(inicial == 'a'){
            formato[0] = (d->ano / 1000) + '0';
            formato[1] = ((d->ano / 100) % 10) + '0';
            formato[2] = ((d->ano / 10) % 100) + '0';
            formato[3] = (d->ano % 10) + '0';
        }
    } else if(i == 2){
        if(inicial == 'm'){
            formato[0] = (d->mes / 10) + '0';
            formato[1] = (d->mes % 10) + '0';
        } else if(inicial == 'd'){
            formato[0] = (d->dia / 10) + '0';
            formato[1] = (d->dia % 10) + '0';
        }
    }
    
    return formato;
}


int obtemDiaSemanaData (Data * d);