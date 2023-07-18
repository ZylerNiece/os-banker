//*********************************************************
//
// Zyler Niece
// Operating Systems
// Bankers Algorithm
// April 17, 2023
// Instuctor: Dr. Michael Scherger
//*********************************************************

//*********************************************************
//
// Includes and Defines
//
//*********************************************************
#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 1024
#define MAX_RESOURCES 26


//*********************************************************
//
// Extern Declarations
//
//*********************************************************
//Struct for BankersAlgorithm
typedef struct {
    int n, m;
    int resource_vector[MAX_RESOURCES];
    int available_vector[MAX_RESOURCES];
    int max_matrix[MAX_PROCESSES][MAX_RESOURCES];
    int allocation_matrix[MAX_PROCESSES][MAX_RESOURCES];
    int need_matrix[MAX_PROCESSES][MAX_RESOURCES];
    int request_process;
    int request_vector[MAX_RESOURCES];
} BankersAlgorithm;

//*********************************************************
//
// Function Prototypes
//
//*********************************************************

//*********************************************************
// initialize
//
// This function initializes a BankersAlgorithm struct with the
// given values for n, m, resource_vector, available_vector,
// max_matrix, allocation_matrix, request_process, and
// request_vector. It copies these values into the appropriate
// fields of the struct.
//
// Return Value
// --------------
// N/A - Void method
//
// Function Parameters
// -------------------
// bankers BankersAlgorithm * pointer to a BankersAlgorithm struct to be initialized
// n int number of processes
// m int number of resource types
// resource_vector int[] array of number of units of each resource type in the system
// available_vector int[] array of number of units of each resource type currently available
// max_matrix int[][] matrix of maximum number of units of each resource type that each process can request
// allocation_matrix int[][] matrix of number of units of each resource type currently allocated to each process
// request_process int index of the process requesting resources
// request_vector int[] array of number of units of each resource type requested by the process
//
// Local Variables
// ----------------
// i int index variable
// j int index variable
//
//*********************************************************

//*********************************************************
// compute_need_matrix
//
// This function computes the need_matrix for a given BankersAlgorithm
// struct. It subtracts the allocation_matrix from the max_matrix
// element-wise and stores the result in need_matrix.
//
// Return Value
// --------------
// N/A - Void method
//
// Function Parameters
// -------------------
// bankers BankersAlgorithm * pointer to a BankersAlgorithm struct for which to compute the need matrix
//
// Local Variables
// ----------------
// i int index variable
// j int index variable
//
//*********************************************************

//*********************************************************
// is_safe
//
// This function determines if a given BankersAlgorithm struct is
// in a safe state. It implements the Banker's algorithm by using a
// work array to simulate resource allocation, and a finish array
// to keep track of which processes have finished executing. The
// function repeatedly loops through all the processes until no
// more processes can be allocated the resources they need, or
// until all processes have finished executing. If all processes
// can be allocated the resources they need, the function returns
// true; otherwise, it returns false.
//
// Return Value
// --------------
// bool - true if the system is in a safe state, false otherwise
//
// Function Parameters
// -------------------
// bankers BankersAlgorithm * pointer to a BankersAlgorithm struct to check for safety
//
// Local Variables
// ----------------
// work int[] array of number of units of each resource type available for allocation
// finish bool[] array of flags indicating whether each process has finished executing
// i int index variable
// j int index variable
// can_allocate bool flag indicating whether the current process can be allocated the resources it needs
//
//*********************************************************

//*********************************************************
// can_grant_request
//
// This function determines if a given BankersAlgorithm struct can
// grant a request for additional resources by a process. It creates
// a copy of the original struct with the requested resources allocated
// to the requesting process, and then checks if the resulting system
// is in a safe state by calling the is_safe function. If the system
// is in a safe state, the function returns true; otherwise, it returns
// false.
//
// Return Value
// --------------
// bool - true if the request can be granted, false otherwise
//
// Function Parameters
// -------------------
// bankers BankersAlgorithm* pointer to the struct representing the current state of the system
//
// Local Variables
// ----------------
// temp_available int[] temporary array for available resources
// temp_allocation int[][] temporary array for allocation matrix
// temp_need int[][] temporary array for need matrix
// temp_bankers BankersAlgorithm temporary struct for the modified state of the system
//
//*********************************************************

