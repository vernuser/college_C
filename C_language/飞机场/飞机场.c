#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CAPACITY 5
#define MAX_CAR_NUMBER_LENGTH 10

typedef struct {
    int capacity;
    char spaces[MAX_CAPACITY][MAX_CAR_NUMBER_LENGTH];
    char waiting_queue[MAX_CAPACITY][MAX_CAR_NUMBER_LENGTH];
    int space_count;
    int waiting_count;
} ParkingLot;

void initParkingLot(ParkingLot *parkingLot, int capacity) {
    parkingLot->capacity = capacity;
    parkingLot->space_count = 0;
    parkingLot->waiting_count = 0;
}

void carArrive(ParkingLot *parkingLot, const char *carNumber) {
    if (parkingLot->space_count < parkingLot->capacity) {
        strcpy(parkingLot->spaces[parkingLot->space_count], carNumber);
        printf("���� %s ��ͣ����ͣ������ͣ��λ���Ϊ %d\n", carNumber, parkingLot->space_count + 1);
        parkingLot->space_count++;
    } else {
        strcpy(parkingLot->waiting_queue[parkingLot->waiting_count], carNumber);
        printf("ͣ�������������� %s �ѽ������Ŷ�\n", carNumber);
        parkingLot->waiting_count++;
    }
}

void carLeave(ParkingLot *parkingLot, const char *carNumber) {
    int i;
    for (i = 0; i < parkingLot->space_count; i++) {
        if (strcmp(parkingLot->spaces[i], carNumber) == 0) {
            int duration = i + 1;  // ����ͣ��ʱ�����ͣ�ڵ�λ�ü�1
            int fee = duration * 10;  // ����ÿСʱ10Ԫ
            printf("���� %s ���뿪ͣ������ͣ��ʱ��Ϊ %d Сʱ��ͣ������Ϊ %d Ԫ\n", carNumber, duration, fee);

            // �����뿪������ĳ���������ǰŲ
            int j=0;
            for (j = i; j < parkingLot->space_count - 1; j++) {
                strcpy(parkingLot->spaces[j], parkingLot->spaces[j + 1]);
            }
            parkingLot->space_count--;

            // ���������еȴ��ĳ��������õ�һ��������ͣ����
            if (parkingLot->waiting_count > 0) {
                strcpy(parkingLot->spaces[parkingLot->space_count], parkingLot->waiting_queue[0]);
                printf("����ϵĳ��� %s ��ͣ����ͣ����\n", parkingLot->waiting_queue[0]);

                // ��������ͣ�����󣬺���ĳ���������ǰŲ
                int k=0;
                for (k = 0; k < parkingLot->waiting_count - 1; k++) {
                    strcpy(parkingLot->waiting_queue[k], parkingLot->waiting_queue[k + 1]);
                }
                parkingLot->waiting_count--;
                parkingLot->space_count++;
            }
            return;
        }
    }
    printf("���� %s ����ͣ������.\n", carNumber);
}

void displayParkingStatus(ParkingLot *parkingLot) {
    printf("ͣ����ʣ���λ��%d\n", parkingLot->capacity - parkingLot->space_count);
    printf("ͣ�����ڳ�����");
    int i=0;
    for (i = 0; i < parkingLot->space_count; i++) {
        printf("%s ", parkingLot->spaces[i]);
    }
    printf("\n");
}

int main() {
    ParkingLot parkingLot;
    initParkingLot(&parkingLot, 5);
    carArrive(&parkingLot, "��A12345");
    carArrive(&parkingLot, "��B54321");
    carArrive(&parkingLot, "��C88888");
    carLeave(&parkingLot, "��A12345");
    displayParkingStatus(&parkingLot);
    return 0;
}
