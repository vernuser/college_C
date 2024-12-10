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
        printf("车辆 %s 已停放在停车场，停车位编号为 %d\n", carNumber, parkingLot->space_count + 1);
        parkingLot->space_count++;
    } else {
        strcpy(parkingLot->waiting_queue[parkingLot->waiting_count], carNumber);
        printf("停车场已满，车辆 %s 已进入便道排队\n", carNumber);
        parkingLot->waiting_count++;
    }
}

void carLeave(ParkingLot *parkingLot, const char *carNumber) {
    int i;
    for (i = 0; i < parkingLot->space_count; i++) {
        if (strcmp(parkingLot->spaces[i], carNumber) == 0) {
            int duration = i + 1;  // 假设停车时间就是停在的位置加1
            int fee = duration * 10;  // 假设每小时10元
            printf("车辆 %s 已离开停车场，停留时间为 %d 小时，停车费用为 %d 元\n", carNumber, duration, fee);

            // 车辆离开，后面的车辆依次往前挪
            int j=0;
            for (j = i; j < parkingLot->space_count - 1; j++) {
                strcpy(parkingLot->spaces[j], parkingLot->spaces[j + 1]);
            }
            parkingLot->space_count--;

            // 如果便道上有等待的车辆，则让第一辆车进入停车场
            if (parkingLot->waiting_count > 0) {
                strcpy(parkingLot->spaces[parkingLot->space_count], parkingLot->waiting_queue[0]);
                printf("便道上的车辆 %s 已停放在停车场\n", parkingLot->waiting_queue[0]);

                // 车辆进入停车场后，后面的车辆依次往前挪
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
    printf("车辆 %s 不在停车场内.\n", carNumber);
}

void displayParkingStatus(ParkingLot *parkingLot) {
    printf("停车场剩余空位：%d\n", parkingLot->capacity - parkingLot->space_count);
    printf("停车场内车辆：");
    int i=0;
    for (i = 0; i < parkingLot->space_count; i++) {
        printf("%s ", parkingLot->spaces[i]);
    }
    printf("\n");
}

int main() {
    ParkingLot parkingLot;
    initParkingLot(&parkingLot, 5);
    carArrive(&parkingLot, "京A12345");
    carArrive(&parkingLot, "京B54321");
    carArrive(&parkingLot, "京C88888");
    carLeave(&parkingLot, "京A12345");
    displayParkingStatus(&parkingLot);
    return 0;
}
