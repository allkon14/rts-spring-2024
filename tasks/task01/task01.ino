// текущий момент времени
unsigned long last_check_time_micros = 0;

// последнее мигание для каждой лампочки
unsigned long previous_led_micros[] = {0, 0, 0, 0, 0};

// состояния лампочек
int state[] = {LOW, LOW, LOW, LOW, LOW};

int pins[] = {3, 5, 6, 9, 10};
int num_of_pins = 5;

// 10 мс, 1 мс, 500 мкс, 100 мкс, 50 мкс
unsigned long pulseDurations[] = {10000, 1000, 500, 100, 50};


void setup() {
    // изменение потока на пинах (по умолчанию INPUT)
    pinMode(3, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
}

void loop() {
    // плохой вариант с использованием delay - остановка выполнения программы
    // digitalWrite(3, HIGH);
    // delay(1000);
    // digitalWrite(3, LOW);

    // digitalWrite(5, HIGH);
    // delay(100);
    // digitalWrite(5, LOW);

    // digitalWrite(6, HIGH);
    // delayMicroseconds(50000);
    // digitalWrite(6, LOW);

    // digitalWrite(9, HIGH);
    // delayMicroseconds(10000);
    // digitalWrite(9, LOW);

    // digitalWrite(10, HIGH);
    // delayMicroseconds(5000);
    // digitalWrite(10, LOW);

  
  
    // вторая реализация с проверкой времени
    last_check_time_micros = micros();
  
  
    // код дублируется, так как использование циклов нежелательно
    //1 лампочка
    if (last_check_time_micros - previous_led_micros[0] >= pulseDurations[0])
    {
        // обновляем время последнего мигания
        previous_led_micros[0] = last_check_time_micros;

        // обновляем состояние
        if (state[0] == LOW){
          state[0] = HIGH; 
        }
        else {
          state[0] = LOW;
        }
        digitalWrite(pins[0], state[0]);
    }
  
    //2 лампочка
    if (last_check_time_micros - previous_led_micros[1] >= pulseDurations[1])
    {
        // обновляем время последнего мигания
        previous_led_micros[1] = last_check_time_micros;

        // обновляем состояние
        if (state[1] == LOW){
          state[1] = HIGH; 
        }
        else {
          state[1] = LOW;
        }
        digitalWrite(pins[1], state[1]);
    }
    //3 лампочка
    if (last_check_time_micros - previous_led_micros[2] >= pulseDurations[2])
    {
        // обновляем время последнего мигания
        previous_led_micros[2] = last_check_time_micros;

        // обновляем состояние
        if (state[2] == LOW){
          state[2] = HIGH; 
        }
        else {
          state[2] = LOW;
        }
        digitalWrite(pins[2], state[2]);
    }
    //4 лампочка
    if (last_check_time_micros - previous_led_micros[3] >= pulseDurations[3])
    {
        // обновляем время последнего мигания
        previous_led_micros[3] = last_check_time_micros;

        // обновляем состояние
        if (state[3] == LOW){
          state[3] = HIGH; 
        }
        else {
          state[3] = LOW;
        }
        digitalWrite(pins[3], state[3]);
    }

    //5 лампочка
    if (last_check_time_micros - previous_led_micros[4] >= pulseDurations[4])
    {
        // обновляем время последнего мигания
        previous_led_micros[4] = last_check_time_micros;

        // обновляем состояние
        if (state[4] == LOW){
          state[4] = HIGH; 
        }
        else {
          state[4] = LOW;
        }
        digitalWrite(pins[4], state[4]);
    }
}