//*********************************************************
// grant_request
//
// This function updates the BankersAlgorithm struct to reflect the
// allocation of additional resources to a process. It subtracts the
// requested resources from the available resources, adds them to
// the allocation matrix for the requesting process, and updates
// the need matrix for the requesting process accordingly.
//
// Return Value
// --------------
// N/A - Void method
//
// Function Parameters
// -------------------
// bankers BankersAlgorithm* pointer to the struct representing the current state of the system
//
// Local Variables
// ----------------
// N/A
//
//*********************************************************

//*********************************************************
// print_matrices
//
// This function prints the contents of the BankersAlgorithm struct
// to the console, including the resource vector, available vector,
// max matrix, allocation matrix, and need matrix.
//
// Return Value
// --------------
// N/A - Void method
//
// Function Parameters
// -------------------
// bankers BankersAlgorithm* pointer to the struct representing the current state of the system
//
// Local Variables
// ----------------
// N/A
//
//*********************************************************

//*********************************************************
// main
//
// The main function reads input from a file and initializes the
// BankersAlgorithm struct with the appropriate values. It then calls
// the is_safe function to check if the current state of the system is
// safe. If it is, it prompts the user for a process and a request vector
// and checks if the request can be granted by calling the can_grant_request
// function. If the request can be granted, it calls the grant_request function
// to update the state of the system and prints the updated matrices. If
// the request cannot be granted, it prints a message indicating that the
// request cannot be granted. If the system is not safe, it prints a message
// indicating that the system is not in a safe state.
//
// Return Value
// --------------
// int - returns 0 to indicate successful completion of the program
//
// Function Parameters
// -------------------
// argc int number of command line arguments
// argv char** array of command line argument strings
//
// Local Variables
// ----------------
// input_filename char* stores the name of the input file
// file FILE* pointer to the input file
// n int number of processes in the system
// m int number of resource types in the system
// resource_vector int[] array of total resources of each type in the system
// available_vector int[] array of available resources of each type in the system
// max_matrix int[][] maximum demand of each process for each resource type
// allocation_matrix int[][] amount of each resource type allocated to each process
// request_process int ID of the process requesting additional resources
// request_vector int[] array of the additional resources requested by the process
// bankers BankersAlgorithm struct representing the current state of the system
//
//*********************************************************


void initialize(BankersAlgorithm *bankers, int n, int m, int resource_vector[], int available_vector[], int max_matrix[][MAX_RESOURCES], int allocation_matrix[][MAX_RESOURCES], int request_process, int request_vector[]) {
    // Set the number of processes and number of resources in the bankers struct
    bankers->n = n;
    bankers->m = m;

    // Copy the resource_vector, available_vector, and request_vector into the bankers struct
    for (int i = 0; i < m; i++) {
        bankers->resource_vector[i] = resource_vector[i];
        bankers->available_vector[i] = available_vector[i];
        bankers->request_vector[i] = request_vector[i];
    }

    // Copy the max_matrix and allocation_matrix into the bankers struct using nested for loops
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bankers->max_matrix[i][j] = max_matrix[i][j];
            bankers->allocation_matrix[i][j] = allocation_matrix[i][j];
        }
    }

    // Set the process requesting a resource in the bankers struct
    bankers->request_process = request_process;
}

void compute_need_matrix(BankersAlgorithm *bankers) {
    // Iterate through each process and resource and calculate the need for each process
    for (int i = 0; i < bankers->n; i++) {
        for (int j = 0; j < bankers->m; j++) {
            // The need for a process is the maximum it could request minus what it currently has
            bankers->need_matrix[i][j] = bankers->max_matrix[i][j] - bankers->allocation_matrix[i][j];
        }
    }
}

