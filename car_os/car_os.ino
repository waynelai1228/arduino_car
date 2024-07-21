void setup() {
  // put your setup code here, to run once:
  // setup timer
  // PRR1 = 0;                 // enables timer (see pg. 56 of data sheet)
  // TCCR0B = 1 << CS01;
  TCCR0B &= ~(1 << WGM02);
  TCCR0A |= 1 << WGM00;       
  TCCR0A |= 1 << WGM01;        // set to Fast PWM (pg. 86)
  TCCR0A |= 1 << COM0A1;       // toggle output for timer

  DDRD |= 1 << DDD6;           // enable hardware output (pg. 70-73)


  DDRD |= 1 << DDD7;           // this is the output setting for left motor direction
}

void loop() {
  // put your main code here, to run repeatedly:
  OCR0A = 0x00;
  // PORTD &= ~(1 << PD7);
  PORTD |= 1 << PD7;
}
