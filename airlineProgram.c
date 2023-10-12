// (Airline Reservations System) A small airline has just purchased a computer for its new automated reservations system. The president has asked you to program the new system. You’ll write a program to assign seats on each flight of the airline’s only plane (capacity: 10 seats).

// Your program should display the following menu of alternatives:

// Please type 1 for "first class"
// Please type 2 for "economy"

// If the person types 1, then your program should assign a seat in the first class section (seats 1–5). If the person types 2, then your program should assign a seat in the economy section (seats 6–10). Your program should then print a boarding pass indicating the person's seat number and whether it’s in the first class or economy section of the plane.

// Use a one-dimensional array to represent the seating chart of the plane. Initialize all the elements of the array to 0 to indicate that all seats are empty. As each seat is assigned, set the corresponding element of the array to 1 to indicate that the seat is no longer available.

// Your program should, of course, never assign a seat that has already been assigned. When the first class section is full, your program should ask the person if it’s acceptable to be placed in the economy section (and vice versa). If yes, then make the appropriate seat assignment. If no, then print the message "Next flight leaves in 3 hours."

#include <stdio.h>
// define array sizes
#define FIRSTCLASS 5
#define ECONOMY 5
// function prototypes
int seatsFull(int arr[], int size);
void printPlaneLayout(int planeLayoutF[], int planeLayoutE[]);
int assignSeatF(int planeLayoutF[], int size, int seat);
int assignSeatE(int planeLayoutE[], int sizeF, int sizeE, int seat);

