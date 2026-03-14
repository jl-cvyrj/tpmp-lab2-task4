/* Аўтар: Караліна Паўлоўская */

/*
 * Серверны модуль PATIENT.
 * Рэалізуе функцыі працы з масівам пацыентаў:
 * чытанне з файла, вывад інфармацыі,
 * выбар пацыентаў з пэўнага аддзялення
 * і запіс вынікаў у файл.
 */

#include <stdio.h>
#include "../../include/patient.h"

/*
 * Функцыя: read_patients_from_file
 *
 * Апісанне:
 *      Чытае інфармацыю пра пацыентаў
 *      з тэкставага файла.
 */

int
read_patients_from_file(const char      *filename,
                        struct PATIENT  patients[],
                        int             max_count)
{
        FILE    *file;
        int     i;

        file = fopen(filename, "r");

        if (file == NULL)
        {
                printf("Памылка адкрыцця файла\n");
                return 0;
        }

        i = 0;

        while (i < max_count &&
               fscanf(file,
                      "%s %s %s %s %s %d %d %d %d %d %s "
                      "%s %s %s %s %s %s %s "
                      "%d %d %s %s %s",
                      patients[i].last_name,
                      patients[i].first_name,
                      patients[i].patronymic,
                      patients[i].gender,
                      patients[i].nationality,
                      &patients[i].height,
                      &patients[i].weight,
                      &patients[i].birth_date.year,
                      &patients[i].birth_date.month,
                      &patients[i].birth_date.day,
                      patients[i].phone,
                      patients[i].home_address.postal_code,
                      patients[i].home_address.country,
                      patients[i].home_address.region,
                      patients[i].home_address.district,
                      patients[i].home_address.city,
                      patients[i].home_address.street,
                      patients[i].home_address.house,
                      &patients[i].hospital_number,
                      &patients[i].department,
                      patients[i].medical_card,
                      patients[i].diagnosis,
                      patients[i].blood_type) == 23)
        {
                i++;
        }

        fclose(file);

        return i;
}


/*
 * Функцыя: print_patients
 *
 * Апісанне:
 *      Выводзіць усіх пацыентаў.
 */

void
print_patients(struct PATIENT patients[], int count)
{
        int     i;

        printf("\nСпіс пацыентаў:\n");

        for (i = 0; i < count; i++)
        {
                printf("%s %s %s | Аддзяленне %d | Дыягназ: %s\n",
                       patients[i].last_name,
                       patients[i].first_name,
                       patients[i].patronymic,
                       patients[i].department,
                       patients[i].diagnosis);
        }
}


/*
 * Функцыя: print_patients_by_department
 *
 * Апісанне:
 *      Выводзіць пацыентаў з пэўнага аддзялення.
 */

void
print_patients_by_department(struct PATIENT patients[],
                             int count,
                             int department)
{
        int     i;

        printf("\nПацыенты з аддзялення %d:\n", department);

        for (i = 0; i < count; i++)
        {
                if (patients[i].department == department)
                {
                        printf("%s %s %s | Дыягназ: %s\n",
                               patients[i].last_name,
                               patients[i].first_name,
                               patients[i].patronymic,
                               patients[i].diagnosis);
                }
        }
}


/*
 * Функцыя: write_patients_to_file
 *
 * Апісанне:
 *      Запісвае пацыентаў з пэўнага аддзялення
 *      у новы тэкставы файл.
 */

void
write_patients_to_file(const char *filename,
                       struct PATIENT patients[],
                       int count,
                       int department)
{
        FILE    *file;
        int     i;

        file = fopen(filename, "w");

        if (file == NULL)
        {
                printf("Памылка стварэння файла\n");
                return;
        }

        for (i = 0; i < count; i++)
        {
                if (patients[i].department == department)
                {
                        fprintf(file,
                                "%s %s %s | Дыягназ: %s\n",
                                patients[i].last_name,
                                patients[i].first_name,
                                patients[i].patronymic,
                                patients[i].diagnosis);
                }
        }

        fclose(file);
}