bool is_safe(BankersAlgorithm *bankers) {
    // Initialize work array and finish array
    int work[MAX_RESOURCES];
    bool finish[MAX_PROCESSES] = {false};

    // Set work array to available resources
    for (int i = 0; i < bankers->m; i++) {
        work[i] = bankers->available_vector[i];
    }

    bool done = false;
    while (!done) {
        // Set done to true; if any process is not finished, then it is set to false in the loop
        done = true;

        // Iterate through each process and check if it can be allocated resources
        for (int i = 0; i < bankers->n; i++) {
            // Initialize can_allocate to true if the process is not yet finished
            bool can_allocate = !finish[i];
            for (int j = 0; j < bankers->m && can_allocate; j++) {
                // Check if the process can be allocated the necessary resources
                can_allocate = can_allocate && (bankers->need_matrix[i][j] <= work[j]);
            }

            // If the process can be allocated resources, mark it as finished and add the resources to the work array
            if (can_allocate) {
                for (int j = 0; j < bankers->m; j++) {
                    work[j] += bankers->allocation_matrix[i][j];
                }
                finish[i] = true;
                done = false;
            }
        }
    }

    // If all processes are finished, then the system is in a safe state
    for (int i = 0; i < bankers->n; i++) {
        if (!finish[i]) {
            return false;
        }
    }
    return true;
}

bool can_grant_request(BankersAlgorithm *bankers) {
    // Initialize temporary arrays to hold the state of the system after the request is granted
    int temp_available[MAX_RESOURCES];
    int temp_allocation[MAX_PROCESSES][MAX_RESOURCES];
    int temp_need[MAX_PROCESSES][MAX_RESOURCES];

    // Check if the request can be granted
    for (int i = 0; i < bankers->m; i++) {
        if (bankers->request_vector[i] > bankers->need_matrix[bankers->request_process][i] || bankers->request_vector[i] > bankers->available_vector[i]) {
            return false;
        }
        temp_available[i] = bankers->available_vector[i] - bankers->request_vector[i];
    }

    // Update the temporary allocation and need matrices based on the granted request
    for (int i = 0; i < bankers->n; i++) {
        for (int j = 0; j < bankers->m; j++) {
            if (i == bankers->request_process) {
                temp_allocation[i][j] = bankers->allocation_matrix[i][j] + bankers->request_vector[j];
                temp_need[i][j] = bankers->need_matrix[i][j] - bankers->request_vector[j];
            } else {
                temp_allocation[i][j] = bankers->allocation_matrix[i][j];
                temp_need[i][j] = bankers->need_matrix[i][j];
            }
        }
    }

    // Initialize a temporary bankers struct and compute the need matrix for the temporary state
    BankersAlgorithm temp_bankers;
    initialize(&temp_bankers, bankers->n, bankers->m, bankers->resource_vector, temp_available, bankers->max_matrix, temp_allocation, bankers->request_process, bankers->request_vector);
    compute_need_matrix(&temp_bankers);

    // Check if the temporary state is safe using the Banker's algorithm
    return is_safe(&temp_bankers);
}

void grant_request(BankersAlgorithm *bankers) {
    // Update the available, allocation, and need matrices based on the granted request
    for (int i = 0; i < bankers->m; i++) {
        // Subtract the requested resources from the available vector
        bankers->available_vector[i] -= bankers->request_vector[i];
        // Add the requested resources to the allocation matrix for the requesting process
        bankers->allocation_matrix[bankers->request_process][i] += bankers->request_vector[i];
        // Subtract the requested resources from the need matrix for the requesting process
        bankers->need_matrix[bankers->request_process][i] -= bankers->request_vector[i];
    }
}

