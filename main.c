#include <stdio.h>
#include <stdbool.h>
#include <string.h>

//le um array de politicos
//criar um espectro de esquerda/direita
//se fores de esquerda, sao automaticamente discartados como bons candidatos

struct politician{
    int position_points;
    float year_of_work;
    float year_of_politics;
    float good_a_job_rating;
    float corruption_provability;
    bool radical;
};

int political_position(const char* party, struct politician* candidate){
    if (strcmp(party, "PCP") == 0){
        candidate->position_points = -3;
        candidate->radical = false;
    }
    if (strcmp(party, "BE") == 0){
        candidate->position_points = -3;
        candidate->radical = false;
    }
    if (strcmp(party, "L") == 0){
        candidate->position_points = -2;
        candidate->radical = false;
    }
    if (strcmp(party, "PS") == 0){
        candidate->position_points = -1;
        candidate->radical = false;
    }
    if (strcmp(party, "PSD") == 0){
        candidate->position_points = 1;
        candidate->radical = false;
    }
    if (strcmp(party, "CDS") == 0){
        candidate->position_points = 2;
        candidate->radical = false;
    }
    if (strcmp(party, "CH") == 0){
        candidate->position_points = 3;
        candidate->radical = true;
    }
    if (strcmp(party, "ADN") == 0){
        candidate->position_points = 4;
        candidate->radical = true;
    }
    if (strcmp(party, "E") == 0){
        candidate->position_points = 5;
        candidate->radical = true;
    }
}

int good_a_job(float year_of_work, float year_of_politics, struct politician* candidate){
    candidate->good_a_job_rating = year_of_work + (year_of_politics / 2);
}

int corruption_provability(float year_of_work, float year_of_politics, int position_points,struct politician* candidate){
    if (candidate->radical == true){candidate->corruption_provability = -(year_of_work / 3) + year_of_politics - 1;}
    if (candidate->radical == false){candidate->corruption_provability = -(year_of_work / 3) + year_of_politics;}

    switch(candidate->position_points){
        case 3:
            candidate->corruption_provability += 5;
            break;
        case 2:
            candidate->corruption_provability += 3;
            break;
        case 1:
            candidate->corruption_provability += 6;
            break;
        case -1:
            candidate->corruption_provability += 10;
            break;
        case -2:
            candidate->corruption_provability += 0;
            break;
        case -3:
            candidate->corruption_provability += 1;
            break;
        case -4:
            candidate->corruption_provability += 1;
            break;
        default:
            candidate->corruption_provability += 0;
    }

}

int main(){
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    struct politician Antronio_costa;

    Antronio_costa.year_of_work = 0;
    Antronio_costa.year_of_politics = 0.3;

    political_position("PSD", &Antronio_costa);
    good_a_job(Antronio_costa.year_of_work,Antronio_costa.year_of_politics,&Antronio_costa);
    corruption_provability(Antronio_costa.year_of_work,Antronio_costa.year_of_politics,Antronio_costa.position_points, &Antronio_costa);

    printf("Good job: %f\n", Antronio_costa.good_a_job_rating);
    printf("Corrupt: %f\n", Antronio_costa.corruption_provability);
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    return 0;
}