#include <stdio.h>

int main()
{
    int n;
    printf("Enter the no.of students or colleges : ");
    scanf("%d", &n);
    int srr[n][n];    // array that contains the preference of student
    int crr[n][n];    // array that contains the preference of colleges
    int srrFlag[n];   // array that tells if the student is admitted or not
    int crrFlag[n];   // array that tells if the college is filled or not
    int srFlag[n][n]; // array that gives information about the write offs
    int count = 0;
    printf("\nEnter the preference list of students : ");
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the preference list of student %d : ", i + 1);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &srr[i][j]);
            srFlag[i][j] = 0;
        }
        srrFlag[i] = 0;
    }
    printf("\nEnter the preference list of colleges : ");
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the preference list of college %d : ", i + 1);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &crr[i][j]);
        }
        crrFlag[i] = 0;
    }
    while (count != n) // there are more matches that need to be done
    {
        for (int i = 0; i < n; i++) // looping to fing the student who is not matched
        {
            if (srrFlag[i] == 0) // if student is not matched
            {
                for (int j = 0; j < n; j++) // looping to fing the college he did not applied and that is free
                {
                    if (srFlag[i][j] == 0) // if college is not write off
                    {
                        int c = srr[i][j];
                        if (crrFlag[c - 1] == 0) // college not filled
                        {
                            int count1 = 0; // to find wether the the student is admitted or not soo that we can break the loop of colleges
                            int k = 0;
                            do
                            {
                                if (srrFlag[crr[c - 1][k] - 1] == 1) // prefered student admitted
                                {
                                    continue;
                                }
                                if (srrFlag[crr[c - 1][k] - 1] == 0 && crr[c - 1][k] != i + 1) // prefered student is not admitted
                                {
                                    srFlag[i][j] = 1; // write off college
                                    break;
                                }
                                if (crr[c - 1][k] == i + 1)
                                {
                                    srrFlag[i] = 1;     // marking that student is admitted
                                    crrFlag[c - 1] = 1; // marking that college is filled
                                    printf("\nStudent %d is admitted in %d college\n", i + 1, c);
                                    count = count + 1;
                                    count1 = 1;
                                    break;
                                }
                                k++;
                            } while (crr[c - 1][k] != i + 1); // most prefered student is not equal to applied student

                            if (count1 == 1)
                            {
                                break; // student 's' admitted break the loop used to search for colleges and countinue searching college for the next student
                            }
                        }
                        else
                        {
                            srFlag[i][j] = 1; // write of college
                        }
                    }
                }
            }
        }
    }
}