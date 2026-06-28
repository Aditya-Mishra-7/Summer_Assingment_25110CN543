// Question-107 : Write a program to create salary management system.
#include <stdio.h>
#include <string.h>

#define CAPACITY_LIMIT 75

typedef struct {
    int staff_uid;
    char full_name[60];
    char post_title[40];
    double base_income;
    double rent_allowance;
    double dearness_allowance;
    double fund_deduction;
    double govt_tax;
    double total_gross;
    double net_takehome;
} PayrollRecord;

void run_payroll_math(PayrollRecord *individual);
void register_new_staff(PayrollRecord database[], int *current_size);
void view_summary_sheet(const PayrollRecord database[], int current_size);
void output_single_stub(const PayrollRecord database[], int current_size);

int main(void) {
    PayrollRecord enterprise_db[CAPACITY_LIMIT];
    int total_registered = 0;
    int admin_action;

    do {
        printf("\n========================================");
        printf("\n   ENTERPRISE PAYROLL SYSTEM CORE V1    ");
        printf("\n========================================");
        printf("\n [1] Enroll New Personnel Record");
        printf("\n [2] Render Global Earnings Spreadsheet");
        printf("\n [3] Extract Isolated Pay Stub Report");
        printf("\n [4] Terminate System Terminal");
        printf("\n========================================");
        printf("\nExecute Command Choice (1-4): ");
        
        if (scanf("%d", &admin_action) != 1) {
            printf("\nInput stream corrupted. Halting.\n");
            break;
        }

        switch (admin_action) {
            case 1:
                register_new_staff(enterprise_db, &total_registered);
                break;
            case 2:
                view_summary_sheet(enterprise_db, total_registered);
                break;
            case 3:
                output_single_stub(enterprise_db, total_registered);
                break;
            case 4:
                printf("\nReleasing system resources. Session ended.\n");
                break;
            default:
                printf("\nCommand sequence unrecognized. Re-enter selection.\n");
        }
    } while (admin_action != 4);

    return 0;
}

void run_payroll_math(PayrollRecord *individual) {
    
    individual->rent_allowance = individual->base_income * 0.18;      
    individual->dearness_allowance = individual->base_income * 0.22;  
    individual->fund_deduction = individual->base_income * 0.11;      
    
    individual->total_gross = individual->base_income + individual->rent_allowance + individual->dearness_allowance;
    
    
    if (individual->total_gross >= 65000.0) {
        individual->govt_tax = individual->total_gross * 0.12;       
    } else if (individual->total_gross >= 35000.0) {
        individual->govt_tax = individual->total_gross * 0.07;       
    } else {
        individual->govt_tax = individual->total_gross * 0.02;       
    }
    
    individual->net_takehome = individual->total_gross - (individual->fund_deduction + individual->govt_tax);
}


void register_new_staff(PayrollRecord database[], int *current_size) {
    if (*current_size >= CAPACITY_LIMIT) {
        printf("\nError: Central registry threshold reached.\n");
        return;
    }

    PayrollRecord profile;
    int clear_buffer;

    printf("\nAssign Personnel Unique ID (Numeric): ");
    scanf("%d", &profile.staff_uid);
    
    
    while ((clear_buffer = getchar()) != '\n' && clear_buffer != EOF);

    printf("Assign Legal Full Name: ");
    fgets(profile.full_name, sizeof(profile.full_name), stdin);
    profile.full_name[strcspn(profile.full_name, "\n")] = '\0'; 

    printf("Assign Employment Assignment Title: ");
    fgets(profile.post_title, sizeof(profile.post_title), stdin);
    profile.post_title[strcspn(profile.post_title, "\n")] = '\0';

    printf("Assign Initial Monthly Contract Base Pay: ");
    scanf("%lf", &profile.base_income);


    run_payroll_math(&profile);

    
    database[*current_size] = profile;
    (*current_size)++;

    printf("\nSuccess: Profile saved securely under UID Reference %d.\n", profile.staff_uid);
}


void view_summary_sheet(const PayrollRecord database[], int current_size) {
    if (current_size == 0) {
        printf("\nRegistry matrix is empty. No tracking nodes available.\n");
        return;
    }

    printf("\n%-6s %-22s %-18s %-12s %-12s %-12s", "UID", "Employee Name", "Department/Post", "Base Pay", "Gross Pay", "Net Pay");
    printf("\n=====================================================================================");
    
    for (int tracking_idx = 0; tracking_idx < current_size; tracking_idx++) {
        printf("\n%-6d %-22s %-18s %-12.2f %-12.2f %-12.2f", 
               database[tracking_idx].staff_uid, 
               database[tracking_idx].full_name, 
               database[tracking_idx].post_title, 
               database[tracking_idx].base_income, 
               database[tracking_idx].total_gross, 
               database[tracking_idx].net_takehome);
    }
    printf("\n=====================================================================================\n");
}


void output_single_stub(const PayrollRecord database[], int current_size) {
    if (current_size == 0) {
        printf("\nRegistry lookup failed. Database is empty.\n");
        return;
    }

    int targeted_uid;
    int target_discovered = 0;

    printf("\nProvide System UID to print earnings slip: ");
    scanf("%d", &targeted_uid);

    for (int locator = 0; locator < current_size; locator++) {
        if (database[locator].staff_uid == targeted_uid) {
            target_discovered = 1;
            printf("\n------------------------------------------------");
            printf("\n         OFFICIAL STATEMENT OF EARNINGS         ");
            printf("\n------------------------------------------------");
            printf("\n Staff UID Code    : %d", database[locator].staff_uid);
            printf("\n Identity Name     : %s", database[locator].full_name);
            printf("\n Active Assignment : %s", database[locator].post_title);
            printf("\n................................................");
            printf("\n CREDITED INCOME FLOWS:");
            printf("\n  + Agreed Base Payment   : INR %.2f", database[locator].base_income);
            printf("\n  + HRA Rent Allowance    : INR %.2f", database[locator].rent_allowance);
            printf("\n  + DA Welfare Allowance  : INR %.2f", database[locator].dearness_allowance);
            printf("\n  = RENDERED GROSS PAY    : INR %.2f", database[locator].total_gross);
            printf("\n................................................");
            printf("\n DEBITED FISCAL LIABILITIES:");
            printf("\n  - Co-Investment Fund    : INR %.2f", database[locator].fund_deduction);
            printf("\n  - Professional Income Tax: INR %.2f", database[locator].govt_tax);
            printf("\n------------------------------------------------");
            printf("\n DISBURSED NET TAKE-HOME  : INR %.2f", database[locator].net_takehome);
            printf("\n------------------------------------------------\n");
            break;
        }
    }

    if (!target_discovered) {
        printf("\nQuery Error: Record identifier %d does not match active records.\n", targeted_uid);
    }
}
