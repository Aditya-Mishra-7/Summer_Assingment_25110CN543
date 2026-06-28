//Question-108 : Write a program to create marksheet generation system.
#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 60
#define TOTAL_SUBJECTS 5


typedef struct {
    int roll_number;
    char student_name[50];
    char academic_term[15];
    int scores_achieved[TOTAL_SUBJECTS];
    int cumulative_score;
    double percentage_ratio;
    char final_grade;
    char pass_status[5];
} AcademicRecord;


void evaluate_academic_metrics(AcademicRecord *profile);
void capture_new_record(AcademicRecord registry[], int *active_count);
void display_summary_matrix(const AcademicRecord registry[], int active_count);
void print_individual_marksheet(const AcademicRecord registry[], int active_count);

int main(void) {
    AcademicRecord classroom_db[MAX_STUDENTS];
    int total_enrolled = 0;
    int navigation_flag;

    do {
        printf("\n========================================");
        printf("\n    ACADEMIC MARKSHEET SYSTEM V2.4     ");
        printf("\n========================================");
        printf("\n 1. Register Student & Scores");
        printf("\n 2. View Performance Ledger Sheet");
        printf("\n 3. Generate Official Marksheet");
        printf("\n 4. Terminate Application");
        printf("\n========================================");
        printf("\nSelect Operations Protocol (1-4): ");
        
        if (scanf("%d", &navigation_flag) != 1) {
            printf("\nStream validation error. Exiting program.\n");
            break;
        }

        switch (navigation_flag) {
            case 1:
                capture_new_record(classroom_db, &total_enrolled);
                break;
            case 2:
                display_summary_matrix(classroom_db, total_enrolled);
                break;
            case 3:
                print_individual_marksheet(classroom_db, total_enrolled);
                break;
            case 4:
                printf("\nClosing academic database. Operations completed.\n");
                break;
            default:
                printf("\nInvalid operational index. Retry entry.\n");
        }
    } while (navigation_flag != 4);

    return 0;
}


void evaluate_academic_metrics(AcademicRecord *profile) {
    profile->cumulative_score = 0;
    int structural_fail = 0;

    for (int sub_idx = 0; sub_idx < TOTAL_SUBJECTS; sub_idx++) {
        profile->cumulative_score += profile->scores_achieved[sub_idx];
        
        if (profile->scores_achieved[sub_idx] < 40) {
            structural_fail = 1;
        }
    }

    profile->percentage_ratio = (double)profile->cumulative_score / TOTAL_SUBJECTS;

    
    if (profile->percentage_ratio >= 85.0) {
        profile->final_grade = 'A';
    } else if (profile->percentage_ratio >= 70.0) {
        profile->final_grade = 'B';
    } else if (profile->percentage_ratio >= 55.0) {
        profile->final_grade = 'C';
    } else if (profile->percentage_ratio >= 40.0) {
        profile->final_grade = 'D';
    } else {
        profile->final_grade = 'F';
        structural_fail = 1;
    }

    if (structural_fail) {
        strcpy(profile->pass_status, "FAIL");
    } else {
        strcpy(profile->pass_status, "PASS");
    }
}


