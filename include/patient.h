/* Аўтар: Караліна Паўлоўская */

#ifndef PATIENT_H
#define PATIENT_H

/*
 * Інтэрфейс модуля PATIENT.
 * Апісвае структуры DATE, ADDRESS, PATIENT і функцыі для працы
 * з масівам пацыентаў.
 */

#include <stdio.h>

#define MAX_PATIENTS    100
#define MAX_NAME        50
#define MAX_STRING      100

struct DATE
{
        int             year;                   /* год */
        int             month;                  /* месяц */
        int             day;                    /* дзень */
};

struct ADDRESS
{
        char            postal_code[20];        /* паштовы індэкс */
        char            country[MAX_NAME];      /* краіна */
        char            region[MAX_NAME];       /* вобласць */
        char            district[MAX_NAME];     /* раён */
        char            city[MAX_NAME];         /* горад */
        char            street[MAX_NAME];       /* вуліца */
        char            house[10];              /* дом */
        char            apartment[10];          /* кватэра */
};

struct PATIENT
{
        char            last_name[MAX_NAME];    /* прозвішча */
        char            first_name[MAX_NAME];   /* імя */
        char            patronymic[MAX_NAME];   /* імя па бацьку */
        char            gender[10];             /* пол */
        char            nationality[MAX_NAME];  /* нацыянальнасць */
        int             height;                 /* рост */
        int             weight;                 /* вага */
        struct DATE     birth_date;             /* дата нараджэння */
        char            phone[20];              /* нумар тэлефона */
        struct ADDRESS  home_address;           /* хатні адрас */
        int             hospital_number;        /* нумар бальніцы */
        int             department;             /* аддзяленне */
        char            medical_card[20];       /* нумар медыцынскай карты */
        char            diagnosis[MAX_STRING];  /* дыягназ */
        char            blood_type[5];          /* група крыві */
};

int     read_patients_from_file  (const char *filename,
                                  struct PATIENT patients[],
                                  int max_count);

void    print_patients           (struct PATIENT patients[],
                                  int count);

void    print_patients_by_department (struct PATIENT patients[],
                                      int count,
                                      int department);

void    write_patients_to_file   (const char *filename,
                                  struct PATIENT patients[],
                                  int count,
                                  int department);

#endif