int main(void)
{
    // definition of variables. Initializing the Array for First Class seating and Economy seating. These can be set manually
    char answer;
    int seat;
    int planeLayoutF[FIRSTCLASS] = {1, 1, 0, 1, 1};
    int planeLayoutE[ECONOMY] = {1, 1, 1, 1, 1};
    // printing the instructions to the user, and accepting input via the "answer" variable in the scanf method
    printf("Welcome to the Airline Reservation System.\n\nPlease Type 1 for 'first class'\nPlease Type 2 for 'economy'\n");
    scanf(" %c", &answer);
    // if statement accounts for if the user inputs something other than a '1' or '2'. If so, we return Invalid choice and exit the program. 
    if (answer != '1' && answer != '2')
    {
        printf("Invalid choice.\n");
        return 0;
    }
    // if statement accounts for whether the seats are full. If they are full, program prints an explaination and exits the program.
    if (seatsFull(planeLayoutF, FIRSTCLASS) && seatsFull(planeLayoutE, ECONOMY))
    {
        printf("All flights are currently booked. Next flight leaves in three hours. Goodbye.");
        return 0;
    }
    // we use a switch statement to account for the user enters a '1' for the answer variable. 
    switch (answer)
    {
    case '1':
        // if statement accounting for if first class seating is full. We use the seatsFull method to check this. If it is full, the user has an option to book an economy flight via the acceptEconomy scanf variable. 
        if (seatsFull(planeLayoutF, FIRSTCLASS))
        {
            printf("First Class is full. Would you like to book an economy ticket?\nPress 1 for Yes, 2 for No\n");
            char acceptEconomy;
            scanf(" %c", &acceptEconomy);
            // we use a nested switch statement to account for the acceptEconomy option
            switch (acceptEconomy)
            {
            // if the user enters 1, we use the assignSeatE function to assign the seat in the planeLayoutE array, and print the neccessary ticketing information for economy ticketing. We then use the printPlaneLayout to provide the user with the visual representation of the airplane seating. We then exit the program since the user has been ticketed.    
            case '1':
                assignSeatE(planeLayoutE, FIRSTCLASS, ECONOMY, seat);
                printPlaneLayout(planeLayoutF, planeLayoutE);
                return 0;
            // if the user enters 2, they do not wish to be ticketed. We print out a message and end the program.
            case '2':
                printf("We are sorry we could not accomedate your travel needs. Next flight leaves in three hours. Goodbye.");
                return 0;

            default:
                printf("Invalid Entry\n");
                return 0;
            }
        }
        // we use the assignSeatF function to assign the seat in the planeLayoutF array, and print the neccessary ticketing information for first class ticketing. We then use the printPlaneLayout to provide the user with the visual representation of the airplane seating. We then exit the program since the user has been ticketed. 
        assignSeatF(planeLayoutF, FIRSTCLASS, seat);
        printPlaneLayout(planeLayoutF, planeLayoutE);
        break;
    // case 2 in the switch statement occurs when the user iputs the char '2' for the answer variable.
    case '2':
        // if statement accounting for if economy seating is full. We use the seatsFull method to check this. If it is full, the user has an option to book a first class flight via the acceptFirstClass scanf variable.  
        if (seatsFull(planeLayoutE, ECONOMY))
        {
            printf("Economy is at full capacity. Would you like to book a first class ticket?\nPress 1 for Yes, 2 for No\n");
            char acceptFirstClass;
            scanf(" %c", &acceptFirstClass);
            switch (acceptFirstClass)
            {
            case '1':
            // if the user enters 1, we use the assignSeatF function to assign the seat in the planeLayoutF array, and print the neccessary ticketing information for first class ticketing. We then use the printPlaneLayout to provide the user with the visual representation of the airplane seating. We then exit the program since the user has been ticketed. 
                assignSeatF(planeLayoutF, FIRSTCLASS, seat);
                printPlaneLayout(planeLayoutF, planeLayoutE);
                return 0;
            // if the user enters 2, they do not wish to be ticketed. We print out a message and end the program.
            case '2':
                printf("We are sorry we could not accomedate your travel needs. Next flight leaves in three hours. Goodbye.");
                return 0;

            default:
                printf("Invalid Entry");
                return 0;
            }
        }
        // we use the assignSeatE function to assign the seat in the planeLayoutE array, and print the neccessary ticketing information for economy ticketing. We then use the printPlaneLayout to provide the user with the visual representation of the airplane seating. We then exit the program since the user has been ticketed. 
        assignSeatE(planeLayoutE, FIRSTCLASS, ECONOMY, seat);
        printPlaneLayout(planeLayoutF, planeLayoutE);
        break;

    default:
        printf("Invalid Choice\n");
        break;
    }
}
// this function takes arguments of array (either planeLayoutE array or planeLayoutF array), and the size, which is either the FIRSTCLASS or ECONOMY array sizes.
int seatsFull(int arr[], int size)
{
    // we loop through the array values, checking to see if the values do not equal 1. If there are values that do not equal 1, we return 0, which means not all seats are full. If we do return 1, all seats are full. 
    for (int i = 0; i < size; i++)
    {
        if (arr[i] != 1)
        {
            return 0; // all seats are not full.
        }
    }
    return 1; // all seats are full.
}
// this function is designed specifically for assigning first class seating. It takes arguments of array(planelayout), size (FIRSTCLASS or ECONOMY), and seat. Taking parameter seat here allows us to print the Bording pass at the end of the statement using the seat variable. 
int assignSeatF(int planeLayoutF[], int size, int seat)
{
    // we loop through array values in the FIRSTCLASS. If there is a '0' in the array, we assign a '1' to the spot. This tickets the passanger. We also assign seat to the array value + 1 in order to assign the seat to make sense for the passanger (since array values start at 0).
    for (int i = 0; i < size; ++i)
    {
        if (planeLayoutF[i] == 0)
        {
            seat = i + 1;
            planeLayoutF[i] = 1;
        }
    }
    // printing the boarding pass and seat number.
    printf("Boarding Pass:\nYour seat number is %d\nYou are flying First Class\n", seat);
}
//this function is designed specifically for assigning economy class seating. It takes arguments of array(planelayout), sizeF(designed for FIRSTCLASS input), and sizeE(designed for ECONOMY input), and seat. Note the difference in equation between assignSeatF and assignSeatE. assignSeatE adds the sizeF (or FIRSTCLASS) size in order to assign the correct seat number. Also, taking parameter seat here allows us to print the Bording pass at the end of the statement using the seat variable.
int assignSeatE(int planeLayoutE[], int sizeF, int sizeE, int seat)
{
    for (int j = 0; j < sizeE; ++j)
    {
        if (planeLayoutE[j] == 0)
        {
            seat = j + 1 + sizeF;
            planeLayoutE[j] = 1;
        }
    }
    // printing the boarding pass and seat number.
    printf("Boarding Pass:\nYour seat number is %d\nYou are flying Economy\n\n", seat);
}
// this function is designed to print the plan layout in tabular format. It first prints First Class in the header, followed by each index in the arrays planeLayoutF and planeLayoutE. 
void printPlaneLayout(int planeLayoutF[], int planeLayoutE[])
{

    printf("%s\n", "***Plane Layout Depicted Below (Passengers indicated with '1') ***\nFirst Class");
    printf("%6d\n%6d\n%6d\n%6d\n%6d\n", planeLayoutF[0], planeLayoutF[1], planeLayoutF[2], planeLayoutF[3], planeLayoutF[4]);

    printf("%10s", "Economy\n");
    printf("%6d\n%6d\n%6d\n%6d\n%6d\n", planeLayoutE[0], planeLayoutE[1], planeLayoutE[2], planeLayoutE[3], planeLayoutE[4]);
}
