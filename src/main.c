/* Аўтар: Караліна Паўлоўская */

/*
 * Кліенцкі модуль праграмы.
 * Выкарыстоўвае серверны модуль PATIENT
 * для працы з інфармацыяй пра пацыентаў.
 */

#include <stdio.h>
#include "../include/patient.h"

int
main(void)
{
        struct PATIENT  patients[MAX_PATIENTS];
        int             count;

        count = read_patients_from_file("patients.txt",
                                        patients,
                                        MAX_PATIENTS);

        print_patients(patients, count);

        print_patients_by_department(patients, count, 4);

        write_patients_to_file("result.txt",
                               patients,
                               count,
                               4);

        return 0;
}
