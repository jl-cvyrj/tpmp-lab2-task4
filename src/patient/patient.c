/* Аўтар: Караліна Паўлоўская */

/*
 * Серверны модуль PATIENT.
 * Рэалізуе функцыі працы з масівам пацыентаў:
 * чытанне з файла, вывад інфармацыі,
 * выбар пацыентаў з пэўнага аддзялення
 * і запіс вынікаў у файл.
 */

#include <stdio.h>
#include <string.h>
#include "../../include/patient.h"

/*
 * Функцыя: read_patients_from_file
 *
 * Апісанне:
 *      Чытае інфармацыю пра пацыентаў
 *      з тэкставага файла.
 */

/* Максімальная даўжыня радка */
#define MAX_LINE 512

int read_patients_from_file(const char *filename,
                            struct PATIENT patients[],
                            int max_count)
{
        FILE *file = fopen(filename, "r");
        if (!file)
        {
                printf("Не атрымалася адкрыць файл: %s\n", filename);
                return 0;
        }

        char line[MAX_LINE];
        int i = 0;

        while (i < max_count && fgets(line, MAX_LINE, file))
        {
                line[strcspn(line, "\r\n")] = 0;  // прыбіраем \n і \r

                // Спачатку чытаем першыя 12 палёў
                int scanned = sscanf(line,
                                     "%s %s %s %s %s %d %d %d %d %d %s %s",
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
                                     patients[i].home_address.postal_code);

                if (scanned != 12)
                {
                        printf("Прапушчаны радок або няправільны фармат:\n%s\n", line);
                        continue;
                }

                // Далей счытваем астатнія паля праз "%s" па чарзе
                scanned = sscanf(line,
                                 "%*s %*s %*s %*s %*s %*d %*d %*d %*d %*d %*s %*s "
                                 "%s %s %s %s %s %s %s %d %d %s %s %s",
                                 patients[i].home_address.country,
                                 patients[i].home_address.region,
                                 patients[i].home_address.district,
                                 patients[i].home_address.city,
                                 patients[i].home_address.street,
                                 patients[i].home_address.house,
                                 patients[i].home_address.apartment,
                                 &patients[i].hospital_number,
                                 &patients[i].department,
                                 patients[i].medical_card,
                                 patients[i].diagnosis,
                                 patients[i].blood_type);

                if (scanned != 12)
                {
                        printf("Прапушчаны радок або няправільны фармат:\n%s\n", line);
                        continue;
                }

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