void print_matrices(BankersAlgorithm *bankers) {
    // Print information about the system
    printf("There are %d processes and %d resource types in the system.\n\n", bankers->n, bankers->m);

    // Print the Resource Vector
    printf("The Resource Vector is...\n");
    for (int i = 0; i < bankers->m; i++) {
        printf("%c ", 'A' + i);
    }
    printf("\n");
    for (int i = 0; i < bankers->m; i++) {
        printf("%d ", bankers->resource_vector[i]);
    }
    printf("\n\n");

    // Print the Available Vector
    printf("The Available Vector is...\n");
    for (int i = 0; i < bankers->m; i++) {
        printf("%c ", 'A' + i);
    }
    printf("\n");
    for (int i = 0; i < bankers->m; i++) {
        printf("%d ", bankers->available_vector[i]);
    }
    printf("\n\n");

    // Print the Max Matrix
    printf("The Max Matrix is...\n   ");
    for (int i = 0; i < bankers->m; i++) {
        printf("%c ", 'A' + i);
    }
    printf("\n");
    for (int i = 0; i < bankers->n; i++) {
        printf("%d: ", i);
        for (int j = 0; j < bankers->m; j++) {
            printf("%d ", bankers->max_matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Print the Allocation Matrix
    printf("The Allocation Matrix is...\n   ");
    for (int i = 0; i < bankers->m; i++) {
        printf("%c ", 'A' + i);
    }
    printf("\n");
    for (int i = 0; i < bankers->n; i++) {
        printf("%d: ", i);
        for (int j = 0; j < bankers->m; j++) {
            printf("%d ", bankers->allocation_matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Print the Need Matrix
    printf("The Need Matrix is...\n   ");
    for (int i = 0; i < bankers->m; i++) {
        printf("%c ", 'A' + i);
    }
    printf("\n");
    for (int i = 0; i < bankers->n; i++) {
        printf("%d: ", i);
        for (int j = 0; j < bankers->m; j++) {
            printf("%d ", bankers->need_matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    // Check if the user provided an input file
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    // Open the input file
    char *input_filename = argv[1];
    FILE *file = fopen(input_filename, "r");
    if (!file) {
        printf("Error: Unable to open input file.\n");
        return 1;
    }

    // Read the input file and initialize the BankersAlgorithm struct
    int n, m;
    fscanf(file, "%d %d", &n, &m);

    int resource_vector[MAX_RESOURCES];
    int available_vector[MAX_RESOURCES];
    int max_matrix[MAX_PROCESSES][MAX_RESOURCES];
    int allocation_matrix[MAX_PROCESSES][MAX_RESOURCES];

    // Read in the Resource Vector
    for (int i = 0; i < m; i++) {
        fscanf(file, "%d", &resource_vector[i]);
    }

    // Read in the Available Vector
    for (int i = 0; i < m; i++) {
        fscanf(file, "%d", &available_vector[i]);
    }

    // Read in the Max Matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fscanf(file, "%d", &max_matrix[i][j]);
        }
    }

    // Read in the Allocation Matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fscanf(file, "%d", &allocation_matrix[i][j]);
        }
    }

    // Read in the Request Vector
    int request_process;
    int request_vector[MAX_RESOURCES];
    fscanf(file, "%d:", &request_process);
    for (int i = 0; i < m; i++) {
        fscanf(file, "%d", &request_vector[i]);
    }

    fclose(file);

    // Initialize the BankersAlgorithm struct and compute the Need Matrix
    BankersAlgorithm bankers;
    initialize(&bankers, n, m, resource_vector, available_vector, max_matrix, allocation_matrix, request_process, request_vector);
    compute_need_matrix(&bankers);

    // Print out the initial state of the system
    print_matrices(&bankers);

    // Check if the system is in a safe state
    if (is_safe(&bankers)) {
        printf("THE SYSTEM IS IN A SAFE STATE\n\n");

        // Print out the Request Vector
        printf("The Request Vector is...\n  ");
        for (int i = 0; i < m; i++) {
            printf("%c ", 'A' + i);
        }
        printf("\n%d:", request_process);
        for (int i = 0; i < m; i++) {
            printf("%d ", request_vector[i]);
        }
        printf("\n\n");

        // Check if the request can be granted
        if (can_grant_request(&bankers)) {
            printf("THE REQUEST CAN BE GRANTED: NEW STATE FOLLOWS\n\n");
            // Grant the request and print out the new state of the system
            grant_request(&bankers);
            print_matrices(&bankers);
        } else {
            printf("THE REQUEST CANNOT BE GRANTED\n");
        }
    } else {
        printf("THE SYSTEM IS NOT IN A SAFE STATE\n");
    }

    return 0;
}