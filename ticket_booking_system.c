#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEATS 20

void showSeats(int seats[]) {
	printf("\nSeat map (0 = free, 1 = booked):\n");
	for (int i = 0; i < MAX_SEATS; i++) {
		printf("%2d:%d  ", i+1, seats[i]);
		if ((i+1) % 5 == 0) printf("\n");
	}
}

void bookSeat(int seats[]) {
	int num, i, found = 0;
	printf("Enter seat number to book (1-%d): ", MAX_SEATS);
	if (scanf("%d", &num) != 1) { while (getchar() != '\n'); printf("Invalid input\n"); return; }
	if (num < 1 || num > MAX_SEATS) { printf("Out of range\n"); return; }
	i = num - 1;
	if (seats[i]) { printf("Seat %d already booked\n", num); }
	else { seats[i] = 1; printf("Seat %d booked successfully\n", num); }
}

void cancelSeat(int seats[]) {
	int num;
	printf("Enter seat number to cancel (1-%d): ", MAX_SEATS);
	if (scanf("%d", &num) != 1) { while (getchar() != '\n'); printf("Invalid input\n"); return; }
	if (num < 1 || num > MAX_SEATS) { printf("Out of range\n"); return; }
	if (!seats[num-1]) printf("Seat %d is already free\n", num);
	else { seats[num-1] = 0; printf("Booking for seat %d cancelled\n", num); }
}

void saveToFile(int seats[]) {
	FILE *f = fopen("bookings.txt", "w");
	if (!f) { printf("Could not save\n"); return; }
	for (int i = 0; i < MAX_SEATS; i++) fprintf(f, "%d\n", seats[i]);
	fclose(f);
	printf("Saved to bookings.txt\n");
}

void loadFromFile(int seats[]) {
	FILE *f = fopen("bookings.txt", "r");
	if (!f) return; // no file yet
	for (int i = 0; i < MAX_SEATS; i++) {
		if (fscanf(f, "%d", &seats[i]) != 1) seats[i] = 0;
	}
	fclose(f);
}

int main() {
	int seats[MAX_SEATS] = {0};
	int choice;
	loadFromFile(seats);
	while (1) {
		printf("\nSimple Ticket Booking\n");
		printf("1. Show seats\n2. Book seat\n3. Cancel seat\n4. Save & Exit\n");
		printf("Enter choice: ");
		if (scanf("%d", &choice) != 1) { while (getchar() != '\n'); printf("Bad input\n"); continue; }
		switch (choice) {
			case 1: showSeats(seats); break;
			case 2: bookSeat(seats); break;
			case 3: cancelSeat(seats); break;
			case 4: saveToFile(seats); printf("Bye\n"); return 0;
			default: printf("Choose 1-4\n");
		}
	}
	return 0;
}
