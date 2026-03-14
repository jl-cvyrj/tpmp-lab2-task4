/* Аўтар: Караліна Паўлоўская */

/*
 * Кліенцкі модуль праграмы.
 * Чытае файл з аргумента каманднага радка
 * і выводзіць пацыентаў з 4 аддзялення.
 */

#include <stdio.h>
#include "../include/patient.h"

int
main(int argc, char *argv[])
{
        struct PATIENT  patients[MAX_PATIENTS];
        int             count;

        if (argc < 2)
        {
                printf("Выкарыстанне: %s <файл>\n", argv[0]);
                return 1;
        }

        count = read_patients_from_file(
                argv[1],
                patients,
                MAX_PATIENTS
        );

        if (count == 0)
        {
                printf("Файл пусты або памылка чытання\n");
                return 1;
        }

        print_patients(patients, count);

        print_patients_by_department(patients, count, 4);

        write_patients_to_file(
                "docs/result.txt",
                patients,
                count,
                4
        );

        return 0;
}
