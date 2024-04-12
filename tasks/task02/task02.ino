#include <TaskManagerIO.h>

#define NUMBER_OF_PINS 5

// текущий момент времени
unsigned long last_check_time_micros = 0;

// последнее мигание для каждой лампочки
unsigned long previous_led_micros[] = {0, 0, 0, 0, 0};

// состояния лампочек
int states[NUMBER_OF_PINS] = {LOW, LOW, LOW, LOW, LOW};

// номер ножек
int pins[NUMBER_OF_PINS] = {3, 5, 6, 9, 10};

// 10 мс, 1 мс, 500 мкс, 100 мкс, 50 мкс
unsigned long pulseDurations[] = {10000, 1000, 500, 100, 50};


// определение функции для смены состояния лампочек
void change_state(int states[], int pins[], int i){
  if (states[i] == LOW) {
      states[i] = HIGH;
  }
  else {
    states[i] = LOW;
  }
  digitalWrite(pins[i], states[i]);
}

void setup() {

    // изменение потока на пинах (по умолчанию INPUT)
    for (int i = 0; i < NUMBER_OF_PINS; ++i) {
        states[i] = LOW;
        pinMode(pins[i], OUTPUT);
  	}
  
    taskid_t taskId0 = taskManager.scheduleFixedRate(pulseDurations[0], [] {
      toggleLedState(pins[0], states[0]);
    }, TIME_MICROS);

    taskid_t taskId1 = taskManager.scheduleFixedRate(pulseDurations[1], [] {
      toggleLedState(pins[1], states[1]);
    }, TIME_MICROS);

    taskid_t taskId2 = taskManager.scheduleFixedRate(pulseDurations[2], [] {
      toggleLedState(pins[2], states[2]);
    }, TIME_MICROS);

    taskid_t taskId3 = taskManager.scheduleFixedRate(pulseDurations[3], [] {
      toggleLedState(pins[3], states[3]);
    }, TIME_MICROS);

    taskid_t taskId4 = taskManager.scheduleFixedRate(pulseDurations[4], [] {
      toggleLedState(pins[4], states[4]);
    }, TIME_MICROS);
}
void loop() {
    taskManager.runLoop();
}
