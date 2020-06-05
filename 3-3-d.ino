// ------------
// Sub to buddy and blink led
// SIT210-Task3.3D-CloudFunction
// ------------

int led2 = D7;

// Event handler
void myHandler(const char *event, const char *data);


void setup() {
    
    // Led setup
    pinMode(led2, OUTPUT);
    
    // Subscribe to deakin particle buddy
    Particle.subscribe("Deakin_RIOT_SIT210_Photon_Buddy", buddyHandler);
    
}


void loop() {
    // NoTHinG hERe !
}


void buddyHandler(const char *event, const char *data) {
    // Compare values to data
    if (strcmp(data,"wave")==0) {
        blink_run(1);
    }
    else if (strcmp(data,"pat")==0) {
        blink_run(0);
    }
    else {
        // Nothing
    }
}


int blink_run(int type_data) {
    // If type_data == 1: Wave
    if (type_data == 1) {
        ledBlink(600,600);
        ledBlink(600,600);
        ledBlink(600,600);
        return 1;
    }
    // Else its Pat
    else if (type_data == 0) {
        ledBlink(200,6000);
        ledBlink(30,30);
        ledBlink(30,30);
        ledBlink(30,30);
        ledBlink(30,30);
        return 0;
    }
    // Not either!?
    else {
        return -1;
    }
    return -1;
}


int ledBlink(int first, int second) {
    delay(first);
    digitalWrite(led2,HIGH);
    delay(second);
    digitalWrite(led2,LOW);
    return 1;
}

