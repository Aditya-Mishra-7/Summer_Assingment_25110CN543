//Question-106 : Write a program to create employee management system.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAPACITY_LIMIT 120
#define TEXT_BOUND 60

typedef struct {
    int unique_id;
    char full_name[TEXT_BOUND];
    char unit_division[TEXT_BOUND];
    double earnings;
} StaffRecord;

void flush_input_buffer() {
    int character_tank;
    while ((character_tank = getchar()) != '\n' && character_tank != EOF);
}

int locate_staff_index(const StaffRecord registry[], int active_total, int target_id) {
    for (int cursor = 0; cursor < active_total; cursor++) {
        if (registry[cursor].unique_id == target_id) {
            return cursor; 
        }
    }
    return -1; 
}

void register_new_staff(StaffRecord registry[], int *active_total) {
    if (*active_total >= CAPACITY_LIMIT) {
        printf("[System Warning] Maximum database allocation volume achieved.\n");
        return;
    }

    int safe_id;
    printf("Assign Unique Identifier Code: ");
    if (scanf("%d", &safe_id) != 1) {
        printf("[Input Error] Digit evaluation failed.\n");
        flush_input_buffer();
        return;
    }
    flush_input_buffer();

    if (locate_staff_index(registry, *active_total, safe_id) != -1) {
        printf("[Execution Denied] Identifier conflict. Code already exists.\n");
        return;
    }

    registry[*active_total].unique_id = safe_id;

    printf("Input Staff Legal Name: ");
    fgets(registry[*active_total].full_name, TEXT_BOUND, stdin);
    registry[*active_total].full_name[strcspn(registry[*active_total].full_name, "\r\n")] = '\0';

    printf("Assign Departmental Division: ");
    fgets(registry[*active_total].unit_division, TEXT_BOUND, stdin);
    registry[*active_total].unit_division[strcspn(registry[*active_total].unit_division, "\r\n")] = '\0';

    printf("Set Standard Remuneration/Earnings: ");
    if (scanf("%lf", &registry[*active_total].earnings) != 1) {
        printf("[Input Error] Decimal assignment aborted.\n");
        flush_input_buffer();
        return;
    }
    flush_input_buffer();

    (*active_total)++;
    printf("[Success] Professional profile safely logged into registry.\n");
}

void display_profile_data(const StaffRecord registry[], int active_total) {
    int target_id;
    printf("Verify target identity code to inspect: ");
    scanf("%d", &target_id);
    flush_input_buffer();

    int position = locate_staff_index(registry, active_total, target_id);
    if (position == -1) {
        printf("[Lookup Error] Reference code not established.\n");
        return;
    }

    printf("\n=== PROFILE SHEET: ID %d ===\n", registry[position].unique_id);
    printf("Legal Name   : %s\n", registry[position].full_name);
    printf("Division Unit: %s\n", registry[position].unit_division);
    printf("Net Earnings : INR %.2f\n", registry[position].earnings);
    printf("=============================\n");
}

void reroute_division(StaffRecord registry[], int active_total) {
    int target_id;
    printf("Input target identification code: ");
    scanf("%d", &target_id);
    flush_input_buffer();

    int position = locate_staff_index(registry, active_total, target_id);
    if (position == -1) {
        printf("[Lookup Error] Employee mismatch.\n");
        return;
    }

    printf("Assign New Departmental Division: ");
    fgets(registry[position].unit_division, TEXT_BOUND, stdin);
    registry[position].unit_division[strcspn(registry[position].unit_division, "\r\n")] = '\0';

    printf("[Confirmed] Operational tracking transfer finalized for %s.\n", registry[position].full_name);
}

void recalculate_earnings(StaffRecord registry[], int active_total) {
    int target_id;
    double delta_adjustment;
    printf("Input target identification code: ");
    scanf("%d", &target_id);

    int position = locate_staff_index(registry, active_total, target_id);
    if (position == -1) {
        printf("[Lookup Error] System profile non-existent.\n");
        flush_input_buffer();
        return;
    }

    printf("Input modification margin value (Negative indicates penalty/deduction): ");
    if (scanf("%lf", &delta_adjustment) != 1) {
        printf("[Input Error] Modification aborted.\n");
        flush_input_buffer();
        return;
    }
    flush_input_buffer();

    registry[position].earnings += delta_adjustment;
    printf("[Confirmed] Remuneration adjusted. Revised base pay: INR %.2f\n", registry[position].earnings);
}

void purge_staff_record(StaffRecord registry[], int *active_total) {
    int target_id;
    printf("Enter specific ID designation to eliminate: ");
    scanf("%d", &target_id);
    flush_input_buffer();

    int position = locate_staff_index(registry, *active_total, target_id);
    if (position == -1) {
        printf("[Lookup Error] Target entry does not exist.\n");
        return;
    }

    for (int offset = position; offset < (*active_total) - 1; offset++) {
        registry[offset] = registry[offset + 1];
    }

    (*active_total)--;
    printf("[System Notice] Target registry file has been wiped successfully.\n");
}

int main() {
    StaffRecord enterprise_registry[CAPACITY_LIMIT];
    int current_workforce_count = 0;
    int system_selection;

    while (1) {
        printf("\n<<<< SYSTEM GATEWAY: STAFF TERMINAL >>>>\n");
        printf("[1] Initialize New Record\n");
        printf("[2] View Specific Employee Sheet\n");
        printf("[3] Modify Branch/Division Location\n");
        printf("[4] Restructure Wage Allocation\n");
        printf("[5] Terminate/Purge Employee Record\n");
        printf("[6] Shutdown Terminal Session\n");
        printf("----------------------------------------\n");
        printf("Action Prompt -> ");
        
        if (scanf("%d", &system_selection) != 1) {
            printf("[Alert] Non-integer command caught. Resetting input loop.\n");
            flush_input_buffer();
            continue;
        }

        switch (system_selection) {
            case 1: register_new_staff(enterprise_registry, &current_workforce_count); break;
            case 2: display_profile_data(enterprise_registry, current_workforce_count); break;
            case 3: reroute_division(enterprise_registry, current_workforce_count); break;
            case 4: recalculate_earnings(enterprise_registry, current_workforce_count); break;
            case 5: purge_staff_record(enterprise_registry, &current_workforce_count); break;
            case 6: 
                printf("[Shutdown] Terminating execution pipeline. Terminal Offline.\n");
                return 0;
            default: 
                printf("[Error Choice] Operational protocol unrecognized. Re-index.\n");
        }
    }
    return 0;
}
