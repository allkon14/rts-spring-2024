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
  
    for (int i = 0; i < num_of_pins; i++){
        if (last_check_time_micros - previous_led_micros[i] >= pulseDurations[i])
        {
            // обновляем время последнего мигания
            previous_led_micros[i] = last_check_time_micros;
        
            // обновляем состояние
            if (state[i] == LOW){
                state[i] = HIGH; 
            }
            else {
                state[i] = LOW;
            }
            digitalWrite(pins[i], state[i]);
        }
    }
}
