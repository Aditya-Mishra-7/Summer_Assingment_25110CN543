//Question-107 : Write a program to create salary management system.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STAFF_SIZE 150
#define CHAR_CAP 60
#define ASSIGNED_TAX_RATE 0.14 

typedef struct {
    int staff_id_code;
    char designation_title[CHAR_CAP];
    char staff_full_name[CHAR_CAP];
    double base_remuneration;
    double accumulated_bonuses;
} CompensationLedger;

void absolute_stream_drain() {
    int byte_buffer;
    while ((byte_buffer = getchar()) != '\n' && byte_buffer != EOF);
}

int search_ledger_index(const CompensationLedger database[], int current_total, int search_id) {
    for (int offset = 0; offset < current_total; offset++) {
        if (database[offset].staff_id_code == search_id) {
            return offset;
        }
    }
    return -1;
}

void enroll_payroll_profile(CompensationLedger database[], int *current_total) {
    if (*current_total >= MAX_STAFF_SIZE) {
        printf("[Database Cap] Maximum allocation limits reached.\n");
        return;
    }

    int numeric_id;
    printf("Input Unique Personnel ID Code: ");
    if (scanf("%d", &numeric_id) != 1) {
        printf("[Format Error] Invalid identification key.\n");
        absolute_stream_drain();
        return;
    }
    absolute_stream_drain();

    if (search_ledger_index(database, *current_total, numeric_id) != -1) {
        printf("[Rejection] Entry blocked. Identity code already mapped.\n");
        return;
    }

    database[*current_total].staff_id_code = numeric_id;

    printf("Input Employee Full Name: ");
    fgets(database[*current_total].staff_full_name, CHAR_CAP, stdin);
    database[*current_total].staff_full_name[strcspn(database[*current_total].staff_full_name, "\r\n")] = '\0';

    printf("Input Corporate Designation: ");
    fgets(database[*current_total].designation_title, CHAR_CAP, stdin);
    database[*current_total].designation_title[strcspn(database[*current_total].designation_title, "\r\n")] = '\0';

    printf("Set Standard Base Salary: ");
    if (scanf("%lf", &database[*current_total].base_remuneration) != 1) {
        printf("[Format Error] Execution aborted due to bad float formatting.\n");
        absolute_stream_drain();
        return;
    }
    absolute_stream_drain();

    database[*current_total].accumulated_bonuses = 0.0;
    (*current_total)++;
    printf("[System Success] New ledger account securely generated.\n");
}

void credit_allowance_bonus(CompensationLedger database[], int current_total) {
    int numerical_key;
    printf("Verify target employee identity code: ");
    scanf("%d", &numerical_key);
    absolute_stream_drain();

    int lookup_pos = search_ledger_index(database, current_total, numerical_key);
    if (lookup_pos == -1) {
        printf("[Lookup Failure] Staff record not established in database.\n");
        return;
    }

    double added_incentive;
    printf("Enter supplemental allowance allocation amount: ");
    if (scanf("%lf", &added_incentive) != 1) {
        printf("[Format Error] Injection aborted.\n");
        absolute_stream_drain();
        return;
    }
    absolute_stream_drain();

    database[lookup_pos].accumulated_bonuses += added_incentive;
    printf("[System Success] Added allowance allocated. Updated total bonuses: INR %.2f\n", 
           database[lookup_pos].accumulated_bonuses);
}

void generate_accounting_slip(const CompensationLedger database[], int current_total) {
    int numerical_key;
    printf("Enter identity code to print pay slip: ");
    scanf("%d", &numerical_key);
    absolute_stream_drain();

    int lookup_pos = search_ledger_index(database, current_total, numerical_key);
    if (lookup_pos == -1) {
        printf("[Lookup Failure] Target profile trace missing.\n");
        return;
    }

    double gross_aggregate = database[lookup_pos].base_remuneration + database[lookup_pos].accumulated_bonuses;
    double tax_withholding = gross_aggregate * ASSIGNED_TAX_RATE;
    double true_net_disbursement = gross_aggregate - tax_withholding;

    printf("\n############################################\n");
    printf("          OFFICIAL STATEMENT OF EARNINGS       \n");
    printf("############################################\n");
    printf("Account Reference Code : %d\n", database[lookup_pos].staff_id_code);
    printf("Legal Recipient Full   : %s\n", database[lookup_pos].staff_full_name);
    printf("Designation Assignment : %s\n", database[lookup_pos].designation_title);
    printf("--------------------------------------------\n");
    printf("Base Earnings Baseline : INR %.2f\n", database[lookup_pos].base_remuneration);
    printf("Extra Corporate Bonus  : INR %.2f\n", database[lookup_pos].accumulated_bonuses);
    printf("Gross Evaluated Total  : INR %.2f\n", gross_aggregate);
    printf("Tax Withheld (%d%%)     : INR %.2f\n", (int)(ASSIGNED_TAX_RATE * 100), tax_withholding);
    printf("--------------------------------------------\n");
    printf("NET PAYOUT AMOUNT      : INR %.2f\n", true_net_disbursement);
    printf("############################################\n");
}

void display_total_corporate_outflow(const CompensationLedger database[], int current_total) {
    double total_outflow_sum = 0.0;
    
    for (int idx = 0; idx < current_total; idx++) {
        double gross = database[idx].base_remuneration + database[idx].accumulated_bonuses;
        double tax = gross * ASSIGNED_TAX_RATE;
        total_outflow_sum += (gross - tax);
    }
    printf("\n>>> Net Corporate Expenditure Summary (Total Outflow): INR %.2f <<<\n", total_outflow_sum);
}

int main() {
    CompensationLedger institutional_vault[MAX_STAFF_SIZE];
    int operational_record_count = 0;
    int interactive_token_choice;

    while (1) {
        printf("\n==== FINANCIAL PORTAL: PAYROLL MANAGEMENT ====\n");
        printf(" 1. Setup Employee Financial Account\n");
        printf(" 2. Allocate Allowance Bonus\n");
        printf(" 3. Print Detailed Earnings Slip\n");
        printf(" 4. View Net Corporate Expenditures\n");
        printf(" 5. Disconnect Financial Terminal\n");
        printf("==============================================\n");
        printf("Selection Console Command -> ");

        if (scanf("%d", &interactive_token_choice) != 1) {
            printf("[Alert] Non-integer option detected. Refreshing loop pipeline.\n");
            absolute_stream_drain();
            continue;
        }

        switch (interactive_token_choice) {
            case 1: enroll_payroll_profile(institutional_vault, &operational_record_count); break;
            case 2: credit_allowance_bonus(institutional_vault, operational_record_count); break;
            case 3: generate_accounting_slip(institutional_vault, operational_record_count); break;
            case 4: display_total_corporate_outflow(institutional_vault, operational_record_count); break;
            case 5:
                printf("[Shutdown] Port session disconnected safely. Gateway offline.\n");
                return 0;
            default:
                printf("[Execution Error] Directive unknown. Restructure input path.\n");
        }
    }
    return 0;
}