void capture_new_record(AcademicRecord registry[], int *active_count) {
    if (*active_count >= MAX_STUDENTS) {
        printf("\nError: Central registry vector has reached peak load capacity.\n");
        return;
    }

    AcademicRecord node;
    int buffer_purge;

    printf("\nEnter Student Examination Roll Number: ");
    scanf("%d", &node.roll_number);
    
    
    while ((buffer_purge = getchar()) != '\n' && buffer_purge != EOF);

    printf("Enter Student Full Name: ");
    fgets(node.student_name, sizeof(node.student_name), stdin);
    node.student_name[strcspn(node.student_name, "\n")] = '\0'; 

    printf("Enter Academic Semester/Term: ");
    fgets(node.academic_term, sizeof(node.academic_term), stdin);
    node.academic_term[strcspn(node.academic_term, "\n")] = '\0';

    printf("\n--- Enter Scores for %d Core Subjects (Out of 100) ---\n", TOTAL_SUBJECTS);
    for (int mark_loop = 0; mark_loop < TOTAL_SUBJECTS; mark_loop++) {
        printf(" Subject Evaluation %d Score: ", mark_loop + 1);
        scanf("%d", &node.scores_achieved[mark_loop]);
        
        
        if (node.scores_achieved[mark_loop] < 0 || node.scores_achieved[mark_loop] > 100) {
            printf(" Out-of-bounds error. Restricting value to 0.\n");
            node.scores_achieved[mark_loop] = 0;
        }
    }

    
    evaluate_academic_metrics(&node);

    
    registry[*active_count] = node;
    (*active_count)++;

    printf("\nSuccess: Profile created for Roll No: %d\n", node.roll_number);
}


void display_summary_matrix(const AcademicRecord registry[], int active_count) {
    if (active_count == 0) {
        printf("\nNo data profiles indexed inside the local array.\n");
        return;
    }

    printf("\n%-10s %-25s %-12s %-10s %-10s %-8s", "Roll No", "Student Identity Name", "Term", "Total/500", "Percentage", "Outcome");
    printf("\n==================================================================================");
    
    for (int scan_idx = 0; scan_idx < active_count; scan_idx++) {
        printf("\n%-10d %-25s %-12s %-10d %-10.2f%% %-8s", 
               registry[scan_idx].roll_number, 
               registry[scan_idx].student_name, 
               registry[scan_idx].academic_term, 
               registry[scan_idx].cumulative_score, 
               registry[scan_idx].percentage_ratio, 
               registry[scan_idx].pass_status);
    }
    printf("\n==================================================================================\n");
}


void print_individual_marksheet(const AcademicRecord registry[], int active_count) {
    if (active_count == 0) {
        printf("\nQuery target unreachable. No operational data records found.\n");
        return;
    }

    int queried_roll;
    int matching_target = 0;

    printf("\nProvide Roll Number to generate formal marksheet: ");
    scanf("%d", &queried_roll);

    for (int trace_idx = 0; trace_idx < active_count; trace_idx++) {
        if (registry[trace_idx].roll_number == queried_roll) {
            matching_target = 1;
            printf("\n--------------------------------------------------");
            printf("\n         OFFICIAL ACADEMIC TRANSCRIPT REPORT       ");
            printf("\n--------------------------------------------------");
            printf("\n Roll Identification : %d", registry[trace_idx].roll_number);
            printf("\n Student Full Name   : %s", registry[trace_idx].student_name);
            printf("\n Term / Semester     : %s", registry[trace_idx].academic_term);
            printf("\n--------------------------------------------------");
            printf("\n SUBJECT EVALUATION SCORE LABELS (MAX: 100):");
            
            for (int sub_print = 0; sub_print < TOTAL_SUBJECTS; sub_print++) {
                printf("\n  - Subject Module Paper %d : %d / 100", 
                       sub_print + 1, registry[trace_idx].scores_achieved[sub_print]);
            }
            
            printf("\n..................................................");
            printf("\n AGGREGATE SUMMARY METRICS:");
            printf("\n  Total Score Earned  : %d out of 500", registry[trace_idx].cumulative_score);
            printf("\n  Calculated Ratio    : %.2f%%", registry[trace_idx].percentage_ratio);
            printf("\n  Assigned Class Grade: Rank [%c]", registry[trace_idx].final_grade);
            printf("\n--------------------------------------------------");
            printf("\n FINAL TERM OUTCOME  : %s", registry[trace_idx].pass_status);
            printf("\n--------------------------------------------------\n");
            break;
        }
    }

    if (!matching_target) {
        printf("\nQuery Error: Roll registration index %d could not be found.\n", queried_roll);
    }
}
